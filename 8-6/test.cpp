bool Is_in(vector<int> num, int target)
{
	int left = 0;
	int right = num.size() - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (num[mid] == target)
		{
			return true;
		}


		if (target > num[left] && target < num[mid])
		{
			if()
				right = mid - 1;
		
			else		
				left = left + 1;
		}
		else if(target>num[mid]&&target<num[right])
		{
			if ()
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return false;
}