#include <iostream>
#include <queue>
using namespace std;

int ans = 100;

void flipCol(vector<vector<int>> &mat, int col, int noRow)
{
    for (int i = 0; i < noRow; i++)
    {
        mat[i][col] = !mat[i][col];
        // cout << mat[i][col] << endl;
    }
}

void countNoOneRows(vector<vector<int>> &mat, int noRow, int noCol)
{
    int sum = 0;
    int val = 0;
    for (int i = 0; i < noRow; i++)
    {
        for (int j = 0; j < noCol; j++)
        {
            sum += mat[i][j];
        }
        if (sum == noCol)
        {
            val++;
        }
        sum = 0;
    }
    if (val <= ans && val != 0)
    {
        ans = val;
    }
}

void solve(vector<vector<int>> &mat, int k, int noRow, int noCol)
{
    if (k == 0)
    {
        countNoOneRows(mat, noRow, noCol);
        // cout << "Here: " << ans << endl;
        return;
    }
    for (int i = 0; i < noCol; i++)
    {
        flipCol(mat, i, noRow);
        solve(mat, k - 1, noRow, noCol);
        flipCol(mat, i, noRow);
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n);
    int x;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            mat[i].push_back(x);
        }
    }
    solve(mat, k, n, m);
    cout << ans << endl;
}
