/*��Ŀ����
Yaoge����n�鼦�ţ����е�n�鼦�ŵ�����ΪMatrix(n)��ͬʱ������Matrix(n)����Matrix(n)=f(n)2

��֪f(n)=x*f(n-1)+y*f(n-2)�����У�f(0)=1,f(1)=1��

Yaogeϣ�����ܰ��������Щ���ŵ���������10007ȡģ��Ľ����

����
��һ������һ��T����ʾ��T���������(T<=10000)��

������T��ÿ������3������n��x��y��(2<=n,x,y<=100000000);

���
������ŵ���������10007ȡģ��Ľ��

��������
2
2 1 1
3 2 3
�������
5
195
��ʾ
��һ��������f(1)=1,f(2)=2,Matrix(1)=1,Matrix(2)=4,�ܺ͵���5


�ڶ��飬f(1)=1,f(2)=5,f(3)=13,Matrix(1)=1,Matrix(2)=25,Matrix(3)=169,�ܺ͵���195*/

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
{ 1,0,0,0,         //��λ���� 
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

int PowMod(Matrix A, int n)    //������ 
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
		ans = (ans + res.data[0][j]) % mod;   //�����ս����ĵ�һ����� 
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