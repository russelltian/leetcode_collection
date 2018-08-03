//
//  list_hash_stack.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/18.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "list_hash_stack.hpp"

/*
 array
 */
/*
 283. Move Zeroes
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 Example:
 Input: [0,1,0,3,12]
 Output: [1,3,12,0,0]
 */
void moveZeroes(vector<int>& nums) {
    //keep track of the last original index until first and last hit
    int last = int(nums.size())-1;
    for(int i = 0;i < nums.size();i++){
        if(nums[i]== 0){
            nums.erase(nums.begin()+i);
            nums.push_back(0);
            i--;
            last--;
        }
        if(last == i)break;
    }
}

/*
 581. Shortest Unsorted Continuous Subarray
 Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
 
 You need to find the shortest such subarray and output its length.
 
 Example 1:
 Input: [2, 6, 4, 8, 10, 9, 15]
 Output: 5
 Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 */
int findUnsortedSubarray(vector<int>& nums) {
    int l=10001,r=-1;
    int size = int(nums.size());
    int maxl=nums[0],minr=nums[size-1];
    /*
     O(n),97.77%
     one situation to consider:  [left][right] inversion
     two number to track left right inversion
     */
    for(int i = 0; i < size; i++){
        // if(nums[i]>nums[i+1]){
        //     l = min(l,i);
        //     r = max(r,i+1);
        // }
        maxl = max(nums[i],maxl);
        minr = min(nums[size-1-i],minr);
        if(maxl > nums[i]) r = i;//inversion
        if(minr < nums[size-1-i]) l = size-1-i;
        
    }
    if(l==10001&&r==-1)return 0;
    return r-l+1;
}

/*
 11. Container With Most Water
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container and n is at least 2.
 
 Example:
 
 Input: [1,8,6,2,5,4,8,3,7]
 Output: 49
 */
int maxArea(vector<int>& height) {
    //self solution, 97.54%
    int left = 0;int right = int(height.size())-1;
    int ans = 0;
    while(left < right){
        int temp = (right - left)*min(height[left],height[right]);//volume
        //cout << temp <<" "<<left<<right<<endl;
        if(temp > ans)ans = temp;
        if(height[left]<height[right])left++;
        else if(height[left]>height[right])right--;
        else right--;
    }
    return ans;
}


/*
 15. 3Sum
 Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note:
 
 The solution set must not contain duplicate triplets.
 
 Example:
 
 Given array nums = [-1, 0, 1, 2, -1, -4],
 
 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    /*
     self idea: 50%0-98.91%, start locating one number, then convert it to a two ptr 2-sum problem
     key: if nums[r]+nums[r-1] < target, no need to searching
     */
    sort(nums.begin(),nums.end());
    int size = int(nums.size());
    vector<vector<int>> ans;
    for(int i = size-1;i>1;i--){
        if((i<size-1&&nums[i]!=nums[i+1])||i==size-1)
            
            threeSum_helper(nums,i-1,-nums[i],i,ans);
    }
    return ans;
}
void threeSum_helper(vector<int>& nums, int r, int tar,int one,vector<vector<int>>&ans){
    // cout<<nums[one]<<" "<<r<<endl;
    int l = 0;
    while(l<r){
        if(nums[r]+nums[r-1]<tar)break;//no possbile
        // cout<<nums[l]+nums[r]<<endl;
        if(nums[l]+nums[r]>tar){
            r--;
            //while(nums[r]==nums[r+1])r--;
        }
        else if(nums[l]+nums[r]<tar){
            l++;
            //while(nums[l]==nums[r-1])l++;
        }
        else {
            ans.push_back({nums[one],nums[l],nums[r]});
            l++;r--;
            while(nums[l]==nums[l-1])l++;
            while(nums[r]==nums[r+1])r--;
        }
    }
    
}

//stack
/*
 94, in order traversal using iterative method
 */
