struct Fenwick
{
	int n;
	VL t;
	
	Fenwick(int _n = 0): n(_n), t(n) {}
	
	void upd(int i, ll x)
	{
		for (; i < n; i |= i + 1)
			t[i] += x;
	}
	ll query(int i)
	{
		ll ans = 0;
		for (; i >= 0; i = (i & (i + 1)) - 1)
			ans += t[i];
		return ans;
	}
};
