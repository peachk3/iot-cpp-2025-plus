#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	vector<int> arr;		// 크기가 0인 벡터 선언
	vector<int> v(10);		// 크기가 10인 벡터 선언
	vector<int> v1 = { 1, 2, 3, 4, 5 }; 	// 크기 5인 벡터 선언

	cout << "arr size : " << arr.size() << endl;	// 벡터의 크기 출력
	cout << "v(10) size : " << v.size() << endl;	// 벡터의 크기 출력
	cout << "v1 size : " << v1.size() << endl;	// 벡터의 크기 출력

	for (int i = 0; i < 10; i++) {
		printf("v[%d] = %d\n", i, v[i]);	// 벡터의 원소 출력
	}
	printf("\n");
	for (auto i : v1) {					// 범위기반 for문/향상된 for문
		cout << i << endl;
	}

	cout << "v1의 첫번째 요소값: " << *v1.begin() << endl;
	cout << "v1의 마지막 요소값: " << *(v1.end()-1) << endl;

	return 0;
}

/*
	범위 기반 for문의 i는 요소값을 가져와서 복사하여 저장한다
	i는 인덱스가 아님!
	v.begin()은 첫번째 주소 리턴
*/