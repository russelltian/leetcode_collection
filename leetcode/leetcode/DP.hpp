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
using namespace std;
int numTrees(int n); //96, unique binary search, dp, tree, hard, very interesting
int maxProfit(vector<int>& prices); //121, Best Time to Buy and Sell Stock, easy,fun
bool wordBreak(string s, vector<string>& wordDict); // 139, word break, mid, need to be faster
int maxProduct(vector<int>& nums);//152, max product subarray, mid
int maximalSquare(vector<vector<char>>& matrix); //221. Maximal Square, mid
int lengthOfLIS(vector<int>& nums); //300. Longest Increasing Subsequence,mid, O(n^2)need to be O(nlogn)
int maxProfit_cd(vector<int>& prices);//309. Best Time to Buy and Sell Stock with Cooldown, mid hard to me, need more thinking

/*
 Greedy Algorithm
 */
int numSquares(int n);
void numSquares_helper(int n, vector<int>&num,int&count,int temp,int start,bool&find); //279. Perfect Squares, mid, I didn't use dp, run time is OK (83%), more thinking later
//easy
int rob(vector<int>& nums); //198, interesting question lol


#endif /* DP_hpp */
