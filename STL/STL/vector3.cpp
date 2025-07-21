#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v;
	
	v.push_back(10);	// 벡터에 원소 추가
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	printf("%d\n", v[6]);

	for (auto i = 0; i < v.size(); i++) {
		cout << v[i] << " ";	// 벡터의 원소 출력
		cout << v.at(i) << " ";	// at() 함수로 벡터의 원소 출력 .
	}
	printf("\n");

	vector<int>::iterator itr;	// 반복자 선언
	for (itr = v.begin(); itr != v.end(); itr++) {
		cout << *itr << " ";	// 반복자를 사용하여 벡터의 원소 출력
	}
	printf("\n");
	// vector 크기를 나타내는 표준화된 정수 자료형
	// vector 템플릿형식에는 int라는 멤버가 있으며, vector<int>::size_type로 정의됨
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";	// 벡터의 원소 출력
	}
	printf("\n");
	// 향상된 for문
	for (auto i : v) {
		cout << i << " ";	// 범위 기반 for문을 사용하여 벡터의 원소 출력
	}

	return 0;
}
