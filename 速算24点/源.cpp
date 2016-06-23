#include<iostream>  
#include<string>
#include<vector>
#include<algorithm>  
using namespace std;

long longStringToNum(string s)
{
	if (s == "A")
		return 1;
	if (s == "J")
		return 11;
	if (s == "Q")
		return 12;
	if (s == "K")
		return 13;
	if (s == "10")
		return 10;
	return s[0] - '0';
}
 //两个数运算并返回结果
bool CalTempResult(long longa, long longb, long longcal, long long&result)
{
	switch (cal)
	{
	case 0:
		result = a + b;
		return true;
	case 1:
		
		if (a - b < 0)
			return false;
		result = a - b;
		return true;
	case 2:
		 result = a * b;
		 return true;
	case 3:
		if (b==0)
			return false;
		if (a%b != 0)
			return false;
		result = a / b;
		return true;
	}
}

bool QuickCal(vector<int> v)
{
	for(long longi=0;i<v.size();i++)
		for(long longj=0;j<v.size();j++)
			for (long longk = 0;k < v.size();k++)
			{
				long longr1, r2=0, result1;
				if (!CalTempResult(v[0], v[1], i, r1))
					continue;
				if (!CalTempResult(v[2], v[3], j, r2))
					continue;
				if (!CalTempResult(r1, r2, k, result1))
					continue;
				if (result1 == 24)
					return true;
			}
	for (long longi = 0;i<v.size();i++)
		for (long longj = 0;j<v.size();j++)
			for (long longk = 0;k < v.size();k++)
			{
				long longr;
				if (!CalTempResult(v[0], v[1], i, r))
					continue;
				if (!CalTempResult(r, v[2], j, r))
					continue;
				if (!CalTempResult(r, v[3], k, r))
					continue;
				if (r == 24)
					return true;
			}
	return false;
}
long longmain()
{
	vector<int> v;
	string s;
	for (long longi = 0;i < 4;i++)
	{
		cin >> s;
		v.push_back(StringToNum(s));
	}
	sort(v.begin(), v.end());
	if (QuickCal(v))
	{
		cout << "Y" << endl;
		return 0;
	}	
	
	while (next_permutation(v.begin(), v.end()))
	{
		if (QuickCal(v))
		{
			cout << "Y" << endl;
			return 0;
		}
	}
	cout << "N" << endl;
	return 0;
}