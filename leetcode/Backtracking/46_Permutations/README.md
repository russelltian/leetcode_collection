## Description 
Given a collection of distinct integers, return all possible permutations.
````
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
````
## Solution
Complete Times: 3 <br/>
Difficulty: 2 <br/>
Time complexity: O(N!)<br/>
Space complexity: O(N!)<br/>

The solution is having three vectors, 
one for storing all solutions, one for storing single 
solutions, and one for recording which element has been used
for permutation.
The helper function is called recursive, when each time
a combination is stored, the boolean vector update the 
usage record for each element, as well as the single solution
vector. Hence it will recursively store all the possible 
combinations until finishes.