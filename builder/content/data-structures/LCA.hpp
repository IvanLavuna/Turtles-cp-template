struct LCA
{
    int n;
    vector<int> I; // v -> po(v)
    vector<int> RI;
    vector<int> M; // to index mapping
    vector<int> D;
    SparseTable st;

    LCA(const vector<vector<int>>& adj, int root)
    {
        n = sz(adj);
        I = vector<int>(n);
        RI = vector<int>(n);
        D = vector<int>(n,-1);
        M = vector<int>(2*n, -1);
        int ctr = 0;
        vector<int> a;
        function<void(int, int, int)> preorder = [&](int v, int pr, int d)
        {
            I[v] = ctr++;
            RI[I[v]] = v;
            a.pb(I[v]);
			D[v]=d;
            for(auto to: adj[v])
            {
                if(to != pr)
                {
                    preorder(to, v,d+1);
                    a.pb(I[v]);
                }
            }
        };
        preorder(root, -1,0);
        FOR(i,0,sz(a))st.pb(a[i]);
        FOR(i,0,sz(a)) M[a[i]] = i;
    }
    
    int lca(int u, int v)
    {        
        return RI[st.query(min(M[I[u]], M[I[v]]), max(M[I[u]], M[I[v]])+1)];
    }
};