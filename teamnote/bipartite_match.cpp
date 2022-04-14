bool bm_dfs(int idx, vector<vector<int>>& edge, vector<int>& vis, vector<int>& aM, vector<int>& bM) {
    if (vis[idx]) return false;
    vis[idx] = true;

    for (auto nxt : edge[idx]) {
        if (bM[nxt] == -1 || // nxt가 아직 매칭이 되지 않았거나
            (!vis[bM[nxt]] && bm_dfs(bM[nxt], edge, vis, aM, bM))) { // nxt의 매칭을 해제하고 바꿀 수 있는 경우라면
            bM[nxt] = idx;
            aM[idx] = nxt;
            return true;
        }
    }

    return false;
}

int bipartite_match(vector<vector<int>>& edge, int n, int m) {
    vector<int> aM = vector<int>(n, -1);
    vector<int> bM = vector<int>(m, -1);

    int rtn = 0;
    for (int i = 0 ; i < n ; i++) {
        vector<int> vis = vector<int>(n);
        if (bm_dfs(i, edge, vis, aM, bM)) rtn++;
    }
    return rtn;
}