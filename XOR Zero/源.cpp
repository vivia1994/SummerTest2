/*Description
给出N个整数，求能否从这N个整数中取出任意个数(至少选一个数)，使他们的XOR值

等于0？

Input
多组数据。

每组数据第一行为一个整数N。(N<=100)

之后一行中有N个整数A[i]。(A[i]<2^63)

Output
对于每组数据，如果能够找到这样的集合，输出”YES”，

否则输出”NO”。*/


#include <iostream>

using namespace std;
typedef long long ll;
const ll maxn = 105;
const ll mod = 1000007;
ll n;
ll s[maxn];

void input()
{
	for (ll i = 0; i < n; ++i)
		scanf_s("%lld", &s[i]);
}

//xor高斯消元求线性基
//复杂度O(30n)
ll xorGauss(ll n)
{
	ll row = 0;
	for (ll i = 64; i >= 0; i--)
	{
		ll j;
		for (j = row; j < n; j++)
			if (s[j] & (1ll << i))
				break;
		if (j != n)
		{
			swap(s[row], s[j]);
			for (j = 0; j < n; j++)
			{
				if (j == row) continue;
				if (s[j] & (1ll << i))
					s[j] ^= s[row];
			}
			row++;
		}
	}
	return row;
}

void GetR()
{
	ll row;
	ll answer, k;
	row = xorGauss(n);
	answer = n - row;
	
	if (answer >0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main()
{
	while (~scanf_s("%lld", &n))
	{
		input();
		GetR();
	}
	return 0;
}