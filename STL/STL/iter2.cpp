#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v = { 10, 20, 30, 40, 50 };
	
	vector<int>::reverse_iterator rit;		// 역순회 반복자
	// 역순환시 rbegin(), rend() 사용
	for (rit = v.rbegin(); rit != v.rend(); rit++) {
		cout << *rit << endl;				// 역순회 반복자 사용
	}
	return 0;
}