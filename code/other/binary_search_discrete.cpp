int binary_search_discrete(int low, int high, bool (*f)(int)) {
    assert(low <= high);
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (f(mid)) high = mid;
        else low = mid + 1;
    }
    assert(f(low));
    return low;
}
