#include<bits/stdc++.h>

using namespace std;
int tracks[25];
vector<int>res;
vector<int>ans;
int num_track,maxn,capacity;


void selection(int index,int sum)
{
    if(index==num_track)
    {
        if(maxn<sum)
        {
            maxn=sum;
            ans.clear();
            //cout<<res.size()<<endl;
            for(int i=0; i<res.size(); i++){
                 ans.push_back(res[i]);
                 //cout<<res[i]<<" ";
            }
           // cout<<endl;

        }
        return ;
    }
    if(sum+tracks[index]<=capacity)
    {
        res.push_back(tracks[index]);
        selection(index+1,(sum+tracks[index]));
        res.pop_back();
    }
    selection(index+1,sum);

}
int main()
{
    string s;
    while(getline(cin,s))
    {
        res.clear();
       // ans.clear();
        maxn=0;
        stringstream ss;
        ss<<s;
        int i;
        ss>>capacity;
//        int num_track;
        ss>>num_track;
        for(i=0; i<num_track; i++)
        {
            ss>>tracks[i];
        }

        selection(0,0);

        for(i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"sum:"<<maxn<<endl;
    }
    return 0;
}
