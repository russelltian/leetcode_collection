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
309. Best Time to Buy and Sell Stock with Cooldown
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 Example:
 
 Input: [1,2,3,0,2]
 Output: 3
 Explanation: transactions = [buy, sell, cooldown, buy, sell]
 */
int maxProfit_cd(vector<int>& prices) {
    /*
     upgrade version to #121
     */
    if(prices.empty()||prices.size()==1)return 0;
    
    vector<int> profit(prices.size(),0);//max profit if sell it today
    vector<int> buy(prices.size(),0);//max profit if buy it today
    buy[0]=-prices[0];buy[1]=max(buy[0],-prices[1]); //
    profit[0]=0;profit[1]=max(0,buy[0]+prices[1]);
    
    
    for(int i = 2; i< prices.size();i++){
        buy[i] = max(profit[i-2]-prices[i],buy[i-1]);//buy or hold
        profit[i] = max(profit[i-1],buy[i-1]+prices[i]);//hold or sell
        //  cout<<i<<": "<<buy[i]<<' '<<profit[i]<<endl;
    }
    return profit[prices.size()-1];
}



/*
 Classic
 */
/*
 322. Coin Change
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Example 1:
 
 Input: coins = [1, 2, 5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 Example 2:
 
 Input: coins = [2], amount = 3
 Output: -1
 */
int coinChange(vector<int>& coins, int amount) {
    /*
     93.58%
     */
    vector<int> best_case(amount+1,-1);//for each amount, store the number of coins needed
    best_case[0]= 0;
    int size = int(coins.size());
    for(int i = 1; i < best_case.size();i++){
        for(int j = 0; j < size;j++){
            if (coins[j]==i){
                //cout <<" "<<i<<endl;
                best_case[i] = 1;//exact amount
            }else if(coins[j]<i){
                if(best_case[i-coins[j]]!= -1){//there is valid combination
                    int temp = best_case[i-coins[j]]+best_case[coins[j]];
                    //  cout <<"temp:"<<temp<<endl;
                    //update #of coins needed for i
                    if(best_case[i]>temp||best_case[i]==-1){
                        best_case[i] = temp;
                    }
                }
            }
        }
        // cout<<i<<':'<<best_case[i]<<endl;
    }
    return best_case[amount];
}

/*
 213. House Robber II
 (first house and last house forms a cycle)
 Example 1:
 Input: [2,3,2]
 Output: 3
 Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
 because they are adjacent houses.
 
 Example 2:
 Input: [1,2,3,1]
 Output: 4
 Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 Total amount you can rob = 1 + 3 = 4.
 */
int robII(vector<int>& nums) {
    /*
     the only method works is trying two times from [0,n-1],[2,n],return the larger one,
     but is there any method that requires only one traversal since no one gonna rob two times
     in a row...
     */
    if(nums.empty())return 0;
    int size = int(nums.size());
    if(size==1)return nums[0];
    //first try,1- n
    vector<int> second = nums;
    nums[2]= max(nums[1],nums[2]);
    for(int i = 3; i< size;i++){
        nums[i] = max(nums[i-2]+nums[i],nums[i-1]);
    }
    //second try,0- n-1
    second[1] = max(second[0],second[1]);
    for(int i = 2; i< size-1;i++){
        second[i] = max(second[i-2]+second[i],second[i-1]);
    }
    return max(nums[size-1],second[size-2]);
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

