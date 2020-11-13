package com.leslieyuan.algorithm;


import java.util.Arrays;

/**
 * Arrays helper class.
 */
public class ArraysHelper {
    // Swap array
    public static void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    // Print the array
    public static void printArray(int[] nums) {
        Arrays.stream(nums).forEach(System.out::println);
    }
}
