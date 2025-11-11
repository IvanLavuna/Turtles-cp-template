// methods work in 0-indexing
struct Fenwick
{
	int n;
	VL ar;
	
	Fenwick (int _n = 0): n(_n + 1), ar(n) {}
	Fenwick (const VL& _ar)
	{
		n = sz(_ar) + 1;
		ar.assign(n, 0);
		FOR (i, 1, n)
		{
			ar[i] += _ar[i - 1];
			int x = i + (i & -i);
			if (x < n)
				ar[x] += ar[i];
		}
	}
	void upd(int x, ll val)
	{
		x++;
		while (x < n)
		{
			ar[x] += val;
			x += x & -x;
		}
	}
	ll getSum(int x)
	{
		ll res = 0;
		while (x)
		{
			res += ar[x];
			x -= x & -x;
		}
		return res;
	}
	// [l, r]
	ll query(int l, int r)
	{
		return getSum(r + 1) - getSum(l);
	}
};
