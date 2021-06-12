#include<vector>
#include<iostream>
#include<string>
using namespace std;
int index[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int cnt;
void DFS(vector<vector<int>>& book, vector<string>& board, int start_row, int start_col, int row, int col) {
    if ((board[start_row][start_col] == '.' && book[start_row][start_col] == 0) || board[start_row][start_col] == '@')
        cnt++;
    if (board[start_row][start_col] == '#')
        return;
    //����ǰ�������Ƚ��б��
    book[start_row][start_col] = 1;
    //����������ȱ���
    for (int k = 0; k < 4; ++k) {

        int new_row = start_row + index[k][0];
        int new_col = start_col + index[k][1];
        if (new_row < 0 || new_row >= row || new_col < 0 || new_col >= col) {
            continue;
        }
        if (board[new_row][new_col] == '.' && book[new_row][new_col] == 0) {
            DFS(book, board, new_row, new_col, row, col);
        }
    }
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        //������ά����
        vector<string> path(N);
        vector<vector<int>> book(N, vector<int>(M, 0));
        for (auto& e : path) {
            cin >> e;
        }
        //�ҵ���@����ʼλ��
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < path[0].size(); ++j) {
                if (path[i][j] == '@') {
                    //����������ȱ���
                    DFS(book, path, i, j, N, M);
                }
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}
