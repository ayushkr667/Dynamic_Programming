/*-------------------------------*
| Name: Ayush Kumar              |
| College: SOE, CUSAT            |
| Dept: CSE                      |
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

ll arr[501][501];//adjacency matrix 
ll dist[501][501]; //it will hold result finally
ll n;
void floydwarsalls()
{
    for (ll i = 1  ; i <=n ; i++)
        for (ll j = 1; j <= n; j++)
            dist[i][j] = arr[i][j];

    //set all the vertices as intermediate between every other two
    for (ll k = 1; k <=n ; k++)
    {
        //pick source vertices
        for (ll i = 1; i <=n; i++)
        {
            //pick destination
            for (ll j = 1; j <= n; j++)
            {
                //update min of i to j and i to j via k
                dist[i][j] =  min(dist[i][j], (dist[i][k] + dist[k][j]));
            }  
        } 
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll  m, q;//q is nimber of queries // is no of edge
    cin>>n>>m>>q;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            arr[i][j] = INF;
        }  
        arr[i][i] = 0;
    }
    
    while (m--)
    {
        ll a, b, w;
        cin>>a>>b>>w;
        arr[a][b] = min(arr[a][b], w);
        arr[b][a] = min(arr[b][a], w);
    }

    floydwarsalls();//pre process to get all pair sortest path

    while (q--)
    {
        ll u, v;
        cin>>u>>v;
        if(dist[u][v] == INF)
        {
            cout<<"-1\n"; continue;
        }
        cout<<dist[u][v]<<"\n";
    }
    
    return 0;
}
