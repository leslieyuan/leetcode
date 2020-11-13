package com.leslieyuan.algorithm;

import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] nums = new int[]{8, 5, 22, 19, 3};
        BubbleSort bubbleSort = new BubbleSort();
        bubbleSort.bubbleSort(nums);
        ArraysHelper.printArray(nums);
    }

    private void bubbleSort(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len; --len) {
            boolean orderness = true;
            for (int j = i; j < len - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    ArraysHelper.swap(nums, j, j + 1);
                    orderness = false;
                }
            }
            if (orderness) {
                break;
            }
        }
    }
}
