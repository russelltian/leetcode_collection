## Description 
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
````
Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
````
````
Example 2:

Input: "cbbd"
Output: "bb"
````
## Solution
Complete Times: 3 <br/>
Difficulty: 3 <br/>
Time complexity: O(N^2)<br/>
Space complexity: O(N^2)<br/>
The idea is to use dynamic programming record if s[i] to s[j] is a 
palindrome, then in the next iteration, check if s[i-1] and s[j+1] is equal
under the condition where isPanlindrome[i][j] equals true.
The current solution is neat, but very slow (160ms), next round will come 
up with a faster solution.
