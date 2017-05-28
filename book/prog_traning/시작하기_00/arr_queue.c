/*
   5/29 이 코드의 동작은 크게 문제없으나 큐의 ADT를 위반한다.
   우선 rear가 enqueue를 담당한다는 사실, front가 dequeue를 담당한다는 사실을 잊지말자.
   그리고 배열 구현에서는 front와 rear가 같은 곳을 가리키고 있으면 안된다.
   그리고 경우에 따라서 queue_size도 만들수도 있겠다.

   삼항 연산자는 맨 끝에만 세미콜론을 적어주면 된다.
 */

#include <stdio.h>

#define Q_CAP 8

int array_queue[Q_CAP];
int front = 0;
int rear = 0;

void enqueue(int num)
{
	array_queue[front] = num;
	front++;

	return;
}

int dequeue(void)
{
	int output = array_queue[rear];

	// 데이터 보호를 위해 0으로 덮어씌우고 rear를 증가시킨다.
	array_queue[rear] = 0;
	rear++;

	return output;
}

int main(void)
{
	int input;

	for(;;){
		printf("input number: "); 
		scanf("%d", &input);

		if(input > 0)
			(front < Q_CAP) ? enqueue(input) : printf("queue full!\n"); 
		else if(input == 0)
			(front != rear) ? printf("[%d]\n", dequeue()) : printf("queue empty!\n");
		else
			return 0;
	}
}


