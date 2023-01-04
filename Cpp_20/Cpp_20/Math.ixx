module;	// global module fragment

// ���� �ܺ� ��� �߰�
#include <vector>

// module ����
export module Math;

// import module ...

// submodule
// math.time�� import�ؼ� �ٽ� math ��⿡ �����ؼ� export
export import Math.time;

// 1 ) �Լ� �տ��ٰ� export
export int Add(int a, int b)
{
	return a + b;
}

// 2 ) export�ϰ� ���� �ֵ��� ���� �����ִ�
export
{
	void TestExport() 
	{

	}
}

void Internal() 
{

}

// 3) namespace�� ����
export namespace test
{
	void TestExport2() 
	{

	}
}