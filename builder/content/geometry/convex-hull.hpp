vector<Pt> convexHull(vector<Pt> v)
{
	if (sz(v) <= 1)
		return v;
	sort(all(v), [](const Pt& p, const Pt& q)
	{
		int dx = sgn(p.x - q.x);
		if (dx != 0)
			return dx < 0;
		return sgn(p.y - q.y) < 0;
	});
	vector<Pt> lower, upper;
	for (const Pt& p : v)
	{
		while (sz(lower) > 1 && 
			sgn(orient(lower[sz(lower) - 2], lower.back(), p)) <= 0)
			lower.pop_back();
		while (sz(upper) > 1 && 
			sgn(orient(upper[sz(upper) - 2], upper.back(), p)) >= 0)
			upper.pop_back();
		lower.pb(p);
		upper.pb(p);
	}
	reverse(all(upper));
	lower.insert(lower.end(), next(upper.begin()), prev(upper.end()));
	return lower;
}
