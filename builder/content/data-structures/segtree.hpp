template <class S, S (*op)(S, S), S (*e)()> 
struct segtree
{
  public:
    segtree() : segtree(0) 
    {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e()))
    {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size()))
    {
        size = (int)(_n <= 1 ? 1u : (1u << (32 - __builtin_clz(_n - 1))));
        log = __builtin_ctz((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        FOR(i,0,_n) d[size + i] = v[i];
        RFOR(i, size, 1) update(i); 
    }

    void set(int p, S x)
    {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        FOR(i,1,log+1) update(p >> i);
    }

    S get(int p) const
    {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
	
	// [l;r)
    S prod(int l, int r) const
    {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r)
        {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

	/* Uncomment if binary search on tree is needed
  
	// If f is monotone, this is the maximum r that satisfies
	//   f(op(a[l], a[l + 1], ..., a[r - 1])) = true
    template <class F> int max_right(int l, F f) const
    {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do
        {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l])))
            {
                while (l < size)
                {
                    l = (2 * l);
                    if (f(op(sm, d[l])))
                    {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

	// If f is monotone, this is the minimum l that satisfies 
	//   f(op(a[l], a[l + 1], ..., a[r - 1])) = true
    template <class F> int min_left(int r, F f) const
    {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do
        {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm)))
            {
                while (r < size)
                {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm)))
                    {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

	*/
  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};