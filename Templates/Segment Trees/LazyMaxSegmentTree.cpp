struct LazyMaxSegmentTree {
	int sz;
	ll *tree, *lazy;

	LazyMaxSegmentTree(int s) {
		sz = 1 << (int)ceil(log2(s));
		tree = new ll[2 * sz];
		lazy = new ll[sz];
		memset(tree, 0, 2 * sz * sizeof(ll));
		memset(lazy, 0, sz * sizeof(ll));
	}
	LazyMaxSegmentTree(int s, ll* st) {
		sz = 1 << (int)ceil(log2(s));
		tree = new ll[2 * sz];
		lazy = new ll[sz];
		memset(tree, 0, 2 * sz * sizeof(ll));
		memset(lazy, 0, sz * sizeof(ll));
		FOR(i, s) {
			tree[i + sz] = st[i];
		}
		F0Rd(ind, 1, sz) {
			tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
		}
	}
	void propagate(int ind) {
		tree[2 * ind] += lazy[ind];
		tree[2 * ind + 1] += lazy[ind];
		if (2 * ind < sz) {
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	void update(int ind, int st, int e, int l, int r, ll v) {
		if (l == st && r == e) {
			tree[ind] += v;
			if (ind < sz) lazy[ind] += v;
			return;
		}
		propagate(ind);
		int mid = (st + e) / 2;
		if (l < mid) update(2 * ind, st, mid, l, min(r, mid), v);
		if (r > mid) update(2 * ind + 1, mid, e, max(l, mid), r, v);
		tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
	}
	void update(int a, int b, ll v) { // update values in [a,b)
		update(1, 0, sz, a, b, v);
	}
	ll query(int ind, int st, int e, int l, int r) {
		if (st == l && e == r) return tree[ind];
		propagate(ind);
		int mid = (st + e) / 2;
		if (l < mid && r > mid) return max(query(2 * ind, st, mid, l, mid), query(2 * ind + 1, mid, e, mid, r));
		else if (l < mid) return query(2 * ind, st, mid, l, min(mid, r));
		else return query(2 * ind + 1, mid, e, max(mid, l), r);
	}
	ll query(int a, int b) { //query values in [a,b)
		return query(1, 0, sz, a, b);
	}
};
