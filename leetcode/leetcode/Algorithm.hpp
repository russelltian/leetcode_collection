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
int rotate_array(vector<int>&nums,int target);//33,mid-bst
int search_for_a_range(vector<int>&nums,int target);//34,mid-bst
int findleftbound(vector<int>&nums,int target);
int findrightbound(vector<int>&nums,int target);
int search_insert_pos(vector<int>&nums,int target);//35,easy-bst
//backtracking
vector<vector<int>> combinationSum(vector<int>& candidates, int target);//39,combination sum, mid-backtracking
void findcomb(vector<int>&candidates,int target,vector<int>&single, vector<vector<int>> &answer,int start);

vector<vector<int>> permute(vector<int>& nums); //46, permutations,mid-backtracking
void find_permutations(vector<int>& nums,vector<bool>& used,vector<vector<int>>& answer,vector<int>&single);

vector<vector<int>> subsets(vector<int>& nums); //78, subsets, mid-backtracking
void find_subsets(vector<vector<int>>& solution,vector<int>& nums,vector<int>& single,int start);

//array
void rotate(vector<vector<int>>& matrix);//48,rotate image, mid-array algo, a little bit tricky
int majorityElement(vector<int>& nums);//169,majority element, easy, divide conquer, need to be faster 
//hash
vector<vector<string>> groupAnagrams(vector<string>& strs);//49,group anagrams,mid-hashtable
//dp,greedy
bool canJump(vector<int>& nums); //55 jump game, mid-dp/greedy
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
vector<Interval> merge(vector<Interval>& intervals); //56,merge intervals,mid-sort,hard to me
void sortColors(vector<int>& nums);//75, sort color, mid-sort, hard to me

//dp
int minPathSum(vector<vector<int>>& grid);//64,mimimum path sum, mid-dp
int climbStairs(int n); //70, climbing stairs, easy-dp

//Linked list
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
bool hasCycle(ListNode *head);//141 Linked List Cycle, easy



/*int countPrimes(unsigned long n);
unsigned long fermat_test(unsigned long a,unsigned long b);
unsigned long no_overflow(unsigned long num,unsigned long base);
 */
#endif /* Algorithm_hpp */
