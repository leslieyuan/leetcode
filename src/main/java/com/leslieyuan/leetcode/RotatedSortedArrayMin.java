package com.leslieyuan.leetcode;

/**
 * leetcode #153
 * Find Minimum in Rotated Sorted Array
 */
public class RotatedSortedArrayMin {
    public static void main(String[] args) {
        int[] nums = new int[] {4,5,6,7,0,1,2};
        RotatedSortedArrayMin min = new RotatedSortedArrayMin();
        System.out.println(min.findMin(nums));
    }

    public int findMin(int[] nums) {
        int first = nums[0];
        int pivot = nums[0];
        for (int i = 0 ; i < nums.length; ++i) {
            if (nums[i] < pivot) {
                return Math.min(first, nums[i]);
            }
            pivot = nums[i];
        }
        return first;
    }
}
