int search(int begin, int mid, int end)
{
	if (begin > mid && begin > end)
	{
		if (mid > end)
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
	else if (mid > begin && mid > end)
	{
		if (begin > end)
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else if(end>begin&&mid>begin)
	{
		if (begin > mid)
		{
			return mid;
		}
		else
		{
			return begin;
		}
	}
}
int part(vector<int> v, int begin, int end)
{
	mid = (begin + end) / 2;
	int key = search(begin, mid, end);
	//int key = end;//end不为最大
	while (begin < end)
	{
		while (begin<end && v[begin]<v[key])
		{
			begin++;
		}
		while (begin<end && v[end]>v[key])
		{
			end--;
		}
		swap(v[begin], v[end]);
	}
	swap(v[key], v[begin]);
	return key;
}
void quicksort(vector<int> v, int begin, int end)
{
	if (begin < end)
	{
		int mid = part(v, 0, v.size()-1);
		quicksort(v, begin, mid - 1);
		quicksort(v, mid + 1, end);
	}
}