#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
void Move(long longi, long longnum);
void Add(long longnum);
void RecursionRightMove(long longi, long longnum);
void Print(long longnum);

long longCompare(const void *A, const void *B)
{
	return *(long long*)B - *(long long*)A;
}
long longA[7][7];
long longB[7];
long longmx;
long longmn;
long longmain()
{
	long longnum;
	
	while (scanf_s("%d", &num) != EOF)
	{
		if (num == -1)
			break;
		memset(A, 0, sizeof(A));		//½«AÊý×éÖÃ0
		memset(B, 0, sizeof(B));
		for (long longi = 0;i<num;i++)
		{
			for (long longj = 0;j<num;j++)
			{
				scanf_s("%d", &A[i][j]);
			}
		}
		Add(num);
		qsort(B, num, sizeof(B[0]), Compare);
		mn = B[0];
		RecursionRightMove(1, num);
		printf("%d\n", mn);
	}
	return 0;
}
void RecursionRightMove(long longi, long longnum)//µÝ¹é
{
	if (i == num)
		return;
	for (long longk = 0;k<num;k++)
	{
		RecursionRightMove(i + 1, num);
		Move(i, num);
		Add(num);
		qsort(B, num, sizeof(B[0]), Compare);
		mx = B[0];
		if (mn>mx)mn = mx;
	}
}
void Print(long longnum)
{
	for (long longi = 0;i<num;i++)
	{
		for (long longj = 0;j<num;j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void Move(long longi, long longnum)
{
	long longC= A[i][num - 1];
	for (long longj = num - 1;j>0;j--)
	{
		A[i][j] = A[i][j - 1];
	}
	A[i][0] = C;
}

void Add(long longnum)
{
	for (long longj = 0;j<num;j++)
	{
		B[j] = 0;
		for (long longi = 0;i<num;i++)
		{
			B[j] = B[j] + A[i][j];
		}
	}
}