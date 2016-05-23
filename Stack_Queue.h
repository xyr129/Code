#pragma once

//用两个栈实现一个队列，实现push、pop方法

//s1用来push，s2用来pop
//push操作直接s1.push(x)
//pop操作如果s2不为空，则s2.pop()
//否则，即s2为空，把s1倒入s2再执行s2.pop()
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