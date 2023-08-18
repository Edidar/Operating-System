#include <bits/stdc++.h>
using namespace std;

int main()
{
	int numFrame, n, i, j, k, t, hit = 0, miss = 0;
	vector<int> input;
	vector<int> frame;
	cout << "Enter the number of input size : ";
	cin >> n;

	cout << "\nNow Enter the input String :";
	for (i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		input.push_back(data);
	}
	cout << "\nEnter the frame size :";
	cin >> numFrame;

	for (int i = 0; i < n; i++)
	{
		for (k = 0; k < frame.size(); k++)
		{
			if (frame[k] == input[i])
			{
				break;
			}
		}
		if (k == frame.size())
		{
			if (frame.size() < numFrame)
			{
				frame.push_back(input[i]);
				miss++;
			}
			else
			{
				int storLoc = 0;
				int index = i - 1;
				int hold = index;
				for (t = 0; t < frame.size(); t++)
				{
					for (j = index; j >= 0; j--)
					{

						if (frame[t] == input[j])
						{
							if (j < hold)
							{
								hold = j;
								storLoc = t;
							}
							break;
						}
					}

					if (j == -1)
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

	cout << "\n Total miss = " << miss;
	cout << "\n Total hit = " << hit;
}