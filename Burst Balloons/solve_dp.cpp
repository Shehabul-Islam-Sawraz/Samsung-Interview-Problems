#include <iostream>
#include <vector>

using namespace std;

int burst_baloon(int l, int r, int maxInd, vector<int> val, vector<vector<int>>&dp)
{
    if(r<l){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    int curr_max = val[l];
    for(int i=l;i<=r;i++){
        int curr_val = 0;
        if(l==0 && r==maxInd){
            curr_val=val[i] + burst_baloon(l, i-1, maxInd, val, dp) + burst_baloon(i+1, r, maxInd, val, dp);
        }
        else{
            int left=1, right=1;
            if(l>0){
                left = val[l-1];
            }
            if(r<maxInd){
                right = val[r+1];
            }
            curr_val = left*right + burst_baloon(l, i-1, maxInd, val, dp) + burst_baloon(i+1, r, maxInd, val, dp);
        }

        curr_max = max(curr_max, curr_val);
    }

    return dp[l][r] = curr_max;
}


int main()
{
    int n, x;
    cin >> n;
    vector<int> val;
    for(int i=0;i<n;i++){
        cin >> x;
        val.push_back(x);
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << burst_baloon(0, n-1, n-1, val, dp);
    return 0;
}
