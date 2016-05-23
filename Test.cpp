#include<iostream>
#include<cassert>
#include<stack>
#include"MyString.h"
#include"FindInMatrix.h"
#include"List.h"
#include"TailToHeadPrintList.h"
//#include"ReCreate.h"
#include"Stack_Queue.h"
#include"FindMinNum.h"
#include"Fibonacci.h"
#include"DoublePower.h"
#include"PrintToMaxNum.h"
#include"DeleteNode.h"
#include"ReOrderOddEven.h"
using namespace std;

//void TestMyString()
//{ 
//	MyString s1("hello");
//	cout <<"s1:"<< s1 << endl;
//	MyString s2(s1);
//	cout << "s2:"<<s2 << endl;
//	MyString s3("MyString");
//	s2 = s3;
//	cout << "s2:" << s2 << endl;
//}

void TestFindInMatrix()
{
	int array[4][5] = { { 1, 6, 9, 13, 15 }, { 2, 7, 10, 14, 16 }, { 3, 8, 12, 15, 20 }, { 6, 18, 22, 25 } };
	cout << "Find 12:" << FindInMatrix(array, 4, 5, 12) << endl;
	cout << "Find 30:" << FindInMatrix(array, 4, 5, 30) << endl;
}

void TestTailToHeadPrintList()
{
	ListNode* head = NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PushBack(head, 5);
	TailToHeadPrintList(head);
	cout << endl;
	TailToHeadPrintList_NR(head);
	cout << endl;
}

void TestStack_Queue()
{
	stack<int> s1;
	stack<int> s2;
	Stack_Queue<int> sq(s1, s2);
	sq.Push(1);
	sq.Push(2);
	sq.Push(3);
	sq.Push(4);
	sq.Push(5);
}

void TestFindMinNum()
{
	int array[9] = { 5, 6, 7, 8, 9, 1, 2, 3, 4 };
	cout <<"FindMinNum:"<< FindMinNum(array, 9) << endl;
}

void TestFibonacci()
{
	cout << "Fibonacci 20:" << Fib_NR2(20) << endl;
}

void TestDoublePower()
{
	double base = 2.0;
	int exponent = 16;
	cout << "2µÄ16´Î·½£º"<< DoublePower(base, exponent) << endl;
}

void TestPrintToMaxNum()
{
	PrintToMaxNum(3);
}

void TestDeleteNode()
{
	ListNode* head = NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PushBack(head, 5);
	print(head);

	ListNode* del = Find(head, 1);
	cout << "delete 1:" << endl;
	DeleteNode(head, del);
	print(head);

	del = Find(head, 5);
	cout << "delete 5:" << endl;
	DeleteNode(head, del);
	print(head);

	del = Find(head, 3);
	cout << "delete 3:" << endl;
	DeleteNode(head, del);
	print(head);
}

void TestReOrderOddEven()
{
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ReOrderOddEven(array, 10);
	cout << "ReOrderOddEven:" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	//TestMyString();
	TestFindInMatrix();
	TestTailToHeadPrintList();
	TestStack_Queue();
	TestFindMinNum();
	TestFibonacci();
	TestDoublePower();
	TestPrintToMaxNum();
	TestDeleteNode();
	TestReOrderOddEven();

	system("pause");
	return 0;
}
