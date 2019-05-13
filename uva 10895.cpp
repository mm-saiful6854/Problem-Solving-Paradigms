#include<bits/stdc++.h>
using namespace std;

int matrix[10004][10004];

vector<int>index;
vector<pair<int,int> >index1;



int main()
{
   // freopen("input.txt","r",stdin);

    //freopen("output.txt","w",stdout);
    int m,n;
    string temp;
    int tm,i,r,y,cnt,j,k,x,val;
    while(scanf("%d %d", &m, &n) != EOF)
    {
        x=0;
        tm =m;
        memset(matrix,0,sizeof(matrix));
        while(tm--)
        {
            x++;
            index.clear();
            cin>>r;

            if(r==0)
            {

                getline(cin,temp);
                continue;
            }
            for(i=0; i<r; i++)
            {
                cin>>y;
                index.push_back(y);
            }
            for(i=0; i<r; i++)
            {
                cin>>val;
                matrix[x][index[i]]=val;
            }
        }


        cout<<n<<" "<<m<<endl;
        for(i=1; i<=n; i++)
        {
            index1.clear();
            cnt=0;
            for(j=1;j<=m;j++)
            {
                if(matrix[j][i]!=0)
                {
                    cnt++;
                    index1.push_back(make_pair(j,i));
                }
            }
            if(cnt==0)
            {
                cout<<cnt<<endl<<endl;
            }
            else
            {
                cout<<cnt;
                for(k=0; k<index1.size(); k++)
                {
                    pair<int,int> p =index1[k];
                    cout<<" "<<p.first;
                }
                cout<<endl;
                int len = index1.size();
                for(k=0;k<len;k++)
                {
                    pair<int,int> p = index1[k];
                    cout<<matrix[p.first][p.second];
                    if(k!=len-1)cout<<" ";
                }
                cout<<endl;
            }

        }
    }

    return 0;
}
