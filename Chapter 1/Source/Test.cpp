#include "MergeMethod.h"
#include <iostream>

template <typename Container>
void Print(const Container& Con)
{
	for (auto& Temp : Con)
	{
		std::cout << Temp << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> A{1, 1,2,4, 5,8};
	std::vector<int> B{ 1,3, 3,4, 4,5,8,10};
	std::vector<int> C = Intersection<int, false>(A, B);

	Print(C);
	return 0;
}