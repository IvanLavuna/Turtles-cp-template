vector<bool> vis; 

void dfs(int v, vector<VI> const& adj, vector<int> &output) 
{
    vis[v] = true;
    for (auto u : adj[v])
        if (!vis[u])
            dfs(u, adj, output);
    output.pb(v);
}

void scc(vector<vector<int>> const& adj,
                                  vector<vector<int>> &comps,
                                  vector<vector<int>> &adj_cond) {
    int n = sz(adj);
    comps.clear(), adj_cond.clear();

    vector<int> ord; 

    vis.assign(n, false);

    FOR (i, 0, n)
        if (!vis[i])
            dfs(i, adj, ord);

    vector<vector<int>> adj_rev(n);
    FOR (v, 0, n)
        for (int u : adj[v])
            adj_rev[u].pb(v);

    vis.assign(n, false);
    reverse(all(ord));

    vector<int> roots(n, 0); 

    for (auto v : ord)
    {
		if (!vis[v]) 
		{
            VI comp;
            dfs(v, adj_rev, comp);
            comps.pb(comp);
            int root = *min_element(all(comp));
            for (auto u : comp)
                roots[u] = root;
        }
	}

    adj_cond.assign(n, {});
    FOR (v, 0, n)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].pb(roots[u]);
}
