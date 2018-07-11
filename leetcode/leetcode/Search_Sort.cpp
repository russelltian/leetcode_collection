//
//  Search_Sort.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/19.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Search_Sort.hpp"
/*
 topological sort
 */
//207 course schdule, mid DFS, topological sort
// it is really slow ......
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    /*
     first, use hash table to store prerequisites, then check if the graph has cycle
     if there is a cycle, no topological sort
     */
    unordered_map<int,vector<int>> dep(numCourses);
    for(int i = 0; i < prerequisites.size(); i++){
        dep[prerequisites[i].first].push_back(prerequisites[i].second);
    }
    vector<int> visited(numCourses,0);
    for(int i=0; i<numCourses;i++){
        if(canFinish_check_cycle(dep,visited,i))return false;
    }
    return true;
}

bool canFinish_check_cycle(unordered_map<int,vector<int>> &dep,vector<int>&visited,int start){
    if(visited[start] == 1)return true; //has been visited
    visited[start] = 1;
    for(int i = 0; i < dep[start].size();i++){
        if(canFinish_check_cycle(dep,visited,dep[start][i]))return true;//visited
    }
    //no visited
    visited[start]=0;
    return false;
    }


/*
 Divide and Conqeur
 */
/*
 240. Search a 2D Matrix II
 Consider the following matrix:
 [
 [1,   4,  7, 11, 15],
 [2,   5,  8, 12, 19],
 [3,   6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]
 ]
 Given target = 5, return true.
 Given target = 20, return false.
 */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty()||matrix[0].empty()) return false;
    int row = int(matrix.size());
    int col = int(matrix[0].size());
    int i = row-1;
    int j = 0;
    //start from bottom left
    // if > target goes up, if < target goes right
    while(true){
        if(j>= col || i <0)return false;//out of bound
        if(matrix[i][j] == target){
            return true;
        }
        
        if(matrix[i][j] > target){
            i--;
            continue;
        }
        if(matrix[i][j] < target){
            j++;
            continue;
        }
    }
    return false;
    }
