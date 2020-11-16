package com.leslieyuan.leetcode;

/**
 * leetcode #1310
 * XOR Queries of a Subarray
 */
public class XorQueries {
    public static void main(String[] args) {

    }

    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] xorP = new int[arr.length];   // New array, xorP[i] means all left(contain itself) arr's XOR result
        xorP[0] = arr[0];
        for (int i = 1; i < arr.length; ++i) {
            xorP[i] = xorP[i-1] ^ arr[i];
        }
        // [i][j] just equal xorP[j] ^ xorP[i-1]
        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            int start = queries[i][0];
            int to = queries[i][1];
            if (start == 0) {
                res[i] = xorP[to];
            } else {
                res[i] = xorP[start-1] ^ xorP[to];
            }
        }
        return res;
    }
}
