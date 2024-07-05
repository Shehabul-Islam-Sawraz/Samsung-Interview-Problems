#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int flip_cols(int n, int m, int k, vector<vector<int>>&v)
{
    unordered_map<string, int> freq;
    for(int i=0;i<n;i++){
        string temp;
        int zeros = 0;

        for(int j=0;j<m;j++){
            if(v[i][j] == 0){
                zeros++;
                temp+=('0'+v[i][j]);
            }
        }

        if(zeros<=k && (k-zeros)%2==0){
            freq[temp]++;
        }
    }
    int ans = INT_MIN;
    for(auto x:freq){
        ans = max(ans, x.second);
    }
    return ans;
}

int main()
{
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<vector<int>> v(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> x;
            v[i].push_back(x);
        }
    }

    cout << flip_cols(n, m, k, v) << endl;
}
