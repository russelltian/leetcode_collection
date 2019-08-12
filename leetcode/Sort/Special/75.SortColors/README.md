## Description 

Given an array with *n* objects colored red, white or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

**Note:** You are not suppose to use the library's sort function for this problem.

````
Example 1:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

````
````
Example 2:


````
## Solution
Complete Times:  3<br/>
Difficulty:  4<br/>
Time complexity: O(N)<br/>
Space complexity: O(1)<br/>

I can't memorize the solution,

the logic is simple:

```
if(nums[i]==1)i++;
else if (nums[i]==0){
	swap(nums[i],nums[left]);
	left++;i=left;
}else{
	swap(nums[i],nums[right]);
	right--;
}
```

