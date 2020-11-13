package com.leslieyuan.algorithm;

public class QuickSort {
    public static void main(String[] args) {
        int[] nums = new int[] {4,3,1,88,4,9};
        QuickSort quickSort = new QuickSort();
        quickSort.quickSort(nums, 0, nums.length-1);
        ArraysHelper.printArray(nums);
    }

    private void quickSort(int[] nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = nums[left];
        int fromLeft = left;
        int fromRight = right;
        while (fromLeft < fromRight) {
            while (fromRight > fromLeft && nums[fromRight] >= pivot) {
                fromRight--;
            }
            while (fromLeft < fromRight && nums[fromLeft] <= pivot) {
                fromLeft++;
            }
            ArraysHelper.swap(nums, fromLeft, fromRight);
        }
        ArraysHelper.swap(nums, left, fromLeft);
        quickSort(nums, left, fromLeft - 1);
        quickSort(nums, fromLeft + 1, right);
    }
}
