#include<bits/stdc++.h>
using namespace std;
int num[20];
int ans[20];
int k;
void subset(int index,int data_index)
{
    if(data_index==6){
            printf("%d",ans[0]);
        for(int i=1;i<6;i++)printf(" %d",ans[i]);
        printf("\n");
        return ;
    }


    if(index>=k) return ;

    ans[data_index] = num[index];
    subset(index+1,data_index+1);

    while(num[index]==num[index+1])index++;

    subset(index+1,data_index);

}


int main()
{
    int i,cs=0;
    while(scanf("%d",&k)==1)
    {
        if(k==0) break;
        else{
                if(cs!=0){
                    printf("\n");
                }
                cs++;
                memset(num,0,sizeof(num));
                memset(ans,0,sizeof(ans));

            for(i=0;i<k;i++)
                scanf("%d",&num[i]);

                subset(0,0);
        }
    }
    return 0;
}
