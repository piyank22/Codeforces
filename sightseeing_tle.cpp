#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>

#define PI acos(-1)
#define ll long long
#define llu long long unsigned
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define sz(v) int(v.size())
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
# define INF 0x3f3f3f3f

using namespace std;

vector< pair<int,int> > *adj;

int graph_shortest_dist(int src,int f,int n)
{
	set< pair<int, int> > setds;
	vector<int> dist(n+1, INF);
	setds.insert(make_pair(0, src));
    dist[src] = 0;
    while (!setds.empty())
    {
    	pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        vector< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
        	int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
            	if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist[f];
}

void AllPathsUtil(int u , int f , vector<bool> &visited , vector<int> &path , int dis , int &ans)
{
	visited[u] = true ;
	path.pb(u);

	if(u==f)
		ans++;
	else
	{
		vector< pair<int,int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[i->first] && dis-(i->second)>=0)
                AllPathsUtil(i->first, f, visited, path, dis-(i->second) , ans);
	}

	visited[u] = false ;
	path.pop_back();
}

int count_all_paths(int s,int f,int dis,int n)
{
	vector<bool> visited(n+1,false);
    vector<int> path;
    int ans=0;
    AllPathsUtil(s, f, visited, path, dis, ans);
    return ans;
}

int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		int n,m;
		cin >> n >> m ;
		adj = new vector< pair<int,int> >[n+1];
		forr(i,1,m)
		{
			int u,v,l;
			cin >> u >> v >> l;
			adj[u].pb( mp(v,l) );
		}
		int s,f;
		cin >> s >> f;
		int sh_ans = graph_shortest_dist(s,f,n);

		// now dfs
		cout<<count_all_paths(s,f,sh_ans+1,n)<<endl;
	}
	return 0;
}