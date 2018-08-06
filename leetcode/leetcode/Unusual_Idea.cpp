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
 461. Hamming Distance
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 Given two integers x and y, calculate the Hamming distance.
 
 Note:
 0 ≤ x, y < 231.
 
 Example:
 Input: x = 1, y = 4
 Output: 2
 Explanation:
 1   (0 0 0 1)
 4   (0 1 0 0)
        ↑   ↑
 The above arrows point to positions where the corresponding bits are different.
 */
int hammingDistance(int x, int y) {
    // by using xor, 0 xor 0 and 1 xor 1 are all 0, only different bit will become 1,
    //and we just count the number of 1's
    int z = x^y;
    //then and n-1 to eliminate 1's
    int count = 0;
    while(z){
        count++;
        z &= z-1;
    }
    return count;
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

/*
 448. Find All Numbers Disappeared in an Array
 Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements of [1, n] inclusive that do not appear in this array.
 
 Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 
 Example:
 
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [5,6]
 */
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int size = int(nums.size());
    vector<int> ans;
    /*
     80%
     idea:since the value of array is fixed (1 -> size)
     we could iteratively updating the index, if number appeared ,let the index becomes 0,then move to the next index
     those none zero index are never appeared
     */
    for(int i =0; i < size;i++){
        if(nums[i]==0)continue;//this number has been erased
        int temp = nums[i]-1;
        while(nums[temp]!=0){
            int j = temp;
            temp = nums[temp]-1;//number on that index
            nums[j]=0;//we have erased this index, means it appeared
        }
    }
    for(int i =0; i < size;i++){
        if(nums[i]!=0)//not appeared
            ans.push_back(i+1);
    }
    return ans;
}


/*
 hard
 */

/*
41. First Missing Positive
 Given an unsorted integer array, find the smallest missing positive integer.
 
 Example 1:
 
 Input: [1,2,0]
 Output: 3
 Example 2:
 
 Input: [3,4,-1,1]
 Output: 2
 Example 3:
 
 Input: [7,8,9,11,12]
 Output: 1
 Note:
 
 Your algorithm should run in O(n) time and uses constant extra space.
*/
int firstMissingPositive(vector<int>& nums) {
    /*
     reference idea:https://www.cnblogs.com/AnnieKim/archive/2013/04/21/3034631.html
     put i to i-1 slot, and check which one violate the rule
     traversel two times,so O(n)
     */
    
    if(nums.size()==0)return 1;
    for(int i = 0;i < nums.size();i++){
        if(nums[i]<=0||nums[i] >nums.size())continue;
        if(nums[i]==i+1||nums[i]==nums[nums[i]-1])continue;
        //cout<<i<<endl;
        while(nums[i]>0&&nums[i]<=nums.size()&&nums[i]!=i+1&&nums[i]!=nums[nums[i]-1])
        {
            //while loop is for avoiding swap two correct positive number and cause a new mistake
            //cout<<"swap"<<nums[i]<<" "<<nums[nums[i]-1]<<endl;
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    
    for(int i = 0;i < nums.size();i++){
        // cout<<nums[i];
        if(nums[i]!=i+1)return i+1;
    }
    
    return int(nums.size())+1;
}
