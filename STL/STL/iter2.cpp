#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v = { 10, 20, 30, 40, 50 };
	
	vector<int>::reverse_iterator rit;		// ����ȸ �ݺ���
	// ����ȯ�� rbegin(), rend() ���
	for (rit = v.rbegin(); rit != v.rend(); rit++) {
		cout << *rit << endl;				// ����ȸ �ݺ��� ���
	}
	return 0;
}