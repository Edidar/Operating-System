// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> g1;
    vector<int>::iterator itr; //begin end pointer tai iteretar type nite hobe or auto

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);


    cout<<g1.capacity();
    cout<<endl<<g1.max_size();

    for(itr = g1.begin() ; itr<g1.end(); itr++)
    {

    }

	return 0;
}
