#include<bits/stdc++.h>

using namespace std;

int main()
{

//    freopen("input.txt","r",stdin);
//
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(),cout.tie();
    int n;
    int used = 0,cs=0;
    while(cin>>n)
    {
        bool flag =true;
        used=0;
        int i,abcde,temp;
        // cout<<n<<endl;
        if(n==0)
        {
            break;
        }
        else
        {
            if(cs!=0){
                printf("\n");

            }
            cs++;
            for(i=1234; i<=98765/n; i++)
            {
                used =0;
                temp = i;
                abcde = temp*n;



                if(temp<10000) used=1;
                int temp1= abcde;
                while(abcde)
                {
                    int r = abcde%10;
                    used |=(1<<r);
                    abcde/=10;
                }

                while(temp)
                {
                    int r = temp%10;
                    used |=(1<<r);
                    temp/=10;
                }

                if(used == (1<<10)-1)
                {
                    if(i<10000)
                        printf("%d / 0%d = %d\n",temp1,i,n);
                    else
                        printf("%d / %d = %d\n",temp1,i,n);
                    flag = false;
                }

            }

            if(flag)
            {
                printf("There are no solutions for %d.\n",n);
                //cout<<endl;
            }
        }

        //cout<<endl;
    }


    return 0;
}
