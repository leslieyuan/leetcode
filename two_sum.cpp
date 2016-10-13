#include <iostream>
#include <vector>


using namespace std;

// https://leetcode.com/problems/two-sum/

class Solution 
{
	public:
		vector<int> twoSum(vector<int>& nums, int target) 
		{
			vector<int> vi_return;
			for(int i = 0; i < nums.size(); ++i)
			{
				for(int j = i+1; j < nums.size(); ++j)
				{
					if(nums[j] == target - nums[i])
					{
						vi_return.push_back(i);
						vi_return.push_back(j);
						return vi_return;
					}
				}
			}
			return vi_return;
		}
};

int main()
{
	Solution s;
	vector<int> nums = {1,2,3,4,5};
	int target = 9;
	vector<int> re = s.twoSum(nums, target);
	for(int i : re)
	{
		cout << i << endl;
	}
	return 0;
}

