#pragma once

//功能：单向链表中的倒数第K个节点

//快慢指针，快指针先走K步，然后快慢指针一起走
//快指针走到结尾时慢指针所指即为倒数第K节点

ListNode* FindKthToTail(ListNode* head, int k)
{
	if (NULL == head || k < 0)
	{
		return NULL;
	}

	ListNode* fast = head;
	ListNode* slow = head;

	while (fast && k)
	{
		fast = fast->next;
		--k;
	}

	//链表节点不够k个
	if (k > 0)
	{
		return NULL;
	}

	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

void TestFindKthToTail()
{
	ListNode* l = NULL;
	PushBack(l, 1);
	PushBack(l, 2);
	PushBack(l, 3);
	PushBack(l, 4);
	PushBack(l, 5);
	PushBack(l, 6);

	cout << "list l:" << endl;
	print(l);
	ListNode* ret = FindKthToTail(l, 3);
	if (ret)
	{
		cout << "倒数第3个节点：" << ret->data << endl;
	}
	
	//cout << "倒数第0个节点：" << FindKthToTail(l, 0)->data << endl;
	ret = FindKthToTail(l, 6);
	if (ret)
	{
		cout << "倒数第6个节点：" << ret->data << endl;
	}
}