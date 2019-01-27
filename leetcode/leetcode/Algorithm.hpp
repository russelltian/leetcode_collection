//
//  Algorithm.hpp
//  practicesession
//
//  Created by HongYi Tian on 2018/4/26.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
//search
int rotate_array(vector<int>&nums,int target);//33,mid-bst, 3

int search_insert_pos(vector<int>&nums,int target);//35,easy-bst,3
//backtracking
vector<vector<int>> combinationSum(vector<int>& candidates, int target);//39,combination sum, mid-backtracking
void findcomb(vector<int>&candidates,int target,vector<int>&single, vector<vector<int>> &answer,int start);
//3

vector<vector<int>> subsets(vector<int>& nums); //78, subsets, mid-backtracking
void find_subsets(vector<vector<int>>& solution,vector<int>& nums,vector<int>& single,int start);
//3

//array
int majorityElement(vector<int>& nums);//169,majority element, easy, divide conquer, need to be faster
//3

//hash
vector<vector<string>> groupAnagrams(vector<string>& strs);//49,group anagrams,mid-hashtable,3
void setZeroes(vector<vector<int>>& matrix);//73. Set Matrix Zeroes, mid, not a fan of it, interview,2

//sort
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
struct compare{
    bool operator()(const Interval &a, const Interval &b)const {
        return a.start < b.start;
    }
};
vector<Interval> merge(vector<Interval>& intervals); //56,merge intervals,mid-sort,hard to me,interview question
//important one, need to know cmp, 3

void sortColors(vector<int>& nums);//75, sort color, mid-sort, 3

//dp
int minPathSum(vector<vector<int>>& grid);//64,minimum path sum, mid-dp,3
int climbStairs(int n); //70, climbing stairs, easy-dp,3

//Linked list
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
bool hasCycle(ListNode *head);//141 Linked List Cycle, easy,2





//math
vector<int> plusOne(vector<int>& digits);//66. Plus One,easy,google interview,2
int titleToNumber(string s);//171. Excel Sheet Column Number

/*int countPrimes(unsigned long n);
unsigned long fermat_test(unsigned long a,unsigned long b);
unsigned long no_overflow(unsigned long num,unsigned long base);
 */
#endif /* Algorithm_hpp */
