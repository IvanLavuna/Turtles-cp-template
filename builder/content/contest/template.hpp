// hash = 44bf95
 
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define MP make_pair
#define x first
#define F first
#define y second
#define S second

typedef long long ll;
typedef double db;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<ll> VL;

int solve()
{
  int n;
  if (!(cin >> n))
    return 1;
  
  return 0;
}

int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int TET = 1e9;
  //cin >> TET;
  for (int i = 1; i <= TET; ++i)
  {
    if (solve())
      break;
    #ifdef ONPC
      cerr << "________________________________\n";
    #endif
  }
  #ifdef ONPC
    cerr << "\nfinished in " << clock() * 1. / CLOCKS_PER_SEC << " sec\n";
  #endif
  return 0;
}
