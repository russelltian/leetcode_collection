//
//  Backtracking.hpp
//  leetcode
//
//  Created by HongYi Tian on 2018/5/31.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#ifndef Backtracking_hpp
#define Backtracking_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

bool exist(vector<vector<char>>& board, string word);
void word_search_helperfunction(vector<vector<char>>& board,string word,int start,int di,int dj,int row,int col,bool&ans,int row_size,int col_size);//79,word search, mid, spent a lot of time

vector<string> letterCombinations(string digits);
void nextLetComb(const string table[],string digits,int digits_index,string &singlecomb, vector<string>& allcombination);//17. Letter Combinations of a Phone Number, mid , interview,staright forward

#endif /* Backtracking_hpp */
