#pragma once

//功能：删除单链表给定节点，要求O(1)时间复杂度

//1、要删除的是头结点
//2、要删除的是尾节点，找到尾节点的前一个
//3、用给定节点下一个节点的值覆盖所要删除的节点值
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