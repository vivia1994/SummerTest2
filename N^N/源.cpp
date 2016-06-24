#include<iostream>
#include<string>
using namespace std;

typedef long long ll;
const ll mod = 10000000007;
ll HashValue[10000];

void CreateHash()
{
	for (ll i = 1;i <= 9999;i++)
	{
		ll tmp = 1;
		for (ll j = 0;j < i;j++)
		{
			tmp = tmp * i % mod;
		}
		HashValue[i] = tmp % mod;
	}
}

ll SearchHashValue(ll hash)
{
	ll i;
	for ( i = 1;i < 10000;i++)
		if (hash == HashValue[i])
			return i;
	return -1;
}
int main()
{
	string str;
	CreateHash();
	while (cin >> str)
	{
		ll hash = 0;
		for (int i = 0;i < str.size();i++)
			hash = (hash * 10 + str[i] - '0') % mod;
		ll r = SearchHashValue(hash);
		if (r != -1)
			cout << r << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}