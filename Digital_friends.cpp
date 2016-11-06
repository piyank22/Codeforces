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

using namespace std;

int p[10];
int q[10];


bool check_equal()
{
	forr(i,0,9)
		if( p[i]*q[i]==0 && p[i]+q[i]!=0 )
			return false;
	return true;
}

bool check(string a, int p[])
{
	bool almost=false;
	forr(i,0,sz(a)-2)
	{
		if(!( a[i]=='0' || a[i+1]=='9' || (a[i]=='1' && i==0) ))
		{
			p[a[i]-'0']--;
			p[a[i]-'0'-1]++;
			p[a[i+1]-'0']--;
			p[a[i+1]-'0'+1]++;
			if(check_equal())
				almost=true;
			p[a[i]-'0']++;
			p[a[i]-'0'-1]--;
			p[a[i+1]-'0']++;
			p[a[i+1]-'0'+1]--;
		}
		if( a[i]!='9' && a[i+1]!='0' )
		{
			p[a[i]-'0']--;
			p[a[i]+1-'0']++;
			p[a[i+1]-'0']--;
			p[a[i+1]-1-'0']++;
			if(check_equal())
				almost=true;
			p[a[i]-'0']++;
			p[a[i]+1-'0']--;
			p[a[i+1]-'0']++;
			p[a[i+1]-1-'0']--;
		}
		if(almost==true)
			return true;
	}
	return false;
}


int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		string a,b;
		cin >> a >> b ;
		forr(i,0,sz(a)-1)
			p[a[i]-'0']++;

		forr(j,0,sz(b)-1)
			q[b[j]-'0']++;

		if(check_equal())
			cout<<"friends\n";
		else
		{
			if(check(a,p)||check(b,q))
				cout<<"almost friends\n";
			else
				cout<<"nothing\n";
		}
	}
	return 0;
}