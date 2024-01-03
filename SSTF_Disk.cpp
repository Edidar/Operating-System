#include<bits/stdc++.h>
using namespace std;
deque<int>v;
int main()
{
    int n,h,i,b,a,mv=0;
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
    int pre=index-1;
    for(i=0; i<n; i++)
    {
        if(pre==-1 || next==v.size())
            break;
        a=v[index]-v[pre];
        b=v[next]-v[index];
        if(a>b)
        {
            mv+=b;
            cout<<v[index]<<"->";
            index=next;
            next++;
        }
        else
        {
            mv+=a;
            cout<<v[index]<<"->";
            index=pre;
            pre--;
        }

    }
    if(pre==-1)
    {
        cout<<v[index]<<"->";
        mv+=v[next]-v[index];
        for(i=next; i<v.size()-1; i++)
        {
            cout<<v[i]<<"->";
            mv+=v[i+1]-v[i];
        }
        cout<<v[v.size()-1];
        cout<<endl<<"total movment ="<<mv<<endl;
    }
    else if(next==v.size())
    {
        cout<<v[index]<<"->";
        mv+=v[index]-v[pre];
        for(i=pre; i>0; i--)
        {
            cout<<v[i]<<"->";
            mv+=v[i]-v[i-1];
        }
        cout<<v[0]<<endl;
        cout<<"total movment = "<<mv<<endl;

    }

}