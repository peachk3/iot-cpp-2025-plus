#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
	return a + b;
}
int main() {

	cout << add(10, 20) << endl;
	cout << add(10.1, 20.2) << endl;	// 실인자를 주면 자동으로 타입 변환이 된다

	return 0;
}