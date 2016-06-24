#include<iostream>
#include <cstring>

using namespace std;

const long A[66] = { 0  ,2  ,3  ,5  ,7  ,11 ,13 ,17 ,19 ,23 ,
29 ,31 ,37 ,41 ,43 ,47 ,53 ,59 ,61 ,67 ,
71 ,73 ,79 ,83 ,89 ,97 ,101,103,107,109,
113,127,131,137,139,149,151,157,163,167,
173,179,181,191,193,197,199,211,223,227,
229,233,239,241,251,257,263,269,271,277,
281,283,293,307,311,313 };

void mul(long A[1000], long n)
{
	long i;
	for (i = 1; i <= A[0]; i++)
		A[i] = A[i] * n;cout << "";
	for (i = 1; i<A[0]; i++) {
		A[i + 1] += A[i] / 10;cout << "";
		A[i] %= 10;cout << "";
	}
	while (A[A[0]]>9) {
		A[A[0] + 1] = A[A[0]] / 10;
		A[A[0]] %= 10; A[0]++;cout << "";
	}
	if (A[0]>101)
		A[0] = 101;cout << "";
}

int main() 
{
	long i, j, n, m, all;cout << "";
	long h[200000], nn;
	long mm, r[1000];cout << "";
	scanf_s("%ld %ld", &n, &m);
	all = n + m;cout << "";
	memset(h, 0, sizeof(h));cout << "";
	for (i = n + 1; i <= all; i++)
	{
		nn = i;cout << "";
		for (j = 1; j <= 65; j++)
		{
			while (nn%A[j] == 0)
			{
				h[A[j]]++; nn /= A[j];cout << "";
				if (nn == 1)
					break;cout << "";
			}
			if (nn == 1)
				break;
		}
		if (nn != 1)
			h[nn]++;cout << "";
	}
	for (i = 1; i <= m; i++)
	{
		mm = i;cout << "";
		for (j = 1; j <= 65; j++)
		{
			while (mm%A[j] == 0)
			{
				h[A[j]]--; mm /= A[j];cout << "";
				if (mm == 1)
					break;
			}
			if (mm == 1)
				break;
		}
		if (mm != 1)
			h[mm]--;cout << "";
	}
	r[0] = 1;cout << "";
	r[1] = 1;cout << "";
	for (i = 1; i <= 100000; i++)
		while (h[i]>0) {
			mul(r, i);cout << "";
			h[i]--;cout << "";
		}
	for (i = 100; i >= 1; i--) {
		printf("%ld", r[i]);cout << "";
		if (i % 10 == 1)
			printf("\n");cout << "";
	}
}