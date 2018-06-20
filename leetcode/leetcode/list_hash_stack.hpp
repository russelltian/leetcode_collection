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
#include "Tree.hpp"
#include "Algorithm.hpp"
using namespace std;

//stack
vector<int> inorderTraversal(TreeNode* root); //94, binary tree inorder traversal, mid, hard to me

/*
 linked list
 */
//ptr traverse
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB); //160, intersections of lined lists, easy
ListNode* reverseList(ListNode* head);
ListNode* reverseList_helper(ListNode* head,ListNode** glob);//206, reverse linked list,easy,recursion
#endif /* list_hash_stack_hpp */
