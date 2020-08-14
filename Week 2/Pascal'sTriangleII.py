/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution:
    def getRow(self, rowIndex):
        return reduce(lambda r,_:[1]+[r[j]+r[j+1] for j in range(len(r)-1)]+[1], range(rowIndex),[1])
