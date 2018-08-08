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
 647. Palindromic Substrings
 Given a string, your task is to count how many palindromic substrings in this string.
 
 The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 
 Input: "abc"
 Output: 3
 Explanation: Three palindromic strings: "a", "b", "c".
 Input: "aaa"
 Output: 6
 Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 */
int countSubstrings(string s) {
    /*
     same with #5 we just count the number 51% 8ms
     */
    int count = 0;
    int size = int(s.size());
    vector<vector<bool>> range(size+1,vector<bool>(size+1,false)); //from i to j is there a palindrome
    for(int i = size-1; i >=0;i--){
        for(int j = i; j < size;j++){
            if(s[i]!=s[j])continue;
            if(s[i]==s[j]&&(j-i<2||range[i+1][j-1])){
                range[i][j] = true;
                count++;
                continue;
            }
        }
    }
    return count;
}
/*
 hard to me
 */

/*
 416. Partition Equal Subset Sum
 Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 
 Note:
 Each of the array element will not exceed 100.
 The array size will not exceed 200.
 Example 1:
 
 Input: [1, 5, 11, 5]
 
 Output: true
 
 Explanation: The array can be partitioned as [1, 5, 5] and [11].
 Example 2:
 
 Input: [1, 2, 3, 5]
 
 Output: false
 
 Explanation: The array cannot be partitioned into equal sum subsets.
 */
bool canPartition(vector<int>& nums) {
    //need more thinking
    //but here the dp is if 1,1,2 then 1,1,2,4 is also true
    //run time only 60%
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum+= nums[i];
    }
    if(sum%2==1)return false;
    int tar = sum/2;
    vector<bool> ans(tar+1,false);
    ans[0] = true;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i]==tar||ans[tar])return true;
        for(int j = tar; j >= nums[i]; j--){
            ans[j] = ans[j]||ans[j-nums[i]];
        }
    }
    return ans[tar];
}

