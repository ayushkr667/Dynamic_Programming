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
int n, m, t;
ll sum = 0;
vector<int>arr[100001];
int dp[100001][3];
int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

ll solve()
{
    dp[1][0] = arr[1][0]; dp[1][1] = arr[1][1]; dp[1][2] = arr[1][2];
    for(int i=2; i <= n; i++)
    {
        dp[i][0] = max( dp[i][0], arr[i][0]+ max( dp[i-1][1] , dp[i-1][2] ));
        dp[i][1] = max( dp[i][1], arr[i][1]+ max( dp[i-1][0] , dp[i-1][2] ));
        dp[i][2] = max( dp[i][2], arr[i][2]+ max( dp[i-1][0] , dp[i-1][1] ));
    }
    return max(dp[n][0], dp[n][1], dp[n][2]);
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin>> a >> b >> c;
        arr[i].pb(a); arr[i].pb(b); arr[i].pb(c);
    }
    cout<<solve();
    return 0;
}
