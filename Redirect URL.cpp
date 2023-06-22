#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
   int j=1;
    while(t--)
    {
        string s;
        cin>>s;
        int a=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==':')
                break;
            else
                a++;
        }

        if(a==4)
        {
            printf("Case %d: https://",j);
            for(int i=7; i<s.size(); i++)
            {
                printf("%c",s[i]);
            }
            cout<<endl;

        }
        else
        {
            cout<<"Case "<<j<<": "<<s<<"\n";

        }
        j++;
    }
}
