#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll num[103];
ll dp[50004];
int main()
{
  ll t,n,i,j,sum=0;
  scanf("%lld",&t);
  while(t--)
  {
      memset(dp,0,sizeof(dp));
      sum=0;
      scanf("%lld",&n);
      for(i=0;i<n;i++)
      {

          scanf("%lld",&num[i]);
          sum+=num[i];

      }
      dp[0]=1;
      for(i=0;i<n;i++)
      {
          for(j=sum;j>=0;j--){
            if(j>=num[i] && dp[j-num[i]])
            {
                dp[j]=1;
            }
          }
      }

      for(i = sum/2;!dp[i];i--);
      ll p1 = i;
      ll p2= sum-i;
      cout<<abs(p2-p1)<<endl;
  }
  return 0;
}
