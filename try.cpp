#include<bits/stdc++.h>
using namespace std;
vector<int>at;
vector<int>bt;
vector<int>process;
vector<int>tat;
vector<int>wt;
vector<int>pSet;

int main()
{
	int n;
	cout<<"Enter the number of process:";
	cin>>n;
	cout<<"\nEnter the Arival time : ";
	for(int i = 0; i<n; i++)
	{
		int data;
		cin>>data;
		at.push_back(data);
		process.push_back(i+1);
	}
	cout<<"\nEnter the Brust Time :";
		for(int i = 0; i<n; i++)
	{
		int data;
		cin>>data;
		bt.push_back(data);
		//process.push_back(i+1);
	}

	int check = 9999;
	for(int i = 0; i<n; i++)
	{
		if(at[i]<check)
		{
			check= at[i];
		}
	}
	int total = check;

	for(int  i = 0; i<n-1; i++)
	{
		for(int j = 0; j<n-1 ; j++)
		{
			if(bt[j]>bt[j+1])
			{
				swap(process[j],process[j+1]);
				swap(at[j],at[j+1]);
				swap(bt[j],bt[j+1]);
			}
		}
	}
	cout<<"|";

	for(int i = 0; i<n ; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(at[j]<=total && bt[j] !=0)
			{
				total= total+bt[j];
				int Tat = total-at[j];
				tat.push_back(Tat);
				int wait = Tat-bt[j];
				wt.push_back(wait);
				bt[j] = 0;
				pSet.push_back(process[j]);
				cout<<" P"<<process[j]<<" | ";
				break;
			}
		}
	}
}