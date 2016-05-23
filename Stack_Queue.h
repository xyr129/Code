#pragma once

//������ջʵ��һ�����У�ʵ��push��pop����

//s1����push��s2����pop
//push����ֱ��s1.push(x)
//pop�������s2��Ϊ�գ���s2.pop()
//���򣬼�s2Ϊ�գ���s1����s2��ִ��s2.pop()
template<class T>
class Stack_Queue
{
public:
	Stack_Queue(stack<T>& first, stack<T>& second)
		:s1(first)
		, s2(second)
	{}
	void Push(const T& value)
	{
		s1.push(value);
	}
	void Pop()
	{
		if (!s2.empty())
		{
			s2.pop();
		}
		else
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
		}
	}
private:
	stack<T> s1;
	stack<T> s2;
};