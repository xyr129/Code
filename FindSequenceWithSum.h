#pragma once

//功能：和为S的所有连续正数序列(至少包含两个数)
 
//输入 9
//输出 {2,3,4}，{4,5}

//标记连续序列的开始值，它最大不能超过(1+S)/2
//从开始值出发，一直加到和大于S，改变开始值(加1)
//如果加到和与S相等，打印当前序列
//重复上述操作，直至开始值等于(1+S)/2

void SequenceWithSum(int sum)
{
	if (sum < 3)
	{
		cout << "没有满足要求的序列" << endl;
	}

	int limit = (1 + sum) / 2;
	int start = 1;
	int end = 2;
	int newSum = start + end;
	while (start < limit)
	{
		if (newSum > sum)
		{
			start++;
			end = start + 1;
			newSum = start + end;
		}
		else if (newSum < sum)
		{
			end++;
			newSum += end;
		}
		else
		{
			for (int i = start; i <= end; ++i)
			{
				cout << i << ',';
			}
			cout << endl;
			start++;
			end = start + 1;
			newSum = start + end;
		}
	}
}

void TestSequenceWithSum()
{
	cout << "和为9的序列：" << endl;
	SequenceWithSum(9);
	cout << "和为15的序列：" << endl;
	SequenceWithSum(15);
}
