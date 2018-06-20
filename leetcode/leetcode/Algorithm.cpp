//
//  Algorithm.cpp
//  practicesession
//
//  Created by HongYi Tian on 2018/4/26.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Algorithm.hpp"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

/*
 #33 search in rotated sorted array
 [0,1,2,4,5,6,7],[4,5,6,7,0,1,2]
 */
int rotate_array(vector<int>& nums, int target) {
    int r = int(nums.size()-1);
    int l = 0;
    while(l <= r){
        int m = (r+l)/2;
        if(nums[m] == target)return m;
        if(nums[l]<nums[m]){
            if (nums[l]==target)return l;
            if(nums[l] <= target && target < nums[m]){
                
                r = m-1;
            }else{
                l = m+1;
            }
        }else{
            if(nums[r] == target)return r;
            if(nums[m]< target && target <= nums[r]){
                
                l = m+1;
            }else {
                r = m-1;
            }
        }
    }
    return -1;
}

/*
 #34, search for a range, find left most index and right most index
 */
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> answer;
    answer.push_back(findleftbound(nums,target));
    answer.push_back(findrightbound(nums,target));
    return answer;
}
int findleftbound(vector<int>&nums,int target){
    if(nums.size() ==0)return -1;
    int l = 0;
    int r = int(nums.size()-1);
    
    while(l <= r){
        int m = (l+r)/2;
        if(nums[m] > target)r = m-1;
        else if(nums[m]< target)l= m+1;
        else r = m-1;
    }
    if(l < nums.size() && nums[l] == target)return l;
    return -1;
    
    
}
int findrightbound(vector<int>&nums,int target){
    if(nums.size() ==0)return -1;
    int l = 0;
    int r = int(nums.size()-1);
    
    while(l <= r){
        int m = (l+r)/2;
        if(nums[m] > target)r = m-1;
        else if(nums[m]< target)l= m+1;
        else l = m+1;
    }
    if(nums[r] == target && r >= 0)return r;
    return -1;
}

/*35,bst search insert postion, if find, return index,
 if not, the left index is going to be the insert position
 */
int search_insert_pos(vector<int>& nums, int target) {
    //bst
    int size = int(nums.size());
    if(size==0)return 0;
    int l = 0;
    int r = size -1;
    while(l <= r){
        int m = (l+r)/2;
        if(nums[m] == target)return m;
        if (nums[m] < target){
            l = m+1;
        }else if (nums[m] > target){
            r = m -1;
        }
    }return l;
}

/*39, [2,3,6,7],target = 7 [2,2,3][7]
    keep recursively substracting the target, and start searching from the previous
    candidate index, do not forget to delete the last element for more possibilities
*/
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int>single_ans;
    if(candidates.size() == 0)return answer;
    findcomb(candidates,target,single_ans,answer,0);
    return answer;
}
void findcomb(vector<int>&candidates,int target,vector<int>&single, vector<vector<int>> &answer,int start){
    if(target == 0){
        answer.push_back(single); //one good solution
        return;
    }
    for(int i = start;i < candidates.size();i++){
        if(target >= candidates[i]){
            //keep substracting
            single.push_back(candidates[i]);
            findcomb(candidates,target - candidates[i],single,answer,i);
            single.pop_back();
        }
    }
}
/*
 permutations,similar to the question above, but need a boolean vector to record the used elements 
 */
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;
    if(nums.empty()) return answer;
    vector<int> single;
    vector<bool> used(nums.size(), false);
    find_permutations(nums,used,answer,single);
    return answer;
}
void find_permutations(vector<int>& nums,vector<bool>& used,vector<vector<int>>& answer,vector<int>&     single){
    if(single.size() == nums.size()){
        answer.push_back(single);
        return;
    }
    for(int i=0;i<nums.size();i++){
        
        if(!used[i]){
            used[i]=true;
            single.push_back(nums[i]);
            find_permutations(nums,used,answer,single);
            single.pop_back();
            used[i]=false;
        }
    }
}

/*
 #48
 rotate image CW 90 degree, 4 element rotation from outer layer to inner layer, use offset to
 represent offset on the same layer
 */
void rotate(vector<vector<int>>& matrix) {
    //from outer layer to inner layer, four elements rotate
    int n = int(matrix.size()); //n*n matrix
    int start = 0;
    int end = n-1;
    while(start < end){
        for(int i = start; i < end;i++){
            int offset = i - start;
            int temp = matrix[start][i];
            matrix[start][i] = matrix[end-offset][start];
            matrix[end-offset][start] = matrix[end][end-offset];
            matrix[end][end-offset]=matrix[start+offset][end];
            matrix[start+offset][end]= temp;
        }
        start++;
        end--;
    }
}

//169. Majority Element [1,1,2] return 1
// didn't think about run time, need to be faster, very easy
int majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int i = int(nums.size());
    int mid = i/2;
    if(nums[mid] == nums[i-1])return nums[mid];
    else if(nums[mid]==nums[0])return nums[0];
    else return nums[mid];
}
/*
 group anagrams, use sorted string as keys
 [ate,eat,tea]
 */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //key is the sorted string, anagrams have the same key
    //element is the index of anagrams from input
    //if more than 2 elements, output them
    vector<vector<string>> answer;
    if(strs.empty()) return answer;
    unordered_map<string,vector<int>> umap;
    for(int i = 0; i < strs.size(); i++){
        string key = strs[i];
        sort(key.begin(),key.end());
        umap[key].push_back(i);
    }
    unordered_map<string, vector<int>>::iterator iter;
    
    for(iter=umap.begin();iter!= umap.end();iter++){
        vector<string> single;
        for(int i = 0; i < iter->second.size(); i++){
            single.push_back(strs[iter->second[i]]);
        }
        answer.push_back(single);
    }
    return answer;
}

