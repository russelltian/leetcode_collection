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
//array
void rotate(vector<vector<int>>& matrix);//48,rotate image, mid-array algo, a little bit tricky
//hash
vector<vector<string>> groupAnagrams(vector<string>& strs);//49,group anagrams,mid-hashtable

/*int countPrimes(unsigned long n);
unsigned long fermat_test(unsigned long a,unsigned long b);
unsigned long no_overflow(unsigned long num,unsigned long base);
 */
#endif /* Algorithm_hpp */
