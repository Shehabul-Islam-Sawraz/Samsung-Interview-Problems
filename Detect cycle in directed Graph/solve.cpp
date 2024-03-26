#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void dfs(int v, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &path, vector<vector<int>> &cycles)
{
    visited[v] = true;
    path.push_back(v);

    for (int t = 0; t < graph[v].size(); t++)
    {
        int x = graph[v][t];
        if (!visited[x])
        {
            dfs(x, graph, visited, path, cycles);
        }
        else
        {
            int found = false;
            for (int i = 0; i < path.size(); i++)
            {
                if (path[i] == x)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                // Cycle Found
                vector<int> cycle;
                for (int i = path.size() - 1; i >= 0; i--)
                {
                    cycle.push_back(path[i]);
                    if (path[i] == x)
                    {
                        break;
                    }
                }
                int len = cycle.size();
                for (int i = 0; i <= len / 2; i++)
                {
                    int temp = cycle[i];
                    cycle[i] = cycle[len - 1 - i];
                    cycle[len - 1 - i] = temp;
                }
                cycles.push_back(cycle);
            }
        }
    }

    path.pop_back();
    visited[v] = false;
}

vector<int> findAllCycles(vector<vector<int>> &graph, int n)
{
    vector<bool> visited(n, false);
    vector<int> path;
    vector<vector<int>> cycles;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited, path, cycles);
        }
    }

    vector<int> minVec;
    int minSum = 1000000;
    for (int i = 0; i < cycles.size(); i++)
    {
        int sum = 0;
        for (int x : cycles[i])
        {
            sum += x;
        }
        if (sum <= minSum)
        {
            minSum = sum;
            minVec = cycles[i];
        }
    }

    return minVec;
}

void sortVec(vector<int> &ans)
{

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = i + 1; j < ans.size(); j++)
        {
            if (ans[j] < ans[i])
            {
                int temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
        }
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
    }

    vector<int> ans = findAllCycles(graph, n);
    sortVec(ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}
