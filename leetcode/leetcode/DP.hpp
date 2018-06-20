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
//easy
int rob(vector<int>& nums); //198, interesting question lol

#endif /* DP_hpp */
