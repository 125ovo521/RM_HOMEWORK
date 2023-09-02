#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <chrono>
#include <random>
#include <cmath>


//����� 
float add(std::vector<float>& nums)
{
	float sum = 0.0;
	for (auto& num : nums)
	{
		sum += num;
    }
	return sum;
}
//����ƽ��ֵ 
float average(std::vector<float>& nums)
{
	float average = 0.0;
	float sum = add(nums);
	average = sum / 100;
	return average;
}
//���㷽�� 
float variance(std::vector<float>& nums)
{
	float avr = average(nums);
	float var = 0.0;
	for (auto& num : nums) 
	{
		var += pow(num - avr, 2);
	}
	var = var / 100.0;
	return var;

}
//����˻� 
float product(std::vector<float>& nums)
{
	float prod = 1.0;
	for (auto& num : nums)
	{
		prod *= num;
	}
	return prod;
}
 
float createTimerLoop(int period, std::vector<float>& data,
	std::vector<std::function<float(std::vector<float>&)>>& operations)
{
	//����0-3������� 
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::random_device rd;
//	int min = 1, max = 4;
	std::uniform_int_distribution<> dis(0, operations.size()-1);
	std::mt19937 gen(rd());

    //ʱ��ѭ�� ������������� 
	while (true)
	{
		int ran = dis(gen);
		auto operation = operations[ran];
		float op = operation(data);
		//std::cout << op << std::endl;
		if (ran == 0) std::cout << "Operation: add" << std::endl;
		else if (ran == 1) std::cout << "Operation: average" << std::endl;
		else if (ran == 2) std::cout << "Operation: variance" << std::endl;
		else std::cout << "Operation: product" << std::endl;
		std::cout << "Result: " << op << std::endl;

        //ʱ��ѭ�� 
		std::this_thread::sleep_for(std::chrono::milliseconds(period));
	}
	return 0.0;
}

int main()
{
	//���������������
	std::random_device rd;
//	float min = 1.0, max = 5.0;
	std::uniform_real_distribution<float> dis(0.0f, 3.0f);
	std::mt19937 gen(rd());

    //��ÿ����������� 
	std::vector<float> nums;
	for (int i = 0; i < 100; i++)
	{
		float num = dis(gen);
		nums.push_back(num);
	}
	
    //��������������ó����������� 
	std::vector<std::function<float(std::vector<float>&)>> operations = {add, average, variance, product};
	//ѭ�� 
    createTimerLoop(500, nums, operations);


	return 0;
}



