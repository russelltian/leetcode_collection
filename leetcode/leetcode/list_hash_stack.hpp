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
int findUnsortedSubarray(vector<int>& nums);//581. Shortest Unsorted Continuous Subarray, easy,cool solution
int maxArea(vector<int>& height);//11. Container With Most Water, mid, interview question

vector<vector<int>> threeSum(vector<int>& nums);
void threeSum_helper(vector<int>& nums, int r, int tar,int one,vector<vector<int>>&ans);//15. 3Sum, mid, ok solution, classic
vector<int> spiralOrder(vector<vector<int>>& matrix);//54. Spiral Matrix

//stack
vector<int> inorderTraversal(TreeNode* root); //94, binary tree inorder traversal, mid, hard to me
bool isValid(string s);//20. Valid Parentheses, easy, interview
/*
 linked list
 */
//ptr traverse
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB); //160, intersections of lined lists, easy
ListNode* reverseList(ListNode* head);
ListNode* reverseList_helper(ListNode* head,ListNode** glob);//206, reverse linked list,easy,recursion
bool isPalindrome(ListNode* head);
ListNode* isPalindrome_list_helper(ListNode* head,ListNode* tail,bool& mybool);//234. Palindrome Linked List, easy, recursion, fast

ListNode* removeNthFromEnd(ListNode* head, int n);//19. Remove Nth Node From End of List, mid,interview
/*
 prioirty queue
 */

int findKthLargest(vector<int>& nums, int k); //215 Kth largest elements in an array
vector<int> topKFrequent(vector<int>& nums, int k);//347. Top K Frequent Elements, mid, self idea


/*
 hash table &&
 hash idea with array implementation
 */
int lengthOfLongestSubstring(string s) ;//3. Longest Substring Without Repeating Characters, mid, ok idea, interview question
vector<int> findAnagrams(string s, string p);//438. Find All Anagrams in a String, long time spent , easy, 99.17%
bool isValidSudoku(vector<vector<char>>& board);//36. Valid Sudoku

/*
 must know
 */
int subarraySum(vector<int>& nums, int k);//560. Subarray Sum Equals K, mid ,hard to me, hash table, must know 
int trap(vector<int>& height);//42. Trapping Rain Water, hard, interview, array


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
