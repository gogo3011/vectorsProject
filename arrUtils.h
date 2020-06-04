#ifndef H_ARRUTILS_H
#define H_ARRUTILS_H

template <typename T, unsigned SZ>
T getMax(T arr[]) {
	T max = arr[0];
	for (size_t i = 0; i < SZ; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template <typename T, unsigned SZ>
unsigned getEquCnt(T arr[]) {
	unsigned cnt = 0;
	for (size_t i = 0; i < SZ - 1; i++)
	{
		for (size_t j = i + 1; j < SZ; j++)
		{
			if (arr[i] == arr[j])
				cnt++;
		}
	}
	return cnt;
}

template <typename T, unsigned SZ>
T getAverage(T arr[]) {
	T result = 0;
	for (size_t i = 0; i < SZ; i++)
	{
		result += arr[i];
	}
	return result / SZ;
}
#endif // !H_ARRUTILS_H
