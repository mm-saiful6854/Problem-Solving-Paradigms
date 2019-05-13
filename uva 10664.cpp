#include<bits/stdc++.h>
#define M 1200
using namespace std;
typedef long long ll;


vector<ll>p;
ll dp[1200][200][20];
bool vis[M+5];

ll n,k,end_;

void seive(void)
{
    vis[0]=1;
    vis[1]=1;
    vis[2]=0;
    p.push_back(2);
    for(int i=4; i<=M; i+=2)vis[i]=1;

    for(int i=3; i*i<=M; i+=2)
    {
        if(vis[i]==0)
        {
            for(int j=i*i; j<=M; j+=2*i)
            {
                vis[j]= 1;
            }
        }
    }

    for(int i=3; i<=M; i+=2)if(vis[i]==0)p.push_back(i);
}

ll call(ll val,ll index,ll cnt)
{


   //cout<<val<<" "<<index<<" "<<cnt<<endl;

    if(val==0 && cnt==k)
    {
        return 1;
    }
    if(cnt>k){

            return 0;

    }
    if(index>end_)return 0;

    if(dp[val][index][cnt]!= -1) {

            return dp[val][index][cnt];
    }


    ll p1 = 0 , p2 = 0;
    if(val-p[index]>=0)
    {
        p1 = call(val-p[index],index+1,cnt+1);

    }
    p2 = call(val,index+1,cnt);



    return dp[val][index][cnt]=(p1+p2);

}
int main()
{

    seive();


    while(cin>>n>>k){
    if(n==0 && k==0)return 0;

    end_= lower_bound(p.begin(),p.end(),n)-p.begin();
    end_++;
    memset(dp,-1,sizeof(dp));

    cout<<call(n,0,0)<<endl;
    }
    return 0;

}
