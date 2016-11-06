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
const int max_n = 2e5+7;
ll arr[max_n];
class cmp
{
public:
	bool operator()(int a,int b)
	{
		return abs( arr[a] ) > abs( arr[b] );
	}
};

int main()
{
	int n , k ;
	ll x;
	cin >> n >> k >> x ;
	int zeros = 0;
	int sign = 1;
	priority_queue< int , vector<int> , cmp > pq;
	forr(i,1,n)
	{
		cin >> arr[i] ;
		if(arr[i]==0) zeros++;
		else if (arr[i]<0) sign *= -1;
		pq.push(i);
	}
	if(zeros<=k) // suppose more zeros than k than we cannot ever come to a situation where we can get a non zero product.. so skip it
	{
		while(k--)
		{
			int in = pq.top();
			pq.pop();
			if(sign==1)
			{
				if(arr[in]>=0)	
				{
					arr[in]-=x;
					if(arr[in]<0)  sign=-1;
				}
				else
				{
					arr[in]+=x;
					if(arr[in]>=0)  sign=-1;
				}
			}
			else
			{
				if(arr[in]>=0) arr[in]+=x;
				else arr[in]-=x;
			}
			pq.push(in);
		}
	}
	forr(i,1,n)
		printf("%I64d ",arr[i] );
	return 0;
}