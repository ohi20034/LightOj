#include<bits/stdc++.h>
#define  ll      long long
#define  pb      push_back
#define  F       first
#define  S       second
#define  Endl    "\n"
#define  Cin     scanf
#define  Cout    printf
using namespace std;

int dc(int n)
{
    int temp,base=1,lst,dec=0,i=0;
    temp = n;
    while(temp)
    {
        lst = temp%10;
        temp = temp / 10;
        dec+=lst * pow(2,i);
        i++;
    }
    return dec;
}
int main()
{
    int t;
    cin>>t;
    int a,b,c,d;
    char x,y,z;
    int aa,bb,cc,dd;
    char xx,yy,zz;
    int  i=1;
    while(t--)
    {

        Cin("%d%c%d%c%d%c%d",&a,&x,&b,&y,&c,&z,&d);
        Cin("%d%c%d%c%d%c%d",&aa,&xx,&bb,&yy,&cc,&zz,&dd);

        int ans1=dc(aa);int ans2=dc(bb);int ans3=dc(cc);int ans4=dc(dd);

        if(ans1!=a || ans2 != b || ans3!= c || ans4!=d)
        {
            Cout("Case %d: No\n",i);
            i++;
        }
        else
        {
            Cout("Case %d: Yes\n",i);
            i++;
        }
    }
}
