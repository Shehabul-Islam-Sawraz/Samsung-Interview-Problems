#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int ans = 0;

void game(int x, int y, int points, bool useBomb, int n, vector<vector<int>> &mat, int count)
{
    if (points > ans)
    {
        ans = points;
    }
    int row, col;
    for (int i = -1; i <= 1; i++)
    {
        row = x - 1;
        col = y + i;
        if (row >= 0 && row < n && col >= 0 && col < 5)
        {
            if ((mat[row][col] == 0 || mat[row][col] == 1) && useBomb == true)
            {
                game(row, col, points + mat[row][col], true, n, mat, count + 1);
            }
            else if ((mat[row][col] == 0 || mat[row][col] == 1) && useBomb == false)
            {
                game(row, col, points + mat[row][col], false, n, mat, count);
            }
            else if (mat[row][col] == 2 && useBomb == true)
            {
                if (count >= 5)
                {
                    break;
                }
                game(row, col, points, true, n, mat, count + 1);
            }
            else if (mat[row][col] == 2 && useBomb == false)
            {
                game(row, col, points, true, n, mat, count);
            }
        }
    }
}

int main()
{
    int t, n, x;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<vector<int>> mat(n);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> x;
                mat[j].push_back(x);
            }
        }
        game(n, 2, 0, false, n, mat, 0);
        cout << "#" << i + 1 << " " << ans << endl;
        ans = 0;
    }
}
