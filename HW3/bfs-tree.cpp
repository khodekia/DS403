#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isInBounds(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void bfs(int x, int y, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
    int m = matrix.size();
    int n = matrix[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isInBounds(nx, ny, m, n) && matrix[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int countForests(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int forestCount = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                bfs(i, j, matrix, visited);
                forestCount++;
            }
        }
    }

    return forestCount;
}

int minDaysToMakeBadMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    if (countForests(matrix) != 1) return 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {

                matrix[i][j] = 0;
                if (countForests(matrix) != 1) {
                    return 1;
                }
                matrix[i][j] = 1;
            }
        }
    }
    return 2; 
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cout << minDaysToMakeBadMatrix(matrix) << endl;

    return 0;
}

