#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <chrono>
#include <random>
#include <cmath>


//����� 
double add(std::vector<double>& nums)
{
	double sum = 0.0;
	for (auto& num : nums)
	{
		sum += num;
    }
	return sum;
}
//����ƽ��ֵ 
double average(std::vector<double>& nums)
{
	double average = 0.0;
	double sum = add(nums);
	average = sum / 100;
	return average;
}
//���㷽�� 
double variance(std::vector<double>& nums)
{
	double avr = average(nums);
	double var = 0.0;
	for (auto& num : nums) 
	{
		var += pow(num - avr, 2);
	}
	var = var / 100.0;
	return var;

}
//����˻� 
double product(std::vector<double>& nums)
{
	double prod = 1.0;
	for (auto& num : nums)
	{
		prod *= num;
	}
	return prod;
}
 
double createTimerLoop(int period, std::vector<double>& data,
	std::vector<std::function<double(std::vector<double>&)>>& operations)
{
	//����0-9������� 
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
		double op = operation(data);
		//std::cout << op << std::endl;
		std::cout << "Operation: " << ran << std::endl;
		std::cout << "Result: " << op << std::endl;

        //ʱ��ѭ�� 
		std::this_thread::sleep_for(std::chrono::milliseconds(period));
	}
	return 0.0;
}

int main()
{
	//1��4֮�����  
	std::random_device rd;
	double min = 1.0, max = 5.0;
	std::uniform_real_distribution<> dis(min, max);
	std::mt19937 gen(rd());

    //��ÿ����������� 
	std::vector<double> nums;
	for (int i = 0; i < 100; i++)
	{
		float num = dis(gen);
		nums.push_back(num);
	}
	
    //��������������ó����������� 
	std::vector<std::function<double(std::vector<double>&)>> operations = {add, average, variance, product};
	//ѭ�� 
    createTimerLoop(500, nums, operations);


	return 0;
}



