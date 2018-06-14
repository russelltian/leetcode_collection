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
