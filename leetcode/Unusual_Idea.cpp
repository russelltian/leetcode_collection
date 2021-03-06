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
191. Number of 1 Bits
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
*/
int hammingWeight(uint32_t n) {
  /*
  divide by two
  */
    int ans = 0;
    while(n > 0){
        ans += (n%2)?1:0;
        n *= 0.5;
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
202. Happy Number,
Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
bool isHappy(int n) {
        //can't form a circle
        // if a number occurs twice, return false;
        //70% run time, 8.4mb memory
        unordered_map<int,int>circle;
        bool ans = true;
        while(ans){
            int temp = 0;
            while(n > 0){
                temp += pow(n%10,2);
                n /=10;
            }
            if(temp == 1)return true;
            unordered_map<int,int>::iterator it;
            it = circle.find(temp);
            if(it != circle.end()){
                ans = false;
            }else{
                circle[temp]=1;
                n = temp;
                //cout << n <<endl;
            }


/*
238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).
 */
vector<int> productExceptSelf(vector<int>& nums) {
       /*
       original vec: 1  2  3  4
       after:        1  1  2  6
       before:       24 12 4  1
       after[i]*before[i] = ans 24 12 8 6

       */
       int size = nums.size();
       vector<int> after(size,1);//left to right
       vector<int> before(size,1);//right to left
       for(int i = 1; i < size;i++){
           after[i] = after[i-1]*nums[i-1];
       }
       for(int i = size-2;i >= 0; i--){
           before[i] = before[i+1]*nums[i+1];
           nums[i+1]=before[i+1]*after[i+1];
       }
       nums[0]=before[0]*after[0];
       return nums;
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
 48. Rotate Image
 You are given an n x n 2D matrix representing an image.

 Rotate the image by 90 degrees (clockwise).

 Note:

 You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 Example 1:

 Given input matrix =
 [
 [1,2,3],
 [4,5,6],
 [7,8,9]
 ],

 rotate the input matrix in-place such that it becomes:
 [
 [7,4,1],
 [8,5,2],
 [9,6,3]
 ]
 Example 2:

 Given input matrix =
 [
 [ 5, 1, 9,11],
 [ 2, 4, 8,10],
 [13, 3, 6, 7],
 [15,14,12,16]
 ],

 rotate the input matrix in-place such that it becomes:
 [
 [15,13, 2, 5],
 [14, 3, 4, 1],
 [12, 6, 8, 9],
 [16, 7,10,11]
 ]
 */
void rotate(vector<vector<int>>& matrix) {
    //from outer layer to inner layer, four elements rotate
    int n = int(matrix.size()); //n*n matrix
    int start = 0;
    int end = n-1;
    while(start < end){
        for(int i = start; i < end;i++){
            int offset = i - start;
            int temp = matrix[start][i];
            matrix[start][i] = matrix[end-offset][start];
            matrix[end-offset][start] = matrix[end][end-offset];
            matrix[end][end-offset]=matrix[start+offset][end];
            matrix[start+offset][end]= temp;
        }
        start++;
        end--;
    }
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
