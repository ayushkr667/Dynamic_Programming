/*-------------------------------*
| Name: Ayush Kumar              |
| Site: atcoder                  |
| Email: ayushkr667@gmail.com    |
*-------------------------------*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define INF (ll) 1e18
const double PI = 3.141592653589793238460;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, k;
    cin>>n>>k;
    ll arr[n+1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    ll dp[n+1];
    dp[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        dp[i] = INF;
        for (ll j = 1; j <= k; j++)
        {
            if( i-j >= 1)
            {
                dp[i] = min(dp[i], (dp[i-j] + abs(arr[i] - arr[i-j])));
            }
        }
    }
    cout<<dp[n];
    return 0;
}
