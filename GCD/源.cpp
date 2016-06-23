#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define mod 1000000007
#define ll long long

int A[1024], B[1024];
int num, num1;

void GCD(int n) {
    num = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
        if ((n % i) == 0) 
		{
            A[num++] = i;
            A[num++] = n / i;	//分解n=i * n / i
            if (n / i == i)
                num--;
        }
    }
    sort(A,A + num);
    num1 = n;
    for (int i = num-1; i >= 0; --i) {
        B[i] = n/A[i];
        for (int j = num-1; j > i ; --j) {
            if(A[j] % A[i] == 0)
                B[i] -= B[j];
        }
        num1 -= B[i];
    }
}

//m的gcd次方
ll MGCD(ll m, int g) {

    ll sum = 1;

    while(g)
	{
        if(g % 2 == 1)
            sum = (sum * m) % mod;
        m = (m * m) % mod;
        g >>= 1;
    }
    sum = sum % mod;
    return sum;
}

int main()
{
    int t, n;
    ll m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n == 1){
			cout << m << endl;
            continue;
        }

        ll r = 0;
        num1 = 1;

        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));

        GCD(n);

        for (int i = 0; i < num; ++i) 
		{
            r = (r + B[i] * MGCD(m, A[i])) % mod;
        }
        r = (r + m * (num1)) % mod;
        r = r % mod;
		cout << r << endl;
    }
    return 0;
}