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
ll n, m, t;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    ll arr[n+1];
    for (ll i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    ll dp[n+1];
    dp[1] = 0;
    dp[2] = abs(arr[2] - arr[1]);
    for (ll i = 3 ; i <= n; i++)
    {
        dp[i] = min((dp[i-1] + abs(arr[i] - arr[i-1])), (dp[i-2] + abs(arr[i] - arr[i-2])) );
    }
    cout<<dp[n];
    return 0;
}
