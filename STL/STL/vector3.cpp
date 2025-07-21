#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v;
	
	v.push_back(10);	// ���Ϳ� ���� �߰�
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	printf("%d\n", v[6]);

	for (auto i = 0; i < v.size(); i++) {
		cout << v[i] << " ";	// ������ ���� ���
		cout << v.at(i) << " ";	// at() �Լ��� ������ ���� ��� .
	}
	printf("\n");

	vector<int>::iterator itr;	// �ݺ��� ����
	for (itr = v.begin(); itr != v.end(); itr++) {
		cout << *itr << " ";	// �ݺ��ڸ� ����Ͽ� ������ ���� ���
	}
	printf("\n");
	// vector ũ�⸦ ��Ÿ���� ǥ��ȭ�� ���� �ڷ���
	// vector ���ø����Ŀ��� int��� ����� ������, vector<int>::size_type�� ���ǵ�
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";	// ������ ���� ���
	}
	printf("\n");
	// ���� for��
	for (auto i : v) {
		cout << i << " ";	// ���� ��� for���� ����Ͽ� ������ ���� ���
	}

	return 0;
}
