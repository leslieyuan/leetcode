#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

// https://leetcode.com/problems/two-sum/

class Solution 
{
	public:
		vector<int> twoSum(vector<int>& nums, int target) 
		{
			vector<int> vi_return;
			// Key is the num, value is the index.
			// std::unordered_map has a constant time complexity.
			unordered_map<int, int> umapii;
			int i_flag = 0;
			for(const auto &num : nums)
			{
				auto it = umapii.find(target - num);
				if(it != umapii.end())
				{
					vi_return.push_back(it->second);
					vi_return.push_back(i_flag);
					return vi_return;
				}
				umapii[num] = i_flag++;
			}
			return vi_return;
		}
};

int main()
{
	Solution s;
	vector<int> nums = {0,1,2,3,4,5,0};
	int target = 0;
	vector<int> re = s.twoSum(nums, target);
	for(int i : re)
	{
		cout << i << endl;
	}
	return 0;
}

