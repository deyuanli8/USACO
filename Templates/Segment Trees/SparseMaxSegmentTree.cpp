const int SZ = 1 << 20;
struct node {
	ll val;
	node* c[2];

	node() {
		val = 0;
		c[0] = c[1] = NULL;
	}
	node* getc(int a) {
		if (!c[a]) c[a] = new node();
		return c[a];
	}
	void update(int ind, ll v, int l = 0, int r = SZ - 1) {
		if (l == r && l == ind) {
			val += v;
			return;
		}
		int mid = (l + r) / 2;
		if (ind <= mid) {
			getc(0)->update(ind, v, l, mid);
		}
		else {
			getc(1)->update(ind, v, mid + 1, r);
		}
		val = max((c[0] ? c[0]->val : 0), (c[1] ? c[1]->val : 0));
	}

	ll query(int ql, int qr, int l = 0, int r = SZ - 1) {
		if (ql <= l && r <= qr) return val;
		if (r < ql || l > qr) return 0;
		int mid = (l + r) / 2;
		return max((c[0] ? c[0]->query(ql, qr, l, mid) : 0), (c[1] ? c[1]->query(ql, qr, mid + 1, r) : 0));
	}
	void upd2d(int ind, node* c1, node* c2, int l = 0, int r = SZ - 1) {
		if (l != r) {
			int mid = (l + r) / 2;
			if (ind <= mid) {
				getc(0)->upd2d(ind, c1 ? c1->c[0] : NULL, c2 ? c2->c[0] : NULL, l, mid);
			}
			else {
				getc(1)->upd2d(ind, c1 ? c1->c[1] : NULL, c2 ? c2->c[1] : NULL, mid + 1, r);
			}
		}
		val = max(c1->val, c2->val);
	}
};
