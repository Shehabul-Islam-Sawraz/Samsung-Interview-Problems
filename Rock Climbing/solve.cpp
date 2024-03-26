#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

void moveTo(int n, int m, int x, int y, queue<pair<int, int>> &q, vector<vector<bool>> &visited, vector<vector<int>> &v)
{
    if (x >= n || y >= m || x < 0 || y < 0)
    {
        return;
    }
    if (visited[x][y] == true || v[x][y] == 0)
    {
        return;
    }
    visited[x][y] = true;
    q.push({x, y});
}

int main()
{
    int n, m, x;
    cin >> n >> m;
    vector<vector<int>> v(n);
    int destX = -1, destY = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            v[i].push_back(x);
            if (x == 3)
            {
                destX = i;
                destY = j;
            }
        }
    }

    int currentLevel = n - 1;
    int ans = currentLevel;
    while (currentLevel >= 0)
    {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({n - 1, 0});
        visited[n - 1][0] = true;
        while (q.size() > 0)
        {
            pair<int, int> t = q.front();
            q.pop();
            int valX = t.first;
            int valY = t.second;

            if (valX == destX && valY == destY)
            {
                ans = currentLevel;
                break;
            }

            moveTo(n, m, valX, valY + 1, q, visited, v); // Right
            moveTo(n, m, valX, valY - 1, q, visited, v); // Left
            for (int lv = 1; lv <= currentLevel; lv++)
            {
                moveTo(n, m, valX + lv, valY, q, visited, v); // Top
                moveTo(n, m, valX - lv, valY, q, visited, v); // Bottom
            }
        }
        currentLevel--;
    }

    cout << ans << endl;

    return 0;
}