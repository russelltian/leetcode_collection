//
//  Tree.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/6.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Tree.hpp"
/*
 #98, inorder run, the first reference, I use a extremely small number to hack it
 */
bool isValidBST(TreeNode* root) {
    //in order traversal, every next value should larger than previous one
    bool ans = true;
    if (!root || (!root->left&&!root->right))return true;
    long ref = LONG_MIN;
    
    ValidBST(root, ans,ref);
    
    return ans;
}
void ValidBST(TreeNode* root, bool &ans,long &ref){
    if(!root || !ans){
        return;
    }
    ValidBST(root->left,ans,ref);
    
    if(root->val <= ref ){
        ans = false;
        return;
    }
    ref = root->val;
    
    ValidBST(root->right,ans,ref);
    
    }

/*
 #109 , max depth of binary tree, easy just update reference when local var > than max reference
 */
int maxDepth(TreeNode* root) {
    int ans = 0;
    maxDepth_search(root,1,ans);
    return ans;
}
void maxDepth_search(TreeNode* root,int temp,int&ans){
    if(!root)return;
    maxDepth_search(root->left,temp+1,ans);
    if(temp > ans)ans= temp;
    maxDepth_search(root->right,temp+1,ans);
}

/*
 114, flatten BT to linked list
 */
void flatten(TreeNode* root) {
    //preorder traverse, then visit vector to change linkedlist O(n)
    if(!root)return;
    vector<TreeNode*> ans;
    flatten_helper(root,ans);
    int n = int(ans.size());
    for(int i =0; i < n-1;i++){
        ans[i]->left = NULL;
        ans[i]->right=ans[i+1];
    }
    
    ans[n-1]->left = NULL;
    ans[n-1]->right = NULL;
}
void flatten_helper(TreeNode* root,vector<TreeNode*> &ans){
    if(!root)return ;
    ans.push_back(root);
    flatten_helper( root->left,ans);
    flatten_helper( root->right,ans);
}

