#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueueUsingFront(int val) {
	if (front == (rear + 1) % SIZE) {
		printf("Queue full!");
	}
	else {
		if (front == -1) {
			front++;
			rear++;
		}
		else
			front = (front + SIZE - 1) % SIZE;
		queue[front] = val;
	}
}
void enqueueUsingRear(int val) {
	if (front == (rear + 1) % SIZE) {
		printf("Queue full!");
	}
	else {
		if (front == -1)
			front++;
		rear = (rear + 1) % SIZE;
		queue[rear] = val;
	}
}
int dequeueUsingFront() {
	int x = -1;
	if (front == -1) {
		printf("Queue empty!");
	}
	else {
		x = queue[front];
		if (front == rear) 
			front = rear = -1;
		else
			front = (front + 1) % SIZE;
	}
	return x;
}
int dequeueUsingRear() {
	int x = -1;
	if (rear == -1) {
		printf("Queue empty!");
	}
	else {
		x = queue[rear];
		if (front == rear) 
			front = rear = -1;
		else
			rear = (rear + SIZE - 1) % SIZE;
	}
	return x;
}

void display() {
	int i = front;
	printf("\n");
	while (i != rear) {
		printf("%d ", queue[i]);
		i = (i + 1) % SIZE;
	}
	printf("%d\n", queue[rear]);
}

int main() {
	int choice, inner_choice, val;
	do {
		printf("1. Input restricted\n2. Output restricted\n3. Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			do {
				printf("1. Enqueue\n2. Dequeue using front\n3. Dequeue using rear\n4. Display\n5. Exit\nEnter choice: ");
				scanf("%d", &inner_choice);
				switch (inner_choice) {
				case 1:
					printf("Enter value: ");
					scanf("%d", &val);
					enqueueUsingRear(val);
					break;
				case 2:
					printf("Dequeued %d\n", dequeueUsingFront());
					break;
				case 3:
					printf("Dequeued %d\n", dequeueUsingRear());
					break;
				case 4:
					display();
					break;
				case 5:
					break;
				default:
					printf("\nInvalid choice!");
					inner_choice = 5;
				}
			} while (inner_choice != 5);
			break;
		case 2:
			do {
				printf("\n1. Enqueue using front\n2. Enqueue using rear\n3. Dequeue\n4. Display\n5. Exit\nEnter choice: ");
				scanf("%d", &inner_choice);
				switch (inner_choice) {
				case 1:
					printf("Enter value: ");
					scanf("%d", &val);
					enqueueUsingFront(val);
					break;
				case 2:
					printf("Enter value: ");
					scanf("%d", &val);
					enqueueUsingRear(val);
					break;
				case 3:
					printf("\nDequeued %d\n", dequeueUsingRear());
					break;
				case 4:
					display();
					break;
				case 5:
					break;
				default:
					printf("\nInvalid choice!");
					inner_choice = 5;
				}
			} while (inner_choice != 5);
			break;
		case 3:
			break;
		default:
			printf("\nInvalid choice!");
			choice = 3;
		}
	} while (choice != 3);
	return 0;
}