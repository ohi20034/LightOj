#include <bits/stdc++.h>
using namespace std;
const long long N=1e18;
long long cntZero(long long num)
{
    long long zero = 0;
    for(long long i=5; i <= num; i*= 5)
    {
        zero += (num/i);
    }
    return zero;
}
int main()
{
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i)
    {
        long long n;
        cin >> n;

        printf("Case %d: ",i);
        long long low = 1, high = N , ans=-1;
        while(low <= high)
        {
            long long mid = ( low + high ) /2;
            long long totalzero = cntZero(mid);
            if(totalzero > n){
                high = mid-1;
            }
            else if(totalzero < n)
            {
                low = mid +1;
            }
            else
            {
                ans = mid;
                high = mid-1;

            }
        }
        if(ans == -1){
            printf("impossible");
        }
        else{
            printf("%lld",ans);
        }
        printf("\n");
    }
}
