## Description 

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

```
Example 1:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

## Solution

Complete Times:  1<br/>
Difficulty: 3<br/>
Time complexity: O(N!)<br/>
Space complexity: O(N!)<br/>

**1st Time**  July 28, 2019 

On top of permutation , add a look up table to store the string version of  permutation, and exclude the extra ones

Slow as hell