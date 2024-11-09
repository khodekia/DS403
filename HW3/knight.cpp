#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

// ساختار داده‌ای برای ذخیره مختصات و تعداد حرکات
struct Position {
    int x, y, moves;
};

// آرایه‌ای برای نگهداری حرکات ممکن اسب
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

// تابع اصلی BFS برای پیدا کردن کمترین تعداد حرکت
int minKnightMoves(int n, int startX, int startY, int endX, int endY) {
    // بررسی اگر مبدا و مقصد یکسان هستند
    if (startX == endX && startY == endY)
        return 0;

    // صف برای BFS و آرایه‌ای برای نگهداری خانه‌های بازدید شده
    queue<Position> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    // اضافه کردن نقطه شروع به صف
    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        // بررسی تمام حرکات ممکن اسب
        for (int i = 0; i < 8; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            // بررسی محدوده و بازدید نشدن قبلی
            if (newX > 0 && newX <= n && newY > 0 && newY <= n && !visited[newX][newY]) {
                // اگر به مقصد رسیده‌ایم
                if (newX == endX && newY == endY)
                    return current.moves + 1;

                // اضافه کردن موقعیت جدید به صف
                q.push({newX, newY, current.moves + 1});
                visited[newX][newY] = true;
            }
        }
    }

    return -1; // اگر به مقصد نرسیدیم (نباید اتفاق بیافتد)
}

int main() {
    int n, startX, startY, endX, endY;
    cin >> n >> startX >> startY >> endX >> endY;

    int result = minKnightMoves(n, startX, startY, endX, endY);
    cout << result << endl;

    return 0;
}
