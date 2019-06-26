/*
3 times, no hint
83.23% run time, 9.9mb memory
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (!l1 && !l2)return NULL;
	if (!l1)return l2; if (!l2)return l1;
	ListNode* l3 = l1; ListNode* l4 = NULL;
	int carry = 0;
	ListNode* head = l1;
	while (l1&&l2) {
		int sum = l1->val + l2->val + carry;
		carry = sum > 9 ? 1 : 0;
		l3->val = sum % 10;
		l1 = l1->next; l2 = l2->next;
		l4 = l3; l3 = l3->next;
	}
	if (!l1&&l2) {
		l4->next = l2;
		l3 = l4->next;
	}

	while (l3) {
		int sum = carry + l3->val;
		carry = sum > 9 ? 1 : 0;
		l3->val = sum % 10;
		l4 = l3;
		l3 = l3->next;
	}
	if (carry)l4->next = new ListNode(1);
	return head;
}