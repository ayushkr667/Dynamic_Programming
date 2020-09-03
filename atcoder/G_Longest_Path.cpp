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
vector<int> arr[100001];
int max_edge[100001];
int dfs(int node)
{
    if(max_edge[node] != -1)
    {
        return max_edge[node];
    }

    int temp = 0;
    vector<int>:: iterator it;
    for(it = arr[node].begin(); it!=arr[node].end(); it++)
    {
        temp = max(temp, dfs(*it));
    }

    max_edge[node] = 1 + temp;
    return max_edge[node];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;   cin>>n>>m;
    while (m--)
    {
        int a, b;   cin>>a>>b;    arr[a].pb(b);
    }
    memset(max_edge, -1, sizeof(max_edge));

    int vertices  = 0;

    for (int i = 1; i <= n; i++)
    {
        vertices = max(vertices, dfs(i));
    }
    cout<<vertices-1;
    return 0;
}
