#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 10, 20, 30, 40, 50 };

	vector<int>::iterator itr;				// 반복자(포인터)
	for (itr = v.begin(); itr != v.end(); itr++) {
		cout << *itr << endl;
	}
	cout << endl << endl;
	// 반복자 선언을 생략하고 auto 키워드를 선언해도 사용 가능
	// auto를 사용한 반복자 - 자동 동적	타입 추론
	for (auto it = v.begin(); it < v.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}