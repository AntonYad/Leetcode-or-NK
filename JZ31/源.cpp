countDigitOneclass Solution{
public:
     int NumberOf1Between1AndN_Solution(int n)
    {
    if (n <= 0) return 0;
    if (n < 10) return 1;
    int high = n, pow = 1;// // 取出最高位 以及 最高位的权重
    while (high >= 10) {
        high /= 10;
        pow *= 10;
    }
    int last = n - high * pow;// 除最高位的数字
    int cnt = high == 1 ? last + 1 : pow;// high是否为1，最高位的1个数不同
    return cnt + high * NumberOf1Between1AndN_Solution(pow - 1) + NumberOf1Between1AndN_Solution(last);

    }

};