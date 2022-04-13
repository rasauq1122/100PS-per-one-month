int sub_node_dfs(vector<vector<int>>& edge, int idx, vector<int>& sub_node, int par = -1) {
    int sum = 1;

    each(edge[idx], nxt) 
        if (nxt != par) sum += sub_node_dfs(edge, nxt, sub_node, idx);

    return sub_node[idx] = sum;
}

void centroid(vector<vector<int>>& edge, int idx, vector<int>& ans, vector<int>& sub_node, int n, int par = -1) {
    pair<int, int> nax = {0, -1};
    for(auto nxt : edge[idx]) 
        if (nxt != par) nax = max(nax, {sub_node[nxt], nxt});

    if (nax.first*2 > n) 
        centroid(edge, nax.second, ans, sub_node, n, idx);
    else {
        ans.push_back(idx);
        if (nax.first*2 == n) ans.push_back(nax.second);
    }
}

/*
1. 한 점을 루트로 삼고, 각 점에 대해 그 점을 루트 노드로 하는 서브 트리의 노드 개수를 구한다. 
    sub_node_dfs로 sub_node 배열을 채운다. sub_node[i]는 i를 루트로 하는 서브 트리 노드의 개수다.

2. 서브 트리의 노드 개수가 n/2를 넘는 정점만 방문하여 센트로이드를 구한다.
    centroid로 ans 배열을 채운다. ans에는 센트로이드인 정점으로 채워진다.
*/