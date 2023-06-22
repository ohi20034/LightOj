#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i)
    {
        int n;
        cin >> n;
        int a[n+4];
        for(int i=0; i<n; ++i)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        int ans = 0;
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                int sum = a[i]+a[j];
                int check = upper_bound(a,a+n,sum-1)-a;
                check--;
                if(check > j)
                {
                    ans += check-j;
                }
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
}
