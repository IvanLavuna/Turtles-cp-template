/**
 * Description: Finds strongly connected components in DAG sorted in topological order.
 * Time: O(n+m)
 **/
template <class E> struct csr
{
    VI start;
    vector<E> elist;
    explicit csr(int n, const vector<pair<int, E>>& edges)
        : start(n + 1), elist(edges.size())
        {
        for (auto e : edges)
        {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++)
        {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges)
        {
            elist[counter[e.first]++] = e.second;
        }
    }
};

struct scc_graph
{
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices()
    {
		return _n;
	}

    void add_edge(int from, int to)
    {
		edges.pb({from, {to}});
	}

    // @return pair of (# of scc, scc id)
    pair<int, vector<int>> scc_ids()
    {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void
        {
            low[v] = ord[v] = now_ord++;
            visited.pb(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++)
            {
                auto to = g.elist[i].to;
                if (ord[to] == -1)
                {
                    self(self, to);
                    low[v] = min(low[v], low[to]);
                }
                else
                {
                    low[v] = min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v])
            {
                while (true)
                {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        FOR(i,0,_n)
        {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids)
        {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }
   
    /*
     * The list of "list of the vertices" are sorted in topological order.
     */
    vector<vector<int>> scc()
    {
        auto ids = scc_ids();
        int group_num = ids.first;
        vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        vector<vector<int>> groups(ids.first);
		FOR(i,0,group_num)
            groups[i].reserve(counts[i]);
		FOR(i,0,_n)
            groups[ids.second[i]].push_back(i);
        return groups;
    }

  private:
    int _n;
    struct edge
    {
        int to;
    };
    vector<pair<int, edge>> edges;
};