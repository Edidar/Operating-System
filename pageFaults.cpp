#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define pb push_back
deque<int>v;
deque<int>:: iterator it;
vector<int>v1;
int main(){
    cout<<"Enter number of page :"<<endl;
    int n,i,a,c=0;
    cin>>n;
    cout<<"Enter Page :"<<endl;
    for(i=0; i<n; i++){
        cin>>a;
        v1.push_back(a);
    }
    for(i=0; i<n; i++){
        int a;
        it=find(v.begin(),v.end(),v1[i]);
        a=find(v.begin(),v.end(),v1[i])-v.begin();
        if(v.size()<3){
            if(it==v.end()){
                v.push_back(v1[i]);
                c++;
            }
        }
        else{
            if(it==v.end()){
                v.pop_front();
                v.push_back(v1[i]);
                c++;
            }
        }
    }
    cout<<"Page Fault : "<<c<<endl;
    return 0;
}
