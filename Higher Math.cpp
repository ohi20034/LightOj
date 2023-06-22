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
        int a,b,c,f;
        cin>>a>>b>>c;
        long long n1=a*a,n2=b*b,n3=c*c;

        if(n1==n2+n3||n2==n1+n3||n3==n1+n2)
        {
            cout<<"Case "<<i<<": "<<"yes"<<endl;
        }
        else
        {
            cout<<"Case "<<i<<": "<<"no"<<endl;
        }
        i++;
    }
return 0;
}
