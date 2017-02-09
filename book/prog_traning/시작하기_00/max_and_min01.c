int max(int x, int y)
{
	if(x > y)
		return x;

	return y;
}

int min(int x, int y)
{
	if(x < y)
		return x;

	return y;
}

int three_max(int x, int y, int z)
{
	int temp;
	temp = (x > y) ? x : y;

	if(temp > z)
		return temp;

	return z;
}

int arr_max(int arr[], int len)
{
	int temp = arr[0];
	int i;

	for(i = 1; i < len; i++)
		if(temp < arr[i])
			temp = arr[i];

	return temp;
}
