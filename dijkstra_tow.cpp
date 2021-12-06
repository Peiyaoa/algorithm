//Acwing 850
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<utility>

using namespace std;
typedef pair<int,int> PII;
const int N=1500000;
priority_queue<PII,vector<PII>,greater<PII>> q;

int idx,h[N],ne[N],e[N],v[N],d[N];
bool st[N];

void add(int a,int b,int x)
{
    e[idx]=b;
    ne[idx]=h[a];
    v[idx]=x;
    h[a]=idx++;
}
int n,m;
int dijkstra()
{
    memset(d,0x3f,sizeof d);
    q.push({0,1});
    d[1]=0;
    
    while(q.size())
    {
        auto t=q.top();
        q.pop();
        int j=t.second;
        if(st[j])
            continue;
        st[j]=true;
        
        for(int i=h[j];i!=-1;i=ne[i])
        {
            int k=e[i];
            if(d[k]>d[j]+v[i])
            {
                d[k]=d[j]+v[i];
                q.push({d[k],k});
            }
        }
        
    }
    if(d[n]==0x3f3f3f3f)
        return -1;
    else
        return d[n];
}

int main()
{

    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++)
    {
        int a,b,x;
        cin>>a>>b>>x;
        add(a,b,x);
    }
    cout<<dijkstra();
    return 0;
}
