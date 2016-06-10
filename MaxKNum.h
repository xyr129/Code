#pragma once

//功能：最大的K个数

//前K个数建小堆
//其余数和堆顶比较，若大于堆顶就替换堆顶


void _MaxKNum(Heap<int>& data, int k, vector<int>& value)
{
	if (k < 1)
	{
		return;
	}
	vector<int>::iterator it = value.begin();
	while (k && it != value.end())
	{
		data.Push(*it);
		++it;
		--k;
	}
	if (k>0)
	{
		return;
	}
	
	while (it != value.end())
	{
		int top = data.Top();
		if (*it>top)
		{
			data.Pop();
			data.Push(*it);
		}
		++it;
	}
}

void TestMaxKNum()
{
	Heap<int> data;
	vector<int> value;
	value.push_back(2);
	value.push_back(5);
	value.push_back(4);
	value.push_back(1);
	value.push_back(8);
	value.push_back(6);
	value.push_back(9);
	value.push_back(3);

	cout << "before:" << endl;
	data.PrintHeap();
	_MaxKNum(data, 3, value);
	cout << "after:" << endl;
	data.PrintHeap();
}