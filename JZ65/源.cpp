class Solution {
public:


    bool dfs(vector<vector<char>>& board, char* str, int index, int x, int y,
        vector<vector<bool>>& visited)

    {
        if (index == strlen(str)) return true;//��Ѱ����·�����ȣ���������������true��//��ʱ�Ѿ��������̶��� strlen���ز��� ��\0���ĳ��ȣ���ʱstr[k]�Ѿ�Խ���ˣ���������ж�һ��Ҫ���ں�����ͷ���������if֮��str[k]��Խ��
        if ((x < 0) || (y < 0) || (x >= board.size()) || (y >= board[0].size()))
            return false;//����Խ�磬��ֹ������false
        if (visited[x][y]) return false;//֮ǰ���ʹ�����֦
        if (board[x][y] != str[index]) return false;//����ȣ���֦
        visited[x][y] = true;
        if (dfs(board, str, index + 1, x, y - 1, visited) || //��
            dfs(board, str, index + 1, x, y + 1, visited) ||     //��
            dfs(board, str, index + 1, x - 1, y, visited) ||     //��
            dfs(board, str, index + 1, x + 1, y, visited))      //��
            return true; //�з���Ҫ���

        visited[x][y] = false;//�ǵô˴��Ļ�false���Է�����һ�α���������
        return false;
    }

    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (str == NULL || rows <= 0 || cols <= 0)
            return false;
        vector<vector<char>> board(rows, vector<char>(cols));
        for (int i = 0; i < rows; ++i) {//��matrixװ���ά����board��
            for (int j = 0; j < cols; ++j) {
                board[i][j] = matrix[i * cols + j];
            }
        }
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, str, 0, i, j, visited) == true)
                    return true;//�Ծ���board�е�ÿ���ַ�Ϊ�����й����������
                //�ҵ�һ�����������ļ�����true.
            }
        }
        return false;//�����궼û�ҵ�ƥ���·��������false
    }



};