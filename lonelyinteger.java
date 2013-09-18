/*
 * File: lonelyinteger.java
 * Class: Solution
 * Author: Charles Guan
 * Last Edit: 2013-09-17
 * ---------------------
 * Solves https://www.hackerrank.com/challenges/lonely-integer
 * Determines which number only occurs once out of an array of integers. All
 * other intgers in the array occur exactly twice.
 * 
 * Input:
 *      First line contains N, the length of the list
 *      Next line contains N integers separated by a single space.
 *
 * Output:
 *      The integer that only occurs once.
 */

import java.io.*;

public class Solution {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int arrayLength = Integer.parseInt(br.readLine());
        String[] array = br.readLine().split(" ");
        int lonelyInt = 0;
        for (int i = 0; i < arrayLength; i++) {
            // Use XOR function so that all pairs are canceled out, leaving
            // the single integer.
            lonelyInt ^= Integer.parseInt(array[i]);
        }
        System.out.println(lonelyInt);
    }
}
