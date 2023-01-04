// module ( 모듈 )
// - 모듈은 딱 한번만 import 된다.
// - import 순서에 상관 없음
// - 심볼 중복 정의
// - 모듈의 이름도 지정 가능
// - 인터페이스 / 구현부 분리 관리할 필요 없음

#include <iostream>

import Math;

import MathPartition;
//import MathPartition_1;

using namespace std;

int main(){
	int sum = Add(1, 2);

	test::TestExport2();

	MathTimeFunc();
	MyFunc();
	MyFunc2();
}