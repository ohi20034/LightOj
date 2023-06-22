#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000;
const int N = 10000000;
bool prime[MAX+5];
vector<int>primes;
void sieve()
{
    memset(prime, true, sizeof prime);

    prime[1] = false;

    for(int i=2; i*i<=MAX; ++i)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                prime[j] = false;
            }
        }
    }
    for(int i=0; i<N; ++i)
    {
        if(prime[i])
        {
            primes.push_back(i);
        }
    }
}
int main()
{
    sieve();
    int t;
    cin >> t;
    for(int i=1; i<=t; ++i)
    {
        int n;
        cin >> n;
        printf("Case %d: ",i);
        int ans = 0;
        for(int j=0; primes[j] <= n/2; j++)
        {
            int a = n -  primes[j];
            int b = primes[j];
            if(prime[a] && prime[b])
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
