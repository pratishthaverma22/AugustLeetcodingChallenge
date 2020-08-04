/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:
Input: 16
Output: true

Example 2:
Input: 5
Output: false
*/


class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0)return false;
        for(int i=0;i<32;i+=2)if(num==1<<i)return true;
        return false;
    }
};
