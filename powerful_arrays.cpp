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
#define xx first
#define yy second
#define sz(v) int(v.size())
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define INF 0x3fffffff
#define ten9 1000000000
#define mod 1000000007
#define debug(x) cerr<<#x<<" = "<<x<<endl;
using namespace std;

const int max_n = 2e5+10;
int n,t;
ll arr[max_n];
int inside[5*max_n];
ll ans[max_n]; 

struct query
{
	int l,r,in;
};

bool operator<(const query& a, const query& b)
{	return ( a.l/610 < b.l/610 || (a.l/610==b.l/610 && a.r<b.r) );	}

query q[max_n];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> t;
	forr(i,0,n-1)
		cin >> arr[i];

	forr(i,0,t-1)
	{
		cin >> q[i].l >> q[i].r , q[i].in = i;
		q[i].l--;
		q[i].r--;
	}
	
	sort(q,q+t);
	int currL = q[0].l;
	int currR = q[0].l;
	inside[arr[currR]]++;
	ll val = arr[currR];
	forr(i,0,t-1)
	{
		while(currL < q[i].l)
		{
			ll x=inside[arr[currL]]--;
			val += -2*x*arr[currL] + arr[currL];
			currL++;
		}
		while(currL > q[i].l)
		{
			currL--;
			ll x=inside[arr[currL]]++;
			val += 2*x*arr[currL] + arr[currL];
		}
		while(currR < q[i].r)
		{
			currR++;
			ll x=inside[arr[currR]]++;
			val += 2*x*arr[currR] + arr[currR];
		}
		while(currR > q[i].r)
		{
			ll x=inside[arr[currR]]--;
			val += -2*x*arr[currR] + arr[currR];
			currR--;
		}
		ans[q[i].in]=val;
	}
	forr(i,0,t-1)
		cout<<ans[i]<<"\n";

	return 0;
}