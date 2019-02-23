//
//  Search_Sort.cpp
//  leetcode
//
//  Created by HongYi Tian on 2018/6/19.
//  Copyright © 2018年 HongYi Tian. All rights reserved.
//

#include "Search_Sort.hpp"

/*
 Binary Search
 */
//special questions
/*
287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
int findDuplicate(vector<int>& nums){
    /*
     referenced idea to http://www.cnblogs.com/grandyang/p/4843654.html
     find mid index m, traverse the array, if the number of elements which <= m is more than m itself,
     means there are duplicates within[1,m], otherwise if less than [m+1,n],
     keep doing it O(nlogn)
     */
    int size = int(nums.size());
    int start = 1;
    int mid = size/2+1;
    int end = size-1;
    int count = 0; // count how many nums are larger than the mid point
    while(start<end ){

        for(int i =0 ; i < size; i++){
            if(nums[i]<= mid){
                count++;
            }
        }
        cout << mid <<' '<<start <<' '<< end <<' '<< count <<endl;
        if(count <= mid){
            //search larger mid
            start = mid+1;
            mid = (end+start)/2;
        }
        else if(count > mid){
            end = mid;
            mid = (end+start)/2;
        }
        count = 0;
    }
    return start;
}

/*
 33. Search in Rotated Sorted Array
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

 (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

 You are given a target value to search. If found in the array return its index, otherwise return -1.

 You may assume no duplicate exists in the array.

 Your algorithm's runtime complexity must be in the order of O(log n).

 Example 1:

 Input: nums = [4,5,6,7,0,1,2], target = 0
 Output: 4
 Example 2:

 Input: nums = [4,5,6,7,0,1,2], target = 3
 Output: -1
 */
int search(vector<int>& nums, int target) {
    int r = int(nums.size())-1;
    int l = 0;
    while(l <= r){
        int m = (r+l)/2;
        if(nums[m] == target)return m;
        if(nums[l]<nums[m]){
            if (nums[l]==target)return l;
            if(nums[l] <= target && target < nums[m]){

                r = m-1;
            }else{
                l = m+1;
            }
        }else{
            if(nums[r] == target)return r;
            if(nums[m]< target && target <= nums[r]){

                l = m+1;
            }else {
                r = m-1;
            }
        }
    }
    return -1;
}

/*
 34. Find First and Last Position of Element in Sorted Array
 Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 Example 1:

 Input: nums = [5,7,7,8,8,10], target = 8
 Output: [3,4]
 Example 2:

 Input: nums = [5,7,7,8,8,10], target = 6
 Output: [-1,-1]
 */
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> answer;
    //answer.push_back(findleftbound(nums,target));
    //answer.push_back(findrightbound(nums,target));
    return answer;
}
int findleftbound(vector<int>&nums,int target){
    if(nums.size() ==0)return -1;
    int l = 0;
    int r = int(nums.size())-1;

    while(l <= r){
        int m = (l+r)/2;
        if(nums[m] > target)r = m-1;
        else if(nums[m]< target)l= m+1;
        else r = m-1;
    }
    if(l < nums.size() && nums[l] == target)return l;
    return -1;
}

int findrightbound(vector<int>&nums,int target){
    if(nums.size() ==0)return -1;
    int l = 0;
    int r = int(nums.size())-1;

    while(l <= r){
        int m = (l+r)/2;
        if(nums[m] > target)r = m-1;
        else if(nums[m]< target)l= m+1;
        else l = m+1;
    }
    if(nums[r] == target && r >= 0)return r;
    return -1;
}



/*
 DFS
 */
/*
 394. Decode String
 Given an encoded string, return it's decoded string.

 The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

 You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

 Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 */
