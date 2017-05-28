/*
   5/29 이 코드의 동작은 크게 문제없으나 큐의 ADT를 위반한다.
   우선 rear가 enqueue를 담당한다는 사실, front가 dequeue를 담당한다는 사실을 잊지말자.
   그리고 배열 구현에서는 front와 rear가 같은 곳을 가리키고 있으면 안된다.
   배열 구현에서 queue_size는 꼭 필요하다. 그래야 용량 검사가 수월해지기 때문이다.
   그리고 무언가 수정할 일이 생긴다면 처음부터 끝까지 제대로 만들자!

   위의 사항을 반영하여 수정하고, 원형으로 만들어서 무한히 쓸 수 있도록 한 버전.

   삼항 연산자는 맨 끝에만 세미콜론을 적어주면 된다.
 */

#include <stdio.h>

#define Q_CAP 8

int array_queue[Q_CAP];
int front = 0;
int rear = -1;
int queue_size = 0;

void enqueue(int num)
{
	rear = (rear + 1)%Q_CAP;
	queue_size++;
	array_queue[rear] = num;

	return;
}

int dequeue(void)
{
	int output = array_queue[front];

	// 데이터 보호를 위해 0으로 덮어씌우고 front를 증가시킨다.
	array_queue[front] = 0;
	front = (front + 1)%Q_CAP;
	queue_size--;

	return output;
}

int main(void)
{
	int input;

	for(;;){
		printf("input number: "); 
		scanf("%d", &input);

		if(input > 0)
			(queue_size != Q_CAP) ? enqueue(input) : printf("queue full!\n"); 
		else if(input == 0)
			(queue_size != 0) ? printf("[%d]\n", dequeue()) : printf("queue empty!\n");
		else
			return 0;
	}
}


