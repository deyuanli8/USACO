//Solution to Question 4-Raccoon Mischief from 2020 MBIT: https://pdfhost.io/v/E8BXkbbdN_mBIT_Advancedpdf.pdf

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>
#include <assert.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SQ(a) ((a)*(a))
#define X real()
#define Y imag()

#define F0R(i, a, b) for (int i=(a); i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORd(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0)
#define INF 1000000000
#define EPS 0.000000001

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef complex<ll> point;

/*struct LazySetSumSegmentTree {
	int sz;
	ll *tree, *lazy;
	bool *lz;
	LazySetSumSegmentTree(int s) {
		sz = 1 << (int)ceil(log2(s));
		tree = new ll[2 * sz];
		lazy = new ll[sz];
		lz = new bool[sz];
		memset(lz, 0, sz * sizeof(bool));
		memset(tree, 0, 2 * sz * sizeof(ll));
		memset(lazy, 0, sz * sizeof(ll));
	}
	LazySetSumSegmentTree(int s, ll* st) {
		sz = 1 << (int)ceil(log2(s));
		tree = new ll[2 * sz];
		lazy = new ll[sz];
		lz = new bool[sz];
		memset(lz, 0, sz * sizeof(bool));
		memset(tree, 0, 2 * sz * sizeof(ll));
		memset(lazy, 0, sz * sizeof(ll));
		FOR(i, s) {
			tree[i + sz] = st[i];
		}
		F0Rd(ind, 1, sz) {
			tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
		}
	}
	void propagate(int ind, int st, int e) {
		if (lz[ind] == false) return;
		int mid = (st + e) / 2;
		tree[2 * ind] = (mid - st) * lazy[ind];
		tree[2 * ind + 1] = (e - mid) * lazy[ind];
		if (2 * ind + 1 < sz) {
			lazy[2 * ind] = lazy[ind];
			lazy[2 * ind + 1] = lazy[ind];
			lz[2 * ind] = true;
			lz[2 * ind + 1] = true;
		}
		lazy[ind] = 0;
		lz[ind] = false;
	}
	void update(int ind, int st, int e, int l, int r, ll v) {
		if (l == st && r == e) {
			tree[ind] = (r - l)*v;
			if (ind < sz) {
				lazy[ind] = v;
				lz[ind] = true;
			}
			return;
		}
		propagate(ind, st, e);
		int mid = (st + e) / 2;
		if (l < mid) update(2 * ind, st, mid, l, min(r, mid), v);
		if (r > mid) update(2 * ind + 1, mid, e, max(l, mid), r, v);
		tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
	}
	void update(int a, int b, ll v) { // update values in [a,b)
		update(1, 0, sz, a, b, v);
	}
	ll query(int ind, int st, int e, int l, int r) {
		if (st == l && e == r) return tree[ind];
		propagate(ind, st, e);
		int mid = (st + e) / 2;
		if (l < mid && r > mid) return query(2 * ind, st, mid, l, mid) + query(2 * ind + 1, mid, e, mid, r);
		else if (l < mid) return query(2 * ind, st, mid, l, min(mid, r));
		else return query(2 * ind + 1, mid, e, max(mid, l), r);
	}
	ll query(int a, int b) { //query values in [a,b)
		return query(1, 0, sz, a, b);
	}
};*/

ll n, q;
ll arr[100005];
ll dif[100005];
ll ans[100005];
ll tree[4 * 100005];
ll lazy[4 * 100005];
void init(int node, int a, int b) {
	if (a == b) {
		tree[node] = 0;
		return;
	}
	int mid = (a + b) / 2;
	init(node * 2, a, mid);
	init(node * 2 + 1, mid + 1, b);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void upd(int node, int a, int b, int i, int j, ll val) {
	if (lazy[node] != 0) {
		tree[node] = (b - a + 1)*lazy[node];
		if (a != b) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if (a > j || b < i) return;
	if (i <= a && b <= j) {
		tree[node] = (b - a + 1)*val;
		if (a != b) {
			lazy[node * 2] = val;
			lazy[node * 2 + 1] = val;
		}
		return;
	}
	int mid = (a + b) / 2;
	upd(node * 2, a, mid, i, j, val);
	upd(node * 2 + 1, mid + 1, b, i, j, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll que(int node, int a, int b, int i, int j) {
	if (lazy[node] != 0) {
		tree[node] = (b - a + 1)*lazy[node];
		if (a != b) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if (a > j || b < i) return 0;
	if (i <= a && b <= j) return tree[node];
	int mid = (a + b) / 2;
	ll q1 = que(node * 2, a, mid, i, j);
	ll q2 = que(node * 2 + 1, 1 + mid, b, i, j);
	return q1 + q2;
}
int main() {
	FAST;
	cin >> n >> q;
	FOR(i, n) {
		cin >> arr[i];
	}
	FOR(i, q) {
		ll l, r, x;
		cin >> l >> r >> x;
		dif[l - 1]++;
		dif[r]--;
		upd(1, 1, n + 5, l, r, x);
	}
	ll curS = 0;
	FOR(i, n) {
		if (i != 0)cout << " ";
		curS += dif[i];
		if (arr[i] == 0) {
			if (curS % 2 == 0) cout << 0;
			else {
				if (curS == 0) cout << arr[i];
				else cout << que(1, 1, n + 5, i + 1, i + 1);
			}
		}
		else {
			if (curS % 2 != 0) cout << 0;
			else {
				if (curS == 0) cout << arr[i];
				else cout << que(1, 1, n + 5, i + 1, i + 1);
			}
		}
	}
	cout << "\n";
	return 0;
}