string decodeString(string s) {
    //things,1. find inner layer of string of a bracket (DFS)
    // when hit [, recursion, when hit ] return
    // use & to trck index of string , O(n)*(string manipulation)
    //100%


    string ans;int i = 0;
    ans = decodeString_helper(s,i);
    return ans;
}
string decodeString_helper(string s,int&start){
    string temp="";
    int times=1;//?*string
    // string chain="";
    for(int i= start;i<s.size();i++){
        if(s[i] == '['){
            //dfs, search another string
            i++;
            string temptemp = decodeString_helper(s,i);
            for(int j= 0;j<times;j++){
                temp += temptemp;
            }
            //   cout << temp <<endl;
            times=1;
        }else if(s[i] == ']'){
            //finish the string
            start = i;
            //  cout<<temp<<endl;
            return temp;
        }else if(s[i]>='0'&&s[i]<='9'){
            //number
            //   chain = s[i];
            if(i>0 &&s[i-1]>='0'&&s[i-1]<='9'){
                //consecutive number
                times=times*10+s[i]-'0';
            }
            else times = s[i] - '0';


            // cout<< "times:"<<times <<endl;
        }else{
            for(int j= 0;j<times;j++){
                temp += s[i];//build the string
            }
        }
    }
    return temp;
}

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
void solve(vector<vector<char>>& board) {
	if (board.size() == 0 || board[0].size() == 0)return;
	vector<vector<int>>lookup(board.size(), vector<int>(board[0].size(), -1));//status of Os
	//-1 not discovered, 0 survive, 1 visited havn't been decided
	vector<pair<int, int>> record;//keep track of O and make update and log to Os
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 'O' && lookup[i][j] == -1)
				surrounded_regions_helper(board, record, lookup, i, j);
			//if all surrounded, flip O to X
			for (int i = record.size() - 1; i >= 0; i--) {
				lookup[record[i].first][record[i].second] = -1;
				board[record[i].first][record[i].second] = 'X';
				record.pop_back();
			}
		}
	}
}

void surrounded_regions_helper(vector<vector<char>>& board, vector<pair<int, int>>& record, vector<vector<int>>& lookup, int i, int j) {

	if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) {
		//survive, update all the Os
		for (int i = record.size() - 1; i >= 0; i--) {
			lookup[record[i].first][record[i].second] = 0;
			record.pop_back();
		}
		return;
	}
	if (board[i][j] == 'X')return;//surrounded
	//if find another O, discovered: return; survived: survived as well;
	//first meet: mark it then keep searching
	if (board[i][j] == 'O') {
		if (lookup[i][j] == 1)return;
		else if (lookup[i][j] == 0) {
			//survive, update all the Os
			for (int i = record.size() - 1; i >= 0; i--) {
				lookup[record[i].first][record[i].second] = 0;
				record.pop_back();
				return;
			}
		}
		else {
			record.push_back(make_pair(i, j));
			lookup[i][j] = 1;
			surrounded_regions_helper(board, record, lookup, i - 1, j);
			surrounded_regions_helper(board, record, lookup, i, j - 1);
			surrounded_regions_helper(board, record, lookup, i + 1, j);
			surrounded_regions_helper(board, record, lookup, i, j + 1);
		}
	}
}

/*
 BFS
 */
/*
 116.Populating Next Right Pointers in Each Node
Example:

Given the following perfect binary tree,

     1
   /  \
  2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:

    1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
 */
void connect(TreeLinkNode *root) {
    if(!root)return;
    vector<TreeLinkNode*>temp;
    temp.push_back(root);
    connect_helper(temp);
}

void connect_helper(vector<TreeLinkNode*> list){
    if(list.size()==0)return;
    vector<TreeLinkNode*> newlist;
    for(auto i: list){
        if(i->left == NULL)break;
        newlist.push_back(i->left);
        newlist.push_back(i->right);
    }
    connect_helper(newlist);
    for(int i = 0;i< list.size();i++){
        if(i == int(list.size())-1)list[i]->next = NULL;
        else list[i]->next = list[i+1];
    }
}

/*
127. Word Ladder
Medium
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	queue<string>bfs{ {beginWord} };//breadth first search
	unordered_map<string, bool>used{ {beginWord,true} };
	for (auto it : wordList) {
		string i = it;
		used[i] = false;
	}
	int count = 1;
	while (!bfs.empty()) {

		// breadth first search one layer, at the same time, add another layer to the queue
		for (int k = bfs.size(); k > 0; k--) {
			string word = bfs.front();
			bfs.pop();
			//each character has 26 alternatives, 26 * ? * O(1) better
			// than sizeof_wordlist * ?
			for (int i = 0; i < word.size(); i++) {
				string temp(word);
				for (int b = 0; b < 26; b++) {
					temp[i] = 'a' + b; //abc,bbc,cbc...abx,aby,abz
					auto it = used.find(temp); //find the word from the wordlist
					if (it != used.end()) {
						if (it->second == true)continue; // has been searched in the previous layers
						if (endWord == temp)return count + 1; // find it
						bfs.push(temp); // for the next layer
						used[temp] = true;
					}
				}
			}
		}
		count++;
		// cout<<count<<endl;
	}
	return 0;
}

/*
 Divide and Conqeur
 */
