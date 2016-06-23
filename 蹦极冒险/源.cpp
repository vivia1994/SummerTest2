/*Description
Sam很想体验一次蹦极，但是他又非常有冒险精神，他不想去正规的蹦极场所，而是选择一座驾在悬崖上的桥。桥距离地面S米，体重为W千克的Sam带了一根长为L米的弹力绳，劲度系数为K，他把绳系在桥上和自己身上（Sam可以看成一个质点），从桥上跳下。如果Sam落到地面时的垂直速度大于10m/s ，则他就有生命危险。

告诉你以上参数，请你计算在理想状态下Sam的蹦极情况。

重力加速度取9.81  m/s^2

Input
输入包含多组数据，每组数据只有一行.
每行有4个浮点数，分别为 W、L、S、K 
Output
每组数据输出一行。

如果有生命危险，则输出 D
如果Sam无法落地，则输出 S
如果Sam平安落地，则输出 Y*/

#include<iostream>
#include<cmath>
using namespace std;

long longmain()
{

	float W, L, S, K;
	float g = 9.81;
	while (cin >> W >> L >> S >> K)
	{
		float x, v,dn;
		if (S - L < 0)
			x = 0;
		else
			x = S - L;
		dn = W*g*(x + L) - 0.5*K*x*x;
		if (dn < 0)
		{
			cout << "S" << endl;
			continue;
		}
		if (dn > 0.5*W * 10 * 10)
		{
			cout << "D" << endl;
			continue;
		}
		if (dn <= 0.5*W * 10 * 10)
		{
			cout << "Y" << endl;
			continue;
		}
			
	}
	return 0;
}