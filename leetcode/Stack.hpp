//
//  Stack.hpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/2.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> inorderTraversal(TreeNode* root); //94, binary tree inorder traversal, mid, hard to me 
vector<vector<int>> zigzagLevelOrder(TreeNode* root);//103. Binary Tree Zigzag Level Order Traversal, mid, interview
#endif /* Stack_hpp */
