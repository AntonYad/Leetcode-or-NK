/*
Ҫ��Ϊ�����������״̬����
ƥ��ֻ�����ǣ�������� ����  S��=��\0�� && p == .

��1�����ڶ����ַ���Ϊ��*��ʱ��ƥ����ǽ��ַ�����ģʽ��ָ�붼����һ������ƥ���ֱ�ӷ���false
��2�����ڶ����ַ�Ϊ'*'ʱ��
        ƥ�䣺
                a.�ַ�������һ����ģʽ����  abc  a*bc
                c.�ַ���������ģʽ��������   abc  .*abc���� .*bc
        ��ƥ�䣺�ַ������Ʋ�����ģʽ��������   abc  b*abc
������⼸��״̬���õݹ�ʵ�ּ��ɣ�
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
