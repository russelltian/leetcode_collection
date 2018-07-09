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
