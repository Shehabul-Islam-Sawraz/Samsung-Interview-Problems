#include <iostream>
#include <queue>
using namespace std;

int ans = 0;

void solve(vector<int> &v, vector<bool> &visited, int cost, int left, int n)
{
    if (left == 0)
    {
        if (cost >= ans)
        {
            ans = cost;
        }
        // cout << cost << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            int mulL = 1;
            int mulR = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (visited[j] == false)
                {
                    mulL = v[j];
                    break;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                if (visited[j] == false)
                {
                    mulR = v[j];
                    break;
                }
            }
            // cout << mulL << " " << mulR << endl;
            if (mulL == 1 && mulR == 1)
            {
                mulR = v[i];
            }
            solve(v, visited, cost + mulL * mulR, left - 1, n);
            visited[i] = false;
        }
    }
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    vector<bool> visited;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
        visited.push_back(false);
    }

    solve(v, visited, 0, n, n);

    cout << ans << endl;
}
