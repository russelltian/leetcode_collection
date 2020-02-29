## Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree `[3,9,20,null,null,15,7]`

```
Example 1:
    3
   / \
  9  20
    /  \
   15   7
```
return its level order traversal as:

```
[
  [3],
  [9,20],
  [15,7]
]
```
## Solution

Complete Times:  3<br/>
Difficulty: 2<br/>
Time complexity: O(N)<br/>
Space complexity: O(N)<br/>

Use a `queue` to store the `node` of the tree elements.
For each level, first count the number of nodes. Second, limiting the visit of nodes by the number of nodes at that level, for each of the node, do the following: <br/>
1. push the `node->val` to a temporary array
2. push the children of `node` to the `queue` if there exist such of them
3. remove the `node` from the queue, and add the counter by 1 <br/>

After each level of traversal, push the temporary array to the answer.

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return{};
        queue <TreeNode*> lvl;
        vector<vector<int>>ans;
        lvl.push(root);
        while(!lvl.empty()){
            vector<int>temp;
            int size = lvl.size();
            int i = 0;
            while(i < size){
                TreeNode* front = lvl.front();
                temp.push_back(front->val);
                if(front->left)lvl.push(front->left);
                if(front->right)lvl.push(front->right);
                lvl.pop();
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }

```
