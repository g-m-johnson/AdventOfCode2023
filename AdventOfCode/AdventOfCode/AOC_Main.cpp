#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<unordered_map>

void Day1()
{

	std::unordered_map<std::string, int> wordToInt
	{
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9}
	};


	std::ifstream DataFile("../Data/day1_data.txt");
	std::string str;
	std::vector<int> numbers;
	int temp_int;
	std::string temp_str;

	int tot_sum = 0;
	int no_lines = 0;

	while(std::getline(DataFile, str))
	{
		//std::getline(DataFile, str);
		for (char& c : str)
		{
			std::stringstream temp_ss;
			temp_ss << c;
			temp_ss >> temp_str;
			if (std::stringstream(temp_str) >> temp_int)
			{
				numbers.push_back(temp_int);
				//std::cout << temp_int;
			}
		}
		
		tot_sum += (numbers.front() * 10 + numbers.back());
		numbers.clear();
	}
	std::cout << tot_sum << std::endl;

}

int main()
{
	Day1();
	return 0;
}