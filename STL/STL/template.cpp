#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
	return a + b;
}
int main() {

	cout << add(10, 20) << endl;
	cout << add(10.1, 20.2) << endl;	// �����ڸ� �ָ� �ڵ����� Ÿ�� ��ȯ�� �ȴ�

	return 0;
}