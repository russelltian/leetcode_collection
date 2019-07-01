## Description 
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.
````
Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
````
## Solution
Complete Times: 3 <br/>
Difficulty: 2 <br/>
Time complexity: O(N^2)<br/>  66%
Solution: first sort this array, then start from left side,
iterate each unique value i, then use -i as target, check the rest of lists,
try to find j + k == -i. If such combinations exist, push them to the ans,
else, if j+k > -i, k (rhs) needs to keep decreasing until k != prev k.. 
The termination condition is lhs >= rhs 




