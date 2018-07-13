//
//  Unusual_Idea.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/10.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Unusual_Idea.hpp"

/*
 bit manipulation
 */
/*
 #136, single number, [4,1,2,1,2] return 4
 idea: bit manipulation
 */
int singleNumber(vector<int>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum = sum ^ nums[i];
    }
    return sum;
}

/*
 338. Counting Bits
 Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 
 Example:
 For num = 5 you should return [0,1,1,2,1,2].
 
 - Space complexity should be O(n).
 - No builtin function
 */
vector<int> countBits(int num) {
    vector<int> ans(num+1,0);
    /*
     referenced hint from http://www.cnblogs.com/grandyang/p/5294255.html
     1. You should make use of what you have produced already.
     2. Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
     3.Or does the odd/even status of the number help you in calculating the number of 1s?
     
     within the same group, when even-> ans[i] = ans[i/2] +1 , odd-> ans[i] = ans[i/2]
     */
    for(int i = 1; i <= num;i++){
        if(i%2 !=0){
            ans[i] = ans[i/2]+1;
        }else{
            ans[i] = ans[i/2];
        }
    }
    return ans;
}





/*
 #142,find cycle start
 first, confirm existance of cycle, then 三元一次方程 lol
 cycle(c) meet distanc in cycle(b) + distance out of cycle(a)
 t = a + b + mc
 2t = a + b + nc
 we find a+b = (n-2m)c
 so we are at b , a more steps to go back to c
 */
ListNode *detectCycle(ListNode *head) {
    ListNode * ptr1 = head;
    ListNode * ptr2 = head;
    if(!head)return NULL;
    
    while(ptr2->next != NULL){
        
        ptr2 = ptr2->next->next;
        ptr1 = ptr1->next;
        if(ptr2==NULL)return NULL;
        if(ptr2==ptr1){
            break;//there is a cycle
        }
    }
    if(ptr2==NULL || ptr2->next ==NULL)return NULL;
    ptr1=head;
    while(ptr1!=ptr2){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr1;
}
/*
238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).
 */
vector<int> productExceptSelf(vector<int>& nums) {
    /*
     original vec: 1  2  3  4
     after:        0  1  2  6
     before:       24 12 4  0
     after[last], before[0]  not change
     the rest after[i]*before[i] = ans 24 12 8 6
     faster than 99.3%
     */
    vector<int> ans(nums.size(),0);
    ans[1]=nums[0];
    for(int i = 2; i < nums.size(); i++){
        ans[i] = nums[i-1]*ans[i-1];
    }
    int size = int(nums.size());
    vector<int> before(size,0);
    before[size-2] = nums[size-1];
    for(int i = size-3; i >=0; i--){
        before[i] = nums[i+1]*before[i+1];
    }
    ans[0] = before[0];
    for(int i = 1; i < nums.size()-1; i++){
        ans[i]=ans[i]*before[i];
        //cout<<ans[i];
    }
    return ans;
}
