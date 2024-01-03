#include<bits/stdc++.h>
using namespace std;
int main()
{
    int fsiz,n,i,j,k,t,input,hit=0,miss=0;
    int x=0;
    vector<int >PF;
    vector<int >pagefu;
    cout<<"Enter the size of frame"<<endl;
    cin>>fsiz;
    cout<<"Enter number of replace string"<<endl;
    cin>>n;
    cout<<"Enter replace string"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>input;
        pagefu.push_back(input);
    }
    for(i=0; i<n; i++)
    {
        for(k=0; k<PF.size(); k++)
        {
            if(PF[k]==pagefu[i])
            {
                break;
            }
        }
        if(k==PF.size())
        {
            if(PF.size()<fsiz)
            {
                PF.push_back(pagefu[i]);
                miss++;
            }
            else
            {
                int res=0;
                int index=i-1;
                int hold=index;
                for(t=0; t<PF.size(); t++)
                {

                    for(j=index; j>=0; j--)
                    {
                        if(PF[t]==pagefu[j])
                        {
                            if(j<hold)
                            {
                                hold=j;
                                res=t;
                            }
                            break;
                        }
                    }
                    if(j==-1)
                    {
                        res=t;
                        break;
                    }
                }

                PF[res]=pagefu[i];
                miss++;
            }

        }
        else
        {
            hit++;
        }
    }
    cout<<"--------------OutPut----------------------"<<endl<<endl;
    cout<<"NUmber of page fault : "<<miss<<endl;
    cout<<"Number of page Hit : "<<hit<<endl;
    return 0;
}
