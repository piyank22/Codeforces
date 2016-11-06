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
#define rep(i,n) for(int i=0 ; i<int(n) ; i++ )
#define INF 0x3fffffff
#define ten9 1000000000
#define mod 1000000007
#define trace1(x) cerr<<#x<<" = "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<endl;

using namespace std;

template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

const int max_n = 1e5+10 , block = 350;
int n,m;
int c[max_n] , col_count[max_n] , number_col_greater[max_n] ;
vi adj[max_n];
vi st,en,col;
struct query
{
	int l,r,k,in;
	bool operator<(const query& a)
	{	return ( (l/block < a.l/block) || (l/block == a.l/block && r < a.r ) );		}
};
query q[max_n];

void dfs(int u,int p)
{
	static int cnt = -1;
	st[u] = ++cnt;
	col[ st[u] ] = c[u];
	for( auto i: adj[u] )
		if(i==p)	continue;
		else dfs(i,u);
	en[u] = cnt;
}

void add_mo(int i)
{
	col_count[col[i]]++;
	number_col_greater[col_count[col[i]]]++;
}

void rem_mo(int i)
{
	number_col_greater[col_count[col[i]]]--;
	col_count[col[i]]--;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	forr(i,0,n-1) cin>>c[i];
	forr(i,1,n-1)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].eb(v);
		adj[v].eb(u);
	}

	st = vi(n) , en = vi(n) , col = vi(n);
	dfs(0,-1);

	forr(i,1,m)
	{
		int v,k;
		cin >> v >> k;
		v--;
		q[i].l = st[v] , q[i].r = en[v] , q[i].k = k , q[i].in = i; 
	}
	sort(q+1,q+m+1);
	int currL = q[1].l;
	int currR = q[1].l-1;

	int ans[max_n];
	forr(i,1,m)
	{
		while( currR < q[i].r ) add_mo(++currR);
		while( currR > q[i].r ) rem_mo(currR--);
		while( currL < q[i].l ) rem_mo(currL++);
		while( currL > q[i].l ) add_mo(--currL);
		ans[q[i].in] = number_col_greater[q[i].k];
	}
	forr(i,1,m) cout<<ans[i]<<"\n";

	return 0;
}