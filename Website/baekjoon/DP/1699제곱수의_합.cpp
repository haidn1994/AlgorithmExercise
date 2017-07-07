#include <iostream>
using namespace std;

int d[100001];
int pow_table[317];

int main(void)
{
	int n; ios_base::sync_with_stdio(false);
	int i, j;
	for(i = 1; i <= 316; i++)
		pow_table[i] = i*i;
	cin >> n;

	d[1] = 1;
	for(i = 1; i <= n; i++){
		for(j = 1; j < 317; j++){
			if(j*j > i){
				j -= 1;
				break;
			}
		}
		d[i] = d[i-1];
	}
	
}
