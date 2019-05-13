#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll>vi;
void precalculate()
{
    ll i,sum=0,digit,k,r,sub,n,j;
    for(i=1;i<=31268;i++)
    {
       for(j=1;j<=i;j++)
       {
           //getchar();
          // cout<<"value of j : "<<j<<endl;
           n =j;
           digit = floor(log10(n))+1;
           //cout<<"digit : "<<digit<<endl;
           k =1;
           while(n!=0)
           {
               r = n/powl(10,digit-k);
               sub = powl(10,digit-k);
               //cout<<
               n-=(r*sub);
               //cout<<"value of r : "<<r<<endl;
               vi.push_back(r);
               k++;
           }
       }
    }
}

int main()
{
   // freopen("output.txt","w",stdout);
    precalculate();
    ll t,lb;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        cout<<vi[n-1]<<endl;
//
//        lb= lower_bound(vi.begin(),vi.end(),n)-vi.begin();
//        if(lb-1>=0)
//        {
//            for(i=vi[lb-1],j=1;i<=n;i++,j++)
//            {
//
//            }
//            cout<<(n-vi[lb-1])<<endl;
//        }
//        else if(lb-1<0){
//            cout<<n<<endl;
//        }
    }
    return 0;
}
