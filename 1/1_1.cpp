#include <fstream>
#include <iostream>

using std::string;

int main()
{
	std::ifstream input("input.txt");
	string line;
	const string digits = "0123456789";
	int sum = 0;
	while (input >> line)
		sum += stoi(line.substr(line.find_first_of(digits), 1) + 
					line.substr(line.find_last_of(digits), 1));
	std::cout << sum << std::endl;
}