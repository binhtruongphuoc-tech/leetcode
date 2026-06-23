int uniquePaths(int m, int n) {
    long long ans = 1;
    
    int k = (m < n) ? m - 1 : n - 1;
    int N = m + n - 2;
    
    for (int i = 1; i <= k; i++) {
        ans = ans * (N - i + 1) / i;
    }
    
    return (int)ans;
}