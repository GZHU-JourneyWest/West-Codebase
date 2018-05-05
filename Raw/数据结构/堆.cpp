long long arr[maxN];  // 待排序数组，0-based

// 下沉操作
void perc_down(long long *arr, int i, int n)
{
	auto lson = [](int x){ return 2*x+1; };
	auto rson = [](int x){ return 2*x+2; }; 
	while (true)
	{
		int l = lson(i), r = rson(i);
		if (l<n) {
			int mx = (r<n && arr[r]>arr[l] ? r : l);
			if (arr[i] < arr[mx]) {
				swap(arr[i], arr[mx]);
				i = mx; 
			} 
			else break; 
		} 
		else break; 
	}
}

// 堆排序
void heap_sort(long long *arr, int n)
{
	for (int i = n-1; i>=0; --i)  // 创建堆
	{
		perc_down(arr, i, n); 
	}
	for (int i = n-1; i; --i)  // 输出排序结果
	{
		swap(arr[0], arr[i]);
		perc_down(arr, 0, i); 
	}
}