#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans = 10000000;

void explore(vector<vector<int>> &mat, bool *visited, int current, int cost, int left, int sz)
{
    if (left == 0)
    {
        cost += mat[current][0];
        if (cost <= ans)
        {
            ans = cost;
        }
        // cout << "Here: " << cost << endl;
        return;
    }

    for (int i = 1; i < sz; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            explore(mat, visited, i, cost + mat[current][i], left - 1, sz);
            visited[i] = false;
        }
    }
}

int main()
{
    int t, n;
    int v;
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        cin >> n;
        vector<vector<int>> mat(n);
        bool visited[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v;
                mat[i].push_back(v);
            }
        }
        visited[0] = true;
        explore(mat, visited, 0, 0, n - 1, n);
        cout << ans << endl;
        ans = 10000000;
    }
}
