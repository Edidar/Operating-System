#include<bits/stdc++.h>
using namespace std;
deque<int>v;
int main()
{
    int n,h,i,a,mv=0;
    cout<<"enter your track number"<<endl;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);

    }
    cout<<"Enter your head position"<<endl;
    cin>>h;
    v.push_front(h);
    sort(v.begin(),v.end());
    int index;
    for(i=0; i<n; i++)
    {
        if(v[i]==h)
        {
            index=i;
            break;
        }
    }

    int next=index+1;
    for(i=index; i>0;i--)
    {

        cout<<v[i]<<"->";
        mv+=abs(v[i]-v[i-1]);

    }
    cout<<v[0]<<"->";
    mv+=abs(v[0]-v[next]);
    for(i=next; i<v.size()-1; i++)
    {

       cout<<v[i]<<"->";
        mv+=abs(v[i]-v[i+1]);
    }
    cout<<v[v.size()-1]<<endl;
    cout<<"TOtal move  ="<<mv<<endl;
}