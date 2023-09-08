#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/ore_info.hpp"
#include "interfaces/msg/ore_array.hpp"
#include "interfaces/srv/ore_position.hpp"
#include "geometry_msgs/msg/point.hpp"


class MiningIndustry : public rclcpp::Node {
public:
    MiningIndustry() : Node("mining_industry") {

        // 创建一个发布者
        publisher_ = this->create_publisher<interfaces::msg::OreArray>("topic", 10);
        //从param.yaml加载参数
        this->declare_parameter("n", 0); //
//        this->declare_parameter("n", 10); //
//        this->declare_parameter("n", 10); //
        this->get_parameter("n", n_);
//        if(n_ > 0)
//        {

        // 创建一个定时器，每秒触发一次发布矿石信息的函数
        timer_ = this->create_wall_timer(
                std::chrono::milliseconds(1000),  //
                std::bind(&MiningIndustry::publishOreInfo, this)

        );
//        }
        //创建服务端
        service_ = this->create_service<interfaces::srv::OrePosition>("ore_srv", std::bind(&MiningIndustry::srvr, this, std::placeholders::_1, std::placeholders::_2));


    }

private:
    interfaces::msg::OreArray ores;

    void publishOreInfo() {
        if(n_ > 0)
        {
            //建立矿石信息
            for (int64_t i = 1; i <= n_; ++i) {
                interfaces::msg::OreInfo ore;
                ore.num = i;
                ore.type = (i % 2 == 0) ? "gold" : "silver";
                ore.position.x = RandomPosition();
                ore.position.y = RandomPosition();
                ore.position.z = RandomPosition();
                ore.value = (ore.type == "gold") ? -80.8 : -40.4;
                ores.ores.push_back(ore);
            }
            RCLCPP_INFO(this->get_logger(), "I send! ores: %zu", n_);
            //发布
            publisher_->publish(ores);
        }
    }
    void srvr(const std::shared_ptr<interfaces::srv::OrePosition::Request> request,
              std::shared_ptr<interfaces::srv::OrePosition::Response> response) {
//        auto idd = request->id;
//        if (idd < 0 || idd >= ores.ores.size()) {
//            RCLCPP_ERROR(this->get_logger(), "Invalid ore ID requested");
//            return;
//        }
        //寻找所需矿石地址
        int64_t record = 0;
        for(int64_t i = 1; i <= n_; ++i)
        {
            if(ores.ores[i].num == request->id)
            {
                response->position = ores.ores[i].position;
                record = i;
            }

        }

        RCLCPP_INFO(this->get_logger(), "Mining! x = %f, y = %f, z = %f", response->position.x,response->position.y,response->position.z);
        //修改矿石信息
        for(int64_t i = record; i < n_; ++i)
        {
            ores.ores[i] = ores.ores[i+1];
        }
        n_ = n_ - 1;
        this->set_parameter(rclcpp::Parameter("n", n_));
    }

    //给矿石地址随机
    double RandomPosition() {
        return (rand() % 21)-10;
    }

    rclcpp::Publisher<interfaces::msg::OreArray>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int64_t n_;
    rclcpp::Service<interfaces::srv::OrePosition>::SharedPtr service_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MiningIndustry>());
    rclcpp::shutdown();
    return 0;
}



