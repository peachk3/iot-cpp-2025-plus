#include <stdio.h>

// ==================== 전역 변수 (Global Variables) ====================
// 데이터 세그먼트(Data Segment)에 저장됨
int a;
const int global_c = 100;

// ==================== 함수들 (Functions) ====================
// 코드 세그먼트(Code Segment)에 저장됨
void func() {

	printf("function: %p\n", func); // 함수의 이름 = 주소
}
int func2() {

	return 2;
}

int main() {
	// 변수 - 저장할 수 있는 공간
	// ==================== 지역 변수들 (Local Variables) ====================
	// 모두 스택(Stack)에 저장됨
	int b = 100;					// 공간의 이름이 b인 것!
	static int c;
	const int d = 10;		// 상수 -> 초기화 시켜야 함	
	char arr[20] = "Hi";
	// ==================== 함수 호출과 스택 ====================
	func();
	printf("func2() : %p\n", func2);	// code segment에 저장됨
	// 스택 (Stack) - 지역 변수들
	printf("local b : %p\n", &b);
	printf("local c : %p\n", &c);
	printf("local d : %p\n", &d);
	printf("array : %p\n", &arr);
	// 데이터 세그먼트 (Data Segment)
	printf("global a : %p\n", &a);
	printf("global c : %p\n", &global_c);

	return 0;
}

/*
	data segmnet : stack(지역, 매개변수), heap(사용자), data(전역, static, 문자열 리터럴)
	code segment : 함수 하나 당 하나의 코드 세그먼트 할당
*/