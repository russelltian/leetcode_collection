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
