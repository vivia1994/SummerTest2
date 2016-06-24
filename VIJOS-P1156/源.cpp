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
		A[i] = A[i] * n;
	for (i = 1; i<A[0]; i++) {
		A[i + 1] += A[i] / 10;
		A[i] %= 10;
	}
	while (A[A[0]]>9) {
		A[A[0] + 1] = A[A[0]] / 10;
		A[A[0]] %= 10; A[0]++;
	}
	if (A[0]>101)
		A[0] = 101;
}

int main() 
{
	long i, j, n, m, all;
	long h[200000], nn;
	long mm, r[1000];
	scanf_s("%ld %ld", &n, &m);
	all = n + m;
	memset(h, 0, sizeof(h));
	for (i = n + 1; i <= all; i++)
	{
		nn = i;
		for (j = 1; j <= 65; j++)
		{
			while (nn%A[j] == 0)
			{
				h[A[j]]++; nn /= A[j];
				if (nn == 1)
					break;
			}
			if (nn == 1)
				break;
		}
		if (nn != 1)
			h[nn]++;
	}
	for (i = 1; i <= m; i++)
	{
		mm = i;
		for (j = 1; j <= 65; j++)
		{
			while (mm%A[j] == 0)
			{
				h[A[j]]--; mm /= A[j];
				if (mm == 1)
					break;
			}
			if (mm == 1)
				break;
		}
		if (mm != 1)
			h[mm]--;
	}
	r[0] = 1;
	r[1] = 1;
	for (i = 1; i <= 100000; i++)
		while (h[i]>0) {
			mul(r, i);
			h[i]--;
		}
	for (i = 100; i >= 1; i--) {
		printf("%ld", r[i]);
		if (i % 10 == 1)
			printf("\n");
	}
}