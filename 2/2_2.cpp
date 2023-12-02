#include <fstream>
#include <iostream>
#include <sstream>

using std::string;

int find_max(string line, string color)
{
	std::istringstream ss(line);
	int num = 0;
	int max = 0;
	string t_color;
	while (ss >> num >> t_color)
	{
		if (t_color == color && num > max)
			max = num;
	}
	return max;
}

int power_of_line(string line)
{
	if (line.find(':') != std::string::npos)
		line = line.substr(line.find(':') + 1, line.length() - 1);

	line.erase(std::remove(line.begin(), line.end(), ','), line.end());
	line.erase(std::remove(line.begin(), line.end(), ';'), line.end());
	int maxblue = find_max(line, "blue");
	int maxred = find_max(line, "red");
	int maxgreen = find_max(line, "green");
	return maxblue * maxred * maxgreen;
}

int main()
{
	std::ifstream input("input.txt");
	int sum = 0;

	for (string line; getline(input, line);)
	{
		sum += power_of_line(line);
	}
	std::cout << sum << std::endl;
}