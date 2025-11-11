// 7385d9 for min_left

// max_right: find maximum r that. f(op over [l, r)) == true
template <class F>
int max_right(int l, F f)
{
	if (l == n) 
		return n;
	l += n;
	int sm = INF;
	do
	{
		while ((l & 1) == 0) 
			l >>= 1;
		if (!f(min(sm, ar[l])))
		{
			while (l < n)
			{
				l = (l << 1);
				if (f(min(sm, ar[l])))
				{
					sm = min(sm, ar[l]);
					l++;
				}
			}
			return l - n;
		}
		sm = min(sm, ar[l]);
		l++;
	} while ((l & -l) != l);
	return n;
}

// min_left: find minimum l that f(op over [l, r)) == true
//template <class F>
//int min_left(int r, F f)
//{
	//if (r == 0) 
		//return 0;
	//r += n;
	//int sm = INF;
	//do
	//{
		//r--;
		//while (r > 1 && (r & 1)) r >>= 1;
		//if (!f(min(ar[r], sm)))
		//{
			//while (r < n)
			//{
				//r = (r << 1) | 1;
				//if (f(min(ar[r], sm)))
				//{
					//sm = min(ar[r], sm);
					//r--;
				//}
			//}
			//return r + 1 - n;
		//}
		//sm = min(ar[r], sm);
	//} while ((r & -r) != r);
	//return 0;
//}
