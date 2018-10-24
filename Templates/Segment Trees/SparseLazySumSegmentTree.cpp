struct SparseLazySumSegmentTree {
	int s, e; //[s,e)
	ll val = 0, lazy = 0;
	SparseLazySumSegmentTree *lChild = NULL, *rChild = NULL;

	SparseLazySumSegmentTree(int sz) {
		s = 0;
		e = sz;
	}
	SparseLazySumSegmentTree(int st, int ed) {
		s = st;
		e = ed;
	}
	void propagate() {
		int mid = (s + e) / 2;
		if (lChild == NULL) lChild = new SparseLazySumSegmentTree(s, mid);
		if (rChild == NULL) rChild = new SparseLazySumSegmentTree(mid, e);
		lChild->val += lazy * (mid - s);
		rChild->val += lazy * (e - mid);
		lChild->lazy += lazy;
		rChild->lazy += lazy;
		lazy = 0;
	}
	void update(int l, int r, ll v) {
		if (l == s && r == e) {
			val += v * (r - l);
			lazy += v;
			return;
		}
		if (lazy != 0) propagate();
		int mid = (s + e) / 2;
		if (l < mid) {
			if (lChild == NULL) lChild = new SparseLazySumSegmentTree(s, mid);
			lChild->update(l, min(r, mid), v);
		}
		if (r > mid) {
			if (rChild == NULL) rChild = new SparseLazySumSegmentTree(mid, e);
			rChild->update(max(l, mid), r, v);
		}
		if (lChild == NULL) val = rChild->val;
		else if (rChild == NULL) val = lChild->val;
		else val = lChild->val + rChild->val;
	}

	ll query(int l, int r) {
		if (l == s && r == e) return val;
		if (lazy != 0) propagate();
		int mid = (s + e) / 2;
		ll lv = 0, rv = 0;
		if (l < mid && lChild != NULL) lv = lChild->query(l, min(mid, r));
		if (r > mid && rChild != NULL) rv = rChild->query(max(mid, l), r);
		if (r <= mid) return lv;
		else if (l >= mid) return rv;
		else return lv + rv;
	}
};
