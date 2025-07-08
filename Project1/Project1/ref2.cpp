#include <iostream>
using namespace std;

void change_val(int* p) {
	// 포인터를 사용하여 값 변경
	// p는 int형 변수의 주소를 가리킴
	*p = 20; // 포인터를 통해 값 변경
}
int main() {

	int num = 10;
	cout << num << endl;
	change_val(&num);
	cout << num << endl;

	return 0;
}