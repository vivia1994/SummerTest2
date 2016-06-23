
/*Description
������������ʽP(x)��Q(x)��ͨ������ʵ�����ǵļӷ���

Input
�������飬ÿ����2������ʽ��ÿ������ʱ�������1������ʽ���������2������ʽ��ÿ�������ɶ�������ʾ������ÿ�������ڵ�������ʾ����ʽ��һ��ֱ�������ϵ�����ݡ����������Ϊ����ʱ����ʾһ������ʽ�Ľ�����һ������ʽ�и���Ĵ���������ġ�

Output
��ÿ������������ʽ���������Case #:��,���С�#���ǲ���������š����������������Ϸֱ������������ʽ���Լ���������ʽ�ĺ͡�Ҫ�󰴽��������������ʽ�ĸ��ÿһ����(a,n)�Ե���ʽ������a��ϵ����n���ݡ���������֮���޿ո�ϵ��Ϊ����������������ʽ��ֻ���0��

Sample Input
-1 2 3 -1 1 2 2 -1
-2 2 4 4 3 -1 2 2 6 1 5 -1
Sample Output
Case 1:
(-1,2)
(1,2)
0
Case 2:
(4,4)(-2,2)
(2,2)(6,1)
(4,4)(6,1)*/

#include<iostream>
#include<list>
#include<string>
#include<sstream>
using namespace std;

void OutPut(list<pair<int, int>> l)
{
	auto j = l.begin();
	int tmp=0;
	for (;j != l.end();j++)
	{
		if (j->first == 0)
			tmp++;
		if (j->first != 0)
			cout << "(" << j->first << "," << j->second << ")";
	}
	if (tmp == l.size())
		cout << "0";
	cout << endl;
}

int main()
{
	int count = 0;
	string line;
	while (getline(cin, line))
	{
		stringstream sstr;
		sstr << line;
		list<pair<int, int>> l1, l2, lr;
		int m, n;
		while (sstr >> m >> n)
		{
			if (n < 0)
				break;
			auto i = l1.begin();
			for (;i != l1.end();i++)
			{
				if (n > i->second)
				{
					l1.insert(i, pair<int, int>(m, n));
					break;
				}
				if (n == i->second)
				{
					i->first += m;
					break;
				}
			}
			if (i == l1.end())
				l1.push_back(pair<int, int>(m, n));
		}
		while (sstr >> m >> n)
		{
			if (n < 0)
				break;
			auto i = l2.begin();
			for (;i != l2.end();i++)
			{
				if (n > i->second)
				{
					l2.insert(i, pair<int, int>(m, n));
					break;
				}
				if (n == i->second)
				{
					i->first += m;
					break;
				}
			}
			if (i == l2.end())
				l2.push_back(pair<int, int>(m, n));
		}
		auto j = l1.begin(), k = l2.begin();
		int tmp1 = 0, tmp2 = 0;
		cout << "Case " << ++count << ":" << endl;
		OutPut(l1);
		OutPut(l2);

		j = l1.begin(), k = l2.begin();
		while (j != l1.end() || k != l2.end())
		{
			if (j != l1.end() && k != l2.end() && j->second == k->second)
			{
				lr.push_back(pair<int, int>(j->first + k->first, j->second));
				j++;
				k++;
				continue;
			}
			if (k == l2.end() || j != l1.end() && j->second > k->second)
			{
				lr.push_back((pair<int, int>(j->first, j->second)));
				j++;
				continue;
			}
			if (j == l1.end() || j->second < k->second)
			{
				lr.push_back((pair<int, int>(k->first, k->second)));
				k++;
				continue;
			}

		}
		OutPut(lr);
	}
	return 0;
}