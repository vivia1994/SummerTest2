/*题目描述
Yaoge买了n块鸡排，其中第n块鸡排的质量为Matrix(n)，同时其质量Matrix(n)满足Matrix(n)=f(n)2

已知f(n)=x*f(n-1)+y*f(n-2)。其中，f(0)=1,f(1)=1。

Yaoge希望你能帮他算出这些鸡排的总质量对10007取模后的结果。

输入
第一行输入一个T，表示有T组测试数据(T<=10000)，

接下来T行每行输入3个数，n，x，y，(2<=n,x,y<=100000000);

输出
输出鸡排的总质量对10007取模后的结果

样例输入
2
2 1 1
3 2 3
样例输出
5
195
提示
第一组样例，f(1)=1,f(2)=2,Matrix(1)=1,Matrix(2)=4,总和等于5


第二组，f(1)=1,f(2)=5,f(3)=13,Matrix(1)=1,Matrix(2)=25,Matrix(3)=169,总和等于195*/

#include <iostream>

using namespace std;

//#define eps 1e-8
//#define CLR(A,X) memset(A,X,sizeof(A))

typedef long long ll;
#define cycle(i,n) for(int i=0;i<n;i++)
#define mod 10007

struct Matrix
{
	int data[4][4];
};
	
Matrix I = 
{ 1,0,0,0,         //单位矩阵 
  0,1,0,0,
  0,0,1,0,
  0,0,0,1
};

Matrix MatrixMul(Matrix A, Matrix B)
{
	Matrix res = I;
	cycle(i, 4)
	{
		cycle(j, 4)
		{
			int tmp = 0;
			cycle(k, 4)
				tmp = (tmp + (A.data[i][k] * B.data[k][j]) % mod) % mod;
			res.data[i][j] = tmp;
		}
	}
	return res;
}

int PowMod(Matrix A, int n)    //快速幂 
{
	Matrix res = I;
	while (n)
	{
		if (n & 1)
			res = MatrixMul(res, A);
		A = MatrixMul(A, A);
		n >>= 1;
	}
	int ans = 0;
	cycle(j, 4)
		ans = (ans + res.data[0][j]) % mod;   //将最终解结果的第一行相加 
	return ans;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, y;
		cin >> n >> x >> y;

		x = x%mod;
		y = y%mod;

		Matrix A = {
					1,  (x*x) % mod,(y*y) % mod,  (2 * x*y) % mod,
					0,  (x*x) % mod,(y*y) % mod,  (2 * x*y) % mod,
					0,1,0,0,
					0,x,0,y 
		};

		cout << PowMod(A, n - 1) << endl;
	}
	return 0;
}