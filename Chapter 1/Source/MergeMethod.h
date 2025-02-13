#pragma once
#include <vector>
#include <type_traits>
#include <algorithm>
#include <functional>

/// <summary> 有序数组的交集、差集、并集 </summary>
/// <typeparam name="IsUnique"> 是否为非重复数组 </typeparam>
/// <param name="ContainerA"></param>
/// <param name="ContainerB"></param>
/// <returns></returns>

template <bool IsUnique = false>
std::vector<int> Intersection(const std::vector<int>& ContainerA, const std::vector<int>& ContainerB)
{
	int ALen = (int)ContainerA.size();
	if (ALen < 1)
	{
		return {};
	}

	int BLen = (int)ContainerB.size();
	if (BLen < 1)
	{
		return {};
	}

	std::vector<int> Result;
	int i = 0, j = 0;

	while ((i < ALen) && (j < BLen))
	{
		if constexpr (!IsUnique)
		{
			//每一轮i、j都会指向相同元素的最后一个
			//对于交集，循环结束时遗留的元素无需加入结果数组
			while (i + 1 < ALen && ContainerA[i] == ContainerA[i + 1])
			{
				i++;
			}

			while (j + 1 < ALen && ContainerB[j] == ContainerB[j + 1])
			{
				j++;
			}
		}

		int AElem = ContainerA[i];
		int BElem = ContainerB[j];

		if (AElem < BElem)
		{
			++i;
		}
		else if (BElem < AElem)
		{
			++j;
		}
		else
		{
			Result.push_back(AElem);
			++i, ++j;
		}
	}

	return Result;
}

template <bool IsUnique = false>
std::vector<int> Difference(const std::vector<int>& ContainerA, const std::vector<int>& ContainerB)
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

	std::vector<int> Result;
	int i = 0, j = 0;

	while ((i < ALen) && (j < BLen))
	{
		if constexpr (!IsUnique)
		{
			//每一轮i、j都会指向相同元素的最后一个
			//因此对于差集，当循环结束时总是会遗留至少1个元素
			while (i + 1 < ALen && ContainerA[i] == ContainerA[i + 1])
			{
				i++;
			}

			while (j + 1 < ALen && ContainerB[j] == ContainerB[j + 1])
			{
				j++;
			}
		}

		int AElem = ContainerA[i];
		int BElem = ContainerB[j];

		if (AElem < BElem)
		{
			Result.push_back(AElem);
			++i;
		}
		else if (BElem < AElem)
		{
			Result.push_back(BElem);
			++j;
		}
		else
		{
			++i, ++j;
		}
	}


	while (i < ALen)
	{
		if constexpr (!IsUnique)
		{
			int AElem = ContainerA[i];
			if (AElem != Result.back())
			{
				Result.push_back(AElem);
			}
			i++;
		}
		else
		{
			Result.reserve(Result.size() + ALen - i);
			while (i < ALen)
			{
				Result.push_back(ContainerA[i]);
				i++;
			}
			break;
		}
	}

	while (j < BLen)
	{
		if constexpr (!IsUnique)
		{
			int BElem = ContainerB[j];
			if (BElem != Result.back())
			{
				Result.push_back(BElem);
			}
			j++;
		}
		else
		{
			Result.reserve(Result.size() + BLen - j);
			while (j < BLen)
			{
				Result.push_back(ContainerB[j]);
				j++;
			}
			break;
		}
	}

	return Result;
}