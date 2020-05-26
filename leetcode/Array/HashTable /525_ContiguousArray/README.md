## Description

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

````
Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
````
````
Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
````
## Solution
Complete Times:  2<br/>
Time complexity: O(N)<br/>
Space complexity: O(N)<br/>

Have a integer to store the sum of the series, if element is 0, plus -1, if element is 1, plus 1. Have a hash table, where the key is the sum of the series over each element, and the value is its index at that element. If a new value is encountered, store its index, if already exist, the difference between the current index and the old index is the subarray with equal number of 0 and 1.
```python
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        store = {}
        store[0] = -1
        s = 0
        ans = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                s += -1
            else:
                s +=1
            if s in store:
                ans = max(ans,i-store[s])
            else:
                store[s] = i
        return ans
```
