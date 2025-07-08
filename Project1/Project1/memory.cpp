#include <stdio.h>

// ==================== ���� ���� (Global Variables) ====================
// ������ ���׸�Ʈ(Data Segment)�� �����
int a;
const int global_c = 100;

// ==================== �Լ��� (Functions) ====================
// �ڵ� ���׸�Ʈ(Code Segment)�� �����
void func() {

	printf("function: %p\n", func); // �Լ��� �̸� = �ּ�
}
int func2() {

	return 2;
}

int main() {
	// ���� - ������ �� �ִ� ����
	// ==================== ���� ������ (Local Variables) ====================
	// ��� ����(Stack)�� �����
	int b = 100;					// ������ �̸��� b�� ��!
	static int c;
	const int d = 10;		// ��� -> �ʱ�ȭ ���Ѿ� ��	
	char arr[20] = "Hi";
	// ==================== �Լ� ȣ��� ���� ====================
	func();
	printf("func2() : %p\n", func2);	// code segment�� �����
	// ���� (Stack) - ���� ������
	printf("local b : %p\n", &b);
	printf("local c : %p\n", &c);
	printf("local d : %p\n", &d);
	printf("array : %p\n", &arr);
	// ������ ���׸�Ʈ (Data Segment)
	printf("global a : %p\n", &a);
	printf("global c : %p\n", &global_c);

	return 0;
}

/*
	data segmnet : stack(����, �Ű�����), heap(�����), data(����, static, ���ڿ� ���ͷ�)
	code segment : �Լ� �ϳ� �� �ϳ��� �ڵ� ���׸�Ʈ �Ҵ�
*/