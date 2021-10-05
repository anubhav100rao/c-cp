/*
input.txt content

6
4 1 10 12 5 2
21

*/


#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define int long long
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"

bool isSubset(int sum, int idx, vector<int>&arr) {
    if(sum == 0) return true;
    if(sum < 0) return false;
    if(idx <= 0) return false;
    return isSubset(sum - arr[idx-1], idx-1, arr) || isSubset(sum, idx-1, arr); 
}

bool isSubsetDp(int sum, vector<int>&arr) {
    int n = arr.size();
    bool dp[n+1][sum+1] = {false};
    for(int i = 0; i<=n; i++)
        dp[i][0] = true;
    for(int i = 1; i<=sum; i++)
        dp[0][i] = false;

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=sum; j++) {
            if(arr[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }
    // for(int i = 0; i<=n; i++) {
    //     for(int j = 0; j<=sum; j++) cout << dp[i][j] << " ";
    //         cout << "\n";
    // }
    return dp[n][sum];
}

bool isSubsetPowerFullDp(int sum, vector<int>&arr) {
    int n = arr.size();
    bool dp[2][sum + 1] = { false };
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=sum; j++) {
            if(j == 0) dp[i%2][j] = true;
            else if(i == 0) dp[i%2][j] = false;
            else if(arr[i-1] > j) {
                dp[i%2][j] = dp[(i+1)%2][j];
            } else {
                dp[i%2][j] = dp[(i+1)%2][j] || dp[(i+1)%2][j - arr[i-1]];
            }
        }
    }
    return dp[n%2][sum];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    # endif
    int n; cin >> n;
    vector<int>arr(n, 0);
    for(int &i: arr) cin >> i;
    int sum; cin >> sum;
    cout << isSubsetDp(sum, arr) << "\n";
    cout << isSubsetPowerFullDp(sum, arr) << "\n";
    return 0;
}