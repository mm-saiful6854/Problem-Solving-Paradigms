#include<bits/stdc++.h>

using namespace std;
int n;
int element[102];
bool flag ;
void subset(int index,int sum)
{
    if(index==n){
        if(sum==0) flag=true;
        return ;
    }
    int i;
    for(i=index;i<n;i++)
    {
        if(sum-element[i]>=0){
              //  cout<<sum-element[i]<<endl;
            subset(i+1,sum-element[i]);


        }

        if(flag) return ;

    }
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        int sum=0,i;
        flag=false;
        memset(element,0,sizeof(element));
        for(i=0;i<n;i++)
        {
            scanf("%d",&element[i]);
            sum+=element[i];
        }
        if(sum&1) {
            printf("NO\n");
        }
        else{
                subset(0,sum/2);
            if(flag){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }


    }
    return 0;
}
