countDigitOneclass Solution{
public:
     int NumberOf1Between1AndN_Solution(int n)
    {
    if (n <= 0) return 0;
    if (n < 10) return 1;
    int high = n, pow = 1;// // ȡ�����λ �Լ� ���λ��Ȩ��
    while (high >= 10) {
        high /= 10;
        pow *= 10;
    }
    int last = n - high * pow;// �����λ������
    int cnt = high == 1 ? last + 1 : pow;// high�Ƿ�Ϊ1�����λ��1������ͬ
    return cnt + high * NumberOf1Between1AndN_Solution(pow - 1) + NumberOf1Between1AndN_Solution(last);

    }

};