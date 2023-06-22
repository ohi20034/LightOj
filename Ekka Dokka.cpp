#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        long long n;
        cin >> n;
        cout << "Case " << i << ": ";
        if (n % 2)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            long long a = n/2;
            long long b = 2;
            while(a%2==0)
            {
                a = a/2;
                b *= 2;
            }
            cout<<a <<' '<<b<<endl;
        }
    }
}
