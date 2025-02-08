// segment tree with sum binary operation
struct SegTree
{
    vector<ll> T;
    int n;

    // Root of the tree has index 1.
    // Zero based indexing of A.
    SegTree(const vector<ll>& A)
    {
        n = sz(A);
        T = vector<ll>(2*n, 0);
        for (int i = 0; i < n; ++i)
            T[i+n] = A[i];
        build();
    }

    SegTree(int n)
    {
        this->n = n;
        T = vector<ll>(2*n, 0);
    }

    // [l; r)
    ll query(int l, int r)
    {
        ll res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if(l & 1) res += T[l++];
            if(r & 1) res += T[--r];
        }
        return res;
    }

    void add(int p, ll delta)
    {
        for (T[p += n] += delta; p > 1; p >>= 1)
            T[p >> 1] = T[p] + T[p ^ 1];
    }

    void build()
    {
        for (int i = n-1; i >= 1; --i)
            T[i] = T[i << 1] + T[i << 1 ^ 1];
    }
};
