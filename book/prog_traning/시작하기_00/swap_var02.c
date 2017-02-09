/*
	전역변수를 사용하지 않고 현재 스택 프레임 외부의 값을 변경하려면,
	포인터를 사용하는 것이 한가지 방법이고 다른 한가지 방법은 배열을 넘기는 것이다.
	참고로 배열을 넘기면 "값"이 아니라 "주소"로 값이 넘어가고 "자동으로" 간접 지정이 된다고 생각하면 좋다.

	물론 배열과 포인터는 엄연히 다른 자료형이다.
 */

int swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int swap_arr(int arr[], int x_idx, int y_idx)
{
	int temp;

	temp = arr[x_idx];
	arr[x_idx] = arr[y_idx];
	arr[y_idx] = temp;
}


