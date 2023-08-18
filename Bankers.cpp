#include <bits/stdc++.h>
using namespace std;

class bankers
{
public:
    int allocation[100];
    int max[100];
    int need[100];
    int check;
};
int main()

{
    bankers store[100];
    int n, r, data, ct , k, g, checker;
    vector<int> available;
    vector<int> safe_seq;
    vector<int> need;
    int s[100],av[100];

    cout << "Enter the number of process : ";
    cin >> n;
    cout << "Enter the number of resource: ";
    cin >> r;

    for (int i = 0; i < n; i++) // for process
    {
        cout << "P" << i << "  "
             << "Enter the ALlocation :";
        for (int j = 0; j < r; j++)
        {
            cin >> store[i].allocation[j];
        }
        cout << "Enter Max :";
        for (int k = 0; k < r; k++)
        {
            cin >> store[i].max[k];
        }
        store[i].check = 0;
    }

    cout << "Enter the available : ";
    for (int i = 0; i < r; i++)
    {
        cin >> data;
        available.push_back(data);
    }

    // Find the need = max - allocation

    int tem;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < r; j++)
        {
            store[i].need[j] = store[i].max[j] - store[i].allocation[j];

            if (store[i].need[j] < 0)
                store[i].need[j] = 0;
        }
    }
    // tem = store[0].max;
    // cout << tem;
    cout << "\t\t\tNeed\t\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << " \tP" << i << " ";
        for (int j = 0; j < r; j++)
        {
            cout << "\t" << store[i].need[j] << " ";
        }
        cout << endl;
    }
    int j, t,fl=0;
    while (checker != n)
    {
        g=0;
        for (j = 0; j < n; j++)
        {
            if (store[j].check == 0)
            {
                ct = 0;
                for (k = 0; k < r; k++)
                {
                    if (available[k] >= store[j].need[k])
                    {
                        ct = ct+1;
                    }
                    else
                        break;
                }
                if (ct == r)
                {
                    cout << j << "  ";
                    safe_seq.push_back(j);
                    //s[fl++]=j;
                    store[j].check = 1;
                    for (k = 0; k < r; k++)
                    {
                        t = available[k] + store[j].allocation[k];
                        available.push_back(t);
                    }
                    checker++;
                    g = 1;
                }
            }
        }
        if (g == 0)
        {
            cout << "\n\nSystem is not safe :";
            break;
        }
    }
    cout << "\nThe safe sequence :";
    for (int i = 0; i <=safe_seq.size(); i++)
    {
        cout << "P->" << safe_seq.at(i) << "  ";
    }
}