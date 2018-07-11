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


/*
 235. Lowest Common Ancestor of a Binary Search Tree
 Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 
    _______6______
    /              \
 ___2__          ___8__
 /      \        /      \
 0      _4       7       9
        /  \
      3     5
 Example 1:
 Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 Output: 6
 Explanation: The LCA of nodes 2 and 8 is 6.
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root ==p)return p;
    if(root == q)return q;
    /*
     difference cases:
     both p,q < root, searching left
     both p,q > root, searching right
     if one < and the other > , we good
     fast 
     */
    if(p->val < root->val && q->val < root->val){
        root = lowestCommonAncestor(root->left,p,q);
    }
    if(p->val > root->val && q->val > root->val){
        root = lowestCommonAncestor(root->right,p,q);
    }
    return root;
}
/*
 236. Lowest Common Ancestor of a Binary Tree
 (hard to me)
 Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 
        _______3______
        /              \
      ___5__          ___1__
     /      \        /      \
     6      _2       0       8
            /  \
            7    4
 Example 1:
 
 Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 Output: 3
 Explanation: The LCA of of nodes 5 and 1 is 3.
 Example 2:
 
 Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 Output: 5
 Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
 according to the LCA definition.
 */
TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q) {
    /*
     not BST, only BT, so has to search p and q and return the common node they have
     */
    if(p == root)return p;
    if(q == root) return q;
    if(!root)return NULL;
    if(root == p || root == q)return root;
    TreeNode* left = lowestCommonAncestor_BST(root->left,p,q); //first move to bottom
    TreeNode* right = lowestCommonAncestor_BST(root->right,p,q);
    if(!left && !right){
        //we find nothing
        return NULL;
    }
    if(left && right)return root;//left right contain p q
    if(left) return left; // only find one
    return right;//only find one
}


/*
 MUST KNOW
 */
/*226. Invert Binary Tree
 Input:
 
     4
   /   \
  2     7
 / \   / \
 1   3 6   9
 Output:
      4
    /   \
   7      2
  / \    / \
 9   6  3   1
 
 */
TreeNode* invertTree(TreeNode* root) {
    //recursively swap left child and right child
    if(!root) return NULL;
    TreeNode* temp = root->left;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    root->left = root->right;
    root->right = temp;
    return root;
}






/*
 general helper function
 */


//helper function that inorder traverse and insert node value to a vector
void inorder_insert_to_vec(TreeNode* root, vector<int>&a){
    if(!root)return;
    inorder_insert_to_vec(root->left,a);
    a.push_back(root->val);
    inorder_insert_to_vec(root->right,a);
}
//helper function that postorder traverse and get node value from vector
void postorder_insert_to_vec(TreeNode* root, vector<int>&a){
    if(!root)return;
    postorder_insert_to_vec(root->right,a);
    root->val = a[0];
    a.erase(a.begin());
    cout<<a[0]<<endl;
    postorder_insert_to_vec(root->left,a);
}


