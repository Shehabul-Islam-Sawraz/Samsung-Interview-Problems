#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxCoins;

int dc[3] = {-1, 0, 1};

void playGame(int r, int c, int coins, bool useBomb, int safeRows, vector<vector<int>>&grid)
{
    if(r==0){
        maxCoins = max(coins, maxCoins);
        return;
    }

    for(int i=0;i<3;i++){
        int nr = r-1;
        int nc = c + dc[i];

        if(nr>=0 && nc>=0 && nc<5){
            if(grid[nr][nc]==2){
                if(!useBomb){
                    playGame(nr, nc, coins, true, 5, grid);
                }
                else{
                    if(safeRows>0){
                        playGame(nr, nc, coins, useBomb, safeRows-1, grid);
                    }
                    else{
                        continue;
                    }
                }
            }
            else{
                playGame(nr, nc, coins+grid[nr][nc], useBomb, safeRows-(safeRows>0), grid);
            }
        }
    }
}

int main()
{
    int t, n, x;
    cin >> t;
    for(int loop=1;loop<=t;loop++){
        cin >> n;
        vector<vector<int>> grid(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin >> x;
                grid[i].push_back(x);
            }
        }

        maxCoins = 0;
        playGame(n, 2, 0, false, 0, grid);
        cout << "#" << loop << " " << maxCoins << endl;
    }
    return 0;
}