vector<int> inorderTraversal(TreeNode* root) {
    // if the root has left , all the way to the left, and pushing back to stack
    // then pop up the most left from the stack,
    // push it back to answer
    // then goes to right , and repeat until the stack becomes empty
    stack<TreeNode*> memory;
    vector<int> answer;
    TreeNode* cur = root;
    while(!memory.empty() || cur != NULL){
        if(cur == NULL){
            cur = memory.top();
            answer.push_back(cur->val);
            cur = cur->right;
            memory.pop();
        }else{
            memory.push(cur);
            cur=cur->left;
        }
    }
    return answer;
}

/*
 Linked list
 */
//ptr traverse

//160. Intersection of Two linked lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL){
        return NULL;
    }
    // first make sure they do merge,
    //then substract diff(len) then move until they meet
    ListNode *itr = headA;
    ListNode *lastA = NULL;
    ListNode *lastB = NULL;
    int len_A = 0 ; int len_B = 0;
    while(itr!=NULL){
        lastA = itr;
        len_A++;itr=itr->next;
    }
    itr =headB;
    while(itr!=NULL){
        lastB = itr;
        len_B++;itr=itr->next;
    }
    if(lastA!=lastB)return NULL;//not found
    int i = 0;
    int diff = abs(len_A - len_B);
    
    while (i < diff){
        i++;
        if(len_A > len_B){
            headA=headA->next;
        }else{
            headB=headB->next;
        }
    }
    while(headA!=NULL){
        if(headA==headB)return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return NULL;
}
//206,reverse linked list, used recursive method to reorder the linked list
ListNode* reverseList(ListNode* head) {
    if (!head)return NULL;
    if(head->next == NULL)return head;
    ListNode* glob;
    head = reverseList_helper(head,&glob);
    // while(glob->next){
    //     cout<<glob->val<<endl;
    //     glob=glob->next;
    // }
    return glob;
}
ListNode* reverseList_helper(ListNode* head,ListNode** glob){
    if(head->next ==NULL){
        *glob = head;
        return head;
    }
    ListNode* mynext = reverseList_helper( head->next,glob);
    mynext->next = head;
    head->next = NULL;
    //cout<<mynext->val <<"->"<<mynext->next->val<<endl;
    return head;
}
/*
 234. Palindrome Linked List
 Input: 1->2
 Output: false
 
 Input: 1->2->2->1
 Output: true
 
 idea: use recursion, first move tail to the last element, then cmp head and tail,
 then return head->next, 99.3%
 */
bool isPalindrome(ListNode* head) {
    if(!head)return true;
    ListNode* tail = head;
    bool global_bool = true;
    head = isPalindrome_list_helper(head,tail,global_bool);
    return global_bool;
}
ListNode* isPalindrome_list_helper(ListNode* head,ListNode* tail,bool& mybool){
    ListNode* cur = tail;
    if(tail->next)
        head = isPalindrome_list_helper(head,tail->next,mybool); // get the last one
    //finally we are at the last node
    if(head->val != cur->val) mybool = false;
    return head->next;
}

/*
 PQ
 */

/*
 215. Kth Largest Element in an Array
 [3,2,1,5,6,4] and k = 2 output : 5
 [3,2,3,1,2,4,5,5,6] and k = 4 output: 4
 use a priority queue, traverse the vector, the larger element is inserted at the top,
 then pop the first k-1 elements, the top is the largest one
 */
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,pq_compare> p;
    for(int i = 0; i < nums.size(); i++){
        p.push(nums[i]);
    }
    for(int i = int(nums.size()); i > k; i--){
        p.pop();
    }
    return p.top();
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    /*
     first use hash to count duplicate O(n)
     then use pq to sort the index, worst case O(nlogn)
     then push back answer, worst case O(n)
     94.75%
     */
    unordered_map<int,int> hash;
    for(int i = 0; i < nums.size();i++){
        if(hash.find(nums[i]) == hash.end()){
            //no record
            hash.insert(make_pair(nums[i],1));
        }else{
            //find it
            hash[nums[i]] = hash[nums[i]]+1;
            //     cout << hash[nums[i]];
        }
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
    for(auto it : hash){
        int a= it.first;
        int b= it.second;
        //  cout << a<<b<<endl;
        pq.push(make_pair(a,b));
    }
    vector<int>result;
    for(int i = 0; i<k;i++){
        result.push_back(pq.top().first);
        //cout<<pq.top().first<<pq.top().second<<endl;
        pq.pop();
    }
    
    return result;
    }


