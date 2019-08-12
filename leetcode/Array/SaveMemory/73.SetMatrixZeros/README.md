## Description 

Given a *m* x *n* matrix, if an element is 0, set its entire row and column to 0. Do it [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm).

````
Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
````
````
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
````
## Solution
Complete Times:  2<br/>
Difficulty:  2<br/>
Time complexity: O(MN)<br/>
Space complexity: O(1)<br/>



Just use the first row and column to record if this row/col needs to zeroed. use two bool variable to represent  if there is originally any 0 value on the first row/col. And zero the first row/col after zero the other rows/cols

