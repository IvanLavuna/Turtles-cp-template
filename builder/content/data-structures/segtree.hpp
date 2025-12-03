struct SegTree
{
	int n;
	VI ar;
	
	SegTree(int _n)
	{
		n = __bit_ceil(_n);
		ar.assign(2 * n, INF);
	}
	SegTree(const VI& _ar)
	{
		n = __bit_ceil(sz(_ar));
		ar.assign(2 * n, INF);
		FOR (i, 0, sz(_ar))
			ar[i + n] = _ar[i];
		
		RFOR (i, n, 1)
			ar[i] = min(ar[i << 1], ar[(i << 1) | 1]);
	}
	void upd(int p, int val)
	{
		p += n;
		ar[p] = val;
		while (p >>= 1)
		{
			ar[p] = min(ar[p << 1], ar[(p << 1) | 1]);
		}
	}
	// [l, r)
	int query(int l, int r)
	{
		l += n;
		r += n;
		
		int resL = INF, resR = INF;
		while (l < r)
		{
			if (l & 1) resL = min(resL, ar[l++]);
			if (r & 1) resR = min(ar[--r], resR);
			l >>= 1;
			r >>= 1;
		}
		return min(resL, resR);
	}
};
