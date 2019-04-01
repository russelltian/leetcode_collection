//
//  Search_Sort.hpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/19.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#ifndef Search_Sort_hpp
#define Search_Sort_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;
/*
 Binary Search
 */
//special questions
int findDuplicate(vector<int>& nums);//287. Find the Duplicate Number, mid,interesting,hard to me
int search(vector<int>& nums, int target);//33. Search in Rotated Sorted Array, mid, more thinking later

vector<int> searchRange(vector<int>& nums, int target);
int findleftbound(vector<int>&nums,int target);
int findrightbound(vector<int>&nums,int target);//34. Find First and Last Position of Element in Sorted Array,mid,bst,interview
void wiggleSort(vector<int>& nums) //324, Wiggle Sort II

/*
 DFS
 */
string decodeString(string s);
string decodeString_helper(string s,int&start);//394. Decode String, mid, fast,can be done by stack


void solve(vector<vector<char>>& board);
void surrounded_regions_helper(vector<vector<char>>& board, vector<pair<int, int>>& record, vector<vector<int>>& lookup, int i, int j);
//130. Surrounded Regions, mid, need better solution
																							  /*
 BFS
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root);
void connect_helper(vector<TreeLinkNode*> list);//116.Populating Next Right Pointers in Each Node, mid, search
int ladderLength(string beginWord, string endWord, vector<string>& wordList);//127. Word Ladder, hard to me, long time spent , BFS & hashing

/*
 divide and conquer
 */
bool searchMatrix(vector<vector<int>>& matrix, int target);//240. Search a 2D Matrix II, mid search


/*
SORT
*/
/*
insert sort
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);//88. Merge Sorted Array, easy
//

/*
sort list
*/
string largestNumber(vector<int>& nums)
bool static largestNumber_compare(string a, string b)
/*
topological sort
*/
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
bool canFinish_dfs(vector<int>&visited, vector<vector<int>>& prq,int i);
//207. Course Schedule, mid topological sort(DFS), now very fast
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
bool findOrder_dfs(int num,vector<vector<int>>&preq,vector<int>&visited,vector<int>&courses);
//210. Course Schedule II


    														 /*
 Must
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);//4. Median of Two Sorted Arrays,hard,divide and conquer,BST high difficult,more thinking later


//179. Largest Number, mid, hard to me



#endif /* Search_Sort_hpp */
