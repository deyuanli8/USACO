struct SparseLazyMinSegmentTree {
	int s, e; //[s,e)
	ll val = 0, lazy = 0;
	SparseLazyMinSegmentTree *lChild = NULL, *rChild = NULL;

	SparseLazyMinSegmentTree(int sz) {
		s = 0;
		e = sz;
	}
	SparseLazyMinSegmentTree(int st, int ed) {
		s = st;
		e = ed;
	}
	void propagate() {
		int mid = (s + e) / 2;
		if (lChild == NULL) lChild = new SparseLazyMinSegmentTree(s, mid);
		if (rChild == NULL) rChild = new SparseLazyMinSegmentTree(mid, e);
		lChild->val += lazy;
		rChild->val += lazy;
		lChild->lazy += lazy;
		rChild->lazy += lazy;
		lazy = 0;
	}
	void update(int l, int r, ll v) { //[l,r)
		if (l == s && r == e) {
			val += v;
			lazy += v;
			return;
		}
		if (lazy != 0) propagate();
		int mid = (s + e) / 2;
		if (l < mid) {
			if (lChild == NULL) lChild = new SparseLazyMinSegmentTree(s, mid);
			lChild->update(l, min(r, mid), v);
		}
		if (r > mid) {
			if (rChild == NULL) rChild = new SparseLazyMinSegmentTree(mid, e);
			rChild->update(max(l, mid), r, v);
		}
		if (lChild == NULL) val = min(0LL, rChild->val);
		else if (rChild == NULL) val = min(0LL, lChild->val);
		else val = min(lChild->val, rChild->val);
	}

	ll query(int l, int r) { //[l,r)
		if (l == s && r == e) return val;
		if (lazy != 0) propagate();
		int mid = (s + e) / 2;
		ll lv = 0, rv = 0;
		if (l < mid && lChild != NULL) lv = lChild->query(l, min(mid, r));
		if (r > mid && rChild != NULL) rv = rChild->query(max(mid, l), r);
		if (r <= mid) return lv;
		else if (l >= mid) return rv;
		else return min(lv, rv);
	}
};
