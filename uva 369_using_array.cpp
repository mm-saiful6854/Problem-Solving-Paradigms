#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll n,m;
ll up[103];
ll r[103];
ll dp[103][103];

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
        if(dp[n][m]!=0)
        {
             printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,dp[n][m]);
             continue;
        }

        ll mm=m;
        if(m > n-m) m = n-m;

        ll rr=1,ans=1,i;
        for(i=1; i<=m; i++)
        {
                    ans*=n-m+i;
                    ans/=i;
        }
        dp[n][m]=ans;
        printf("%llu things taken %llu at a time is %llu exactly.\n",n,mm,ans);
    }

    return 0;

}
