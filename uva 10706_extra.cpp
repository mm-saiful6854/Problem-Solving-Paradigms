#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 40000
//ll sum[MAX+2];
vector<ll>sum;
string ans_digit="";

string toString(int n) {
	string res = "";
	while (n) {
		res += (n % 10) + 48;
		n /= 10;
	}
	reverse(res.begin(),res.end());
	return res;
}
//
//string cal_string(ll n)
//{
//    string res="";
//
//   ll digit = floor(log10(n))+1;
//    ll k =1,r,sub;
//    while(n!=0)
//    {
//        r = n/powl(10,digit-k);
//        sub = powl(10,digit-k);
//        n-=(r*sub);
//        res+=(r+48);
//        k++;
//    }
//    return res;
//}


void precalculation()
{
    ll digit=0,val,i;
    sum.push_back(0);
    for(i=1; i<MAX; i++)
    {
        digit +=floor(log10(i))+1;
        val=sum[i-1]+digit;
        sum.push_back(val);
        ans_digit+=toString(i);
    }
}

int main()
{
   // freopen("output.txt","w",stdout);

    precalculation();


    ll t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);

//        	int lo = 1, hi = MAX - 1, p = MAX - 1;
//		while (lo <= hi) {
//			int mid = (lo + hi) >> 1;
//			if (sum[mid] >= n)
//				hi = mid - 1, p = min(p, mid);
//			else lo = mid + 1;
//		}
        ll lb = lower_bound(sum.begin(),sum.end(),n)-sum.begin();

        cout<<ans_digit[n-sum[lb-1]-1]<<endl;
    }
    return 0;
}
