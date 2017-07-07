#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v(2);
	std::vector<int>::iterator tempIt;
	v[0] = v[1] = 10;
	for(int i = 0; i < v.size(); i++)
		cout << "v[" << i << "]: " << v[i] << '\n';

	tempIt = v.begin()+1;
	tempIt = v.insert(tempIt, 20);
	for(int i = 0; i < v.size(); i++)
		cout << "v[" << i << "]: " << v[i] << '\n';

	v.erase(tempIt+1);
	v.erase(tempIt-1);
	for(int i = 0; i < v.size(); i++)
		cout << "v[" << i << "]: " << v[i] << '\n';


	return 0;
}
