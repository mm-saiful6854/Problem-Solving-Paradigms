#include<bits/stdc++.h>

using namespace std;

int maze[12][12];



bool valid(int num,int row,int column)
{
    int i,j;
    for(i=0; i<9; i++)
    {
        if(maze[row][i]==num)
        {
            return false;
        }
    }

    for(i=0; i<9; i++)
    {
        if(maze[i][column]==num)
        {
            return false;
        }
    }

    int rr = row- row%3;
    int cc= column - column%3;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(maze[i+rr][j+cc]==num)
            {
                return false;
            }
        }
    }
    if(maze[row][column]!=0) return false;
    return true;
}

bool complete(int &row,int &column)
{

    for(row=0; row<9; row++)
    {
        for(column=0; column<9; column++)
        {
            if(maze[row][column]==0)
            {
                return true;
            }
        }
    }
}


bool backtracking()
{
    int i,j,k,row,column;

    if(!complete(row,column)){
        return true;
    }


    for(k=1; k<=9; k++)
    {
        if(valid(k,row,column))
        {
            maze[row][column]=k;

            if(backtracking()) return true;
            maze[row][column]=0;
        }

    }
    return false;
}

int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        memset(maze,0,sizeof(maze));
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                scanf("%d",&maze[i][j]);
            }
        }

        if(backtracking())
        {
           // printf("%d",maze[0][0]);
            for(i=0; i<9; i++)
            {
                for(j=0; j<9; j++)
                {
                    printf("%d ",maze[i][j]);
                    //if(i8) printf(" ");
                }
                //if(i!=8) printf(" ");
            }
        }

    }
    return 0;
}
