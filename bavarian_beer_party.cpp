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
#define INF 0x3f3f3f3f

using namespace std;

int arr[1010];
int dp[1010][1010];

int solve(int s,int e)
{
	if(s>=e)
		return 0;
	if(dp[s][e]!=-1)
		return dp[s][e];
	
	int ans=0;
	for(int i=s+1;i<=e;i+=2)
		ans = max( ans , (arr[s]==arr[i]) + solve(s+1,i-1) + solve(i+1,e) );

	dp[s][e]=ans;
	return ans;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		forr(i,0,1005) forr(j,0,1005) dp[i][j] = -1;
		int p;
		cin>>p;
		forr(i,1,p)
			cin>>arr[i];
		cout<<solve(1,p)<<endl;
	}
	return 0;
}