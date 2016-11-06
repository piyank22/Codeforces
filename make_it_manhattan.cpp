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

int x[1010];
int y[1010];

int main()
{
	int t;
	cin >> t ;
	map< int,set<int> > mx,my;
	while(t--)
	{
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		int d,n;
		cin >> d >>n;
		mx.clear();
		my.clear();
		forr(i,1,n)
		{
			int t1,t2;
			cin >> t1 >> t2 ;
			t1 = (t1%d+d)%d;
			t2 = (t2%d+d)%d;

			x[t1]++;
			y[t2]++;

			mx[t1].insert(i);
			my[t2].insert(i);
		}

		int m1=x[0];
		int x1=0;
		int m2=y[0];
		int y1=0;
		forr(i,1,d-1)
		{
			if(m1>x[i])
			{
				m1=x[i];
				x1=i;
			}
			if(m2>y[i])
			{
				m2=y[i];
				y1=i;
			}
		}
		my[y1].insert(mx[x1].begin(),mx[x1].end());
		cout<<sz(my[y1])<<endl;
	}
	return 0;
}