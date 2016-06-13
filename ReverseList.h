#pragma once

//功能：反转单链表

//不破坏链表结构：摘节点 头插
//改变链表结构：遍历一次链表，将所有节点压栈，按出栈顺序链接节点

ListNode* ReverseList(ListNode*& head)
{
	if (NULL == head)
	{
		return NULL;
	}
	ListNode* cur = head;
	ListNode* newHead = NULL;
	while (cur)
	{
		ListNode* tmp = cur;
		cur = cur->next;
		tmp->next = newHead;
		newHead = tmp;
	}
	head = newHead;
	return head;
}

ListNode* ReverseList_C(ListNode*& head)
{
	if (NULL == head)
	{
		return NULL;
	}

	ListNode* cur = head;
	stack<ListNode*> s;
	while (cur)
	{
		s.push(cur);
		cur = cur->next;
	}

	ListNode* newHead = s.top();
	cur = newHead;
	s.pop();
	while (!s.empty())
	{
		cur->next = s.top();
		cur = cur->next;
		s.pop();
	}
	cur->next = NULL;
	head = newHead;
	return head;
}

void TestReverseList()
{
	ListNode* l = NULL;
	PushBack(l, 1);
	PushBack(l, 2);
	PushBack(l, 3);
	PushBack(l, 4);
	PushBack(l, 5);
	PushBack(l, 6);
	PushBack(l, 7);
	PushBack(l, 8);
	PushBack(l, 9);
	PushBack(l, 10);
	cout << "before reverse:" << endl;
	print(l);
	cout << "after reverse:" << endl;
	ReverseList(l);
	print(l);

	cout << "after reverse_C:" << endl;
	ReverseList_C(l);
	print(l);
}