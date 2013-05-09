template <class T>
class avl_tree {
public:

    struct node {
        node *p, *l, *r;
        int size, height;
        T item;
        node(const T &item, node *p = NULL) : item(item), p(p), l(NULL), r(NULL), size(1), height(0) { }
    };

    avl_tree() : root(NULL) { }

    node *root;

    node* find(const T &item) const {
        node *cur = root;
        while (cur) {
            if (cur->item < item) cur = cur->r;
            else if (item < cur->item) cur = cur->l;
            else break;
        }

        return cur;
    }

    node* insert(const T &item) {
        node *prev = NULL, **cur = &root;
        while (*cur) {
            prev = *cur;
            if ((*cur)->item < item) cur = &((*cur)->r);
            else if (item < (*cur)->item) cur = &((*cur)->l);
            else return *cur;
        }

        node *n = new node(item, prev);
        *cur = n;
        fix(n);
        return n;
    }

    void erase(const T &item) { erase(find(item)); }
    void erase(node *n) {
        if (!n) return;
        if (!n->l && n->r) {
            child_leg(n->p, n) = n->r;
            n->r->p = n->p;
        } else if (n->l && !n->r) {
            child_leg(n->p, n) = n->l;
            n->l->p = n->p;
        } else if (n->l && n->r) {
            node *s = successor(n);
            n->item = s->item; // TODO: don't just copy contents
            erase(s);
            fix(n);
            return;
        } else child_leg(n->p, n) = NULL;
        fix(n->p);
        delete n;
    }

    node* successor(node *n) const {
        if (!n) return NULL;
        if (n->r) return nth(0, n->r);
        node *p = n->p;
        while (p && p->r == n) n = p, p = p->p;
        return p;
    }

    inline int size() const { return sz(root); }

    void clear() {
        delete_tree(root);
        root = NULL;
    }

    node* nth(int n, node *cur = NULL) const {
        if (!cur) cur = root;
        while (cur) {
            if (n < sz(cur->l)) cur = cur->l;
            else if (n > sz(cur->l)) n -= sz(cur->l) + 1, cur = cur->r;
            else break;
        }

        return cur;
    }

private:

    inline int sz(node *n) const { return n ? n->size : 0; }
    inline int height(node *n) const { return n ? n->height : -1; }
    inline bool left_heavy(node *n) const { return n && height(n->l) > height(n->r); }
    inline bool right_heavy(node *n) const { return n && height(n->r) > height(n->l); }
    inline bool too_heavy(node *n) const { return n && abs(height(n->l) - height(n->r)) > 1; }

    void delete_tree(node *n) {
        if (!n) return;
        delete_tree(n->l);
        delete_tree(n->r);
        delete n;
    }

    node*& child_leg(node *p, node *c) {
        if (!p) return root;
        if (p->l == c) return p->l;
        if (p->r == c) return p->r;
        // assert(false);
    }

    void augment(node *n) {
        if (!n) return;
        n->size = 1 + sz(n->l) + sz(n->r);
        n->height = 1 + max(height(n->l), height(n->r));
    }

    void left_rotate(node *n) {
        // assert(n->r);
        node *r = n->r;
        r->p = n->p;
        child_leg(n->p, n) = r;
        n->r = r->l;
        if (r->l) r->l->p = n;
        r->l = n;
        n->p = r;
        augment(n);
        augment(r);
    }

    void right_rotate(node *n) {
        // assert(n->l);
        node *l = n->l;
        l->p = n->p;
        child_leg(n->p, n) = l;
        n->l = l->r;
        if (l->r) l->r->p = n;
        l->r = n;
        n->p = l;
        augment(n);
        augment(l);
    }

    void fix(node *n) {
        while (n) {
            augment(n);
            if (too_heavy(n)) {
                if (left_heavy(n) && right_heavy(n->l)) left_rotate(n->l);
                else if (right_heavy(n) && left_heavy(n->r)) right_rotate(n->r);
                if (left_heavy(n)) right_rotate(n);
                else left_rotate(n);
                n = n->p;
            }

            n = n->p;
        }
    }
};
