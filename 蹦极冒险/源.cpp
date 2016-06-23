/*Description
Sam��������һ�αļ����������ַǳ���ð�վ���������ȥ����ıļ�����������ѡ��һ�����������ϵ��š��ž������S�ף�����ΪWǧ�˵�Sam����һ����ΪL�׵ĵ�����������ϵ��ΪK��������ϵ�����Ϻ��Լ����ϣ�Sam���Կ���һ���ʵ㣩�����������¡����Sam�䵽����ʱ�Ĵ�ֱ�ٶȴ���10m/s ��������������Σ�ա�

���������ϲ������������������״̬��Sam�ıļ������

�������ٶ�ȡ9.81  m/s^2

Input
��������������ݣ�ÿ������ֻ��һ��.
ÿ����4�����������ֱ�Ϊ W��L��S��K 
Output
ÿ���������һ�С�

���������Σ�գ������ D
���Sam�޷���أ������ S
���Samƽ����أ������ Y*/

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