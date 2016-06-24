/*Description
����N�����������ܷ����N��������ȡ���������(����ѡһ����)��ʹ���ǵ�XORֵ

����0��

Input
�������ݡ�

ÿ�����ݵ�һ��Ϊһ������N��(N<=100)

֮��һ������N������A[i]��(A[i]<2^63)

Output
����ÿ�����ݣ�����ܹ��ҵ������ļ��ϣ������YES����

���������NO����*/


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

//xor��˹��Ԫ�����Ի�
//���Ӷ�O(30n)
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