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
 221. Maximal Square
 Input:
 
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 
 Output: 4
 */
int maximalSquare(vector<vector<char>>& matrix) {
    /*
     create another square DP, DP[i][j] is the max length of square that can reach this point,
     O(n^2)
     row 0 and col 0 be initialized first,
     then if matrix[i][j] == 1, dp[i][j] = min(left,up,up_left)
     */
    int ans = 0;
    if(matrix.empty())return 0;
    int row = int(matrix.size());
    int col = int(matrix[0].size());
    vector<vector<int>> dp(row,vector<int>(col,0));
    //initialize
    for(int i = 0; i< row; i++){
        dp[i][0] = (matrix[i][0] - '0');
        if(dp[i][0]==1) ans = 1;
    }
    for(int i = 0; i< col; i++){
        dp[0][i] = (matrix[0][i] - '0');
        if(dp[0][i]==1) ans = 1;
    }
    
    for(int i = 1; i < row;i++){
        for(int j = 1; j < col; j++){
            if(matrix[i][j]=='0')dp[i][j]=0;
            else{
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                
                if(dp[i][j]>ans) ans=dp[i][j];
            }
            // cout<<dp[i][j]<<endl;
        }
        // cout<<endl;
    }
    return ans*ans;
}

/*
 300. Longest Increasing Subsequence,mid,need to be faster
 Given an unsorted array of integers, find the length of longest increasing subsequence.
 
 Example:
 
 Input: [10,9,2,5,3,7,101,18]
 Output: 4
 Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/
int lengthOfLIS(vector<int>& nums) {
    /*
     start from back dp[i] = max(dp[>i])+1 O(n^2)
     */
    if(nums.empty())return 0;
    int longest = 1;
    int size = int(nums.size());
    vector<int>dp(size,1);//array to store longest subsequences
    dp[size-1]=1;
    for(int i = size-2;i>=0;i--){
        //for this element find all possible increasing sequence
        for(int j = i+1; j< size; j++){
            if(nums[j]> nums[i]){
                if(dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    if(dp[i]>longest)longest = dp[i];
                }
            }
        }
    }
    return longest;
}

/*
 Greedy Algorithm
 */
/*
 279. Perfect Squares
 Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 Example 1:
 
 Input: n = 12
 Output: 3
 Explanation: 12 = 4 + 4 + 4.
 Example 2:
 
 Input: n = 13
 Output: 2
 Explanation: 13 = 4 + 9.
 */
/*
 idea: I didn't really use DP, still 83% in timing performance
 i use a greedy algo with improvement
 first build perfect square array that might be needed by the number
 then I find the least number by using greedy algo
 and keep trying the rest combination, if there is no better solution,break it
 
 key: keep track of index i to avoid repeated iteration in the array
 */
int numSquares(int n) {
    int origin = pow(n,0.5);//largest potential root
    vector<int> num;
    //build perfect square number vector
    for(int i = origin; i >= 1; i--){
        num.push_back(pow(i,2));
    }
    //int size = int(num.size());
    int count = 9999;
    bool find =false;
    numSquares_helper(n,num,count,1,0,find);
    return count;
}
void numSquares_helper(int n, vector<int>&num,int&count,int temp,int start,bool&find){
    int i = start;
    while(true){
        if(i == num.size())break;
        if(temp >count)break;
        if(n-num[i] == 0){
            find = true;
            if(temp < count)count = temp;
            break;
        }
        if(n-num[i]>0){
            // n -= num[i];
            // cout<<n<<' '<<temp<< ' '<< n-num[i]<<endl;
            temp++;
            numSquares_helper(n-num[i],num,count,temp,i,find);
            temp--;
        }
        i++;// n is larger than num[i], try a smaller num[i+1]
    }
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

