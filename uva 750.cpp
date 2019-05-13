#include<bits/stdc++.h>

using namespace std;

int a,b,cnt;
int row[10];
bool place (int r,int c)
{
    int pre;
    for(pre = c-1;pre>=0;pre--){
        if(row[pre]==r || abs(row[pre]-r) == abs(c-pre))
            return false;
    }
    return true;
}


void backtracking(int c)
{
    if(c==8)
    {
        cnt++;
        int j;
        printf("%2d      %d",cnt,row[0]+1);
        for(j=1;j<8;j++)printf(" %d",row[j]+1);
        printf("\n");
        return ;
    }


    if(c==b)
    {
        if(place(a,b))
        {
            row[b]=a;
            backtracking(c+1);
        }
    }
    else
    {
        int i;
        for(i=0; i<8; i++)
        {
            if(place(i,c))
            {
                row[c]=i;
                backtracking(c+1);
            }
        }
    }

}

int main()
{
   // freopen("output.txt","w",stdout);

    string s;
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        memset(row,0,sizeof(row));
        cnt=0;
        scanf("%d %d",&a,&b);
        a--;b--;
        getline(cin,s);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        backtracking(0);
        if(t) printf("\n");
    }
    return 0;
}
