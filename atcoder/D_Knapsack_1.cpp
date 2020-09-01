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

ll weigh[101], val[101];
ll dp[101][100001];

// memoization
// ll solve(ll n, ll w)
// {
//     if(w == 0)
//         return 0;
//     if(n == 0)
//         return 0;

//     if(dp[n][w] != -1)
//         return dp[n][w];
    
//     if(weigh[n] > w)
//         return dp[n][w] = solve(n-1, w);

//     else
//     {
//         return dp[n][w] = max( (val[n] + solve(n-1, w-weigh[n])), solve(n-1, w));
//     }    
// }

//tabulation
ll solve(ll n, ll w)
{
    for (ll i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    
    for (ll i = 0; i <= w; i++)
    {
        dp[0][i] = 0;
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= w; j++)
        {
            if(weigh[i] > j)
            {
                dp[i][j] = dp[i-1][j];
            }

            else
            {
                dp[i][j] = max( (val[i] + dp[i-1][j-weigh[i]]), dp[i-1][j]);
            }  
        } 
    }  
    return dp[n][w];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    ll w, n;
    cin>>n>>w;
    for (ll i = 1; i <= n; i++)
    {
        cin>>weigh[i]>>val[i];
    }
    cout<<solve(n, w);
    return 0;
}
