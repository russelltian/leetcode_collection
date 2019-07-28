## Description 

Given an array `nums` of *n* integers where *n* > 1,  return an array `output` such that `output[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

```
Example 1:

Input:  [1,2,3,4]
Output: [24,12,8,6]
```

## Solution

Complete Times:  3<br/>
Difficulty: 2 <br/>
Time complexity: O(N)<br/>
Space complexity: O(1)<br/>

**3rd Time**

Product(except self) = P(lhs)*P(rhs)

```
int product = 1;
```



So use output array which is excluded from memory usage count to record the ans 

first loop starting from 2nd element till the right most element, where `product` equals  to 

`product * nums[i-1]`, and write the answer to the output array ith element

````
nums = [1,2,3,4]
ans = [1,1,2,6]
````

second loop starting from 2nd right most element and goes all the way to the left, and same product idea will be applied and `ans[i]*=product`







