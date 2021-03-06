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
 581. Shortest Unsorted Continuous Subarray
 Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

 You need to find the shortest such subarray and output its length.

 Example 1:
 Input: [2, 6, 4, 8, 10, 9, 15]
 Output: 5
 Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 Difficulties: 3 , need more practice
 */
int findUnsortedSubarray(vector<int>& nums) {
   /*
   Updated at 09-Sep-2019
   replace hardcoded l r value to a boolean that records the inversion of ascending order values
   Use maxL and minR to assert the ascending order, and record the violation index
   */
	int l = 0; int r = nums.size() - 1;
	int maxL = nums[0]; int minR = nums[r];
	bool haschanged = false;
	for (int i = 0; i < nums.size(); i++) {
		maxL = max(maxL, nums[i]);
		minR = min(minR, nums[nums.size() - 1 - i]);
		if (nums[i] < maxL) { r = i; haschanged = true; }
		if (nums[nums.size() - 1 - i] > minR)l = nums.size() - 1 - i;
	}
	return haschanged ? r - l + 1 : 0;
}

/*
 11. Container With Most Water
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

 Note: You may not slant the container and n is at least 2.

 Example:

 Input: [1,8,6,2,5,4,8,3,7]
 Output: 49

 Update: 3rd time 09Sep2019, silo with no problem
 Difficulties: 1 Should be OK
 Idea: calculate current volume, and move the shorter side towards the middle 
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
 54. Spiral Matrix
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

 Example 1:

 Input:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 Output: [1,2,3,6,9,8,7,4,5]
 Example 2:

 Input:
 [
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]
 ]
 Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //first lock boundary then traverse
    //self idea: 3rd time, difficulty 2, careful about the boundary check
    if(matrix.empty())return {};
    if(matrix[0].empty())return {};
    int l = 0; int r = int(matrix[0].size())-1;
    int up = 0; int down = int(matrix.size())-1;
    vector<int> ans;
    while(l<=r&&up<=down){
        for(int i = l; i <= r;i++){
            ans.push_back(matrix[up][i]);
            // cout << matrix[up][i]<<" ";
        }
        cout <<endl;
        for(int i = up+1; i <= down;i++){
            ans.push_back(matrix[i][r]);
            //   cout << matrix[i][r]<<" ";
        }
        cout <<endl;
        for(int i = r-1; i >= l&&up<down;i--){
            ans.push_back(matrix[down][i]);
            //  cout << matrix[down][i]<<" ";
        }
        cout <<endl;
        for(int i = down-1; i >= up+1&&l<r;i--){
            ans.push_back(matrix[i][l]);
            //    cout << matrix[i][l]<<" ";
        }
        //shrink spiral
        l++;r--;up++;down--;
        //cout<<endl<<l<<r<<up<<down;
    }
    return ans;
}

/*
289. Game of Life
*/
void gameOfLife(vector<vector<int>>& board) {
        /*wikipedia first lol, use stitch left,right top,bottom and make it toroidal array
         use two buffer array to store the next stage,
         for example:
         a = row0, then b = row1, then update a, then a for row2

        */
        // f* test case
        if(board.size()==1){
            for(auto  &z : board[0]){
                z = 0;
            }
            return;
        }

        vector<int> a(board[0].size(),0);
        vector<int> b(board[0].size(),0);
        int old = 1; //0, a being written latest ; 1, b being written
        int row_read = 0;//the number of row has been calculated
        for(int i = 0; i < board.size();i++){
            if(row_read >= 1){
                // update a row
                for(int z = 0; z < board[0].size();z++){
                    board[row_read-1][z] = (old==0)? b[z]:a[z];
                }
            }

            for(int j = 0; j < board[0].size();j++){
            if(old==0){
                b[j] = gameOfLife_calculatesum(board,i,j);
             //   cout << "stored b "<<endl;
            }
                else {
                    a[j] = gameOfLife_calculatesum(board,i,j);
                 //  cout << "stored a "<<endl;
                }
            }
            old = !old;
            row_read = i;
        }
        for(int z = 0; z < board[0].size();z++){
            board[board.size()-2][z] = (old==0)? b[z]:a[z];
            board[board.size()-1][z] = (old==0)? a[z]:b[z];
        }
    }

    int gameOfLife_calculatesum(vector<vector<int>>&board, int i, int j){
        int result = board[i][j];
        if(i > 0 )result += board[i-1][j];
        if(i < board.size()-1) result+=board[i+1][j];
        if(j > 0) result += board[i][j-1];
        if(j < board[0].size()-1) result+= board[i][j+1];
        if(i>0&&j>0)result+= board[i-1][j-1];
        if(i < board.size()-1&&j<board[0].size()-1)result+=board[i+1][j+1];
        if(i>0 && j < board[0].size()-1)result+=board[i-1][j+1];
        if(i < board.size()-1 && j > 0) result+=board[i+1][j-1];

        //calculate the next stage result
        // 3: 1 +2*1 ok, 0 +3*1 revive; 4:1+3*1 ok, 0+4*1 no
        // the rest, no
        //cout << result << " ";
        if(result == 3)
            return 1;
        if(result == 4)
            return board[i][j];
        return 0;
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
  20. Valid Parentheses
 Input: "([)]"
 Output: false
 Example 5:

 Input: "{[]}"
 Output: true
 */
 bool isValid(string s) {
   //100% runtime 8.4Mb, 100%memory
         stack<char> mystack;
         for(auto &i : s){
             if(i == '('||i=='['||i=='{')mystack.push(i);
             else{
                 if(mystack.empty())return false;
                 char top = mystack.top();
                 mystack.pop();
                 if(i!=')'&&i!=']'&&i!='}')return false;
                 if(i==')'&&top!='('||i==']'&&top!='['||i=='}'&&top!='{') return false;
             }
         }
         return mystack.empty();
}

/*
150. Evaluate Reverse Polish
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/
int evalRPN(vector<string>& tokens) {
	//idea: using stack to store numbers and intermediate result
	//return top, don't forget to pop before push
	if (tokens.size() == 0)return 0;
	stack<int> s;
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "+") {
			int a = s.top(); s.pop(); int b = s.top(); s.pop();
			s.push(a + b);
		}
		else if (tokens[i] == "-") {
			int a = s.top(); s.pop(); int b = s.top(); s.pop();
			s.push(b - a);
		}
		else if (tokens[i] == "*") {
			int a = s.top(); s.pop(); int b = s.top(); s.pop();
			s.push(a*b);
		}
		else if (tokens[i] == "/") {
			int a = s.top(); s.pop(); int b = s.top(); s.pop();
			s.push((a == 0 || b == 0) ? 0 : b / a);
		}
		else {
			// arbitary number, push it to the stack
			s.push(stoi(tokens[i]));
		}
	}
	return s.top();
}
/*
 Linked list
 */
//ptr traverse

//160. Intersection of Two linked lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  // God solution: http://www.cnblogs.com/grandyang/p/4128461.html
      if(!headA||!headB)return NULL;
      ListNode* a= headA; ListNode*b = headB;
      while(a != b){
          a = a?a->next:headB;
          b = b?b->next:headA;
      }
      return a;
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
 19. Remove Nth Node From End of List
 Given a linked list, remove the n-th node from the end of list and return its head.

 Example:

 Given linked list: 1->2->3->4->5, and n = 2.

 After removing the second node from the end, the linked list becomes 1->2->3->5.
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    ListNode* ptr1 = head;
    ListNode* ptr2 = head;
    //Idea: ptr2 moves n+1 steps ahead of ptr1
    for(int i = 0; i < n;i++){
        ptr2 = ptr2->next;
        if(ptr2 == NULL){//delete head
            head = ptr1->next;
            delete ptr1;
            return head;
        }
    }
    while(ptr2->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr1 -> next = ptr1->next->next;
    return head;
}

/*
328. Odd Even Linked List
*/
ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* cur = head;
        ListNode* even = cur->next;
        ListNode* evenhead = even;
        ListNode*prev;
        while(cur&&cur->next){
            cur -> next = even->next;
            prev = cur;
            cur = cur->next;
            if(cur){
                even->next = cur->next;
                even = even->next;
            }

        }
        if(cur)  cur->next = evenhead;
        else prev->next = evenhead;

        return head;
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
 36. Valid Sudoku
 Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

 Each row must contain the digits 1-9 without repetition.
 Each column must contain the digits 1-9 without repetition.
 Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 */
bool isValidSudoku(vector<vector<char>>& board) {
    /*
     97.8% more memory, but the idea is straight forward
     */
    vector<vector<int>>rol(9,vector<int>(9,-1));//i row j num
    vector<vector<int>>col(9,vector<int>(9,-1));//i col j num
    vector<vector<int>>blk(9,vector<int>(9,-1));//which block on board
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int location = board[i][j]-'1';//loaction in array
            if(location<0)continue;
            // cout << location<<endl;
            int zuo = j/3;int shang = i/3;//左右，上下
            int block = shang*3+zuo;
            if(rol[i][location]!=-1){
                return false;
            }
            else {
                rol[i][location] = i;
            }
            if(col[j][location]!=-1){
                return false;
            }
            else col[j][location] = j;
            if(blk[block][location]!=-1){

                return false;
            }
            else{
                blk[block][location] = block;
            }
        }
    }
    return true;
}

