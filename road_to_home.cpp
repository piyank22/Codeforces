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
const int max_n = 1e5+7;
ll arr[max_n];
pair< int,int > dp[max_n] ; // xx is the count and yy is the endtime 
int L,n,p,t;

pair<int,int> get_best ( pair<int,int> a , pair<int,int> b )
{
	if( a.xx > b.xx || (a.xx==b.xx && a.yy < b.yy ) )
		return a;
	else return b;
}

int main()
{
	cin >> L >> n >> p >> t;
	int pos = 1;
	dp[0].xx=0;
	dp[0].yy=-t;
	
	forr(i,1,n)
	{
		pos--;
		int l,r;
		cin >> l >> r;
		while( pos < i && dp[pos].yy + t < r )
		{
			int st = max( l , dp[pos].yy + t );
			int songs = (r-st)/p;
			int en = songs*p + st;
			dp[i] = get_best( dp[i] , mp(dp[pos].xx+songs,en) );
			pos++;
		}
		dp[i] = get_best( dp[i] , dp[i-1] );
	}
	cout<<dp[n].xx;
	return 0;
}