#include <iostream>
#include <queue>
using namespace std;

int ans = 1000000;

class Point
{
public:
    int x, y;
    Point()
    {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int distance(Point &b)
    {
        return abs(this->x - b.x) + abs(this->y - b.y);
    }
};

void solve(Point *customers, vector<bool> &visited, Point current, Point home, int n, int total, int dist)
{
    if (n == 0)
    {
        dist += current.distance(home);
        if (dist <= ans)
        {
            ans = dist;
        }
        return;
    }

    for (int i = 0; i < total; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            solve(customers, visited, customers[i], home, n - 1, total, dist + current.distance(customers[i]));
            visited[i] = false;
        }
    }
}

int main()
{
    int n;
    Point office, home;
    Point *customers;
    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        customers = new Point[n];
        vector<bool> visited;
        cin >> office.x >> office.y >> home.x >> home.y;
        for (int j = 0; j < n; j++)
        {
            cin >> customers[j].x >> customers[j].y;
            visited.push_back(false);
        }
        solve(customers, visited, office, home, n, n, 0);
        cout << "# " << i + 1 << " " << ans << endl;
        ans = 1000000;
        free(customers);
    }
}
