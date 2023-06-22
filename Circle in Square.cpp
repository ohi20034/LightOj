#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        double n,ans;
        cin>>n;
        double a = ((2*n)*(2*n));
        double b = (3.14159265359*n*n);
        ans = (a-b)+10e-9;
        printf("Case %d: %.2lf\n",i,ans);
        i++;
    }
}

