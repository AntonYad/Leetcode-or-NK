class sum
{
public:
    friend class Solution;
    sum()
    {
        ret = ret + i;
        i++;
    }
    static int getret()
    {
        return ret;
    }
private:
    static int i;
    static int ret;
};
int sum::i = 1;
int sum::ret = 0;
class Solution {
public:
    int sumNums(int n) {
        sum::i = 1;
        sum::ret = 0;
        sum arr[n];
        return sum::getret();

    }
};