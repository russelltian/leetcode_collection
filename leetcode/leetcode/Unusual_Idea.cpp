//
//  Unusual_Idea.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/10.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Unusual_Idea.hpp"
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
