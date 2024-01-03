#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i, j, k, t, hit = 0, miss = 0, n, numFrame;
    vector<int> frame;
    vector<int> input;
    cout << "Enter the number of string :";
    cin >> n;
    cout << "\nEnter the String :";
    for (i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        input.push_back(data);
    }
    cout << "Enter the number of Frame Size :";
    cin >> numFrame;

    for (i = 0; i < n; i++)
    {
        for (k = 0; k < frame.size(); k++)
        {
            if (frame[k] == input[i])
            {
                break;
            }
        }
        if (k == frame.size()) // initail fillup
        {
            if (frame.size() < numFrame)
            {
                frame.push_back(input[i]);
                miss++;
            }

            else
            {
                int storLoc = 0;
                int index = i + 1;
                int hold = index;
                for (t = 0; t < frame.size(); t++) // check where is data
                {
                    for (j = index; j < n; j++)
                    {

                        if (frame[t] == input[j])
                        {
                            if (j > hold)
                            {
                                hold = j;
                                storLoc = t;
                            }
                            break;
                        }
                    }
                    if (j == n)
                    {
                        storLoc = t;
                        break;
                    }
                }
                frame[storLoc] = input[i];
                miss++;
            }
        }
        else
        {
            hit++;
        }
    }
    cout << "Total Hit = " << hit << endl;
    cout << "Total Miss = " << miss << endl;
}