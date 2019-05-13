#include<bits/stdc++.h>

using namespace std;
vector<int>vi[600000];
bool visit[4200000];
void calculate()
{
    int i,ball,d,left,right;
    for(i=1; i<530000; i++)
    {
        ball = 1;
        d=0;
        // getchar();
        while(d<20)
        {

            vi[i].push_back(ball);
            left= 2*ball;
            right = 2*ball+1;
            if(visit[ball]==false)
            {
                visit[ball]= true;
                  //cout<<"ball : "<<ball<<endl;
                ball= left;


            }
            else
            {
                visit[ball]= false;
                // cout<<"ball : "<<ball<<endl;
                ball =right;
            }

            d++;
        }

    }
}

int main()
{
    calculate();
    while(1)
    {
        int t,d,b;
        scanf("%d",&t);
        if(t==-1){
            return 0;
        }

        while(t--)
        {
            int d,b;
            scanf("%d %d",&d,&b);
            cout<<vi[b][d-1]<<endl;
        }
    }

    return 0;
}
