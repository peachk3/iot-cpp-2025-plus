#include <iostream>
using namespace std;

void change_val(int* p) {
	// �����͸� ����Ͽ� �� ����
	// p�� int�� ������ �ּҸ� ����Ŵ
	*p = 20; // �����͸� ���� �� ����
}
int main() {

	int num = 10;
	cout << num << endl;
	change_val(&num);
	cout << num << endl;

	return 0;
}