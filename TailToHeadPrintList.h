#pragma once
using namespace std;
//�����ӡ������
//Ҫ�󲻸ı�ԭ����

//�ݹ��ӡ
void TailToHeadPrintList(ListNode* head)
{
	if (NULL == head)
	{
		return;
	}
	TailToHeadPrintList(head->next);
	cout << head->data << "->";
}

//�����ռ�
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