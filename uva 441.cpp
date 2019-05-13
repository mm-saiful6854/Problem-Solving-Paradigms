#include<bits/stdc++.h>
using namespace std;
int num[20];
int ans[20];
int main()
{
    int k,cs=0,i;
    while(scanf("%d",&k)==1)
    {
        if(k==0) break;
        else
        {
            if(cs!=0){
                printf("\n");
            }
            cs++;
            memset(num,0,sizeof(num));
            for(i=0; i<k; i++)
            {
                cin>>num[i];
            }

            // cout<<char(num[0]+48)<<endl;
            memset(ans,0,sizeof(ans));
            string ans ="";
            int j,l,m,n,o;
            for(i=0; i<=k-6; i++)
            {
               ans[i]=num[i];
                for(j=i+1; j<=k-5; j++)
                {
                    ans[j]=num[j];
                    for(l=j+1; l<=k-4; l++)
                    {
                       ans[l]=num[l];
                        for(m=l+1; m<=k-3; m++)
                        {
                           ans[m]=num[m];
                            for(n=m+1; n<=k-2; n++)
                            {
                                ans[n]=num[n];
                                for(o=n+1; o<=k-1; o++)
                                {
                                    ans[o]=num[o];

                                        printf("%d %d %d %d %d %d\n",ans[i],ans[j],ans[l],ans[m],ans[n],ans[o]);

                                }

                            }
                        }
                    }
                }
            }
            //printf("\n");
        }

    }
    return 0;
}
