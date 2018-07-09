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

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
bool canFinish_check_cycle(unordered_map<int,vector<int>> &dep,vector<int>&visited,int start);//207. Course Schedule, mid topological sort(DFS), need to be way faster 


#endif /* Search_Sort_hpp */