/*
 #55,jump game
 within previous largest distance, find if there is further distance
 */
bool canJump(vector<int>& nums) {
    //actually dynamic programming idea,the max limit is previous max + current max
    int final = int(nums.size()-1);
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
 56, merge interval, sort first, then check if answer.back().end
 < interval[i].start or not
 */
vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    sort(intervals.begin(),intervals.end(),compare());
    for(int i = 0; i < intervals.size(); i++){
        if(ans.empty()||ans.back().end < intervals[i].start){
            ans.push_back(intervals[i]);
            //   cout << i <<endl;
        }else if(ans.back().end >= intervals[i].start){
            ans.back().end = max(intervals[i].end,ans.back().end);
            //    cout << i <<endl;
        }
    }
    return ans;
}

/*
 #64,mimimum path sum, not the condition of left column and top row
 then select min(left,top)
 */
int minPathSum(vector<vector<int>>& grid) {
    int m = int(grid.size()-1);
    int n = int(grid[0].size()-1);
    //vector<vector<int>>ans(m+1,vector<int>(n+1,0));
    for(int i = 0; i <= m;i++){
        for(int j= 0; j <= n; j++){
            if(i == 0)//top row
            {
                if(j == 0)continue;
                grid[i][j] += grid[i][j-1];
                continue;
            }
            if(j == 0){// left column
                grid[i][j] += grid[i-1][j];
                continue;
            }
            grid[i][j] += min(grid[i][j-1],grid[i-1][j]);
        }
    }
    return grid[m][n];
}

/*
 #70, climbing stairs, each times 1 step or 2 steps,
 so ans[0] = 1, ans[1] = 2, ans[n] = ans[n-2]+ ans[n-1]
 */
int climbStairs(int n) {
    vector<int> n_solutions(n,0);
    n_solutions[0]=1; n_solutions[1]=2;
    for(int i = 2; i < n; i++){
        n_solutions[i]= n_solutions[i-2] + n_solutions[i-1];
    }
    return n_solutions[n-1];
}

/*
 75, sort color (0,1,2)
 if 1 good, if 0 swap with left, left++,
 if 2 swap with right, right--
 while loop terminate when cur > right
 */
void sortColors(vector<int>& nums) {
    // left for red-white boundary
    //right for white-blue boundary
    //cur for current
    int left = 0;
    int right = int(nums.size()-1);
    int cur = 0;
    while(cur <= right){
        if(nums[cur] == 0){
            int temp = nums[left];
            nums[left] = nums[cur];
            nums[cur]=temp;
            left++;
            cur++;
        }
        else if(nums[cur] == 1){
            cur++;
        }
        else if(nums[cur] == 2){
            int temp = nums[right];
            nums[right] = 2;
            nums[cur]=temp;
            right--;
        }
    }
}

/*
 78, subsets, backtracking
a helper function with a start index to go through all possible subsets,
 don't forget to pop_back the last element after recursion
 */
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> single;
    vector<vector<int>> solution;
    solution.push_back(single);
    find_subsets(solution,nums,single,0);
    return solution;
}
void find_subsets(vector<vector<int>>& solution,vector<int>& nums,vector<int>& single,int start){
    for(int i = start; i < nums.size();i++){
        single.push_back(nums[i]);
        solution.push_back(single);
        find_subsets(solution,nums,single,i+1);
        single.pop_back();
    }
}

/*Linked list */
/*141, linked list cycle
 Idea: two ptr, one goes one step, one goes two steps
 if there is a cycle, they will hit anyways
 */
bool hasCycle(ListNode *head) {
    if(!head)return false;
    ListNode *iter1 = head;
    ListNode *iter2 = head;
    while(iter2->next != NULL){
        iter2 = iter2->next->next;
        iter1 = iter1->next;
        if(iter2 == NULL)return false;
        if(iter2 == iter1){
            return true;
        }
    }
    return false;
}






/*
int countPrimes(unsigned long n) {
    vector<bool> prime(n,true);
    unsigned long limit = sqrt(n);
    //cout << limit <<endl;
    for (unsigned long i = 2; i <= limit ; i++){
        if(prime[i]){
            for (unsigned long j = i*i; j < n ; j+=i){
                prime[j] = false;
            }
        }
    }
    unsigned count =0;
    for(unsigned long i = 2;i < prime.size();i++){
        if (prime[i]) {
            //  cout << i <<endl;
            count++;
        }
    }
    return count;
}

unsigned long fermat_test(unsigned long a,unsigned long b){
    vector<int> fermet_test_base = {2,3,4,5,6,7,8,9,10,11,12,13};
    unsigned long count = 0;
    bool this_num;
    for(unsigned long i = a;i <= b;i++){
        this_num = true; // whether this number is a prime
        for(int j = 0; j < fermet_test_base.size(); j++){
            if(no_overflow(i, fermet_test_base[j]) != 1){
                this_num = false;//nope
                break; //no need for further compute
            }
        }
        if(this_num){
            count++;
        }
    }
    return count;
}

//prevent integer overflow
unsigned long no_overflow(unsigned long N,unsigned long a){
    if(N == 1 )return 0;
    unsigned long remainder = 1;
    //a^b mod N, a is base, b is exponent, N is mod
    unsigned long b = N - 1 ; //exponent
    while(b > 0){
        if(b % 2 == 1){
            remainder = (remainder*a)%N;
        }
        a = (a*a)%N;
        b = b/2;
    }
    return remainder;
}
*/
