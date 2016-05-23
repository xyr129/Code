#pragma once
using namespace std;
//逆序打印单链表
//要求不改变原链表

//递归打印
void TailToHeadPrintList(ListNode* head)
{
	if (NULL == head)
	{
		return;
	}
	TailToHeadPrintList(head->next);
	cout << head->data << "->";
}

//辅助空间
void TailToHeadPrintList_NR(ListNode* head)
{
	if (NULL == head)
	{
		return;
	}
	stack<ListNode*> s;
	ListNode* cur = head;
	while (cur)
	{
		s.push(cur);
		cur = cur->next;
	}
	while (!s.empty())
	{
		cout << s.top()->data << "->";
		s.pop();
	}
}