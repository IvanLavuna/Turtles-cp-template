struct TwoSat 
{
    int n, N;
    vector<vector<int>> g;
    vector<vector<int>> comps, g_cond;
    vector<bool> val;

    TwoSat(int _n) : n(_n), N(2 * _n), g(N), val(_n, false) {}

    // add clause (x_a v x_b)
    // na, nb — whether to negate
    void add(int a, bool na, int b, bool nb) 
    {
        int A = 2 * a ^ na;
        int B = 2 * b ^ nb;
        int NA = A ^ 1;
        int NB = B ^ 1;
        g[NA].pb(B);
        g[NB].pb(A);
    }

    bool solve() 
    {
        comps.clear();
        g_cond.clear();

        scc(g, comps, g_cond);

        vector<int> id(N, -1);
        FOR (i, 0, sz(comps))
            for (int v : comps[i])
                id[v] = i;

        FOR (i, 0, n)
            if (id[2 * i] == id[2 * i + 1])
                return false;

        val.assign(n, false);
        FOR (i, 0, n)
            val[i] = (id[2 * i] > id[2 * i + 1]);

        return true;
    }
};
