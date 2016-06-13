#pragma once

//���ܣ��ϲ���������������(����)

//l1��l2��һ���ڵ���ѡһ����С��ժ������Ϊ�������ͷ
//���αȽ�l1��l2���ڵ㣬ÿ��ѡ��С��ժ����β��
//��ʣ���l1��l2����������֮��

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