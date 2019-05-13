#include<bits/stdc++.h>
using namespace std;
int color[55];
int n,m,e;
bool visit[55];
vector<int>vi[55];
int main()
{
    int t,i,u,v;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&n,&m,&e);
        memset(color,0,sizeof(color));
        memset(visit,false,sizeof(visit));
        for(i=0;i<55;i++) vi[i].clear();
        for(i=0; i<e; i++)
        {
            scanf("%d %d",&u,&v);
            vi[u].push_back(v);
            vi[v].push_back(u);
        }

        int j,k,cnt_vertex=0,c;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<vi[i].size(); j++)
            {
                v = vi[i][j];
                visit[color[v]]=true;
            }
            bool notgiven=false;
            for(c=1; c<=m; c++)
            {
                if(visit[c]==false && !notgiven)
                {
                    color[i]=c;
                    cnt_vertex++;
                    notgiven=true;
                }
                if(visit[c]==true)
                {
                    visit[c]=false;
                }
            }
        }
        if(cnt_vertex==n)
        {
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }

    return 0;
}
