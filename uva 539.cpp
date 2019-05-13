#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>vi[30];
//bool node[30];
map<pair<int,int>,bool>mb;

int maxn=0;
void backtracking(int u,int path)
{

    int i;
    for(i=0;i<vi[u].size();i++)
    {
        int v = vi[u][i];
        if((mb.find(make_pair(u,v))==mb.end() && mb.find(make_pair(v,u))==mb.end()) || (mb[make_pair(u,v)] == false && mb[make_pair(v,u)]== false) ){

            mb[make_pair(u,v)]=true;
            mb[make_pair(v,u)]=true;

            path+=1;
            //node[v]=true;
            backtracking(v,path);
            maxn=max(path,maxn);
            //cout<<path<<endl;
            path-=1;
            mb[make_pair(u,v)]=false;
            mb[make_pair(v,u)]=false;
        }
    }
}
int main()
{
    int i,u,v;
    while(scanf("%d %d",&n,&m)==2)
    {
        maxn=0;
        if(n==0 && m==0) return 0;
        else{
            for(i=0;i<30;i++)
                vi[i].clear();
            mb.clear();
            for(i=0;i<m;i++)
            {
                scanf("%d %d",&u,&v);
                vi[u].push_back(v);
                vi[v].push_back(u);
            }
        memset(node,false,sizeof(node));
            for(i=0;i<n;i++){
               // if(node[i]==false){
                        node[i]=true;
                    backtracking(i,0);
               // }
            }
            cout<<maxn<<endl;
        }
    }
    return 0;
}
