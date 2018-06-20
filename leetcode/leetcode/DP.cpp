//
//  DP.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/6.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "DP.hpp"
/*
 #96, unique binary search tree, cool idea
 */
int numTrees(int n) {
    //combination = f(left)*f(right)
    // if n = 3 ans = f(0)f(2) + f(1)f(1) + f(2)f(0)
    // use a vector to record f(?), f(0) = 1
    vector<int> answer(n+1,0);
    answer[0] = 1;
    for(int i = 1; i < answer.size();i++){
        for(int j = 0; j < i;j++){
            answer[i] += answer[j]*answer[i-1-j];
        }
    }
    return answer[n];
    }
/*
 #121,Best Time to Buy and Sell Stock
 max[n] = max(max[n-1]-price[n-1]+price[n],-price[n-1]+price[n] )
 */
int maxProfit(vector<int>& prices) {
    if(prices.empty())return 0;
    int n = int(prices.size());
    vector<int> best_profit(n,0);
    best_profit[0] = -prices[0];
    int ans = 0;
    for(int i = 1; i < n; i++){
        best_profit[i]=max(best_profit[i-1]-prices[i-1]+prices[i],-prices[i-1]+prices[i]);
        if(best_profit[i] > ans){
            ans = best_profit[i];
        }
    }
    return ans;
    }

/*139
 currently, I first check if the word can be break directly,
 then check subword, need to be improved, this answer is not optimal
 */
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool>z(int(s.length()),false);
    for(int i = 0; i < s.length();i++){
        for(int k = 0; k < wordDict.size();k++){
            if(s.substr(0,i+1) == wordDict[k]){
                z[i]= true;
                break;
            }
        }
        if(z[i] == true)continue;
        for(int j = i-1; j >= 0;j--){
            if(z[j] == true){
                //cout << s.substr(0,j+1) <<" "<<s.substr(j+1,i-j)<<endl;
                for(int k = 0; k < wordDict.size();k++){
                    if(s.substr(j+1,i-j) == wordDict[k]){
                        z[i] = true;
                        break;
                    }
                }
                if(z[i]==true)break;
            }
        }
    }
    return z[s.length()-1];
    }

/*
 152. Maximum Product Subarray
 [2,3,-2,4] gives 6
 [-2,0,-1] gives 0
 */
int maxProduct(vector<int>& nums) {
    if(nums.size() == 1)return nums[0];
    int product = nums[0];
    int t_max=nums[0];
    int t_min=nums[0];
    for(int i = 1; i < nums.size(); i++){
        //because of +/- signs, needs to record both max and min product
        //max = max(nums[i],nums[i]*nums[i-1])
        //min = min(nums[i],nums[i]*nums[i-1])
        // then, cross muptiply to find the new max,min
        int temp = t_max;
        t_max = max(nums[i]*t_min,max(nums[i],t_max*nums[i]));
        if(t_max > product){
            product = t_max;
        }
        t_min = min(min(nums[i],t_min*nums[i]),temp*nums[i]);
        // cout << t_max << ' '<<t_min<<endl;
        
    }
    return product;
    }

/*
 easy
 */
//198, house robber, cannot rob two adjacent houses
int rob(vector<int>& nums) {
    //for house n, compare [n]+[n-2] and [n-1] to decide rob or not
    if(nums.empty())return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() ==2) return max(nums[0],nums[1]);
    nums[1] = max(nums[0],nums[1]);
    for(int i = 2; i < nums.size();i++){
        nums[i] = max(nums[i-2]+nums[i],nums[i-1]);
    }
    return nums[nums.size()-1];
}
