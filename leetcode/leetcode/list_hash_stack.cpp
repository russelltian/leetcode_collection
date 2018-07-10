//
//  list_hash_stack.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/18.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "list_hash_stack.hpp"
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
