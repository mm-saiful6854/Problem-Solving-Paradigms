#include<bits/stdc++.h>
using namespace std;
int n;
int row[12];
bool flag;
bool place(int ro,int col)
{
    int pre;
    for(pre= col-1;pre>0;pre--)
    {
        if(row[pre]==ro || abs(row[pre]-ro) == abs(pre-col))
            return false;

    }
    return true;
}

void n_queen(int c)
{
   if(c==n+1)
   {
       int i;
       printf("[");
      // printf("%d",row[1]);
       for(i=1;i<=n;i++){
        printf("%d ",row[i]);
       }
       printf("] ");
       flag= true;
       return ;

   }
   int r;
   //bool flag;
   for(r=1;r<=n;r++)
   {
       if(place(r,c))
       {
           row[c]=r;
          n_queen(c+1);

       }
   }

   //return flag;


}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(row,0,sizeof(row));
    scanf("%d",&n);
    flag =false;
        n_queen(1);
     if(flag==false)
        printf("-1");
        printf("\n");
    }

    return 0;
}
