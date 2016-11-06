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

int main()
{
	ll a , b , c;
	scanf("%I64d %I64d %I64d",&a,&b,&c);
	ll ans = 0;

	if(a==b && b==c)
		ans = 0;
	else if(b==c)
	{
		if(a>b)
			ans = 2*(a-(b+1));
		else
			ans = (b-a-1);
	}
	else if(a==c)
	{
		if(b>a)
			ans = (b-a-1)*2;
		else
			ans = a-b-1;
	}
	else if(a==b)
	{
		if(c>a)
			ans = (c-a-1)*2;
		else
			ans = a-c-1;
	}
	else if(a>b && a>c)
		ans = (a-b-1) + (a-c-1);
	else if(b>a && b>c)
		ans = (b-a-1) + (b-c-1);
	else if(c>a && c>b)
		ans = (c-a-1) + (c-b-1);

	printf("%I64d\n",ans );
	return 0;
}