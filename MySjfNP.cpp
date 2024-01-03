#include <bits/stdc++.h>
using namespace std;
	vector<int> at;
	vector<int> bt;
	vector<int> process;
	vector<int> tat;
	vector<int> wt;
	vector<int> pSet;
	int n, data;
void showAfterSort()
{
	cout <<"\tGive INPUT  After Sort:\n\n";
	cout <<"Process\tArival Time\tBrust Time\n";
	for (int i = 0; i < n; i++)
	{
		cout<<"  "<<process[i]<<" \t\t  "<<at[i]<<"\t\t\t"<<bt[i]<<endl;
	}
	cout<<endl;

}

void result()
{
	
	for(int i = 0; i<n;i++)
	{
		cout<<"|"<<"P"<<pSet[i]<<" | ";
	}
	
	cout<<"\n\nProcess   Turn Arround Time  Waiting Time"<<endl<<endl;
	for(int i =0;i<n;i++)
	{
		cout<<pSet[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
	}
}

void show()
{
	cout << "\tGive INPUT :\n\n\n";
	cout <<"Process\tArival Time\tBrust Time\n";
	for (int i = 0; i < n; i++)
	{
		cout<<"  "<<process[i]<<" \t  "<<at[i]<<"\t\t"<<bt[i]<<endl;
	}
	cout<<endl;

}

int main()
{
;
	cout << "Enter the number of data :";
	cin >> n;
	cout << "Enter the Arival time :" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		at.push_back(data);
		process.push_back(i + 1);
	}
	cout << "Enter the Brust time :" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> data;
		bt.push_back(data);
	}

	
	show();
	int check =9999;
	for(int i = 0; i<n;i++)
	{
		if(at[i]<check)
		{
			check = at[i];
		}
	}

	int total = check;

	for(int i =0; i<n-1; i++)
	{
		for(int j =0;j<n-1;j++) // for sort according to burst time
		{
			if(bt[j]>bt[j+1])
			{
				swap(process[j],process[j+1]);
				swap(bt[j],bt[j+1]);
				swap(at[j],at[j+1]);
			}
		}
	}
	showAfterSort();
	for(int i = 0; i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			if(at[j]<=total && bt[j]!=0)
			{
				total = total+bt[j]; //CT
				int Tat = total-at[j];
				tat.push_back(Tat);
				int Wt = Tat -bt[j];
				wt.push_back(Wt);
				pSet.push_back(process[j]);
				
				bt[j] = 0; //bcz its done
				break;;

			}

		}
	}


	result();


}
