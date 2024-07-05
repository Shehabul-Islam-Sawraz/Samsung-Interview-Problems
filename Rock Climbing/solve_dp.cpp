#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int isValid(int r, int c, int m, vector<vector<int>>&grid)
{
    return c>=0 && c<m && grid[r][c]>0;
}

void bfs(int r, int c, vector<vector<int>>&grid, vector<vector<int>>&dp, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({r,c});

    while(!q.empty()){
        int l = q.front().first;
        int r = q.front().second;
        q.pop();

        if(isValid(l, r+1, m, grid) && dp[l][r+1]>dp[l][r]){
            dp[l][r+1] = dp[l][r];
            q.push({l, r+1});
        }

        if(isValid(l, r-1, m, grid) && dp[l][r-1]>dp[l][r]){
            dp[l][r-1] = dp[l][r];
            q.push({l, r-1});
        }

        for(int x=0;x<n;x++){
            if(x!=l && grid[x][r]>0){
                int dis = max(abs(x-l), dp[l][r]);
                if(dp[x][r]>dis){
                    dp[x][r] = dis;
                    q.push({x, r});
                }
            }
        }
    }
}

int main()
{
    int n, m, x;
    cin >> n >> m;

    vector<vector<int>> grid(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> x;
            grid[i].push_back(x);
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, n-1));
    dp[n-1][0] = 0;
    bfs(n-1, 0, grid, dp, n, m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==3){
                cout << dp[i][j] << endl;
                return 0;
            }
        }
    }
    return 0;
}
