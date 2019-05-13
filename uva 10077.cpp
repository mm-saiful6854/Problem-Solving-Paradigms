#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll compare(ll x,ll y,ll n,ll m)
{
    if(x==n && y==m) return 0;
    else
    {
        return (x*m<y*n)? 1:-1;
    }
}
int main()
{
    ll n,m,a,b,c,d,x,y,decision;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        if(n==1 && m==1) break;
        else
        {
            a=0,b=1,c=1,d=0;
            while(1)
            {

                 x= a+c;
                 y= b+d;
                 decision = compare(x,y,n,m);
                if(decision==0) break;
                if(decision==1)
                {
                    printf("R");
                    a=x;
                    b=y;
                }
                else if(decision==-1)
                {
                    printf("L");
                    c=x;
                    d=y;
                }
            }
            printf("\n");

        }
    }
    return 0;
}
