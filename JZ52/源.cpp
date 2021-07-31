/*
要分为几种情况：（状态机）
匹配只可能是：两者相等 或者  S！=‘\0’ && p == .

（1）当第二个字符不为‘*’时：匹配就是将字符串和模式的指针都下移一个，不匹配就直接返回false
（2）当第二个字符为'*'时：
        匹配：
                a.字符串下移一个，模式不动  abc  a*bc
                c.字符串不动，模式下移两个   abc  .*abc或者 .*bc
        不匹配：字符串下移不动，模式下移两个   abc  b*abc
搞清楚这几种状态后，用递归实现即可：
*/
class Solution {
public:
    bool match(char* str, char* pattern) {
        if (str[0] == '\0' && pattern[0] == '\0')
            return true;
        else if (str[0] != '\0' && pattern[0] == '\0')
            return false;
        if (pattern[1] != '*') {
            if (str[0] == pattern[0] || (pattern[0] == '.' && str[0] != '\0'))
                return match(str + 1, pattern + 1);
            else
                return false;
        }
        else {
            if (str[0] == pattern[0] || (pattern[0] == '.' && str[0] != '\0'))
                return match(str, pattern + 2) || match(str + 1, pattern);
            else
                return match(str, pattern + 2);
        }
    }
};
