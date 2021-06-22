// ʱ�临�Ӷ�: O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = { 0 };
        for (int i = 0; i < magazine.length(); i++) {
            // ͨ��recode���ݼ�¼ magazine������ַ����ִ���
            record[magazine[i] - 'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // ����ransomNote����record���Ӧ���ַ�������--����
            record[ransomNote[j] - 'a']--;
            // ���С����˵��ransomNote����ֵ��ַ���magazineû��
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
