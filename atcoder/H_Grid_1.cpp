/*-------------------------------*
| Name: Ayush Kumar              |
| Site: CSES                     |
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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
ll dp[1001][1001]; 

int main()
{
    int h, w;
    cin >> h >> w;
    string a[h];
    for(int i=0; i<h; i++)
        cin >> a[i];

    dp[1][1]=1;
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(a[i-1][j-1] == '.')//is cell i, j
                dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[i][j-1]) % mod;
            else
                dp[i][j] = 0;
        }
    }
    cout << dp[h][w] << endl;
    return 0;
}
