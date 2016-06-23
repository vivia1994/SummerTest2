
/*Description
给定两个多项式P(x)与Q(x)，通过链表实现它们的加法。

Input
有若干组，每组有2个多项式。每组输入时先输入第1个多项式，再输入第2个多项式。每组用若干对整数表示，依序每两个相邻的整数表示多项式的一项，分别是它的系数和幂。当输入的幂为负数时，表示一个多项式的结束。一个多项式中各项的次序是随机的。

Output
对每组中两个多项式，先输出“Case #:”,其中“#”是测试数据序号。接着在下面三行上分别输出这两多项式，以及这两多项式的和。要求按降幂排列输出多项式的各项，每一项用(a,n)对的形式，其中a是系数，n是幂。相邻两对之间无空格。系数为零的项不输出。对零多项式，只输出0。

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