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


bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
bool canFinish_check_cycle(unordered_map<int,vector<int>> &dep,vector<int>&visited,int start);//207. Course Schedule, mid topological sort(DFS), badly need to be way faster!!

/*
 divide and conquer
 */
bool searchMatrix(vector<vector<int>>& matrix, int target);//240. Search a 2D Matrix II, mid search 
#endif /* Search_Sort_hpp */
