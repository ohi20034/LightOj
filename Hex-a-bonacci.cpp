#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n;
    scanf("%lld",&t);
    for (int cs = 1; cs <= t; cs++) {
        long long h[10009];
        scanf("%lld %lld %lld %lld %lld %lld %lld",&h[0],&h[1],&h[2],&h[3],&h[4],&h[5],&n);
        for (int i =6; i <= n; ++i) {
            h[i] =( h[i-1]+h[i-2]+h[i-3]+h[i-4]+h[i-5]+h[i-6] ) %10000007;
        }
        printf("Case %d: %lld\n",cs,h[n] % 10000007);
    }

    return 0;
}
}
