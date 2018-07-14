//
//  list_hash_stack.hpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/18.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#ifndef list_hash_stack_hpp
#define list_hash_stack_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>
#include <queue>
#include "Tree.hpp"
#include "Algorithm.hpp"
using namespace std;

/*
 array
 */
void moveZeroes(vector<int>& nums);//283. Move Zeroes, easy, 97%

//stack
vector<int> inorderTraversal(TreeNode* root); //94, binary tree inorder traversal, mid, hard to me

/*
 linked list
 */
//ptr traverse
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB); //160, intersections of lined lists, easy
ListNode* reverseList(ListNode* head);
ListNode* reverseList_helper(ListNode* head,ListNode** glob);//206, reverse linked list,easy,recursion
bool isPalindrome(ListNode* head);
ListNode* isPalindrome_list_helper(ListNode* head,ListNode* tail,bool& mybool);//234. Palindrome Linked List, easy, recursion, fast

/*
 prioirty queue
 */

int findKthLargest(vector<int>& nums, int k); //215 Kth largest elements in an array
vector<int> topKFrequent(vector<int>& nums, int k);//347. Top K Frequent Elements, mid, self idea

//comparator
struct pq_compare{//215, Kth largest elements in an array
    bool operator()(const int& lhs,const int& rhs){
        return lhs>rhs;
    }
};
struct cmp{ //347. Top K Frequent Elements
    bool operator()(pair<int,int>&lhs,pair<int,int>&rhs){
        return (lhs.second<rhs.second); //comparator for pair<int,int>
    }
};
#endif /* list_hash_stack_hpp */
