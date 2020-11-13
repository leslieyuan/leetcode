package com.leslieyuan.algorithm;

import java.util.Arrays;

/**
 * Found if an array has some numbers sum as the half sum of the whole.
 * Example: [1,5,6,2] return true. Because 1+6=7, 1+5+6+2=14. Just half.
 */
public class ZeroOneBackPack {
    public static void main(String[] args) {
        int[] nums = new int[] {1,5,6,2};
        ZeroOneBackPack instance = new ZeroOneBackPack();
        System.out.println(instance.zoBackPack(nums));
    }

    public boolean zoBackPack(int[] nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        boolean[][] flagNums = new boolean[nums.length][target+1];

        // Initial first row
        flagNums[0][0] = true;
        for (int i = 1; i < target+1; ++i) {
            flagNums[0][i] = false;
            if (i == nums[0]) {
                flagNums[0][i] = true;
            }
        }

        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < target+1; ++j) {
                flagNums[i][j] = flagNums[i-1][j];
                if (j >= nums[i]) {
                    flagNums[i][j] = flagNums[i-1][j - nums[i]] || flagNums[i-1][j];
                }
            }
            if (flagNums[i][target]) {
                return true;
            }
        }
        return false;
    }
}

