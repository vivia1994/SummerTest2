
/*��Ŀ����
ACM����ĳ�������ѧԺ��T��Y�����ˡ�Y��Ҫ��ҵ�ˣ�Ϊ��ǰ;��YҲ��Ҫȥ�������չ������ҵ�����ǣ�T��Y��ʼ�ƻ��Ժ���μ��档T�и������⣬����YԼ���ھ���ACM�����Future�������ߵ��е���̵�Heart������棬���ܰ������ҳ���������Heart������
����
����Ϊһ����N,��ʾ��N������ ������N�У�ÿ�а�������С��X,Y,Z����ʾһ����������ꡣ ��N+2�а�������С��X,Y,Z����ʾACM��������ꡣ ��N+3�а�������С��X,Y,Z����ʾFuture��������ꡣ N<=5000,1<=X,Y,Z<=99999
���
Heart��������ꡣ������3λС����
��������
5
1062.961900 47382.348900 49636.324000
21829.052500 75418.119200 6862.009300
24339.931000 6028.722000 27365.733500
20111.459200 22797.250400 42073.367900
29601.644400 39841.340000 55461.667800
21829.052500 75418.119200 6862.009300
20111.459200 22797.250400 42073.367900
�������
21829.053 75418.119 6862.009*/

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

struct Point
{
	double x, y, z;
	Point()
	{

	}
	Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

double Distance(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
}

long longmain()
{
	vector<Point> v;
	vector<Point> vr;
	Point center;
	long longN;
	cin >> N;
	for (long longi = 0;i < N;i++)
	{
		double x, y, z;
		cin >> x>>y>>z;
		v.push_back(Point(x,y,z));
	}
	double x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	center = Point(abs((x1 + x2) / 2.0), abs((y1 + y2) / 2.0), abs((z1 + z2)/2.0));
	double min = Distance(center, v[0]);
	long longmininde=0;
	for (long longi = 0;i < v.size();i ++)
	{
		double tmp=Distance(center, v[i]);
		if (tmp < min)
		{
			min = tmp;
			mininde = i;
		}
	}
	cout <<fixed<< setprecision(3)<< v[mininde].x<<" "<< v[mininde].y<< " " << v[mininde].z << endl;
	return 0;
}