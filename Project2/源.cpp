class Solution {
public:
    int Add(int num1, int num2) {
        int carry;
        int sum;
        if (num2 == 0)
        {
            return num1;
        }
        while (num2)
        {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        }
        return num1;


    }
};