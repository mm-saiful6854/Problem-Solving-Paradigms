#include<bits/stdc++.h>
#define MAX 100006
#define block_size sqrt(MAX)+5


using namespace std;
typedef long long ll;

ll arr[MAX];
ll n,q;
vector<ll>block[350];
ll bz;

void block_build()
{
    ll i ,bn=-1;

    for(i=0;i<n;i++)
    {
        if(i%bz==0){
            bn++;
            block[bn].clear();
            if(bn-1>=0)
                sort(block[bn-1].begin(),block[bn-1].end());
        }
        block[bn].push_back(arr[i]);
    }
}


ll query(ll l,ll r,ll x)
{

    ll ans=0;
    while(l<=r && l%bz!=0 && l!=0)
    {
        if(arr[l]<=x) ans++;
        l++;
    }

    while(l+bz-1<=r)
    {
        ll bn = l/bz;
        ans+=upper_bound(block[bn].begin(),block[bn].end(),x)-block[bn].begin();
        l+=bz;
    }

    while(l<=r)
    {
        if(arr[l]<=x) ans++;
        l++;
    }

    return ans;


}


int main()
{
    ll i;
    cin>>n>>q;
    bz = sqrt(n);
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    block_build();

    char ch;
    ll l,r,x,val,ind;
    while(q--)
    {
        cin>>ch;
        if(ch=='C')
        {
            cin>>l>>r>>x;
            cout<<query(l-1,r-1,x)<<endl;
        }
        else{

            cin>>ind>>val;
            ll bn = (ind-1)/bz;
            for(i=0;i<block[bn].size();i++)
            {
                if(block[bn][i]==arr[ind-1]){
                    block[bn][i]=val;
                    arr[ind-1]=val;
                    sort(block[bn].begin(),block[bn].end());
                    break;
                }
            }
        }
    }

    return 0;
}