/*
494. Target Sum
 You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 
 Find out how many ways to assign symbols to make sum of integers equal to target S.
 
 Example 1:
 Input: nums is [1, 1, 1, 1, 1], S is 3.
 Output: 5
 Explanation:
 
 -1+1+1+1+1 = 3
 +1-1+1+1+1 = 3
 +1+1-1+1+1 = 3
 +1+1+1-1+1 = 3
 +1+1+1+1-1 = 3
 
 There are 5 ways to assign symbols to make the sum of nums be target 3.
*/
int findTargetSumWays(vector<int>& nums, int S) {
    /*
     referenced idea: https://blog.csdn.net/magicbean2/article/details/78720623
     P is set for all + , N is set for all -
     sum(P) - sum(N) = target
     sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
     2 * sum(P) = target + sum(nums)
     find: sum(P) = (target + sum(nums)) / 2
     O(target * n) n is size of nums
     */
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum<S||(sum+S)&1){
        //need to be >= S and %2==0
        return 0;
    }
    return findTargetSumWays_helper(nums, (S+sum)/2);
}
int findTargetSumWays_helper(vector<int>& nums, int S){
    vector<int> ans(S+1,0);
    ans[0]=1;
    for(int i = 0; i < nums.size();i++){
        for(int j = S; j >= nums[i];j--){
            ans[j] += ans[j-nums[i]];
        }
    }
    return ans[S];
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
 5. Longest Palindromic Substring
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 
 Example 1:
 
 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:
 
 Input: "cbbd"
 Output: "bb"
 
 */
string longestPalindrome(string s) {
    /*
     This is a very classic question,
     We could use brute force method, but this time we tried DP (although both are O(n^2))
     2D array vec[i][j] if from i to j is a palindrome
     1.if s[i]=s[j] when i = j-1
     2. i = j
     3 if s[i]=s[j] and f[i+1][j-1] is true
     */
    int size = int(s.size());
    vector<vector<bool>> range(size+1,vector<bool>(size+1,false)); //from i to j is there a palindrome, size+1 to prevent overflow
    int start=0;int end=0;//return substr
    int len= 1;//max len
    for(int i = size-1; i >=0;i--){
        for(int j = i; j < size;j++){
            if(s[i]!=s[j])continue;
            if(s[i]==s[j]&&(j-i<2||range[i+1][j-1])){
                range[i][j] = true;
                if(j-i+1>len){
                    len = j-i+1;
                    start = i; end = j;
                }
                continue;
            }
            
            
        }
    }
    
    return s.substr(start,len);
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
 406. Queue Reconstruction by Height
 Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 
 Note:
 The number of people is less than 1,100.
 
 
 Example
 
 Input:
 [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 
 Output:
 [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    /*
     referenced solution from http://www.cnblogs.com/grandyang/p/5928417.html
     tallest at the front
     */
    vector<pair<int, int>> ans;
    
    sort(people.begin(),people.end(),cmp_second_pair());
    // for(int i = 0; i < people.size(); i++){
    //     cout << people[i].first<<" "<<people[i].second << endl;
    // }
    for(auto i:people){
        ans.insert(ans.begin()+i.second,i);
    }
    return ans;
}


/*
 621. Task Scheduler
 Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 
 However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 
 You need to return the least number of intervals the CPU will take to finish all the given tasks.
 
 Example 1:
 Input: tasks = ["A","A","A","B","B","B"], n = 2
 Output: 8
 Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 */
int leastInterval(vector<char>& tasks, int n) {
    /*
     idea: push all the appearance of each tasks to a pq,
     then consider the idle, start from largest number and do
     as much as tasks before idle
     solution is  true but not fast enough
     */
    vector<int>temp(26,0);
    for(int i = 0; i< tasks.size();i++){
        temp[tasks[i]-'A']++;
    }
    // priority_queue<pair<char,int>,vector<pair<char,int>>,cmp_str_int>pq;
    priority_queue<int,vector<int>>pq;
    bool alldone = true;//finish all tasks
    for(int i = 0; i < temp.size();i++){
        if(temp[i]>0)
            pq.push(temp[i]);
        if(temp[i]>1)
            alldone = false;
    }
    //temp.erase(temp.begin(),temp.end());
    int cd = n;//cool down
    int inter=0;//total interval
    
    while(!pq.empty()){
        vector<int> temp2;//temperary store the cd
        for(;cd>=0;cd--){
            //if pq is not empty, pop up the task
            if(!pq.empty()){
                temp2.push_back(pq.top());
                pq.pop();
                inter++;
            }else{//pq.empty()
                if(alldone){
                    return inter;
                }
                inter++;
            }
        }
        cd = n;//reset cool down
        alldone=true;//assume every task is over
        for(int i = 0;i<temp2.size();i++){
            if(temp2[i]>1){
                temp2[i]--;
                pq.push((temp2[i]));
                //  cout << temp2[i] <<endl;
            }
            if(temp2[i]>1)alldone = false;//unfinished task
        }
    }
    return inter;
}

/*
 55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
jump length is 0, which makes it impossible to reach the last index.
*/
bool canJump(vector<int>& nums) {
    //actually dynamic programming idea,the max limit is previous max + current max
    //O(n)
    int final = int(nums.size())-1;
    int limit = 0;
    for(int i = 0; i < nums.size();i++){
        if (limit < i)return false;
        if(i+nums[i] > limit){
            limit = i + nums[i];
            if(limit >= final)return true;
        }
    }
    return limit >= final ? true: false;
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

/*
 53. Maximum Subarray
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 Example:
 Input: [-2,1,-3,4,-1,2,1,-5,4],
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 */
int maxSubArray(vector<int>& nums) {
    //100% lol
    vector<int> sum(nums.size(),0);
    sum[0]=nums[0];
    int ans = nums[0];
    for(int i = 1; i < nums.size();i++){
        sum[i]=max(nums[i],nums[i]+sum[i-1]);
        // cout << sum[i]<<endl;
        if(sum[i]>ans)ans=sum[i];
    }
    return ans;
    }
