ListNode* mergeKLists(vector<ListNode*>& lists) {
        //99.82%run time, 99.63% memory
        if(!lists.size())return NULL;
        int first = 0; int second = 1;
        while(second < lists.size()){
            lists.push_back(mergeTwoLists(lists[first], lists[second]));
            first+=2;second+=2;
        }
        return lists[lists.size()-1];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode*head = (l1->val <= l2->val)?l1:l2;
        (l1->val <= l2->val)?l1=l1->next:l2=l2->next;
        ListNode* cur = head;
        cur->next=NULL;
        while(l1&&l2){
            ListNode* temp = (l1->val <= l2->val)?l1:l2;
            (l1->val <= l2->val)?l1=l1->next:l2=l2->next;
            cur->next = temp;
            temp->next = NULL;
            cur = cur->next;
        }
        cur->next=!l1?l2:l1;
        return head;
    }
