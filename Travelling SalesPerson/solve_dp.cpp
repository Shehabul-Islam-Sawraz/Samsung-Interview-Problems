#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int tsp(int mask, int current, int n, vector<vector<int>> dist, vector<vector<int>>&dp)
{
    if(mask == (1<<n)-1){
        return dist[current][0];
    }
    if(dp[mask][current]!=-1){
        return dp[mask][current];
    }
    int cost = INT_MAX;
    for(int c=0;c<n;c++){
        if((mask & (1<<c)) == 0){
            cost = min(cost, dist[current][c]+tsp(mask | (1<<c), c, n, dist, dp));
        }
    }
    return dp[mask][current] = cost;
}

int main()
{
    int t, n, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<vector<int>> dist(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> x;
                dist[i].push_back(x);
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        cout << tsp(1, 0, n, dist, dp) << endl;
    }
    return 0;
}
