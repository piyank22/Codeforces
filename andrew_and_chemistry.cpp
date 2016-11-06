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
#define INF 0x3fffffff
#define ten9 1000000000
using namespace std;

const int max_n=1e5+7;

vector<int> adj[max_n];
map<int,int> memo[max_n];
map< vector<int> , int > m;
int cnt=1;

int dfs(int u, int p=0)
{
	if(memo[u][p]) return memo[u][p];

	vector<int> temp;
	forr(i,0,sz(adj[u])-1)
		if( adj[u][i] != p )
			temp.pb( dfs(adj[u][i],u) ); 

	sort(temp.begin() , temp.end() );
	if( m[temp] == 0 )	m[temp] = cnt++;
	
	return memo[u][p] = m[temp] ;
}

int main()
{
	int n;
	cin >> n;
	forr(i,1,n-1)
	{
		int u , v ;
		cin >> u >> v ;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	set<int > se;
	forr(i,1,n)
		if( sz(adj[i]) < 4 )
			se.insert( dfs(i) );

	cout << sz(se) << endl ;
	return 0;
}