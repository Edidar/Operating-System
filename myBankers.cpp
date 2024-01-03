#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int>v;
int need[10][10];
int main()
{
    int n,h,i,j,b,a,c;
    int alc[10][10];
    int mx[10][10];
    cout<<"Enter number of process"<<endl;
     cin>>n;
     cout<<"Enter your resource size"<<endl;
     int r;
     cin>>r;
     cout<<"Enter total allocation:"<<endl;
    for(i=0; i<n; i++)
    {

        for(j=0; j<r; j++)
        {

          cin>>alc[i][j];
        }
    }
    cout<<"Enter total maximum:"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<r; j++)
        {

          cin>>mx[i][j];
        }
    }
    cout<<"Enter your available"<<endl;
    cin>>a>>b>>c;
    for(i=0; i<n; i++)
    {
        for(j=0; j<r; j++)
        {
            need[i][j]=mx[i][j]-alc[i][j];
        }
    }
   int y=0;
   vector<int>ans;
   for(i=0; i<n; i++)
   {
    if(need[i][0]==9999)
         continue;
    if(a>=need[i][0] && b>=need[i][1] && c>=need[i][2])
    {
        ans.pb(i);
        need[i][0]=9999;
        a+=alc[i][0];
        b+=alc[i][1];
        c+=alc[i][2];
        i=-1;
    }
    else{
        if(n-1==i)
        {
            y=1;
            break;
        }
    }
   }
   if(y==1)
      cout<<"Dead lock ";
   else{
    cout<<"System is safe possition"<<endl;
    cout<<"Safe sequence :";
    for(i=0; i<ans.size()-1; i++)
        cout<<"p"<<ans[i]<<"->";
        cout<<"p"<<ans[ans.size()-1];
   }

}
//1 1 2
//2 1 2
//3 0 1
//0 2 0
//1 1 2