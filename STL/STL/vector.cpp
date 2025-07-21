#include <iostream>
#include <vector>
using namespace std;

int main() {

	std::vector<int> v;
	
	cout << "[v[i], v.size(), v.capacity()]" << endl;	// size(���� ���� ������ ũ�⸦ ��Ÿ��) != capacity(������ ũ�⸦ ��Ÿ��)
	//for (int i = 0; i <= 32; i++) {
	//	v.push_back(i + 1);
	//	cout << "[" << v[i] << "," << v.size() << ", " << v.capacity() << "]" << endl;
	//}

	vector<int> v1;
	v1.push_back(1);		// ���������� ���Ҹ� ����
	v1.push_back(2);
	v1.push_back(3);
	v1.insert(v1.begin(), 10);	// ������ �� �տ� 10�� ����
	v1.insert(find(v1.begin(), v1.end(), 3), 20);	// 3�� ã�Ƽ� �� �տ� 20�� ����

	v1.push_back(7);
	v1.pop_back();	// �� �������� ���Ҹ� ����

	for (auto i : v1) {
		cout << i << endl;
	}


	return 0;
}