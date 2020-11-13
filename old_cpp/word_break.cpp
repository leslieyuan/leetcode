#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector< vector<string> > vvsAllWay;

void recurFindDictWords(string s, vector<string> &vsOneWay, const unordered_set<string> &wordDict)
{
	// Recursion end 
	if(s.empty())
	{
		// Get one method to cut up
		vvsAllWay.push_back(vsOneWay);
		return;
	}		

	int i_npos = 1;	
	string s_sub;
	do
	{
		auto vs_tmp = vsOneWay;
		s_sub = s.substr(0, i_npos);
		// If words found in dict
		if(wordDict.find(s_sub) != wordDict.end())
		{
			vs_tmp.push_back(s_sub);
			recurFindDictWords(s.substr(i_npos), vs_tmp, wordDict);
		}
		++i_npos;	
	}while(s_sub != s);
}

int main()
{
	string s = "mcatsanddog";
	unordered_set<string> set_dict = {"m", "cat", "cats", "and", "sand", "dog"};
	
	vector<string> vs_re_one_way;
	recurFindDictWords(s, vs_re_one_way, set_dict);

	for(const auto &vs : vvsAllWay)
	{
		for(const auto &s : vs)
		{
			cout << s << ",";
		}
		cout << endl;
	}

	return 0;
}
