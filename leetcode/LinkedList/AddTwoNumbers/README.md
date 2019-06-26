## Description 
You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
`
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
`

## Solution
Complete Times: 3 <br/>
Difficulty: 1 <br/>
Time complexity: O(N)<br/>
Space complexity: O(1)<br/>
Things to note: the key is to iterate through two lists
concurrently, and then has a Node to track the previous node,
so when one list reach the end, it can connect to the other one




