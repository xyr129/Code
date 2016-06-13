#pragma once

//���ܣ����������еĵ�����K���ڵ�

//����ָ�룬��ָ������K����Ȼ�����ָ��һ����
//��ָ���ߵ���βʱ��ָ����ָ��Ϊ������K�ڵ�

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

	//����ڵ㲻��k��
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
		cout << "������3���ڵ㣺" << ret->data << endl;
	}
	
	//cout << "������0���ڵ㣺" << FindKthToTail(l, 0)->data << endl;
	ret = FindKthToTail(l, 6);
	if (ret)
	{
		cout << "������6���ڵ㣺" << ret->data << endl;
	}
}