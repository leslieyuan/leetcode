package com.leslieyuan.leetcode;

import com.leslieyuan.algorithm.ArraysHelper;

import java.util.HashMap;

/**
 * https://leetcode.com/problems/two-sum/
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 */
public class TwoSum {
    public static void main(String[] args) {
        int[] nums = new int[]{1, 2, 3, 4};
        TwoSum twoSum = new TwoSum();
        ArraysHelper.printArray(twoSum.twoSum(nums, 6));
    }

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int need = target - nums[i];
            if (map.containsKey(need) && map.get(need) != i) {
                return new int[]{map.get(need), i};
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("Can't found an answer, pls check inputs");
    }
}
