#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i)
    {
        int x,y,x2,y2;
        cin >>x>>y>>x2>>y2;
        int n;
        cin>>n;
        cout<<"Case "<<i<<':'<<endl;
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            if((a>x && a<x2) && (b>y&&b<y2))
            {
                printf("Yes\n");
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
}
