//
//  Tree.hpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/6.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
bool isValidBST(TreeNode* root);
void ValidBST(TreeNode* root, bool &ans,long &ref);//98 validate BST,mid- in-order traversal
int maxDepth(TreeNode* root);
void maxDepth_search(TreeNode* root,int temp,int&ans); //109 max depth of binary tree, easy
void flatten(TreeNode* root);
void flatten_helper(TreeNode* root,vector<TreeNode*> &ans);//114, flatten BT to linkedlist
#endif /* Tree_hpp */
