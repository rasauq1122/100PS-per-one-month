    // vis[idx] : id of node
    // nin : least id of node that I can arrive.

    s.push(idx);
    // memorize path.

    for (auto nxt : edge[idx]) {
        // to find least id of node that I can arrive.
        
        if (!vis[nxt]) nin = min(nin, dfs(nxt, edge, vis, scc, node_cnt, scc_cnt, s));
        else if (!scc[nxt]) nin = min(nin, vis[nxt]); // I found cycle!
    }

    // nin < vis[idx] : I found cycle!
    if (nin == vis[idx]) {
        // I am the least id of node in cycle.        

        scc_cnt++;
        bool okay = true;
        for ( ; !s.empty() && okay ; s.pop()) {
            // stack memorizes path.
            // all nodes in stack is in cycle.
            
            scc[s.top()] = scc_cnt;
            if (s.top() == idx) okay = false; // end of cycle.
        }
    }

    return nin;
}

vector<int> get_scc(int n, vector<vector<int>>& edge) {
    vector<int> scc(n+1);
    vector<int> vis(n+1);
    stack<int> s;
    int node_cnt = 0, scc_cnt = 0;   

    for (int i = 1; i <= n ; i++) if (!vis[i]) dfs(i, edge, vis, scc, node_cnt, scc_cnt, s);

    return scc;
}