#pragma once

//����ǰ�������������������ؽ�������
//�ؽ��ɹ�����true�����򷵻�false

//ǰ������ĵ�һ��ֵΪ���ڵ㣬������������������ҵ�������ڵ�
//�ݹ�Ĵ������ڵ����������
bool ReCreate(const int* preOrder, const int* inOrder,int& preStart, int preEnd,int inStart, int inEnd)
{
	if (NULL == preOrder || NULL == inOrder)
	{
		return true;
	}
	if (preStart <= preEnd)
	{
		BinaryTreeNode<int>* node(preOrder[preStart]);
		int pos = inStart;
		while (pos <= inEnd)
		{
			if (inOrder[pos] == preOrder[preStart])
			{
				break;
			}
			pos++;
		}
		if (pos > inEnd)
		{
			return false;
		}
		node->_left = ReCreate(preOrder, inOrder, ++preStart, preEnd, inStart, pos - 1);
		node->_right = ReCreate(preOrder, inOrder, ++preStart, preEnd, pos + 1, inEnd);
	}
	return true;
}