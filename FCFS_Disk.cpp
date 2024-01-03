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
    for(i=0; i<v.size()-1; i++)
    {
        cout<<v[i]<<"->";
        mv+=abs(v[i]-v[i+1]);
    }
    cout<<v[i]<<endl;
    cout<<"total movment = "<<mv<<endl;
    return 0;
}