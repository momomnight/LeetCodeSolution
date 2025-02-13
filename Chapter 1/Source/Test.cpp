#include "MergeMethod.h"
#include <iostream>
#include <string>

template <typename Container>
void Print(const Container& Con, std::string Str)
{
	std::cout << Str << "\t";
	for (auto& Temp : Con)
	{
		std::cout << Temp << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> A{1, 1,2,4, 5,8,8,8};
	std::vector<int> B{ 1,3, 3,4, 4,5,7,7,10};
	std::vector<int> C{ 1,2,4, 5, 8 };
	std::vector<int> D{ 1, 3, 4, 5, 7,10 };
	std::vector<int> IntersectionTestFalse = Intersection<false>(A, B);
	std::vector<int> DifferenceTestFalse = Difference<false>(A, B);
	std::vector<int> IntersectionTestTrue = Intersection<true>(C, D);
	std::vector<int> DifferenceTestTrue = Difference<true>(C, D);

	Print(A, "������");
	Print(B, "������");
	Print(IntersectionTestFalse, "�������ظ���");
	Print(DifferenceTestFalse, "����ظ���");

	Print(C, "������");
	Print(D, "������");
	Print(IntersectionTestTrue, "�������ظ���");
	Print(DifferenceTestTrue, "����ظ���");
	return 0;
}