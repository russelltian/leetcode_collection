## Description 
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

````
Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
````
````
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
````
## Solution
Complete Times:  2<br/>
Difficulty:  2<br/>
Time complexity: O(N)<br/>
Space complexity: O(1)<br/>

Set a variable called `limit` to record the max distance can reach. If can't reach the next element in the iteration, return false. Otherwise, check the furthest distance `ith` element can reach.

Keep updating unless it reaches the last element or `limit` goes beyond the max. 

