/*
	배열에 할당된 값을 재배치하는 예제가 제공된다.
	"회전"이라는 개념과 구현에 많이 도움이 된 것 같다.

	특히 구현하면서 다음과 같은 패턴을 알아냈다.

	유의 사항
	0. 오른쪽 회전은 tail(오른쪽)부터 감소하는 방향으로 값을 대입해야 한다.
	   그렇지 않으면 다음에 대입해야할 값이 덮어씌워져서 값이 유실된다.
	   왼쪽 회전도 마찬가지로 head부터 증가하는 방향으로 값을 대입해야 한다.
	   이유는 위와 같다.
	-----------------------------------------------------------------------
	로직이 전개되는 과정
	1. 끝에 붙어있어서 "회전"시 반대쪽부터 다시 인덱스가 시작하면
	   그 부분은 따로 임시 변수를 만들어서 저장해 두어야 한다.
	   그래야 값을 대입하는 루프에서 값이 유실되는 사태를 막을 수 있다.

	2. 반대쪽으로 밀려나지 않는 변수들을 루프를 돌려 대입한다.

	3. 임시 변수에 저장했던 변수를(들을) 올바른 인덱스에 대입한다.
 */

void right_rotate(int arr[], int head, int tail)
{
	int last;
	int i;


	last = arr[tail];
	for(i = tail; i > head; i--)
		arr[i] = arr[i-1];

	arr[head] = last;
}

// right_rotate를 거꾸로 뒤집기만 하면 된다.
void left_rotate(int arr[], int head, int tail)
{
	int first;
	int i;

	first = arr[head];
	for(i = head; i < tail; i++)
		arr[i] = arr[i+1];

	arr[tail] = first;
}

// 이건 좀 어려웠다. 하지만 k가 일종의 오프셋이고 오프셋만큼 임시변수를 잡고,
// 다시 임시변수를 재할당하는 루프를 만들면 문제는 해결된다.
// 특이한 점은 루프는 1개인데 반복자가 2개씩 필요했다는 점이다.
void k_right_rotate(int arr[], int head, int tail, int k)
{
	int temp[k];
	int i, j;

	for(i = tail, j = k - 1; j > -1; i--, j--)
		temp[j] = arr[i];

	for(i = tail; i > head; i--)
		arr[i] = arr[i-1];

	for(i = head, j = 0; j < k; i++, j++)
		arr[i] = temp[j];
}




