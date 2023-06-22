#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        int n;cin>>n;
        int ar[n],sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
            if(ar[i]>=0){
            sum+=ar[i];
            }
        }
       // if(a)
        cout<<"Case "<<i<<": "<<sum<<endl;
        i++;
    }
}
