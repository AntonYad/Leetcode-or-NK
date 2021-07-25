class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        if (height.size() <= 2)
        {
            return sum;
        }
        for (int i = 1; i <= height.size() - 2; i++)
        {
            int l, r;
            r = i + 1;
            l = i - 1;
            int maxl = height[i];
            int maxr = height[i];
            while (r <= height.size() - 1)
            {
                if (maxr < height[r])
                {
                    maxr = height[r];
                }
                r++;
            }
            while (l >= 0)
            {
                if (maxl < height[l])
                {
                    maxl = height[l];
                }
                l--;
            }
            int h = min(maxl, maxr) - height[i];
            if (h > 0)
            {
                sum += h;
            }
        }
        return sum;
    }
};