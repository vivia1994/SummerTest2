#include <iostream>
#include<string>

using namespace std;

#define mod 1000000007
#define ll long long

struct Matrix
{
	ll A[6][6];
};

Matrix origin, res, tmp, A, ans;

int n = 5;

//矩阵相乘
Matrix MatrixMul(Matrix x, Matrix y)
{
	memset(tmp.A, 0, sizeof(tmp.A));
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
			{
				tmp.A[i][j] += (x.A[i][k] * y.A[k][j]) % mod;
				tmp.A[i][j] %= mod;
			}
	return tmp;
}
//快速幂
void QuickPow(ll k)
{
	memset(res.A, 0, sizeof(res.A));
	for ( int i = 1;i <= n;i++)
		res.A[i][i] = 1;

	while (k)
	{
		if (k & 1)
			res = MatrixMul(res, A);
		A = MatrixMul(A, A);
		k >>= 1;
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

		memset(origin.A, 0, sizeof(origin.A));

		origin.A[1][1] = F1;
		origin.A[1][2] = A1;
		origin.A[1][3] = B1;
		origin.A[1][4] = 1;
		origin.A[1][5] = S0;

		memset(A.A, 0, sizeof(A.A));

		A.A[1][1] = (AX*BX) % mod;
		A.A[1][5] = 1;
		A.A[2][1] = (AX*BY) % mod;
		A.A[2][2] = AX%mod;
		A.A[3][1] = (AY*BX) % mod;
		A.A[3][3] = BX%mod;
		A.A[4][1] = (AY*BY) % mod;
		A.A[4][2] = AY%mod;
		A.A[4][3] = BY%mod;
		A.A[4][4] = 1;
		A.A[5][5] = 1;

		QuickPow(N);
		ans = MatrixMul(origin, res);
		cout << ans.A[1][5] << endl;
	}
	return 0;
}