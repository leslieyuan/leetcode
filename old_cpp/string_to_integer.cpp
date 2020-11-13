/* Note:
	1. StringStream's head file is <sstream>
	2. Empty a StringStream like this: ss.str("")
	3. substr(size_type pos, size_type lenght)

   URL:
   	https://leetcode.com/problems/string-to-integer-atoi/

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int myAtoi(string str);
int myAtoiAllDigit(string str);

int main()
{
	// Test Cases
	vector<string> vs_cases;
	vs_cases.push_back("987"); // 987
	vs_cases.push_back("-987"); // -987
	vs_cases.push_back("  987"); // 987
	vs_cases.push_back("  +987 "); // 987
	vs_cases.push_back("  -987 "); // -987
	vs_cases.push_back("  -987 00Ad "); // -987
	vs_cases.push_back("2147483647"); // 2147483647 (INT_MAX)
	vs_cases.push_back("2147483648"); // 2147483647 overflow 
	vs_cases.push_back("-2147483648"); // -2147483648¡¡(INT_MIN)
	vs_cases.push_back("-2147483649"); // -2147483648 overflow

	// Test and print
	for (auto s : vs_cases)
	{
		int i_re = myAtoi(s);
		cout << s << "\t trans to \t" << i_re << endl;
	}
	
	getchar();
	return 0;
}

int myAtoi(string str)
{
	// Skip all front space
	for (unsigned i = 0; i < str.size(); ++i)
	{
		if (!isspace(str[i]))
		{
			str = str.substr(i);
			break;
		}
	}

	// Empty juge
	if (str.empty())
	{
		return 0;
	}

	// Negative juge
	int i_flag = 1;
	if ('-' == str[0])
	{
		i_flag = -1;
		str = str.substr(1);
		if (str.empty())
		{
			return 0;
		}
	}
	else if ('+' == str[0])
	{
		str = str.substr(1);
	}

	// Get first part digit
	stringstream ss_str;
	for (auto c : str)
	{
		if (!isdigit(c))
		{
			break;
		}
		ss_str << c;
	}
	str = ss_str.str();

	// Overflow juge
	string str_max_int = to_string(INT_MAX);
	string str_min_int = to_string(INT_MIN);
	str_min_int = str_min_int.substr(1);
	if (str.size() >= str_max_int.size())
	{
		if (i_flag == 1)
		{

			if ((str.size() > str_max_int.size()) || (str.compare(str_max_int) > 0))
			{
				return INT_MAX;
			}
		}
		else
		{

			if ((str.size() > str_min_int.size()) || (str.compare(str_min_int) > 0))
			{
				return INT_MIN;
			}
		}
	}

	// Trans to int
	int i_result = myAtoiAllDigit(str);
	return i_result * i_flag;
}

// Trans pure digit string
int myAtoiAllDigit(string str)
{
	if (str.empty())
	{
		return 0;
	}

	int i_size = str.size();

	int i_head_digit = str[0] - '0';
	return i_head_digit * pow(10, i_size - 1) + myAtoiAllDigit(str.substr(1));
}