#include <iostream>
#include <vector>
using namespace std;

int main() {

	std::vector<int> v;
	
	cout << "[v[i], v.size(), v.capacity()]" << endl;	// size(벡터 안의 원소의 크기를 나타냄) != capacity(벡터의 크기를 나타냄)
	//for (int i = 0; i <= 32; i++) {
	//	v.push_back(i + 1);
	//	cout << "[" << v[i] << "," << v.size() << ", " << v.capacity() << "]" << endl;
	//}

	vector<int> v1;
	v1.push_back(1);		// 순차적으로 원소를 삽입
	v1.push_back(2);
	v1.push_back(3);
	v1.insert(v1.begin(), 10);	// 벡터의 맨 앞에 10을 삽입
	v1.insert(find(v1.begin(), v1.end(), 3), 20);	// 3을 찾아서 그 앞에 20을 삽입

	v1.push_back(7);
	v1.pop_back();	// 맨 마지막의 원소를 제거

	for (auto i : v1) {
		cout << i << endl;
	}


	return 0;
}