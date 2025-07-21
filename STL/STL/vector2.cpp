#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	vector<int> arr;		// ũ�Ⱑ 0�� ���� ����
	vector<int> v(10);		// ũ�Ⱑ 10�� ���� ����
	vector<int> v1 = { 1, 2, 3, 4, 5 }; 	// ũ�� 5�� ���� ����

	cout << "arr size : " << arr.size() << endl;	// ������ ũ�� ���
	cout << "v(10) size : " << v.size() << endl;	// ������ ũ�� ���
	cout << "v1 size : " << v1.size() << endl;	// ������ ũ�� ���

	for (int i = 0; i < 10; i++) {
		printf("v[%d] = %d\n", i, v[i]);	// ������ ���� ���
	}
	printf("\n");
	for (auto i : v1) {					// ������� for��/���� for��
		cout << i << endl;
	}

	cout << "v1�� ù��° ��Ұ�: " << *v1.begin() << endl;
	cout << "v1�� ������ ��Ұ�: " << *(v1.end()-1) << endl;

	return 0;
}

/*
	���� ��� for���� i�� ��Ұ��� �����ͼ� �����Ͽ� �����Ѵ�
	i�� �ε����� �ƴ�!
	v.begin()�� ù��° �ּ� ����
*/