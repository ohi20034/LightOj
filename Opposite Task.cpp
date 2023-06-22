#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

            if(n<=10)
                printf("%d %d\n",0,n);

        else
            printf("10 %d\n",n-10);

    }
    return 0;
}
