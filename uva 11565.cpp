#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c;
bool fun(ll mid,ll x,ll y)
{
    if(mid!=x && mid!=y && x+y+mid==a && x*x+y*y+mid*mid==c && x*y*mid==b){
        return true;
    }
    else{
        return false;
    }
}

ll binary(ll x,ll y)
{
    ll lo =1,hi=2449489743,ans=0,mid;
    //cout<<x<<" "<<y<<endl;
  //  cout<<lo<<" "<<hi<<endl;

    while(lo<=hi)
    {
        mid = lo +(hi-lo)/2;
        //cout<<mid<<endl;
        if(fun(mid,x,y))
        {
            ans = mid;
            //cout<<ans;
            break;
        }
        else{
            if(x+y+mid<a){
                lo= mid+1;
            }
            else{
                hi=mid-1;
            }
        }

    }
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

    ll t,ans=0,x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        //cout<<a<<b<<c<<endl;
       // x=-2449489743;
        //y= -1817121;
      // cout<<x<<" "<<y<<endl;
        bool sol = true;
        for(x=-2449489743; x<=1817121 && sol; x++)
        {
           // cout<<x<<endl;
            if(x*x<c)
            {
               // cout<<x<<endl;
                for(y=-1817121; y<=2449489743 && sol; y++)
                {
                    if(x*x+y*y<c && y!=x)
                    {
                      //  cout<<x<<" "<<y<<endl;
//                        for(z=1; z<=100 && sol; z++)
//                        {
//
//                            if(z!=x && z!=y && x+y+z==a && x*y*z==b && x*x+y*y+z*z==c){
//                                printf("%I64d %I64d %I64d\n",x,y,z);
//                                sol = false;
//                            }
//
//                        }
                           ans = binary(x,y);
                           if(ans!=0)
                           {
                               printf("%lld %lld %lld\n",x,y,ans);
                               sol = false;
                           }
                    }
                }

            }
        }
        if(sol) {
            printf("No solution.\n");
        }



    }


    return 0;
}
