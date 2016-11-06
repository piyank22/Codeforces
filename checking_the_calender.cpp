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
	string s1;
	int i1,i2;
	cin>>s1;
	if(s1=="monday")
		i1=0;
	else if(s1=="tuesday")
		i1=1;
	else if(s1=="wednesday")
		i1=2;
	else if(s1=="thursday")
		i1=3;
	else if(s1=="friday")
		i1=4;
	else if(s1=="saturday")
		i1=5;
	else
		i1=6;

	i2=i1;

	cin>>s1;
	if(s1=="monday")
		i1=0;
	else if(s1=="tuesday")
		i1=1;
	else if(s1=="wednesday")
		i1=2;
	else if(s1=="thursday")
		i1=3;
	else if(s1=="friday")
		i1=4;
	else if(s1=="saturday")
		i1=5;
	else
		i1=6;

	if( (i2+2)%7==i1 || (i2+3)%7==i1 || i1==i2)
		cout<<"Yes\n";
	else 
		cout<<"No\n";
	return 0;
}