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
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )

using namespace std;

int solve(int n,int m)
{
	if(n==m)
		return 0;
	else
	{
		if(m%2==1)
			return 1+solve(n,m+1);
		else
		{
			if( n < m )
				return 1+solve(n,m/2);
			else
				return 1+solve(n,m+1);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m ;
	cout<<solve(n,m);
	return 0;
}