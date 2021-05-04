class Solution {
public:
	int minArray(vector<int>& numbers) {
		//暴力法
		//int min=INT_MAX;
		//for(int i=0;i<numbers.size();i++)
		//{
		//    if(numbers[i]<=min)
		//    {
		//      min=numbers[i];
		//}
		//}
		//return min;

		//二分法
		int left = 0;
		int right = numbers.size() - 1;
		while (left<right)
		{
			int mid = (left + right) / 2;
			//int mid = (left + right) >> 1;
			if (numbers[mid]>numbers[right])
			{
				left = mid + 1;
			}
			else if (numbers[mid]<numbers[right])
			{
				right = mid;
			}
			else
			{
				right--;
			}
		}
		return numbers[left];
	}
};