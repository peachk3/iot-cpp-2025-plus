#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 10, 20, 30, 40, 50 };

	vector<int>::iterator itr;				// �ݺ���(������)
	for (itr = v.begin(); itr != v.end(); itr++) {
		cout << *itr << endl;
	}
	cout << endl << endl;
	// �ݺ��� ������ �����ϰ� auto Ű���带 �����ص� ��� ����
	// auto�� ����� �ݺ��� - �ڵ� ����	Ÿ�� �߷�
	for (auto it = v.begin(); it < v.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}