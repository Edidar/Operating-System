
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int >Atime;
    vector<int >Btime;
    vector<int >Process;
    vector<int >TAtime;
    vector<int >Wtime;
    vector<int >setprocess;
    int n,a;
    cout<<"Enter the number of process"<<endl;
    cin>>n;
    cout<<"Enter the araival time "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        Atime.push_back(a);
        Process.push_back(i+1);

    }
    cout<<"Enter Brust time"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        Btime.push_back(a);
    }
    cout<<"Process       Arival_time      Brust_time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<Process[i]<<"             "<<Atime[i]<<"                "<<Btime[i]<<endl;
    }

    int check=1000; //find smallest arival time
    for(int i=0; i<n; i++)
    {
        if(Atime[i]<check)
        {
            check=Atime[i];
        }
    }

    int total=check;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(Btime[j]>Btime[j+1]) // for sort according to burst time
            {
                swap(Process[j],Process[j+1]);
                swap(Btime[j],Btime[j+1]);
                swap(Atime[j],Atime[j+1]);

            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((Atime[j]<=total)&&(Btime[j]!=0))
            {
                total=total+Btime[j];
                int tat=total-Atime[j];
                TAtime.push_back(tat);
                int wt=tat-Btime[j];
                Wtime.push_back(wt);
                setprocess.push_back(Process[j]);
                Btime[j]=0;
                tat=0;
                wt=0;
                cout<<"P"<<Process[j]<<" => ";
                break;
            }
        }
    }


    // print for acending order
     for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(setprocess[j]>setprocess[j+1])
            {
                swap(setprocess[j],setprocess[j+1]);
                swap(TAtime[j],TAtime[j+1]);
                swap(Wtime[j],Wtime[j+1]);

            }
        }
    }
    cout<<endl;
    cout<<"process      Trunaround_time         wating_time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<setprocess[i]<<"                  "<<TAtime[i]<<"                 "<<Wtime[i]<<endl;
    }

    return 0;
}
