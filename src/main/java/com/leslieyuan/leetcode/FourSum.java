package com.leslieyuan.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * https://leetcode.com/problems/4sum/
 * Give a array and a target, pick 4 numbers which sum equal target.
 */
public class FourSum {
    public static void main(String[] args) {
        int[] nums = new int[]{0, 0, 0, 0};
        FourSum fourSum = new FourSum();
        for (List lst : fourSum.fourSum(nums, 0)) {
            System.out.println(lst.toString());
        }
    }


    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        return kSum(nums, 0, target, 4);
    }

    public List<List<Integer>> kSum(int[] nums, int start, int target, int k) {
        List<List<Integer>> result = new ArrayList<>();
        if (start + k > nums.length || nums[start] * k > target || nums[nums.length - 1] * k < target) {
            return result;
        }

        if (k == 2) {
            return twoSum(nums, start, target);
        }

        for (int i = start; i < nums.length; ++i) {
            int current = nums[i];
            int need = target - current;
            if (i == start || nums[i] != nums[i - 1]) {
                for (List<Integer> lst : kSum(nums, i + 1, need, k - 1)) {
                    result.add(new ArrayList<>(Arrays.asList(current)));
                    result.get(result.size() - 1).addAll(lst);
                }
            }
        }
        return result;
    }

    public List<List<Integer>> twoSum(int[] nums, int target, int start) {
        List<List<Integer>> res = new ArrayList<>();
        int lo = start, hi = nums.length - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
                ++lo;
            else if (sum > target || (hi < nums.length - 1 && nums[hi] == nums[hi + 1]))
                --hi;
            else
                res.add(Arrays.asList(nums[lo++], nums[hi--]));
        }
        return res;
    }
}
