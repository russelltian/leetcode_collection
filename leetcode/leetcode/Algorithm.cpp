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



/*35,bst search insert postion, if find, return index,
 if not, the left index is going to be the insert position
 */
int search_insert_pos(vector<int>& nums, int target) {
    //bst, 98.2%
	int l = 0; int r = nums.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (nums[m] == target)return m;
		if (nums[m] < target) l = m + 1;
		else r = m - 1;
	}
	return l;
}

/*39, [2,3,6,7],target = 7 [2,2,3][7]
    keep recursively substracting the target, and start searching from the previous
    candidate index, do not forget to delete the last element for more possibilities
*/
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> answer;
    vector<int>single_ans;
    if(candidates.size() == 0)return answer;
	sort(candidates.begin(), candidates.end()); // sort the list to improve timing performance
    findcomb(candidates,target,single_ans,answer,0);
    return answer;
}
void findcomb(vector<int>&candidates,int target,vector<int>&single, vector<vector<int>> &answer,int start){
	if (target == 0) {
		answer.push_back(single);
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		int temp = candidates[i];
		if (target >= temp) {
			single.push_back(temp);
			findcomb(candidates, target - temp, single, answer, i);
			single.pop_back();
		}
		else {
			return;
		}
	}
}


//169. Majority Element [1,1,2] return 1
// didn't think about run time, need to be faster, very easy, O(nlogn)
// update 18/11/18, after sorting it, the middle one is the majority element
int majorityElement(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int m = int(nums.size()) / 2;
	return nums[m];
}
/*
 49,group anagrams, use sorted string as keys
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
 73. Set Matrix Zeroes
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 https://leetcode.com/problems/set-matrix-zeroes/description/
 */
void setZeroes(vector<vector<int>>& matrix) {
    /*
     not a big fan of this question, just use O(m+n)space
     */
    int m = int(matrix.size());
    int n = int(matrix[0].size());
    vector<bool> row(m,false);vector<bool> col(n,false);
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            if(matrix[i][j]==0){
                row[i]=true;col[j]=true;
            }
        }
    }
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n;j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;
            }
        }
    }
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
        }
		else if (ans.back().end < intervals[i].end) {
			ans.back().end = intervals[i].end;
		}
    }
    return ans;
}

/*
 #64,minimum path sum, not the condition of left column and top row
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
    //l for red-white boundary
    //r for white-blue boundary
    //cur for current
	int l = 0; int r = nums.size() - 1; int cur = l;
	while (cur <= r) {
		if (nums[cur] == 1) {
			cur++;
		}
		else if (nums[cur] == 0) {//put it left
			swap(nums[l], nums[cur]);
			l++; cur = l;
		}
		else {//put it right
			swap(nums[cur], nums[r]);
			r--;
		}
	}
}

/*
 78, subsets, backtracking
a helper function with a start index to go through all possible subsets,
 don't forget to pop_back the last element after recursion
 Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
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
	if (!head)return false;

	ListNode *l1 = head; ListNode *l2 = l1;
	while (l2->next != NULL) {
		l1 = l1->next; l2 = l2->next->next;
		if (l2 == NULL)return false;
		if (l1 == l2)return true;
	}return false;
}
/*
 math
 */
/*
 66. Plus One
 Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

 The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

 You may assume the integer does not contain any leading zero, except the number 0 itself.

 Example 1:

 Input: [1,2,3]
 Output: [1,2,4]
 Explanation: The array represents the integer 123.
 Example 2:

 Input: [4,3,2,1]
 Output: [4,3,2,2]
 Explanation: The array represents the integer 4321.
 */
vector<int> plusOne(vector<int>& digits) {
    //100%,only corner case is 9->0, if first bit is 0, change it to 1,and push_back(0)
    //like 9999->10000
    int size = int(digits.size());
    if(digits[size-1]<9){
        digits[size-1]++;return digits;
    }
    else{
        //carry on bit = 1
        digits[size-1]=0;
        int i = size-2;
        while(i>=0){
            digits[i]=(digits[i]<9)?digits[i]+1:0;
            if(digits[i]==0)i--;
            else break;
        }
        if(digits[0]==0){
            digits[0]=1;
            digits.push_back(0);
        }
    }
    return digits;
}

/*
template
 int size = int(nums.size());
 vector<int> ans;
 for(int i =0; i < size;i++){

 }
 for(int i =0; i < nums.size();i++){

 }
return ans;

 for(int i = 0; i < m;i++){
    for(int j = 0; j < n;j++){

    }
 }

 vector<int> ans(nums.size(),0);
 cout << <<" "<<<<endl;


 hash table:
 int size = int(nums.size());
 unordered_map<int,int> ht;
 for(int i = 0; i < size; i++){
 ht.insert(make_pair(i,nums[i]));
 }

 for(auto i : ht){

 }
 tree:
 root->left;
 root->rigth;
 return root;
*/


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
