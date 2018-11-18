//
//  Backtracking.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/5/31.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Backtracking.hpp"
#include <cmath>
#include <iostream>

/*
 #79, word search, the idea is start from any character on the board,
 check if the move is legit (within the bound, and not being used)
 recursively call itself, if the character is the last one, then good
 (After visiting a charcter, I change it to ' ', and before return, change it back to original character)
 */
bool exist(vector<vector<char>>& board, string word) {
    bool ans = false;
    int row_size = int(board.size());
    int col_size = int(board[0].size());
    for(int row = 0; row < row_size;row++){
        for(int col = 0; col < col_size; col++){
            word_search_helperfunction(board,word,0,0,0,row,col,ans,row_size,col_size);
            if(ans)return ans;
        }

    }

    return ans;
}
void word_search_helperfunction(vector<vector<char>>& board,string word,int start,int di,int dj,int row,int col,bool&ans,int row_size,int col_size){
    char temp = board[row][col];
    if(board[row][col]==word[start]){//find it
        board[row][col]=' ';
        //cout << row << ' '<<col<<endl;
        if(start == word.size()-1){//last character
            ans = true;
            return;
        }else{
            for(int i = -1;i <= 1; i++){
                for(int j = -1;j<=1;j++){
                    if(ans) return;
                    if((i == 0 && j == 0)|| (i==-1 && j==-1)
                       ||(i==1&&j==1)||(i==1&&j==-1)||(i==-1&&j==1))continue; //original
                    if(i == di && j == dj)continue;//come from that direction
                    if(j+col < 0 || j + col >= col_size)continue;//left right boundary
                    if(row == 0){//top row
                        if(i < 0) continue; //top row
                    }
                    if(row == row_size -1){ //bottom row
                        if(i>0)continue; //bottom row
                    }
                    word_search_helperfunction(board,word,start+1,-i,-j,row+i,col+j,ans,row_size,col_size);
                }
            }
        }
    }
    board[row][col]=temp;
}

/*
 17. Letter Combinations of a Phone Number
 Input: "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 reference keyboard from last generation of cell phones
 */
vector<string> letterCombinations(string digits) {
    vector<string> allcombination ;
    if (digits.size() == 0) return allcombination;

    string singlecomb(digits.size(),'\0');//initial a combination string
    const string table[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    nextLetComb(table,digits,0,singlecomb,allcombination);

    //0,1,2,3,4,5,6,7,8,9
    return allcombination;
}

void nextLetComb(const string table[],string digits,int digits_index,string &singlecomb, vector<string>& allcombination){
    // table[] is {0,1,2,3..}
    if( digits.size() == digits_index){ // break
        allcombination.push_back(singlecomb);
        return;
    }
    string letters = table[digits[digits_index] - '0'];
    for(int i = 0; i < letters.size(); i++){
        singlecomb[digits_index] = letters[i];
        nextLetComb(table,digits,digits_index+1,singlecomb,allcombination);
    }
}


/*
Must Know
 */

/*
22. Generate Parentheses
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 */
vector<string> generateParenthesis(int n) {
    //self solution: 100%
    //list all combinations
    vector<string> sol;
    string single(n*2,'\0');
    generateParenthesis_helper(2*n,0,0,0,single,sol);
    return sol;
}
void generateParenthesis_helper(int n,int i,int l,int r,string&single,vector<string>&sol){
    //n total elements, i: current generated elements, l: # of ( r: # of ), single: single string

    if(i == n){
        sol.push_back(single);
        return;
    }
    if(r>=l){
        //cannot generate ')'
        single[i]='(';
        generateParenthesis_helper(n,i+1,l+1,r,single,sol);
    }else{
        if(l<n/2){
            single[i]='(';
            generateParenthesis_helper(n,i+1,l+1,r,single,sol);
        }
        single[i]=')';
        generateParenthesis_helper(n,i+1,l,r+1,single,sol);
    }
}

/*
 46. Permutations
 Given a collection of distinct integers, return all possible permutations.

 Example:

 Input: [1,2,3]
 Output:
 [
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
 ]
 */
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;
    if(nums.empty()) return answer;
    vector<int> single;
    vector<bool> used(nums.size(), false);
    find_permutations(nums,used,answer,single);
    return answer;
}
void find_permutations(vector<int>& nums,vector<bool>& used,vector<vector<int>>& answer,vector<int>& single){
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
