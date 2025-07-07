#include <stdio.h>

int main() {
	// ==================== 데이터 타입 이해하기 ====================
	/*
	char: 8비트 (1바이트) 부호 있는 정수 (-128 ~ 127)
	unsigned char: 8비트 (1바이트) 부호 없는 정수 (0 ~ 255)

	최상위 비트(MSB - Most Significant Bit):
	- char: 부호 비트로 사용 (0=양수, 1=음수)
	- unsigned char: 일반적인 데이터 비트로 사용
	*/

	unsigned char uch = 0x7f;		// 0b 0111 1111
	char ch = 0x7f;					
	/*
	0x7f의 이진 표현: 0b 0111 1111
	- 최상위 비트가 0이므로 양수
	- unsigned char: 0*128 + 1*64 + 1*32 + 1*16 + 1*8 + 1*4 + 1*2 + 1*1 = 127
	- char: 부호 비트가 0이므로 양수 127
	- 둘 다 같은 값으로 저장됨
	*/
	printf("uch: %#x, ch: %#x\n ",uch, ch);

	unsigned char uch1 = 0x9f;		// 0b 1001 1111
	char ch1 = 0x9f;		
	/*
	0x9f의 이진 표현: 0b 1001 1111
	- 최상위 비트가 1
	- unsigned char: 1*128 + 0*64 + 0*32 + 1*16 + 1*8 + 1*4 + 1*2 + 1*1 = 159
	- char: 최상위 비트가 1이므로 음수!
	  2의 보수 계산: 1001 1111 → 0110 0000 + 1 = 0110 0001 = 97
	  따라서 -97로 해석됨
	*/
	printf("uch1: %#x, ch1: %#x\n", uch1, ch1);


	unsigned char uch2 = 0x11f;	// 0b 1 0001 1111
	char ch2 = 0x11f;
	/*
	0x11f의 이진 표현: 0b 1 0001 1111 (9비트 필요)
	하지만 char는 8비트만 저장 가능!

	오버플로우 발생: 상위 비트(1)는 잘리고 하위 8비트만 저장
	결과: 0b 0001 1111 = 0x1f = 31

	- unsigned char: 31
	- char: 31 (최상위 비트가 0이므로 양수)
	*/
	printf("uch2: %#x, ch2: %#x\n", uch2, ch2);

	uch = uch << 1;
	ch = ch << 1;
	printf("uch << 1: %#x, ch << 1: %#x\n", uch, ch);

	uch1 = uch1 >> 1;		// 0b 1001 1111 → 0b 0100 1111
	ch1 = ch1 >> 1;			//			    → 1100 1111
	printf("uch1 >> 1: %#x, ch1 >> 1: %#x\n", uch1, ch1);

	return 0;
}