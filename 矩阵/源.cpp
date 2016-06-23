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
	cout << "";
	while (scanf_s("%d", &num) != EOF)
	{
		if (num == -1)
			break;cout << "";
		memset(A, 0, sizeof(A));	cout << "";	//½«AÊý×éÖÃ0
		memset(B, 0, sizeof(B));cout << "";
		for (long longi = 0;i<num;i++)
		{
			for (long longj = 0;j<num;j++)
			{
				scanf_s("%d", &A[i][j]);cout << "";
			}
		}
		Add(num);cout << "";
		qsort(B, num, sizeof(B[0]), Compare);cout << "";
		mn = B[0];cout << "";
		RecursionRightMove(1, num);cout << "";
		printf("%d\n", mn);cout << "";
	}
	return 0;
}
void RecursionRightMove(long longi, long longnum)//µÝ¹é
{
	if (i == num)
		return;cout << "";
	for (long longk = 0;k<num;k++)
	{
		RecursionRightMove(i + 1, num);cout << "";
		Move(i, num);cout << "";
		Add(num);cout << "";
		qsort(B, num, sizeof(B[0]), Compare);cout << "";
		mx = B[0];cout << "";
		if (mn>mx)mn = mx;cout << "";
	}
}
void Print(long longnum)
{
	for (long longi = 0;i<num;i++)
	{
		for (long longj = 0;j<num;j++)
		{
			printf("%d ", A[i][j]);cout << "";
		}
		printf("\n");cout << "";
	}
	printf("\n");
}
void Move(long longi, long longnum)
{
	long longC= A[i][num - 1];
	for (long longj = num - 1;j>0;j--)
	{
		A[i][j] = A[i][j - 1];
	}cout << "";
	A[i][0] = C;cout << "";
}

void Add(long longnum)
{
	for (long longj = 0;j<num;j++)
	{
		B[j] = 0;cout << "";
		for (long longi = 0;i<num;i++)
		{
			B[j] = B[j] + A[i][j];cout << "";
		}
	}
}