# IoT 개발자 C++ 보충 수업
# 📘 C/C++ 기본 개념 정리
## ✅ 1일차
### 🔹 사용자 정의 자료형
- 구조체 (`struct`)
- 클래스 (`class`)

### 🔹 오버로딩 vs 오버라이딩
- **오버로딩 (Overloading)**
: 동일한 이름, 매개변수 타입/개수/순서가 다르면 **다른 함수로 인식**
```cpp
void func(int a);
void func(double a);   // OK
void func(int a, int b); // OK
```
- **오버라이딩 (Overriding)**
: 상속 관계에서 기존 부모 클래스의 메서드를 재정의

```cpp
class Base {
public:
    virtual void speak();
};

class Derived : public Base {
public:
    void speak() override;
};
```
### 🔹 객체지향 기본 개념
- 클래스 안의 함수 → 메서드
- 객체 생성 시 **임시 객체(Temporary Object)**도 활용 가능

### 🔸 함수 개념
1. 함수 선언 (Declaration)
```cpp
int add(int, int);
void hello();
```
2. 함수 정의 (Definition)
```cpp
int add(int a, int b) {
    return a + b;
}
```
3. 함수 호출 (Call)
```cpp
int result = add(3, 4);
hello();
```
4. 매개변수
- 형식 매개변수(Parameter): 함수 정의 시 사용
- 실인자(Argument): 호출 시 실제 전달값

5. 반환값
- `void`: 반환 없음
- `int`, `char` 등: 값 반환
- `return` 키워드로 반환

#### 🔸 데이터 타입 & 연산
1. 부호 비트
- `char`: 최상위 비트 = 부호
- `unsigned char`: 모든 비트가 데이터

