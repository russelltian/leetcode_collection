//
//  Unusual_Idea.hpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/10.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#ifndef Unusual_Idea_hpp
#define Unusual_Idea_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include "Algorithm.hpp"
using namespace std;
/*
 bit manipulation
 */
int singleNumber(vector<int>& nums);//136,single number, easy, bitwise manipulation
vector<int> countBits(int num);//338. Counting Bits, mid, hard to me, interesting idea
int hammingDistance(int x, int y);//461. Hamming Distance, easy, interesting



ListNode *detectCycle(ListNode *head); //142,linked list cycle II, mid, interesting math

vector<int> productExceptSelf(vector<int>& nums);//238. Product of Array Except Self, mid, fast solution, no division(avoid divide by zero)

vector<int> findDisappearedNumbers(vector<int>& nums);//448. Find All Numbers Disappeared in an Array, easy, own idea, array, O(n) runtime, no extra space


// Design
class TrieNode{
    /*
     each trieNode has a size 26 prefix list,
     and a bool to find out if this word is a inserted word, or a prefix
     drawback: larger memory
     */
public:
    TrieNode *child[26]; // next prefix list
    bool isWord; // is this a inserted word
    TrieNode():isWord(false){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
    
};
class Trie {
public:
    /** Initialize your data structure here. */
    
    Trie() {
        root = new TrieNode();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        //if not inserted, create a new node and mark the last character as isWord
        TrieNode *temp = root; //first location
        for(int i = 0; i < word.size(); i++){
            int j = word[i] - 'a'; // the index that should be inserted
            if(!temp->child[j]) temp->child[j] = new TrieNode(); // create one
            // cout <<word[i] <<' '<< j<<endl;
            temp = temp->child[j];
        }
        temp->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        //if find the word and isWord is true, yes
        TrieNode *temp = root;
        for(int i = 0; i < word.size();i++){
            int j = word[i] - 'a';
            if(!temp->child[j]) return false;
            temp = temp->child[j];
        }
        if(temp->isWord)return true;
        else return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        //find the prefix
        TrieNode *temp = root;
        for(int i = 0; i < prefix.size();i++){
            int j = prefix[i] - 'a';
            if(!temp->child[j]) return false;
            temp = temp->child[j];
        }
        return true;
    }
    
private:
    TrieNode *root;
};
//208 implement trie (prefix tree), mid-trie
//very good question, how dictionary works


#endif /* Unusual_Idea_hpp */
