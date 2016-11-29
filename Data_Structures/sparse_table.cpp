int arr[MAX];
int st[LOGMAX][MAX];

// sparse table that holds indices for maximum query.
void build() {
    fori(i, 1, LOGMAX) {
        for(int j = 1; j + (1 << i) - 1 <= n; j++) {
            if(arr[st[i - 1][j]] > arr[st[i - 1][j + (1 << (i - 1))]]) {
                st[i][j] = st[i - 1][j];
            }
            else {
                st[i][j] = st[i - 1][j + (1 << (i - 1))];
            }
        }
    }
}

inline int query(int l, int r) {
    int sz = r - l + 1;
    int lg = 31 - __builtin_clz(sz);
    int ans = -1;
    if(arr[st[lg][l]] > arr[st[lg][r - (1 << lg) + 1]]) {
        ans = st[lg][l];
    }
    else {
        ans = st[lg][r - (1 << lg) + 1];
    }
    return ans;
}