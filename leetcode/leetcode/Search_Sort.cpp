//
//  Search_Sort.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/19.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Search_Sort.hpp"

/*
 Binary Search
 */
//special questions
/*
287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
int findDuplicate(vector<int>& nums){
    /*
     referenced idea to http://www.cnblogs.com/grandyang/p/4843654.html
     find mid index m, traverse the array, if the number of elements which <= m is more than m itself,
     means there are duplicates within[1,m], otherwise if less than [m+1,n],
     keep doing it O(nlogn)
     */
    int size = int(nums.size());
    int start = 1;
    int mid = size/2+1;
    int end = size-1;
    int count = 0; // count how many nums are larger than the mid point
    while(start<end ){
        
        for(int i =0 ; i < size; i++){
            if(nums[i]<= mid){
                count++;
            }
        }
        cout << mid <<' '<<start <<' '<< end <<' '<< count <<endl;
        if(count <= mid){
            //search larger mid
            start = mid+1;
            mid = (end+start)/2;
        }
        else if(count > mid){
            end = mid;
            mid = (end+start)/2;
        }
        count = 0;
    }
    return start;
}

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
