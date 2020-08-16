struct LazySetSumSegmentTree {
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
};
