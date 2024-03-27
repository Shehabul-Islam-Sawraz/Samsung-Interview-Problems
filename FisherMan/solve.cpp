#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int ans = 1000000;

void solve(int index, int current, int cost, int total, int *gate, int *fisherman, int n)
{
    if (current == total)
    {
        if (cost < ans)
        {
            ans = cost;
        }
        return;
    }

    if (index > n)
    {
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (fisherman[i] > 0)
        {
            fisherman[i]--;
            solve(index + 1, current + 1, cost + 1 + abs(gate[i] - index), total, gate, fisherman, n);
            fisherman[i]++;
        }
    }

    solve(index + 1, current, cost, total, gate, fisherman, n);
}

int main()
{
    int n;
    cin >> n;
    int gate[3];
    int fisherman[3];
    cin >> gate[0] >> gate[1] >> gate[2];
    cin >> fisherman[0] >> fisherman[1] >> fisherman[2];
    int total = fisherman[0] + fisherman[1] + fisherman[2];
    solve(1, 0, 0, total, gate, fisherman, n);

    cout << ans << endl;
    return 0;
}
