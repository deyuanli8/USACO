struct MinSegmentTree2D {
	int sz;
	MinSegmentTree *tree;

	MinSegmentTree2D(int s, int t) {
		sz = 1 << (int)ceil(log2(s));
		allocator<MinSegmentTree> al;
		tree = al.allocate(2 * sz);
		FOR(i, 2 * sz) {
			tree[i] = MinSegmentTree(t);
		}
	}
	MinSegmentTree2D(int s, int s2, ll* st) {
		sz = 1 << (int)ceil(log2(s));
		allocator<MinSegmentTree> al;
		tree = al.allocate(2 * sz);
		FOR(i, s) {
			tree[i + sz] = MinSegmentTree(s2, st + i * s2);
		}
		F0R(i, s + sz, 2 * sz) {
			tree[i] = MinSegmentTree(s2);
		}
		ll *t = new ll[s2];
		F0Rd(ind, 1, sz) {
			FOR(i, s2) {
				t[i] = min(tree[2 * ind].tree[tree[2 * ind].sz + i], tree[2 * ind + 1].tree[tree[2 * ind + 1].sz + i]);
			}
			tree[ind] = MinSegmentTree(s2, t);
		}
	}
	void add(int ind1, int ind2, ll x) {
		ind1 += sz;
		tree[ind1].add(ind2, x);
		for (ind1 /= 2; ind1 >= 1; ind1 /= 2) {
			tree[ind1].add(ind2, min(tree[2 * ind1].tree[ind2 + tree[ind1].sz], tree[2 * ind1 + 1].tree[ind2 + tree[ind1].sz]) - tree[ind1].tree[tree[ind1].sz + ind2]);
		}
	}
	ll query(int a, int b, int c, int d) { //min of rows [a,b], columns [c,d] inclusive
		a += sz; b += sz;
		ll s = tree[a].query(c, d);
		while (a <= b) {
			if (a % 2 == 1) s = min(s, tree[a++].query(c, d));
			if (b % 2 == 0) s = min(s, tree[b--].query(c, d));
			a /= 2; b /= 2;
		}
		return s;
	}
};
