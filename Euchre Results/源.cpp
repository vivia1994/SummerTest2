/*Description
Anna, Betty, Cindy and Zelda like playing the card game Euchre. Euchre is a game for two teams of two, and each time they meet the girls split off into different teams. They also keep overall records of the number of games each player has won and lost. Anna has misplaced her won-loss results, but she does have the results of the other three players. Given this, she figures she can determine her won-loss record
Input
Input will consist of multiple problem instances. Each instance will consist of a single line containing six integers. The first two are the number of wins and losses (respectively) for Betty, the next two are the number of wins and losses for Cindy and the last two are the number of wins and losses for Zelda.

A final line of six zeroes will terminate input and should not be processed.

Output
For each problem instance, output a single line indicating Anna's won-loss record, in the format shown in the example below.*/
#include<iostream>
#include<vector>
using namespace std;

long longmain()
{

	long longa, b;
	while (cin >> a >> b && (a +b )> 0)
	{
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		for (long longi = 0;i < 4;i++)
		{
			long longtmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		long longwon=0, loss=0;
		for (long longi = 0;i < v.size();i+=2)
		{
			loss += v[i];
			loss -= v[i + 1];
		}
		won = (v[0] + v[1] - loss) / 2;
		loss += won;
		cout << "Anna's won-loss record is " << won << "-" << loss << "." << endl;
	}
	return 0;
}