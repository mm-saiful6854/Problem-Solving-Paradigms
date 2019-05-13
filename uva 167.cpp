#include<bits/stdc++.h>
using namespace std;
int board[10][10];
int maxn;
int rows[10];
bool place(int row,int column)
{
    int pre;
    for(pre = row -1;pre>=0;pre--)
    {
        if(rows[pre]==column || abs(rows[pre]-column) == abs(row-pre)){
            return false;
        }
    }
    return true;
}


void backtracking(int sum,int row)
{
    if(row==8)
    {
        maxn = max(maxn,sum);
        return ;
    }

    int c;
    for(c=0;c<8;c++)
    {
        if(place(row,c)){
                rows[row]=c;
            sum +=board[row][c];

            backtracking(sum,row+1);
            sum-=board[row][c];
        }
    }

}

int main()
{
   // freopen("output.txt","w",stdout);
    int k,i,j;
    scanf("%d",&k);
    while(k--)
    {
        maxn=0;
        memset(board,0,sizeof(board));
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                scanf("%d",&board[i][j]);
            }
        }
        backtracking(0,0);
        cout<<setw(5)<<maxn<<endl;

    }

    return 0;
}
