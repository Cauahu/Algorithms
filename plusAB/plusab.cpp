#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};

ListNode* plusab(ListNode *a, ListNode *b)
{
	ListNode *pa = a, *pb = b;
	ListNode *p = NULL;
	while(pa != NULL && pb != NULL)
	{

		ListNode *psum = new ListNode;
		psum->val = pa->val + pb->val;
		pa = pa->next;
		pb = pb->next;

		psum ->next = p;
		p = psum;
	}
	while(pa != NULL)
	{
		ListNode *psum = new ListNode;
		psum->val = pa->val;
		psum ->next = p;
		p = psum;
		pa = pa->next;
	}
	while(pb != NULL)
	{
		ListNode *psum = new ListNode;
		psum->val = pb->val;
		psum ->next = p;
		p = psum;
		pb = pb->next;
	}

	int carry = 0;
	while(p != NULL)
	{
		p->val += carry;
		carry = p->val / 10;
		p->val = p->val % 10;
		p = p->next;
	}
	if(carry != 0)
	{
		ListNode *psum = new ListNode;
		psum->val = carry;
		psum ->next = p;
		p = psum;
	}
	return p;
}

int main()
{
	ListNode *pa = new ListNode;
	pa->val = 1;
	pa->next = new ListNode;
	pa->next->val = 2;
	pa->next->next = new ListNode;
	pa->next->next->val = 3;
	pa->next->next->next = NULL;
	
	ListNode *pb = new ListNode;
	pb->val = 3;
	pb->next = new ListNode;
	pb->next->val = 2;
	pb->next->next = new ListNode;
	pb->next->next->val = 1;
	pb->next->next->next = NULL;
	
	pa = plusab(pa , pb);

	while(pa != NULL)
	{
		cout << pa->val << " ";
		pa = pa->next;
	}
	return 0;
}
