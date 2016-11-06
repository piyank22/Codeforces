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
#define endl '\n'
#define ll long long
#define llu long long unsigned
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(v) int(v.size())
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define INF 0x3fffffff
#define ten9 1000000000
#define mod 1000000007
#define trace1(x) cerr<<#x<<" = "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<endl;

using namespace std;
const int max_n = 2e5+10;
vi adj[max_n];
int c[max_n];
map<int,int> mpa;
bool visited[max_n];

void dfs(int i)
{
	visited[i]=true;
	mpa[c[i]]++;
	for( auto j: adj[i]) if(!visited[j]) dfs(j);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,k;
	cin >> n >> m >> k;
	forr(i,1,n)
		cin >> c[i];

	forr(i,1,m)
	{
		int u,v;
		cin >> u >> v;
		adj[u].eb(v);
		adj[v].eb(u);
	}

	int ans=0;
	forr(i,1,n)
	{
		if(!visited[i])
		{
			dfs(i);
			int local_max=0;
			int local_sum=0;
			for( auto x: mpa)
			{
				local_max = max(local_max,x.yy);
				local_sum += x.yy;
			}
			ans += local_sum - local_max;
			mpa.clear();
		}
	}
	cout<<ans;
	return 0;
}