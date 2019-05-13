#include<bits/stdc++.h>

using namespace std;
int n;
int maze[12][12];

vector<string>solution;
vector<char>res;
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
bool visited[12][12];
bool valid(int i,int j)
{
    if((i>=0 && i<n) && (j>=0 && j<n) && maze[i][j]==1 && visited[i][j]==false) return true;
    return false;
}

void traveling(int i,int j)
{

    if(i==n-1 && j==n-1)
    {
        string s="";
        int k;
        for(k=0;k<res.size();k++)
        {
            s+=res[k];
        }
        solution.push_back(s);
        return ;
    }
    int k,x,y;
    for(k=0;k<4;k++)
    {
        x=i+ di[k];
        y=j+ dj[k];

        if(valid(x,y))
        {
            if(k==0)
                res.push_back('R');
            else if(k==1)
                res.push_back('D');
            else if(k==2)
                res.push_back('L');
            else if(k==3)
                res.push_back('U');
                //cout<<x<<" "<<y<<"k : "<<k<<endl;
            visited[x][y]=true;
            traveling(x,y);
            visited[x][y]=false;
            res.pop_back();
        }
    }
}


int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(),cout.tie();

    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        solution.clear();
        res.clear();
        memset(visited,false,sizeof(visited));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&maze[i][j]);
            }
        }
           // cout<<"out"<<endl;
        visited[0][0] =true;
        traveling(0,0);

        sort(solution.begin(),solution.end());
        int l =solution.size();
        if(l!=0) cout<<solution[0];
        for(i=1;i<l;i++)
            cout<<" "<<solution[i];
            printf("\n");
    }

    return 0;
}