RandomListNode *copyRandomList(RandomListNode *head) {
	if (!head)return NULL;
	RandomListNode *cur = head;
	cur = cur->next;
	RandomListNode *newhead = new RandomListNode(head->label);
	// the key is initial node, the second one is
	unordered_map<RandomListNode*, RandomListNode*> hashtable;
	RandomListNode *newcur = newhead;
	if (head->random != NULL) {
		hashtable[head] = newcur;
	}
	while (cur) {
		RandomListNode* temp1 = new RandomListNode(cur->label);
		hashtable[cur] = temp1;
		cur = cur->next;
		newcur->next = temp1;
		newcur = newcur->next;
	}

	auto iter = hashtable.begin();
	while (iter != hashtable.end()) {
		if (iter->first->random)iter->second->random = hashtable[iter->first->random];
		iter++;
	}
	return newhead;
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

/*
 42. Trapping Rain Water
 https://leetcode.com/problems/trapping-rain-water/description/
 */
int trap(vector<int>& height) {
    //reference idea from http://www.cnblogs.com/grandyang/p/4402392.html
    //use two ptr to calculate area of water, 58.39%
    int size = int(height.size());
    int l = 0; int r = size-1;//left most and right most
    int ans = 0;
    while(l<r){
        if (height[l]<= height[r]){
            //scan from left to right
            int temp = l;
            while(height[l]>= height[temp]&&temp<=r){
                ans += height[l] - height[temp];
                temp++;
            }
            l = temp; // re allocate window
        }else if(height[l]> height[r]){
            //scan from right to left
            int temp = r;
            while(height[r]>= height[temp]&&temp>=0){
                ans += height[r] - height[temp];
                temp--;
            }
            r = temp; // re allocate window
        }
    }
    return ans;
}

/*
239. Sliding Window Maximum
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Idea: deque left always largest number's index
when insert a number from end, remove all the number's value
that are smaller than new number, and store its index in the back,
so always up to date and always in desc order
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>ans;
    deque<int> q;
    for(int i = 0; i < nums.size();i++){
        if(!q.empty()&&q.front()==i-k)q.pop_front();
        while(!q.empty()&& nums[q.back()]<=nums[i])q.pop_back();
        q.push_back(i);
        if(i > k-2)ans.push_back(nums[q.front()]);
    }
    return ans;
}
