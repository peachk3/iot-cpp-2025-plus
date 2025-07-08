#include <iostream>
using namespace std;

void change_val(int&& p) { // 임시 객체 or 상수를 초기화시키는 형태
	// 포인터를 사용하여 값 변경
	// p는 int형 변수의 주소를 가리킴
	p = 20; // 포인터를 통해 값 변경
}
int main() {

	int num = 10;
	cout << num << endl;
	change_val(10);
	cout << num << endl;

	return 0;
}

/*
	int n;
	int* pn;
	int& rn;			// 참조 변수(Reference Variable)(별명, 별칭)

	(lvalue:변수)int n = 10(rvalue:리터럴, 변수);
	n = n2;
	10 = n2; // 오류! 리터럴은 lvalue가 아님
*/