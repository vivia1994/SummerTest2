
/*Description
��һԪ���η���ax^2+bx+c=0�Ľ⡣

Input

a,b,c��ֵ��

Output
������X1��X2������X1>=X2���� 
���������λС��
x=[-b����(b^2-4ac)]/(2a)*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

long longmain()
{
	double a, b, c;
	double x1, x2;
	cin >> a >> b >> c;
	x1 = (-b + sqrt(b*b - 4.0 * a*c))/ (2.0 * a);
	x2 = (-b - sqrt(b*b - 4.0 * a*c)) / (2.0 * a);
	if (x1 >= x2)
		cout << fixed<< setprecision(2) << x1 <<" "<< x2<<endl;
	else
		cout << x2 <<" "<< x1 << endl;
	return 0;
}