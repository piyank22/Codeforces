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
using namespace std;

const int max_n = 2e5+10;
map< int,vi > power;
pii socket[max_n];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin >> n >> m;
	forr(i,1,n)
	{
		int temp;
		cin >> temp;
		power[temp].pb(i);
	}

	forr(j,1,m)
	{
		int temp;
		cin >> temp;
		socket[j] = {temp,j};
	}

	sort(socket+1,socket+m+1);
	vi a(m+1,0) , b(n+1,0);
	int connected_comp = 0 , adap_need = 0;
	forr(i,1,m)
	{
		int socket_number = socket[i].yy;
		int socket_power = socket[i].xx;
		int cnt=0;
		while(1)
		{
			if( sz(power[socket_power]) )
			{
				int comp = power[socket_power].back();
				power[socket_power].pop_back();
				a[socket_number] = cnt;
				adap_need += cnt;
				connected_comp++ ;
				b[comp] = socket_number;
				break;
			}
			cnt++;
			if(socket_power==1) break;
			socket_power = (socket_power+1)>>1;
		}
	}

	cout << connected_comp <<" "<<adap_need<<"\n";
	forr(i,1,m)
		cout<<a[i]<<" \n"[i==m];

	forr(i,1,n)
		cout<<b[i]<<" \n"[i==n];
	return 0;
}