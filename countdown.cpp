#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

int Iter(const std::vector<int> &input, std::string &str);

int main()
{
	std::srand(unsigned(time(0)));
	rand(); rand(); rand();

	int target;
    std::cin >> target;
	std::vector<int> input = { 25, 50, 75, 100, 3};

	std::string outputInfo;
	int result = 0, foundCount = 0;
	while (foundCount < 10) //choose how many answers you want to look for
	{
		unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()); //obtain a time-based seed
		shuffle(input.begin(), input.end(), std::default_random_engine(seed));
		result = Iter(input, outputInfo);
		if (result == target)
		{
			++foundCount;
			std::cout << "Output info " << foundCount << " : " << outputInfo << std::endl;
		}
	}

	std::cin.get();
	return 0;
}

int Iter(const std::vector<int> &input, std::string &str)
{
	//input is already shuffled
	std::vector<int> operators(input.size() - 1);
	for (size_t i = 0; i < operators.size(); ++i) //filling the operators vector with random "operators" (atm just integers that define later on which operator will be used)
	{
		operators[i] = rand() % 4;
	}

	int _result = input[0];
	str.clear(); //clear for each new possible solution
	str += "((((("; //for visual output
	for (size_t i = 0; i < operators.size(); ++i)
	{
		//Making the string
		str += std::to_string(input[i]);
		if (i != 0) str += ')';

		//Calculations
		switch (operators[i])
		{
		case 0: _result += input[i + 1];
			str += " + ";
			break;
		case 1: _result -= input[i + 1];
			str += " - ";
			break;
		case 2: _result *= input[i + 1];
			str += " * ";
			break;
		case 3: _result /= input[i + 1];
			str += " / ";
			break;
		default: std::cout << "Hit default in loop from operators.\n";
			break;
		}
	}
	str += std::to_string(input[input.size() - 1]) + ')'; //need to do this out of the operators loop because there is 1 operator less than there are numbers

	return _result;
}