#pragma once
#include <vector>
#include <type_traits>
#include <algorithm>
#include <functional>


//注意const_iterator的使用
template<typename ElemType>
bool FindLastElemPos(typename std::vector<ElemType>::const_iterator& Start,
	typename std::vector<ElemType>::const_iterator End)
{
	if (End <= Start) return false;

	auto Next = Start;
	std::advance(Next, 1);

	while (Next != End)
	{
		if (*Start == *Next)
		{
			std::advance(Start, 1);
			std::advance(Next, 1);
		}
		else
		{
			break;
		}
	}
	return true;
}

/// <summary> 求交集 </summary>
/// <typeparam name="ElemType"></typeparam>
/// <typeparam name="Operation"></typeparam>
/// <typeparam name="IsUniqueElem"></typeparam>
/// <param name="ContainerA"></param>
/// <param name="ContainerB"></param>
/// <returns> 无重复元素数组 </returns>
template <typename ElemType, bool IsUniqueElem = std::true_type::value>
std::vector<ElemType> Intersection(const std::vector<ElemType>& ContainerA, const std::vector<ElemType>& ContainerB)
{
	int ALen = (int)ContainerA.size();
	if (ALen < 1)
	{
		return ContainerB;
	}

	int BLen = (int)ContainerB.size();
	if (BLen < 1)
	{
		return ContainerA;
	}

	std::vector<ElemType> Result;

	if constexpr (IsUniqueElem)
	{
		int i = 0, j = 0;
		//无重复元素
		while (i < ALen && j < BLen)
		{
			if (ContainerA[i] < ContainerB[j])
			{
				i++;
			}
			else if (ContainerA[j] < ContainerB[i])
			{
				j++;
			}
			else
			{
				Result.push_back(ContainerA[i]);
				i++;
				j++;
			}
		}
	}
	else
	{
		auto StartA = ContainerA.begin();
		auto StartB = ContainerB.begin();
		auto EndA = ContainerA.end();
		auto EndB = ContainerB.end();

		while ((StartA != EndA) && (StartB != EndB))
		{
			if (!FindLastElemPos<ElemType>(StartA, EndA) || !FindLastElemPos<ElemType>(StartB, EndB))
			{
				return {};
			}

			if (*StartA < *StartB)
			{
				std::advance(StartA, 1);
			}
			else if (*StartB < *StartA)
			{
				std::advance(StartB, 1);
			}
			else
			{
				Result.push_back(*StartA);
				std::advance(StartA, 1);
				std::advance(StartB, 1);
			}
		}
	}

	return Result;
}
