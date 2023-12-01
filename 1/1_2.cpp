#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::string;
using std::min;
using std::max;

std::vector<string> words = {
	"one", "two", "three",
	"four", "five", "six",
	"seven", "eight", "nine"
};

std::pair <size_t, size_t> find_first_digit_word(string str)
{
	auto first = std::make_pair<size_t, size_t>(SIZE_MAX, SIZE_MAX);
	for (size_t i = 0; i < words.size(); i++)
	{
		auto pos = str.find(words[i]);
		if (pos != std::string::npos && pos < first.second)
		{
			first.first = i + 1;
			first.second = pos;
		}
	}
	return first;
}

std::pair <size_t, size_t> find_last_digit_word(string str)
{
	auto last = std::make_pair<size_t, size_t>(0, 0);
	for (size_t i = 0; i < words.size(); i++)
	{
		auto pos = str.rfind(words[i]);
		if (pos != std::string::npos && pos > last.second)
		{
			last.first = i + 1;
			last.second = pos;
		}
	}
	return last;
}

int main()
{
	std::ifstream input("input.txt");
	string line, s_num;
	const string digits = "0123456789";
	int sum = 0;
	while (input >> line)
	{
		auto first_word = find_first_digit_word(line);
		auto last_word = find_last_digit_word(line);
		auto first_digit_pos = line.find_first_of(digits);
		auto last_digit_pos = line.find_last_of(digits);

		if (first_digit_pos != std::string::npos 
			&& first_digit_pos < first_word.second)
			sum += stoi(line.substr(first_digit_pos, 1)) * 10;
		else
			sum += first_word.first * 10;

		if (last_digit_pos != std::string::npos 
			&& last_digit_pos >= last_word.second)
			sum += stoi(line.substr(last_digit_pos, 1));
		else
			sum += last_word.first;
	}
	std::cout << sum << std::endl;
}
