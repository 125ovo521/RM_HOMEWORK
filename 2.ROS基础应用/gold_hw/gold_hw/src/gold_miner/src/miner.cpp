#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/ore_info.hpp"
#include "interfaces/msg/ore_array.hpp"
#include "interfaces/srv/ore_position.hpp"
#include "geometry_msgs/msg/point.hpp"

#include <cmath>
#include <vector>
#include <chrono>

using std::placeholders::_1;

//struct minerPosition {
//    float_t x;
//    float_t y;
//    float_t z;
//};


class Miner : public rclcpp::Node {
public:
    Miner() : Node("miner") {
        subscription_ = this->create_subscription<interfaces::msg::OreArray>(
                "topic", 10, std::bind(&Miner::oreInfoCallback, this, _1));

//        callback_group_input_ = this->create_callback_group(rclcpp::callback_group::CallbackGroupType::MutuallyExclusive);

//        client_ = this->create_client<interfaces::srv::OrePosition>("ore_srv",rmw_qos_profile_services_default, callback_group_input_);
        client_ = this->create_client<interfaces::srv::OrePosition>("ore_srv");
//        this->declare_parameter("n", 1); //
//        this->get_parameter("n", n_);
    }

private:
    //设置矿工初始地点以及所得价值
    float_t miner_x = 0.0;
    float_t miner_y = 0.0;
    float_t miner_z = 0.0;
    float_t value_sum = 0.0;
    //计算距离
    float_t Distance(float_t x, float_t y, float_t z ) {
        float_t dx = x - miner_x;
        float_t dy = y - miner_y;
        float_t dz = z - miner_z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    void oreInfoCallback(const interfaces::msg::OreArray & msg) {  //
        RCLCPP_INFO(this->get_logger(), "I receive!");
        std::vector<float> dis;
        //找距离最近的矿石
        size_t count = msg.ores.size();
        for (size_t i = 0; i < count; ++i) {
            float_t mid = Distance(msg.ores[i].position.x, msg.ores[i].position.y,msg.ores[i].position.z);
            dis.push_back(mid);
        }
        size_t minPosition = min_element(dis.begin(),dis.end()) - dis.begin();
        //发布第一个矿石信息
        RCLCPP_INFO(this->get_logger(), "The first ore's information : id:%ld, x:%f, y:%f, z:%f, type:%s, value:%f", msg.ores[1].num, msg.ores[1].position.x,msg.ores[1].position.y,msg.ores[1].position.z, msg.ores[1].type.c_str(), msg.ores[1].value);
        //发出请求
        auto request = std::make_shared<interfaces::srv::OrePosition::Request>();
        request->id = msg.ores[minPosition].num;


        while (!client_->wait_for_service(std::chrono::seconds(1))) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
                // return 0;
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
        }
        //获取response
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "I need the ore id:%ld", msg.ores[minPosition].num);
        auto result = client_->async_send_request(request);

//        int inner_result = -1;
//        auto inner_client_callback = [&,this](rclcpp::Client<interfaces::srv::OrePosition>::SharedFuture inner_future)
//        {
//            auto inner_result = inner_future.get();
//            choice = stoi(inner_result->input);
//            RCLCPP_INFO(this->get_logger(), "[inner service] callback executed");
//        };
//        auto result = client_->async_send_request(request, inner_client_callback);
//
//        while (inner_result < 0 && rclcpp::ok())
//        {
//            std::this_thread::sleep_for(std::chrono::milliseconds(10));
//        }
//
//        // Wait for the result.
//        if (rclcpp::spin_until_future_complete(shared_from_this(), result) ==
//        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) ==
//            rclcpp::FutureReturnCode::SUCCESS)
//        {
//            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Position: %f", result.get()->position);
          //修改矿工地址
            miner_x = result.get()->position.x;
            miner_y = result.get()->position.y;
            miner_z = result.get()->position.z;
            value_sum += msg.ores[request->id].value;
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "I am here! x:%f, y:%f, z:%f, value:%f", miner_x,miner_y,miner_z, value_sum);
//        } else {
//            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service.");
//        }


    }

    rclcpp::Subscription<interfaces::msg::OreArray>::SharedPtr subscription_;
    rclcpp::Client<interfaces::srv::OrePosition>::SharedPtr client_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
//    rclcpp::executors::MultiThreadedExecutor executor;
    rclcpp::spin(std::make_shared<Miner>());
//    executor.add_node(std::make_shared<Miner>());
//    executor.spin();
    rclcpp::shutdown();
    return 0;
}

