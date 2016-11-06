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

ll arr[100010];
int main()
{
	ll n,m;
	cin >> n >> m;
	forr(i,1,n)
	{
		ll temp;
		cin >> temp;
		arr[i] = arr[i-1]+temp;
	}
	ll d=m;
	forr(i,1,m)
	{
		ll temp;
		cin >> temp;
		d += temp;
	}
	int start = d-1 , end = n+1;
	while( end-start > 1 )
	{
		int mid = (start + end )>>1;
		if( arr[mid] >= m)
			end = mid;
		else
			start = mid;
	}
	while( arr[end]-arr[end-1] == 0 && end <= n+1 ) end++;
	if(end>=n+1)
		cout<<"-1";
	else
		cout<<end;
	return 0;
}