2. 2의 보수 (Two's Complement)
- 음수 표현 방식
```text
-1 → ~00000000 + 1 → 11111111
```
3. 오버플로우
```text
값이 초과 → 상위 비트 잘림
0x11F → 0x1F
```
4. 비트 시프트 연산
- `<<`: 좌측 시프트 → x2
- `>>`: 우측 시프트
   - `unsigned`: 논리적 시프트
   - `signed`: 산술적 시프트

5. 논리적 vs 산술적 시프트

| 구분   | 논리적 시프트    | 산술적 시프트   |
| ---- | ---------- | --------- |
| 빈 자리 | 항상 0       | 부호 비트로 채움 |
| 사용 예 | `unsigned` | `signed`  |

6. 형식 지정자
```cpp
%d    → 부호 있는 10진수  
%u    → 부호 없는 10진수  
%#x   → 0x 붙은 16진수
```
7. 메모리 관점
- 비트 패턴은 같아도 자료형 해석 방식에 따라 다르게 읽힘

## ✅ 2일차

### 🔹 메모리 구조 개요

#### 📌 메모리 세그먼트 구조

| 세그먼트        | 내용                                      |
|-----------------|-------------------------------------------|
| 코드(Code)       | 프로그램 실행 코드 (읽기 전용)            |
| 데이터(Data)     | 초기화된 전역/static 변수                 |
| BSS              | 초기화되지 않은 전역/static 변수         |
| 힙(Heap)         | 동적 할당 메모리 (`malloc`, `new`)       |
| 스택(Stack)      | 지역 변수, 함수 호출 정보                |


#### 도식:
```
[Low Address]
| 코드 세그먼트
| 데이터 세그먼트
| BSS 세그먼트
| 힙 (위로 성장)
|  ...
| 스택 (아래로 성장)
[High Address]
```

#### 🔸 스택 (Stack)

- **LIFO 구조**
- 함수 호출 시: 스택 프레임 생성
- 함수 종료 시: 자동 제거
- **주소는 높은 곳에서 낮은 방향**으로 성장
- 지역 변수 저장

```c
void foo() {
    int a = 10; // 스택에 저장
}
```

#### 🔸 힙 (Heap)

- **동적 메모리 할당 영역**
- `malloc`, `new`로 메모리 요청
- 프로그래머가 직접 **free**, `delete`로 해제 필요
- **낮은 주소 → 높은 주소로 성장**
- 대용량 데이터 적합

```cpp
int* arr = new int[1000]; // 힙
delete[] arr;
```

#### 🔸 스택 vs 힙 비교

| 구분     | 스택                  | 힙                          |
|----------|------------------------|------------------------------|
| 할당 방식 | 자동                  | 수동 (`malloc`, `new`)      |
| 메모리 크기 | 작음 (1~8MB)         | 큼 (시스템에 따라 다름)       |
| 속도     | 빠름                  | 상대적으로 느림             |
| 해제     | 자동                  | 직접 해제 필요               |
| 문제점   | Stack Overflow        | 메모리 누수, 조각화          |


#### 🔸 스택 프레임

- 함수 호출 시 생성되는 **일시적 메모리 블록**
- 지역 변수, 매개변수, 복귀 주소 포함
- 함수 종료 시 자동 해제됨


#### 🔸 변수 저장 위치

| 변수 유형      | 저장 위치           |
|----------------|---------------------|
| 지역 변수      | 스택                |
| 전역 변수      | 데이터 세그먼트     |
| `static` 변수 | 데이터 세그먼트     |
| 동적 할당 변수 | 힙                  |


#### 🔸 주소 분포 예시
```
[코드]          → 가장 낮은 주소
[데이터 영역]   → 중간
[힙]            → 중간 ~ 높은 주소 (↑)
[스택]          → 가장 높은 주소 (↓)
```

#### 🔸 메모리 관련 문제

- **스택 오버플로우**: 너무 깊은 재귀, 큰 지역 변수
- **메모리 누수**: `free`, `delete` 안함
- **댕글링 포인터**: 해제된 주소 접근
- **조각화(Fragmentation)**: 힙 공간이 잘게 나뉘어 사용 불가능해짐

#### 🔸 좋은 메모리 사용 습관

- `new/malloc` → `delete/free` 반드시 호출
- 포인터 해제 후 `nullptr`로 초기화
- 큰 데이터는 힙, 임시 데이터는 스택 사용
- 가급적 **스마트 포인터(std::unique_ptr, shared_ptr)** 사용 (C++)

### 🔸 가비지 컬렉션 (GC, Garbage Collection)
- **C++은 기본적으로 GC 없음**
- Java, Python 등에서 사용
- 자동으로 참조되지 않는 객체의 메모리 해제

#### 📝 기타 요약

- **참조 변수**: 객체 주소를 저장
- `null`을 참조 변수에 대입하면 아무것도 가리키지 않음


## 3일차 - 25.07.21(월)
### STL (Standard Template Library)
- C++ STL은 표준 템플릿 라이브러리로, 자료구조와 알고리즘을 **템플릿 기반**으로 제공하여 효율적인 코딩을 가능하게 합니다.

```cpp
template<typename T>
T add(T a, T b) {
	return a + b;
}
```

### ✅ 컨테이너 (Containers)
- 데이터를 저장하는 자료구조
- `시퀀스 컨테이너`,`연관 컨테이너`로 나뉨

### ✅ 1. 시퀀스 컨테이너 (Sequence Containers)

* 데이터를 **순서대로 저장**
* 인덱스 또는 삽입 순서로 요소에 접근

| 컨테이너           | 특징                               |
| -------------- | -------------------------------- |
| `vector`       | 동적 배열. 임의 접근 O(1), 뒤쪽 삽입/삭제 O(1) |
| `deque`        | 양쪽 끝 삽입/삭제 모두 O(1)               |
| `list`         | 이중 연결 리스트. 중간 삽입/삭제가 빠름          |
| `array`        | 고정 크기 배열 (C++11\~), 컴파일 타임 크기 필요 |
| `forward_list` | 단방향 연결 리스트. 메모리 적음. 중간 삽입/삭제에 적합 |

#### 📌 vector 예시

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);      // 끝에 추가
v[2] = 10;           // 임의 접근 가능
```

### ✅ 2. 연관 컨테이너 (Associative Containers)

* 키(key)를 기준으로 정렬된 상태로 저장됨
* 내부적으로 **이진 탐색 트리(RB Tree)** 사용

| 컨테이너       | 특징                           |
| ---------- | ---------------------------- |
| `set`      | 중복 없는 값 저장, 자동 정렬            |
| `multiset` | 중복 허용, 자동 정렬                 |
| `map`      | (key, value) 쌍 저장. key 중복 불가 |
| `multimap` | (key, value) 쌍 저장. key 중복 허용 |

#### 📌 map 예시

```cpp
map<string, int> m;
m["apple"] = 3;
m["banana"] = 5;

