/* Note: 
	1. INT_MIN = -2^31; INT_MAX = 2^31-1
	2. to_string(); stoi()
	3. std::reverse(xx.begin(), xx.end())

   URL:
	https://leetcode.com/problems/reverse-integer/
*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;
int getReverse(int x);

int main()
{
	int i = 2147483641;
	int i_rev = getReverse(i);
	cout << i_rev << endl;

	getchar();
	return 0;
}

int getReverse(int x)
{
	// Can't be INT_MIN
	if (x == INT_MIN)
	{
		return 0;
	}
	
	// To string, and reverse
	string str_x = to_string(abs(x));
	std::reverse(str_x.begin(), str_x.end());

	// Overflow juge
	string str_max = to_string(INT_MAX);
	if ((str_x.size() == str_max.size()) && (str_x.compare(str_max) > 0))
	{
		return 0;
	}

	return (x > 0) ? stoi(str_x) : stoi(str_x) * -1;
}