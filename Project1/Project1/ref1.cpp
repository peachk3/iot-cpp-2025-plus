#include <iostream>
using namespace std;

void change_val(int&& p) { // �ӽ� ��ü or ����� �ʱ�ȭ��Ű�� ����
	// �����͸� ����Ͽ� �� ����
	// p�� int�� ������ �ּҸ� ����Ŵ
	p = 20; // �����͸� ���� �� ����
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
	int& rn;			// ���� ����(Reference Variable)(����, ��Ī)

	(lvalue:����)int n = 10(rvalue:���ͷ�, ����);
	n = n2;
	10 = n2; // ����! ���ͷ��� lvalue�� �ƴ�
*/