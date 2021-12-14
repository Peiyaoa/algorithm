//AcWing853
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;


const int N=510,M=10010;
struct edge{
	int a,b,c;
}ed[M];
int d[N],bankrupt[N],n,m,k;

int bellman_ford()
{
	memset(d,0x3f,sizeof d);
	d[1]=0;
	for(int i=0;i<k;i++)
	{
		memcpy(bankrupt,d,sizeof d);
		for(int j=0;j<m;j++)
		{
			auto t=ed[j];
			d[t.b]=min(d[t.b],bankrupt[t.a]+t.c);
		}
	}
	if(d[n]>0x3f3f3f3f/2)
		return 0;
	else
		return d[n];
}
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ed[i]={a,b,c};
	}	
	int t=bellman_ford();
	if(!t)
	{
		puts("impossible");
	}
	else
		cout<<t;
	return 0;
}
