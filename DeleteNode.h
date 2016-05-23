#pragma once

//���ܣ�ɾ������������ڵ㣬Ҫ��O(1)ʱ�临�Ӷ�

//1��Ҫɾ������ͷ���
//2��Ҫɾ������β�ڵ㣬�ҵ�β�ڵ��ǰһ��
//3���ø����ڵ���һ���ڵ��ֵ������Ҫɾ���Ľڵ�ֵ
void DeleteNode(ListNode*& head, ListNode*& del)
{
	if (NULL == head || NULL == del)
	{
		return;
	}
	if (head == del)
	{
		head = head->next;
		delete del;
		del = NULL;
	}
	else if (NULL == del->next)
	{
		ListNode* prev = NULL;
		ListNode* cur = head;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		delete del;
		del = NULL;
	}
	else
	{
		ListNode* delNext = del->next;
		del->data = delNext->data;
		del->next = delNext->next;
		delete delNext;
		delNext = NULL;
	}

}