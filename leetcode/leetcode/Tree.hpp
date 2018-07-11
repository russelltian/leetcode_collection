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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);//235. Lowest Common Ancestor of a BST, easy, interesting idea
TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q);//236.Lowest Common Ancestor of a BT, mid, hard to me, important solution idea
/*
 must know
 */
TreeNode* invertTree(TreeNode* root);//226. Invert Binary Tree , easy, must know, homebrew google meme 
/*
 general helper function
 */
void inorder_insert_to_vec(TreeNode* root, vector<int>&a);
void postorder_insert_to_vec(TreeNode* root, vector<int>&a);

#endif /* Tree_hpp */
