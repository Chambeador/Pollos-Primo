// >>>>>>>>> Implement
struct Node { //VALOR NEUTRO

int x = 0; };

Node e() { return Node(); }
 
Node op(Node &a, Node &b) {
    //GENERALIZAR
    Node c;
    c.x = a.x + b.x;
    return c;
}
// <<<<<<<
 
struct segtree { 
    vector<Node> t;
    int n;
 
    void init(int n) {
        t.assign(n * 2, e());
        this->n = n;
    }
 
    void init(vector<Node>& s) {
        n = s.size();
        t.assign(n * 2, e());
        for (int i = 0; i < n; i++) {
            t[i+n] = s[i];
        }
        build();
    }
 
    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = op(t[i<<1], t[i<<1|1]);
    }
 
    // set value at position p
    void update(int p, const Node& value) {
        for (t[p += n] = value; p >>= 1; ) t[p] = op(t[p<<1], t[p<<1|1]);
    }
 
    // sum on interval [l, r]
    Node query(int l, int r) {
        r++; // make this inclusive
        Node resl=e(), resr=e(); // nuint element
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) resl = op(resl, t[l++]);
            if (r&1) resr = op(t[--r], resr);
        }
        return op(resl, resr);
    }
 
    Node get(int i) {
        return query(i, i);
    }
};