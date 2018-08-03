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
 DFS
 */
/*
 394. Decode String
 Given an encoded string, return it's decoded string.
 
 The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 
 You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 
 Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 */
string decodeString(string s) {
    //things,1. find inner layer of string of a bracket (DFS)
    // when hit [, recursion, when hit ] return
    // use & to trck index of string , O(n)*(string manipulation)
    //100%
    
    
    string ans;int i = 0;
    ans = decodeString_helper(s,i);
    return ans;
}
string decodeString_helper(string s,int&start){
    string temp="";
    int times=1;//?*string
    // string chain="";
    for(int i= start;i<s.size();i++){
        if(s[i] == '['){
            //dfs, search another string
            i++;
            string temptemp = decodeString_helper(s,i);
            for(int j= 0;j<times;j++){
                temp += temptemp;
            }
            //   cout << temp <<endl;
            times=1;
        }else if(s[i] == ']'){
            //finish the string
            start = i;
            //  cout<<temp<<endl;
            return temp;
        }else if(s[i]>='0'&&s[i]<='9'){
            //number
            //   chain = s[i];
            if(i>0 &&s[i-1]>='0'&&s[i-1]<='9'){
                //consecutive number
                times=times*10+s[i]-'0';
            }
            else times = s[i] - '0';
            
            
            // cout<< "times:"<<times <<endl;
        }else{
            for(int j= 0;j<times;j++){
                temp += s[i];//build the string
            }
        }
    }
    return temp;
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


/*
 Must
 */
/*
 4. Median of Two Sorted Arrays
 There are two sorted arrays nums1 and nums2 of size m and n respectively.
 
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 
 You may assume nums1 and nums2 cannot be both empty.
 Example 1:
 nums1 = [1, 3]
 nums2 = [2]
  The median is 2.0
 Example 2:
 nums1 = [1, 2]
 nums2 = [3, 4]
 The median is (2 + 3)/2 = 2.5
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*
     O(log(m+n))BST two array at the same time
     referenced idea: http://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/
     always throw away a half until locate the medium
     Ck-1 = max(Am1-1,Bm2-1)
     Ck = min(Am1,Bm2)
     */
    
    int size1 = int(nums1.size());
    int size2 = int(nums2.size());
    const int k = (size1+size2+1)/2;
    if(size1>size2)return findMedianSortedArrays(nums2,nums1);
    int l = 0; int r = size1;
    
    while(l<r){
        int m1,m2;
        m1 = l+ (r-l)/2;
        m2 = k - m1;
        if(nums1[m1]<nums2[m2-1]){
            l = m1+1;
        }else{
            r = m1;
        }
        // cout << l << r <<endl;
        // cout << nums1[m1]<<" "<<nums2[m2]<<endl;
    }
    int m1 = l;int m2 = k-l;
    int C1 = max(m1<=0?INT_MIN:nums1[m1-1],m2<=0?INT_MIN:nums2[m2-1]);
    if((size1+size2)&1)return C1;
    int C2=min(m1>=size1?INT_MAX:nums1[m1],m2>=size2?INT_MAX:nums2[m2]);
    
    return (C2+C1)/2.0;
}

