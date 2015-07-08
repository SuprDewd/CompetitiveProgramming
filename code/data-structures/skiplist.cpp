#define BP 0.20
#define MAX_LEVEL 10
unsigned int bernoulli(unsigned int MAX) {
    unsigned int cnt = 0;
    while(((float) rand() / RAND_MAX) < BP && cnt < MAX) cnt++;
    return cnt; }
template<class T> struct skiplist {
    struct node {
        T item;
        int *lens;
        node **next;
        #define CA(v, t) v((t*)calloc(level+1, sizeof(t)))
        node(int level, T i) : item(i), CA(lens, int), CA(next, node*) {}
        ~node() { free(lens); free(next); }; };
    int current_level, _size;
    node *head;
    skiplist() : current_level(0), _size(0), head(new node(MAX_LEVEL, 0)) { };
    ~skiplist() { clear(); delete head; head = NULL; }
    #define FIND_UPDATE(cmp, target) \
        int pos[MAX_LEVEL + 2]; \
        memset(pos, 0, sizeof(pos)); \
        node *x = head; \
        node *update[MAX_LEVEL + 1]; \
        memset(update, 0, MAX_LEVEL + 1); \
        for(int i = MAX_LEVEL; i >= 0; i--) { \
            pos[i] = pos[i + 1]; \
            while(x->next[i] != NULL && cmp < target) { \
                pos[i] += x->lens[i]; x = x->next[i]; } \
            update[i] = x; \
        } x = x->next[0];
    int size() const { return _size; }
    void clear() { while(head->next && head->next[0])
        erase(head->next[0]->item); }
    node *find(T target) { FIND_UPDATE(x->next[i]->item, target);
        return x && x->item == target ? x : NULL; }
    node *nth(int k) { FIND_UPDATE(pos[i] + x->lens[i], k+1); return x; }
    int count_less(T target) { FIND_UPDATE(x->next[i]->item, target);
        return pos[0]; }
    node* insert(T target) {
        FIND_UPDATE(x->next[i]->item, target);
        if(x && x->item == target) return x; // SET
        int lvl = bernoulli(MAX_LEVEL);
        if(lvl > current_level) current_level = lvl;
        x = new node(lvl, target);
        rep(i,0,lvl+1) {
            x->next[i] = update[i]->next[i];
            x->lens[i] = pos[i] + update[i]->lens[i] - pos[0];
            update[i]->next[i] = x;
            update[i]->lens[i] = pos[0] + 1 - pos[i];
        }
        for(int i = lvl + 1; i <= MAX_LEVEL; i++) update[i]->lens[i]++;
        _size++;
        return x; }
    void erase(T target) {
        FIND_UPDATE(x->next[i]->item, target);
        if(x && x->item == target) {
            rep(i,0,current_level+1) {
                if(update[i]->next[i] == x) {
                    update[i]->next[i] = x->next[i];
                    update[i]->lens[i] = update[i]->lens[i] + x->lens[i] - 1;
                } else update[i]->lens[i] = update[i]->lens[i] - 1;
            }
            delete x; _size--;
            while(current_level > 0 && head->next[current_level] == NULL)
                current_level--; } } };
