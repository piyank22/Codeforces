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
const int max_n = 5005;

int u[max_n] , v[max_n] , w[max_n] , dp[max_n][max_n] , parent[max_n][max_n] ;
int path[max_n] ;
int main()
{
	// dp[i][j] denotes the minimum time taken to reach j for 1 going through
	// i many points

	memset(dp,0x3f,sizeof(dp)); // each bit of int is set to 3f
								// so dp is set as 3f3f3f3f which
								// which is more than 1e9
	dp[1][1]=0;
	int n, m , t;
	cin >> n >> m >> t;
	forr(i,0,m-1)
		cin >> u[i] >> v[i] >> w[i] ;

	int places ; 
	forr(i,2,n)
	{
		forr(j,0,m-1)
		{
			if( dp[i-1][ u[j] ] + w[j] < dp[i][ v[j] ] )
			{
				dp[i][ v[j] ] = w[j] + dp[i-1][ u[j] ] ;
				parent[i][ v[j] ] = u[j] ;
			}
		}
		if( dp[i][n] <= t ) places = i;
	}

	int id = n;
	rof(i,places,1)
	{
		path[i] = id;
		id = parent[i][id] ;
	}

	cout << places << endl;
	forr(i,1,places)
		cout << path[i] << " ";
	return 0;
}