#pragma once

//功能：合并两个已排序链表(升序)

//l1和l2第一个节点中选一个较小的摘下来做为新链表的头
//依次比较l1和l2各节点，每次选较小的摘下来尾插
//把剩余的l1或l2链到新链表之后

ListNode* MergeList(ListNode*& l1, ListNode*& l2)
{
	if (NULL == l1)
	{
		return l2;
	}
	if (NULL == l2)
	{
		return l1;
	}

	ListNode* pl1 = l1;
	ListNode* pl2 = l2;
	ListNode* newHead = NULL;
	if (pl1->data <= pl2->data)
	{
		newHead = pl1;
		pl1 = pl1->next;
	}
	else
	{
		newHead = pl2;
		pl2 = pl2->next;
	}

	ListNode* cur = newHead;

	while (pl1 && pl2)
	{
		if (pl1->data <= pl2->data)
		{
			cur->next = pl1;
			pl1 = pl1->next;
		}
		else
		{
			cur->next = pl2;
			pl2 = pl2->next;
		}
		cur = cur->next;
	}
	while (pl1)
	{
		cur->next = pl1;
		pl1 = pl1->next;
	}
	while (pl2)
	{
		cur->next = pl2;
		pl2 = pl2->next;
	}

	return newHead;
}

void TestMergeList()
{
	ListNode* l1 = NULL;
	PushBack(l1, 1);
	PushBack(l1, 3);
	PushBack(l1, 5);
	PushBack(l1, 7);
	PushBack(l1, 9);
	ListNode* l2 = NULL;
	PushBack(l2, 2);
	PushBack(l2, 4);
	PushBack(l2, 6);
	PushBack(l2, 8);
	PushBack(l2, 10);

	ListNode* ret = MergeList(l1, l2);
	print(ret);
}