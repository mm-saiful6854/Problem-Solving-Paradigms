#include<bits/stdc++.h>

using namespace std;
string s;
vector<int>vi[256];
//int cnt[256];
void precalculate()
{
    int i;
    for(i=0; i<s.size(); i++)
    {
        vi[s[i]].push_back(i);
    }
}
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//XDbxDfxTSuS
    cin>>s;
    precalculate();
    int q,i,c;
    scanf("%d",&q);
    while(q--)
    {
        bool flag=true;
        //memset(cnt,0,sizeof(cnt));
        string ss;
        cin>>ss;
        int l =ss.size(),k,sz,index,cnt=0;
        char ch;
        for(i=0; i<l;)
        {

            ch = ss[i];
            cnt=0;
             sz = vi[ch].size();
            if(i==0)
                c=sz;
            while(i<l && ss[i]==ch)
            {
                cnt++;
                i++;
            }
            if(cnt>c)
            {
                flag=false;
                break;
            }


            //c=0;
            if(i<l)
            {
                 index = vi[ch][(sz-c)+cnt-1];
               // cout<<"pre ch : "<<ch<<" "<<index<<endl;
                c=0;
                for(k=0; k<vi[ss[i]].size(); k++)
                {
                   // cout<<"index value : "<<index<<" "<<vi[ss[i]][k]<<endl;
                    if(index < vi[ss[i]][k])
                    {
                       // cout<<"ch : "<<ss[i]<<" "<<"index value : "<<index<<" "<<vi[ss[i]][k]<<endl;
                        c++;
                    }
                }
            }


        }
        if(flag)
            printf("Matched %d %d\n",vi[ss[0]][0],vi[ch][(sz-c)+cnt-1]);
        else
        {
            printf("Not matched\n");
        }

//cnt[ss[l-1]]-1
    }
    return 0;

}
