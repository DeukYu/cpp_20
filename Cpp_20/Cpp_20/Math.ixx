module;	// global module fragment

// 각종 외부 헤더 추가
#include <vector>

// module 시작
export module Math;

// import module ...

// submodule
// math.time을 import해서 다시 math 모듈에 포함해서 export
export import Math.time;

// 1 ) 함수 앞에다가 export
export int Add(int a, int b)
{
	return a + b;
}

// 2 ) export하고 싶은 애들을 따로 묶어주는
export
{
	void TestExport() 
	{

	}
}

void Internal() 
{

}

// 3) namespace를 지정
export namespace test
{
	void TestExport2() 
	{

	}
}