#include <iostream>
#include <vector>

using namespace std;

void insertToSortedArray(vector<int> &des, int iLeft, int iRight, int iNum)
{
	if(iLeft >= iRight)
	{
		auto itor = des.begin();
		if(des[iRight] > iNum)
		{
			des.insert(itor + iLeft, iNum);
			return;
		}
		else
		{
			if((itor + iRight + 1) == des.end())
			{
				des.push_back(iNum);
				return;
			}
			des.insert(itor + iRight + 1, iNum);
			return;
		}
	}

	int i_mid = (iLeft + iRight) / 2;
	if(des[i_mid] >= iNum)
	{
		insertToSortedArray(des, iLeft, i_mid - 1, iNum);
	}
	else
	{
		insertToSortedArray(des, i_mid + 1, iRight, iNum);
	}
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	// all empty
	if(nums1.empty() && nums2.empty())
	{
		return 0.0;
	}

	// nums1 not empty
	if(!nums1.empty())
	{
		for(const auto &i : nums2)
		{
			insertToSortedArray(nums1, 0, nums1.size() - 1, i);      
		}
	}
	// nums2 is empty, nums2 not
	else
	{
		nums1.swap(nums2);
	}

	int i_mid = nums1.size() / 2;

	if(nums1.size() == 2 || nums1.size() % 2 == 0)
	{
		return (nums1[i_mid] + nums1[i_mid - 1]) / 2.0;
	}
	return nums1[i_mid] / 1.0;
}

int main()
{
	vector<int> vi_1 = {3,4};
	vector<int> vi_2 = {1,2,3};
	auto result = findMedianSortedArrays(vi_1, vi_2);
	for(auto i : vi_1)
	{
		cout << i << ",";
	}
	cout << "\n";
	cout << result << endl;

	return 0;
}

