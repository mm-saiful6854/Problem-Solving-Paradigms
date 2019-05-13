#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j,ansj,ansi,m,one,two;
    while(scanf("%d",&n)!=EOF)
    {
        int prices[n+2];
        for(i=0;i<n;i++)
        {
            scanf("%d",&prices[i]);
        }
        int m;
        scanf("%d",&m);
        string s;
        getchar();
        getline(cin,s);
        sort(prices,prices+n);
        one = 0;
        two = n-1;
        while(one<two)
        {
            if(prices[one] + prices[two]==m)
            {
                ansi=one;
                ansj=two;
                one=one+1;
            }
            else if(prices[one]+prices[two]>m)
            {
                two--;
            }
            else if(prices[one]+prices[two]<m){
                one++;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n",prices[ansi],prices[ansj]);
    }

    return 0;
}
