#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c=1;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        int ar[n+4];
        for(int i=1; i<=n; ++i)
        {
            cin >> ar[i];
        }
        printf("Case %d:\n",c);
        for(int f=0; f<q; ++f)
        {
            int ak,bk;
            scanf("%d%d",&ak,&bk);
            int i = lower_bound(ar+1,ar+n+1,ak) - ar;
            int j = upper_bound(ar+1,ar+n+1,bk) - ar;
            printf("%d\n",j-i);
        }
        c++;
    }
}
