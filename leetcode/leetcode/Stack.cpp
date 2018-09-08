//
//  Stack.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/2.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Stack.hpp"
/*
 94, in order traversal using iterative method
 */
vector<int> inorderTraversal(TreeNode* root) {
    // if the root has left , all the way to the left, and pushing back to stack
    // then pop up the most left from the stack,
    // push it back to answer
    // then goes to right , and repeat until the stack becomes empty
    stack<TreeNode*> memory;
    vector<int> answer;
    TreeNode* cur = root;
    while(!memory.empty() || cur != NULL){
        if(cur == NULL){
            cur = memory.top();
            answer.push_back(cur->val);
            cur = cur->right;
            memory.pop();
        }else{
            memory.push(cur);
            cur=cur->left;
        }
    }
    return answer;
    }

/*
103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		stack<TreeNode*>mystack;
		vector<vector<int>>ans;
		if (!root)return ans;
		mystack.push(root);
		int left_or_right = 0;//0 left to right, 1 right to left
		while (!mystack.empty()) {
			vector<TreeNode*>temp;
			while (!mystack.empty()) {
				temp.push_back(mystack.top());
				mystack.pop();
			}
			vector<int> onelayer;//for ans vector
			for (auto i : temp) {
				if (!left_or_right) {
					if (i->left)mystack.push(i->left);
					if (i->right)mystack.push(i->right);

				}
				else {
					if (i->right)mystack.push(i->right);
					if (i->left)mystack.push(i->left);
				}onelayer.push_back(i->val);
			}
			//toggle the left and right 
			left_or_right = ~left_or_right;
			ans.push_back(onelayer);
		}
		return ans;
	}
