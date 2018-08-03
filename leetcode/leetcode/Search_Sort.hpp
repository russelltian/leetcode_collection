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

/*
 DFS
 */
string decodeString(string s);
string decodeString_helper(string s,int&start);//394. Decode String, mid, fast,can be done by stack

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
bool canFinish_check_cycle(unordered_map<int,vector<int>> &dep,vector<int>&visited,int start);//207. Course Schedule, mid topological sort(DFS), badly need to be way faster!!

/*
 divide and conquer
 */
bool searchMatrix(vector<vector<int>>& matrix, int target);//240. Search a 2D Matrix II, mid search 

/*
 Must
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);//4. Median of Two Sorted Arrays,hard,divide and conquer,BST high difficult,more thinking later 

#endif /* Search_Sort_hpp */
