## Description 
Given *n*, how many structurally unique **BST's** (binary search trees) that store values 1 ... *n*?

````
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
````
## Solution
Complete Times:  1<br/>
Difficulty:  4 (for me, still having problem understanding the logic<br/>
Time complexity: O(N^2) where N is the number of nodes<br/>
Space complexity: O(N)<br/>

To solve this problem, we use dynamic programming technique, where the number of unique subtrees under each node is stored.  The base case is `node0` (empty subtree) is 0, `node1` is 1, and `node2` is 2, then for each new node added, we do the following calculation:

- The number of unique subtrees under new node  `n` equals to the sum of unique subtrees from `1` to `n`, and each node `i` is calculated by  `# of node (i-1) * # of node(n-i)`
- The left subtree is put the max subtree to the left of the root, and the right subtree is put the max subtree to the right of the root. 
- when computing the value of right subtree which consists of nodes from `i+1` to `n`, we do not have the value of `n`, however, since it has `n-i-1` nodes which equals to `n-1-i` , we can use the result from `n-1` to represent the number of unique subtree on the right.

````python
class Solution:
    def numTrees(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        db = [1,1,2] # first term means when the left or right subtree is empty, give 1
        for i in range(3,n+1):
            db.append(1)
            ans = 0
            for j in range(1,i+1):
                if j >= n-1:
                    ans += db[j-1]
                else:
                    ans += db[j-1]*db[i-j]
            db[-1] = ans
        return db[-1]
````