/*
 240. Search a 2D Matrix II
 Consider the following matrix:
 [
 [1,   4,  7, 11, 15],
 [2,   5,  8, 12, 19],
 [3,   6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]
 ]
 Given target = 5, return true.
 Given target = 20, return false.
 */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty()||matrix[0].empty()) return false;
    int row = int(matrix.size());
    int col = int(matrix[0].size());
    int i = row-1;
    int j = 0;
    //start from bottom left
    // if > target goes up, if < target goes right
    while(true){
        if(j>= col || i <0)return false;//out of bound
        if(matrix[i][j] == target){
            return true;
        }

        if(matrix[i][j] > target){
            i--;
            continue;
        }
        if(matrix[i][j] < target){
            j++;
            continue;
        }
    }
    return false;
    }

/*
SORT
*/
/*
insert sort
*/
/*
88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int c1 = m - 1; int c2 = n - 1;
	//reverse insert sort ？
	int location = int(nums1.size()) - 1;
	while (c1 >= 0 || c2 >= 0) {
		if (c1 >= 0 && c2 >= 0) {
			nums1[location] = max(nums1[c1], nums2[c2]);
			location--;
			if (nums1[c1] <= nums2[c2])c2--;
			else c1--;
		}
		else if (c1 < 0) {
			//only c2
			nums1[location] = nums2[c2];
			location--; c2--;
		}
		else {
			//only c1
			nums1[location] = nums1[c1];
			location--; c1--;
		}
	}
}


/*
Sort list
*/
/*
179. Largest Number
Input: [3,30,34,5,9]
Output: "9534330"
*/


/*
 topological sort
 */
//207 course schdule, mid DFS, topological sort
// it is really slow ......
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    /*
     first, use hash table to store prerequisites, then check if the graph has cycle
     if there is a cycle, no topological sort
     */
    unordered_map<int,vector<int>> dep(numCourses);
    for(int i = 0; i < prerequisites.size(); i++){
        dep[prerequisites[i].first].push_back(prerequisites[i].second);
    }
    vector<int> visited(numCourses,0);
    for(int i=0; i<numCourses;i++){
        if(canFinish_check_cycle(dep,visited,i))return false;
    }
    return true;
}

//each status of the vertex, preq list, the vertex is visiting
   bool canFinish_dfs(vector<int>&visited, vector<vector<int>>& prq,int i){
       if(visited[i] == 1)return false;//visiting, forms a circle
       if(visited[i] == 2)return true;//visited, ok
       visited[i] = 1;//mark it as visiting
       for(const int j: prq[i]){
           if(!canFinish_dfs(visited,prq,j))return false;
       }
       visited[i] = 2;//mark it as visited
       return true;
}

/*
 Must
 */
/*
 4. Median of Two Sorted Arrays
 There are two sorted arrays nums1 and nums2 of size m and n respectively.

 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 You may assume nums1 and nums2 cannot be both empty.
 Example 1:
 nums1 = [1, 3]
 nums2 = [2]
  The median is 2.0
 Example 2:
 nums1 = [1, 2]
 nums2 = [3, 4]
 The median is (2 + 3)/2 = 2.5
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*
     O(log(m+n))BST two array at the same time
     referenced idea: http://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/
     always throw away a half until locate the medium
     Ck-1 = max(Am1-1,Bm2-1)
     Ck = min(Am1,Bm2)
     */

    int size1 = int(nums1.size());
    int size2 = int(nums2.size());
    const int k = (size1+size2+1)/2;
    if(size1>size2)return findMedianSortedArrays(nums2,nums1);
    int l = 0; int r = size1;

    while(l<r){
        int m1,m2;
        m1 = l+ (r-l)/2;
        m2 = k - m1;
        if(nums1[m1]<nums2[m2-1]){
            l = m1+1;
        }else{
            r = m1;
        }
        // cout << l << r <<endl;
        // cout << nums1[m1]<<" "<<nums2[m2]<<endl;
    }
    int m1 = l;int m2 = k-l;
    int C1 = max(m1<=0?INT_MIN:nums1[m1-1],m2<=0?INT_MIN:nums2[m2-1]);
    if((size1+size2)&1)return C1;
    int C2=min(m1>=size1?INT_MAX:nums1[m1],m2>=size2?INT_MAX:nums2[m2]);

    return (C2+C1)/2.0;
}
