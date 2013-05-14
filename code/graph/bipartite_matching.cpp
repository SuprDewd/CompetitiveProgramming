vi* adj;
bool* done;
int* owner;

int alternating_path(int left) {
    if (done[left]) return 0;
    done[left] = true;
    for (int i = 0; i < size(adj[left]); i++) {
        int right = adj[left][i];
        if (owner[right] == -1 || alternating_path(owner[right])) {
            owner[right] = left;
            return 1;
        }
    }

    return 0;
}
