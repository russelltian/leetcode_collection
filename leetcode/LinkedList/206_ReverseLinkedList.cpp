class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //run time 100%, memeory 8%
        // recursive and knowledge on ptr 
        if (!head)return NULL;
        if(head->next == NULL)return head;
        ListNode* newhead = NULL;
        ListNode* nomeaning = reverseList_helper(head,&newhead);
        return newhead;
    }

    ListNode* reverseList_helper(ListNode*head,ListNode**firstNode){

        if(!head->next){
            //last element
            *firstNode = head;
            return head;
        }
        //next element becomes previous element
        reverseList_helper(head->next,firstNode)->next = head;
        head->next = NULL;
        return head;
    }
};