cout << m["apple"];  // 출력: 3
```

* 정렬된 키값 기준으로 O(log n) 시간 복잡도

### ✅ 정리 표

| 구분  | 종류                          | 정렬 여부 | 중복 여부                                  | 주요 특징                       |
| --- | --------------------------- | ----- | -------------------------------------- | --------------------------- |
| 시퀀스 | `vector`, `list`, `deque` 등 | ❌     | ✅                                      | 순서대로 저장, 삽입/삭제 성능 다양        |
| 연관  | `set`, `map` 등              | ✅     | `set/map`: ❌<br>`multiset/multimap`: ✅ | 키 기반 저장, 자동 정렬, O(log n) 성능 |

## ✅ std::vector란?
* C++ STL에서 가장 많이 사용되는 **시퀀스 컨테이너**
* 내부적으로 **동적 배열(Dynamic Array)** 사용
* 요소 추가 시 자동으로 메모리 재할당 수행

#### ✅ size() vs capacity() 차이

| 항목           | 설명                              |
| ------------ | ------------------------------- |
| `size()`     | 현재 vector에 실제로 저장된 요소의 개수       |
| `capacity()` | 재할당 없이 vector가 저장할 수 있는 최대 요소 수 |

#### ✅ 동작 원리 요약

1. 내부적으로 동적 배열을 생성하여 저장
2. 요소가 추가되면, 배열이 꽉 찼을 때 더 큰 메모리 블록을 재할당
3. 기존 데이터를 복사해 새 배열에 옮김
4. 따라서 `capacity()`는 `size()`보다 클 수 있음

#### 📌 vector 관련 코드

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr;           // 크기 0
	vector<int> v(10);         // 크기 10, 초기화 X
	vector<int> v1 = {1,2,3,4,5};

	cout << "arr size: " << arr.size() << endl;
	cout << "v size: " << v.size() << endl;
	cout << "v1 size: " << v1.size() << endl;

	for (int i = 0; i < 10; i++)
		printf("v[%d] = %d\n", i, v[i]);

	for (auto i : v1)
		cout << i << endl;

	cout << "첫 요소: " << *v1.begin() << endl;
	cout << "마지막 요소: " << *(v1.end() - 1) << endl;
	return 0;
}
```

#### 📌 `vector` 주요 함수 정리
| 함수                    | 설명                               |
| --------------------- | -------------------------------- |
| `v.size()`            | 벡터의 현재 요소 개수 반환                  |
| `v.empty()`           | 벡터가 비어 있는지 확인 (`true/false`)     |
| `v.clear()`           | 모든 요소 제거 (벡터 초기화)                |
| `v.push_back(val)`    | 벡터 끝에 요소 추가                      |
| `v.pop_back()`        | 마지막 요소 제거                        |
| `v.front()`           | 첫 번째 요소 반환 (`*v.begin()`과 같음)    |
| `v.back()`            | 마지막 요소 반환 (`*(v.end() - 1)`과 같음) |
| `v.insert(itr, val)`  | 반복자 위치에 `val` 삽입                 |
| `v.erase(itr)`        | 반복자 위치 요소 제거                     |
| `v.erase(itr1, itr2)` | `itr1`부터 `itr2` 전까지 범위 삭제        |
| `v.resize(n)`         | 크기를 `n`으로 변경 (늘어나면 기본값 0으로 채움)   |
| `v.assign(n, val)`    | `val`을 `n`개 할당하여 벡터 재구성          |

## ✅ 반복자 (Iterator)

* **컨테이너 요소를 순회하거나 조작할 수 있는 도구**
* 포인터처럼 동작 (실제로 대부분 포인터를 wrapping한 형태)
* begin(), end(), rbegin(), rend() 등과 함께 사용

### 📌 반복자 사용 예시

```cpp
vector<int> v = {1,2,3,4,5};

vector<int>::iterator it;
for (it = v.begin(); it != v.end(); ++it) {
	cout << *it << endl;
}

// auto 키워드를 사용하면 반복자 타입 추론
for (auto it = v.begin(); it != v.end(); ++it) {
	cout << *it << endl;
}
```

### 📌 역순 반복자 (reverse\_iterator)

```cpp
vector<int>::reverse_iterator rit;
for (rit = v.rbegin(); rit != v.rend(); ++rit) {
	cout << *rit << endl;
}
```

### 📎 참고 파일
* [vector 예제 소스코드](./STL/STL/vector.cpp)
* [반복자 예제 소스코드](./STL/STL/iter.cpp)
* [역순 반복자 예제](./STL/STL/iter2.cpp)
* [vector 요소값(사이즈)](./STL/STL/vector2.cpp)
* [vector 출력 형태](./STL/STL/vector3.cpp)

