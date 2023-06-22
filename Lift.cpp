#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int l=(abs(b-a))+a;
        int ans = (l*4);
        int ans1=ans+16+3;
        cout<<"Case "<<i<<": "<<ans1<<endl;
        i++;
    }
}
