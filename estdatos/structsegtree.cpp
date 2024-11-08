template <typename T>
struct segtree {
    int n;
    vector<T> tree;
    T neutral;
    void init(int nn, T neutralx) {
        neutral = neutralx;
        n = nn;
        int size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, neutral);
    }
    segtree(int nn, T neutral) { init(nn, neutral); }
    
    T combine(T a, T b) {
        //Cambiar por la operacion que se necesite
        return a xor b;
    }
 
    void update(int i, int sl, int sr, int pos, T diff) {
        if (sl <= pos && pos <= sr) {
            if (sl == sr) {
                tree[i] = diff;
            } else {
                int mid = (sl + sr) / 2;
                update(i * 2 + 1, sl, mid, pos, diff);
                update(i * 2 + 2, mid + 1, sr, pos, diff);
                tree[i] = combine(tree[i * 2 + 1], tree[i * 2 + 2]);
            }
        }
    }
 
    void update(int pos, T diff) {
        update(0, 0, n - 1, pos, diff);
    }
 
    T query(int i, int sl, int sr, int l, int r) {
        if (l <= sl && sr <= r) {
            return tree[i];
        } else if (sr < l || r < sl) {
            return neutral;
        } else {
            int mid = (sl + sr) / 2;
            T a = query(i * 2 + 1, sl, mid, l, r);
            T b = query(i * 2 + 2, mid + 1, sr, l, r);
            return combine(a, b);
        }
    }
 
    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};