/*
 hash table &&
 hash idea with array implementation
 */

/*
 3. Longest Substring Without Repeating Characters
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
int lengthOfLongestSubstring(string s) {
    /*
     100% myself idea: use lower bound and upper bound to track the longest substring,
     use hash table to ensure the substring has no dup characters
     36%-60% run time
     */
    unordered_map<char,int> ht;
    int start = 0,end = 0;
    int ans = 0;
    for(int i =0; i < s.size();i++){
        if(ht.find(s[i])==ht.end()){
            ht.insert({s[i],i});//no repeat characterhttps://leetcode.com/points/
        }else{
            //find duplicate, update hash table, and update lower bound
            if(end - start > ans)ans = end-start;//update longest substr
            if(s[i]==s[i-1]){
                //to solve adjacent dup corner case
                ht[s[i]] = i;
                //start = ht[s[ht[s[i]]+1]];
                start= i;
            }
            else{
                //only update lower bound if the dup is within our bound
                if(ht[s[i]]>=start)
                    start = max(ht[s[ht[s[i]]+1]],start);
                ht[s[i]] = i;
            }
            
        }
        end++;
        
    }
    if(end-start>ans)ans = end-start;//update longest substr
    return ans;
}
/*
 438. Find All Anagrams in a String
 Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 
 Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 
 The order of output does not matter.
 Input:
 s: "cbaebabacd" p: "abc"
 
 Output:
 [0, 6]
 
 Explanation:
 The substring with start index = 0 is "cba", which is an anagram of "abc".
 The substring with start index = 6 is "bac", which is an anagram of "abc".
 Example 2:
 
 Input:
 s: "abab" p: "ab"
 
 Output:
 [0, 1, 2]
 
 Explanation:
 The substring with start index = 0 is "ab", which is an anagram of "ab".
 The substring with start index = 1 is "ba", which is an anagram of "ab".
 The substring with start index = 2 is "ab", which is an anagram of "ab".
 */
vector<int> findAnagrams(string s, string p) {
    /*
     99.17%, the idea is use two array and a slicing window,
     constantly update the number of each char from the second array,
     and then compare it with the second array
     */
    vector<int>ans;
    if(s.size()<p.size()) return ans;
    vector<int>track1(26,0);//compare two strings all value
    vector<int>track2(26,0);
    for(int i = 0; i < p.size();i++){
        track1[p[i]-'a']++;
    }
    for(int i = 0; i < p.size();i++ ){
        track2[s[i]-'a']++;
    }
    if(track1==track2)ans.push_back(0);
    int size = int(p.size())-1;
    for(int i = 1; i< s.size()-p.size()+1;i++){
        // cout<<s[i-1]<<" "<<s[size+i]<<endl;
        track2[s[i-1]-'a']--;
        track2[s[size+i]-'a']++;
        if(track1==track2){
            ans.push_back(i);
        }
    }
    return  ans;
    }


/*
 must know
 */
/*
560. Subarray Sum Equals K
 Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 Example 1:
 Input:nums = [1,1,1], k = 2
 Output: 2
 */
int subarraySum(vector<int>& nums, int k) {
    /*referenced idea: http://algorithm.books.mafengshe.com/answer/560.html
     O(n)solution
     still confused...
     nums=[1,2,-1,-1,1,5],k=1
     sum =[1,3,2,1,2,7]
     every time we get a new key value, we check if (sum-K)has occured,
     if so , means there is sum-k  new consequtive subarray that sum up to k
     */
    int size = int(nums.size());
    unordered_map<int,int> ht{{0,1}}; //first: sum, second: appearance times
    int sum = 0;
    int count =0;
    for(int i =0; i < size;i++){
        sum+= nums[i];
        if(ht.find(sum-k) != ht.end()){
            count+=ht[sum-k];
        }
        if(ht.find(sum)==ht.end()){
            ht.insert({sum,1});
        }else{
            ht[sum]++;
        }
        
    }
    return count;
    }
