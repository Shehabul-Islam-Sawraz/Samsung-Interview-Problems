#include <iostream>
#include <vector>

using namespace std;

int getLeft(int pos, vector<bool>&vis, int n)
{
    if(pos<0){
        return INT_MAX;
    }
    int dis = 0;
    for(int i=pos-1;i>=0;i--){
        dis++;
        if(!vis[i]){
            return dis;
        }
    }
    return INT_MAX;
}

int getRight(int pos, vector<bool>&vis, int n)
{
    if(pos>=n){
        return INT_MAX;
    }
    int dis = 0;
    for(int i=pos+1;i<n;i++){
        dis++;
        if(!vis[i]){
            return dis;
        }
    }
    return INT_MAX;
}

int distForGate(int gate, int n, vector<int>&gates, vector<int>&mens, vector<bool>&vis)
{
    int gatePos = gates[gate]-1;
    int dis = 0;

    for(int i=0;i<mens[gate];i++){
        if(!vis[gatePos]){
            dis+=1;
            vis[gatePos] = true;
        }
        else{
            int l = getLeft(gatePos, vis, n);
            int r = getRight(gatePos, vis, n);

            if(l<r){
                if(gatePos-l>=0){
                    vis[gatePos-l] = true;
                }
                dis+=l+1;
            }
            else{
                if(gatePos+r<n){
                    vis[gatePos+r] = true;
                }
                dis+=r+1;
            }
        }
    }
    return dis;
}

int findDist(vector<int>&comb, int n, vector<int>&gates, vector<int>&mens)
{
    vector<bool> vis(n, false);
    int dis=0;
    for(int i=0;i<comb.size();i++){
        dis+=distForGate(comb[i], n, gates, mens, vis);
    }
    return dis;
}

int main()
{
    int n, x;
    vector<int> gates;
    vector<int> mens;
    cin >> n;
    for(int i=0;i<3;i++){
        cin >> x;
        gates.push_back(x);
    }

    for(int i=0;i<3;i++){
        cin >> x;
        mens.push_back(x);
    }

    vector<vector<int>> comb = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 0},
        {1, 0, 2},
        {2, 1, 0},
        {2, 0, 1}
    };

    int minDist = INT_MAX;
    for(int i=0;i<comb.size();i++){
        minDist = min(minDist, findDist(comb[i], n, gates, mens));
    }

    cout << minDist << endl;
    return 0;
}
