#include <iostream>
using namespace std;

int a[27][2];

void preorder(int node)
{
	if(node == -1) return;
	cout << (char)(node+'A');
	preorder(a[node][0]);
	preorder(a[node][1]);
}
void inorder(int node)
{
	if(node == -1) return;
	inorder(a[node][0]);
	cout << (char)(node+'A');
	inorder(a[node][1]);
}
void postorder(int node)
{
	if(node == -1) return;
	postorder(a[node][0]);
	postorder(a[node][1]);
	cout << (char)(node+'A');
}

int main(void)
{
	char x, y, z;
	int n, i;
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> x >> y >> z;
		x = x-'A';
		(y == '.') ? (a[x][0] = -1) : (a[x][0] = y-'A');
		(z == '.') ? (a[x][1] = -1) : (a[x][1] = z-'A');
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}
