//
//  DP.hpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/6.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#ifndef DP_hpp
#define DP_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <functional>
#include <numeric>
#include <queue>
using namespace std;

int numTrees(int n); //96, unique binary search, dp, tree, hard, very interesting
int maxProfit(vector<int>& prices); //121, Best Time to Buy and Sell Stock, easy,fun
bool wordBreak(string s, vector<string>& wordDict); // 139, word break, mid, need to be faster
int maxProduct(vector<int>& nums);//152, max product subarray, mid
int maximalSquare(vector<vector<char>>& matrix); //221. Maximal Square, mid
int lengthOfLIS(vector<int>& nums); //300. Longest Increasing Subsequence,mid, O(n^2)need to be O(nlogn)
int maxProfit_cd(vector<int>& prices);//309. Best Time to Buy and Sell Stock with Cooldown, mid hard to me, need more thinking
int countSubstrings(string s);//647. Palindromic Substrings
/*
 hard to me
 */
bool canPartition(vector<int>& nums);//416. Partition Equal Subset Sum, mid, hard to me, need to be faster (better method)
int findTargetSumWays(vector<int>& nums, int S);
int findTargetSumWays_helper(vector<int>& nums, int S);//494. Target Sum,mid ,hard to me, think later
/*
 classic
 */
int coinChange(vector<int>& coins, int amount);//322. Coin Change, mid, fast, classic question
int robII(vector<int>& nums);//213. House Robber II, upgrade to 198, mid, must know, fast, need more thinking 
string longestPalindrome(string s);//5. Longest Palindromic Substring,mid,classic,need to be faster,interview question 
/*
 Greedy Algorithm
 */
int numSquares(int n);
void numSquares_helper(int n, vector<int>&num,int&count,int temp,int start,bool&find); //279. Perfect Squares, mid, I didn't use dp, run time is OK (83%), more thinking later
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people); //406. Queue Reconstruction by Height, hard to me, more think later, excellent solution
int leastInterval(vector<char>& tasks, int n);//621. Task Scheduler, mid, cool idea, but slow

//easy
int rob(vector<int>& nums); //198, interesting question lol
int maxSubArray(vector<int>& nums);//53. Maximum Subarray

//compare a vector of pair<int,int>
struct cmp_second_pair{
    bool operator()(const pair<int,int> &left, const pair<int,int> &right){
        return left.first>right.first || (left.first == right.first && left.second<right.second);
    }
};

#endif /* DP_hpp */
