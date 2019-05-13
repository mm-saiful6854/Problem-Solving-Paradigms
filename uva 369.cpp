#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[103][103];
ll n,m;
ll nCr(ll n,ll m)
{
    if(n==m) return 1;
    else if(m==1) return n;
    if(dp[n][m]!=0) return dp[n][m];
    dp[n][m]= nCr(n-1,m-1) + nCr(n-1,m);
    printf("%lld\n",dp[n][m]);
    return  dp[n][m];

}
int main()
{
    string s;
    while(getline(cin,s))
    {

        stringstream ss;
        ss<<s;
        ss>>n;
        ss>>m;

        if(n==0 && m==0) break;
        else{
           //memset(dp,0,sizeof(dp));
           ll ans= nCr(n,m);
            printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,ans);

        }
    }

    return 0;
}
