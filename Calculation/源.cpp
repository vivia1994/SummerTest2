#include <iostream>
#include<string>

using namespace std;

#define mod 1000000007
#define ll long long

struct Matrix
{
	ll a[6][6];
};

Matrix origin, res, tmp, A, ans;

int n = 5;

//矩阵相乘
Matrix MatrixMul(Matrix x, Matrix y)
{
	memset(tmp.a, 0, sizeof(tmp.a));
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
			{
				tmp.a[i][j] += (x.a[i][k] * y.a[k][j]) % mod;
				tmp.a[i][j] %= mod;
			}
	return tmp;
}
//快速幂,
//n：n次加法
void QuickPow(ll n)
{
	memset(res.a, 0, sizeof(res.a));
	for ( int i = 1;i <= n;i++)
		res.a[i][i] = 1;

	while (n)
	{
		if (n & 1)
			res = MatrixMul(res, A);
		A = MatrixMul(A, A);
		n >>= 1;
	}
}
int main()
{
	ll A0, AX, AY;
	ll B0, BX, BY;
	ll N;
	ll F1, A1, B1, S0;
	while (cin >> N) 
	{
		cin >> A0 >> AX >> AY;
		cin >> B0 >> BX >> BY;

		A1 = (A0*AX + AY) % mod;
		B1 = (B0*BX + BY) % mod;
		F1 = (A1*B1) % mod;

		S0 = 0;

		memset(origin.a, 0, sizeof(origin.a));

		origin.a[1][1] = F1;
		origin.a[1][2] = A1;
		origin.a[1][3] = B1;
		origin.a[1][4] = 1;
		origin.a[1][5] = S0;

		                                                                

		A.a[1][1] = (AX*BX) % mod;
		A.a[1][5] = 1;
		A.a[2][1] = (AX*BY) % mod;
		A.a[2][2] = AX%mod;
		A.a[3][1] = (AY*BX) % mod;
		A.a[3][3] = BX%mod;
		A.a[4][1] = (AY*BY) % mod;
		A.a[4][2] = AY%mod;
		A.a[4][3] = BY%mod;
		A.a[4][4] = 1;
		A.a[5][5] = 1;

		QuickPow(N);
		ans = MatrixMul(origin, res);
		cout << ans.a[1][5] << endl;
	}
	return 0;
}