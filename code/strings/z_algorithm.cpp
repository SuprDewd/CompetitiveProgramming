int* z_values(string s) {
    int n = size(s);
    int* z = new int[n];
    int l = 0, r = 0;
    z[0] = n;
    for (int i = 1; i < n; i++) {
        z[i] = 0;
        if (i > r) {
            l = r = i;
            while (r < n && s[r - l] == s[r]) r++;
            z[i] = r - l; r--;
        } else if (z[i - l] < r - i + 1) z[i] = z[i - l];
        else {
            l = i;
            while (r < n && s[r - l] == s[r]) r++;
            z[i] = r - l; r--; } }
    return z;
}
