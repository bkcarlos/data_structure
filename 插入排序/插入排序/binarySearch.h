int binary_search(int array[], int low, int height, int searchKey)
{
	while (low <= height)
	{
		int mid = low + (height - low) / 2;

		if (searchKey > array[mid])
		{
			low = mid + 1;
		}
		else if (searchKey < array[mid])
		{
			height = mid - 1;
		}
	}
	return low;
}