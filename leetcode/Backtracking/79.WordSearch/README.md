## Description 

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

````
Example 1:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

````
````
Example 2:


````
## Solution
Complete Times:  3<br/>
Difficulty: 3 (hard to code correctly) <br/>
Time complexity: O(N^2 * Len(Word)!)<br/>
Space complexity: O(N^2)<br/>

We start from the first element on the grid, and recursively traverse to up/down/left/right four direction if the element matches the character. To avoid traversing from the element just visited, we use another grids to record all the visited elements. Note the element has to be recovered once the recursion exit

