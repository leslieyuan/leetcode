#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) 
{
	// Insert " " to every char, and the string's head and tail
	string s_with_space;
	for(char c : s)
	{
		s_with_space.push_back(' ');
		s_with_space.push_back(c);
	}
	s_with_space.push_back(' ');

	string s_re;
	// From the second char
	auto it_move = s_with_space.begin() + 1;
	while(it_move != s_with_space.end() - 1)
	{
		string s_sub;
		auto it_left = it_move - 1;
		auto it_right = it_move + 1;
		while(*it_left == *it_right)
		{
			// To the border
			if(it_left == s_with_space.begin() || it_right == s_with_space.end() - 1)
			{
				s_sub = s_with_space.substr(it_left - s_with_space.begin(), it_right - it_left + 1); // sutstr is [)
				break;
			}
			--it_left;
			++it_right;
		}
		if(s_sub.empty())
		{
			s_sub = s_with_space.substr(it_left - s_with_space.begin() + 1, it_right - it_left - 1);
		}

		if(s_sub.size() > s_re.size())
		{
			s_re = s_sub;
		}
		++it_move;
	}

	// Clear the " " insert by first step
	string s_re_no_space;
	for(char c : s_re)
	{
		if(c != ' ')
		{
			s_re_no_space.push_back(c);
		}
	}
	return s_re_no_space;
}

int main()
{
	string s = "forgeeksskeegfor";
	auto s_re = longestPalindrome(s);
	cout << s_re << endl;
	return 0;
}
