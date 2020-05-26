/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1

Hint:
An important thing to note is that we don't really care which room gets freed up while allocating a room for the current meeting. As long as a room is free, our job is done. 

We already know the rooms we have allocated till now and we also know when are they due to get free because of the end times of the meetings going on in those rooms. We can simply check the room which is due to get vacated the earliest amongst all the allocated rooms.

Following up on the previous hint, we can make use of a min-heap to store the end times of the meetings in various rooms. 

So, every time we want to check if any room is free or not, simply check the topmost element of the min heap as that would be the room that would get free the earliest out of all the other rooms currently occupied. 

If the room we extracted from the top of the min heap isn't free, then no other room is. So, we can save time here and simply allocate a new room.
*/

struct compare {
        bool operator() (const int &a , const int &b)
        {
            return a > b;
        }
};

int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end());
        std::priority_queue<int,vector<int>,compare> pq;
        for(auto i : intervals){
            if(pq.empty()){
                pq.push(i[1]);
            }else{
                int earliest_end = pq.top();
                if(earliest_end > i[0]){
                    pq.push(i[1]);
                }else{
                    pq.pop();
                    pq.push(i[1]);
                }
            }
        }
        
        return pq.size();
}
