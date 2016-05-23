#pragma once

//根据前序遍历、中序遍历序列重建二叉树
//重建成功返回true，否则返回false

//前序遍历的第一个值为根节点，在中序遍历的序列中找到这个根节点
//递归的创建根节点的左右子树
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