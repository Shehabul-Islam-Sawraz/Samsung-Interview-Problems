#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tsp(int mask, int current, int n, vector<vector<int>> &dp, vector<vector<int>> &dist)
{
    if(current == n-1){
        if(mask == (1<<n)-1){
            return 0;
        }
        return 1e9;
    }
    if(dp[mask][current]!=-1){
        return dp[mask][current];
    }

    int cost = INT_MAX;
    for(int c=0;c<n;c++){
        if((mask & (1<<c)) == 0){
            cost = min(cost, dist[current][c]+tsp((mask | (1<<c)), c, n, dp, dist));
        }
    }
    return dp[mask][current] = cost;
}


int main()
{
    int n;
    for(int t=0;t<10;t++){
        cin >> n;
        n+=2;
        vector<pair<int, int>> coord(n);
        int x,y;

        cin >> x >> y;
        coord[0] = {x, y};

        cin >> x >> y;
        coord[n-1] = {x,y};

        for(int i=1;i<=n-2;i++){
            cin >> x >> y;
            coord[i] = {x, y};
        }

        vector<vector<int>> dist(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = abs(coord[i].first-coord[j].first) + abs(coord[i].second-coord[j].second);
                dist[i][j] = x;
                dist[j][i] = x;
            }
        }

        vector<vector<int>> dp(1<<n, vector<int>(n, -1));
        cout << "# " << t+1 << " " << tsp(1, 0, n, dp, dist) << endl;
    }
    return 0;
}
