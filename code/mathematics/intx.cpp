class intx {
public:
    intx() { normalize(1); }
    intx(string n) { init(n); }
    intx(int n) { stringstream ss; ss << n; init(ss.str()); }
    intx(const intx& other) : sign(other.sign), data(other.data) { }

    friend bool operator <(const intx& a, const intx& b);
    friend intx operator +(const intx& a, const intx& b);
    friend intx operator -(const intx& a, const intx& b);
    friend intx operator -(const intx& a);
    friend intx operator *(const intx& a, const intx& b);
    friend intx operator /(const intx& a, const intx& b);
    friend intx operator %(const intx& a, const intx& b);
    friend ostream& operator <<(ostream& outs, const intx& n);

protected:
    int sign;
    vector<unsigned int> data;
    static const unsigned int radix = 1000000000U;
    int size() const { return data.size(); }
    void init(string n) {
        intx res; res.data.clear();
        if (n.empty()) n = "0";
        if (n[0] == '-') res.sign = -1, n = n.substr(1);
        for (int i = n.size() - 1; i >= 0; i -= 9) {
            unsigned int digit = 0;
            for (int j = 8; j >= 0; j--) {
                int idx = i - j;
                if (idx < 0) continue;
                digit = digit * 10 + (n[idx] - '0');
            }
            res.data.push_back(digit);
        }
        data = res.data;
        normalize(res.sign);
    }
    void normalize(int nsign) {
        if (data.empty()) data.push_back(0);
        for (int i = data.size() - 1; i > 0 && data[i] == 0; i--) data.erase(data.begin() + i);
        sign = data.size() == 1 && data[0] == 0 ? 1 : nsign;
    }
    intx mult_radix(int n) {
        vector<unsigned int> d(n + data.size(), 0);
        for (int i = 0; i < size(); i++) d[i + n] = data[i];
        intx res; res.data = d; res.normalize(sign);
        return res;
    }
};
ostream& operator <<(ostream& outs, const intx& n) {
    if (n.sign == -1) outs << '-';
    bool first = true;
    for (int i = n.size() - 1; i >= 0; i--) {
        if (first) outs << n.data[i], first = false;
        else {
            unsigned int cur = n.data[i];
            stringstream ss; ss << cur;
            string s = ss.str();
            int len = s.size();
            while (len < 9) outs << '0', len++;
            outs << s;
        }
    }
    return outs;
}
bool operator <(const intx& a, const intx& b) {
    if (a.sign != b.sign) return a.sign < b.sign;
    if (a.size() != b.size()) return a.sign == 1 ? a.size() < b.size() : a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--) if (a.data[i] != b.data[i])
            return a.sign == 1 ? a.data[i] < b.data[i] : a.data[i] > b.data[i];
    return false;
}
intx operator +(const intx& a, const intx& b) {
    if (a.sign != b.sign) return -(-a - b);
    intx c; c.data.clear();
    unsigned long long carry = 0;
    for (int i = 0; i < a.size() || i < b.size() || carry; i++) {
        carry += (i < a.size() ? a.data[i] : 0ULL) + (i < b.size() ? b.data[i] : 0ULL);
        c.data.push_back(carry % intx::radix);
        carry /= intx::radix;
    }
    c.normalize(a.sign);
    return c;
}
intx operator -(const intx& a) { intx res(a); res.sign *= -1; return res; }
intx operator -(const intx& a, const intx& b) {
    if (a.sign != b.sign) return intx() - (intx() - a + b);
    if (a < b) return -(b - a);
    intx c; c.data.clear();
    long long borrow = 0;
    for (int i = 0; i < a.size(); i++) {
        borrow = a.data[i] - borrow - (i < b.size() ? b.data[i] : 0ULL);
        c.data.push_back(borrow < 0 ? intx::radix + borrow : borrow);
        borrow = borrow < 0 ? 1 : 0;
    }
    c.normalize(a.sign);
    return c;
}
intx operator *(const intx& a, const intx& b) {
    int n = max(a.size(), b.size());
    if (n == 1) {
        unsigned long long res = static_cast<unsigned long long>(a.data[0]) * b.data[0];
        stringstream ss; ss << res;
        intx result(ss.str());
        result.normalize(a.sign * b.sign);
        return result;
    }
    if (n & 1) n++;
    int n2 = n >> 1;
    vector<unsigned int> buff1, buff2;
    buff1.reserve(n2); buff2.reserve(n2);
    for (int at = n2 - 1; at >= 0; at--) {
        int idx = n - at - 1;
        buff1.push_back(idx < a.size() ? a.data[idx] : 0);
        buff2.push_back(idx < b.size() ? b.data[idx] : 0);
    }
    intx i, k;
    i.data = buff1; k.data = buff2;
    buff1.clear(); buff2.clear();
    for (int at = n - 1; at >= n2; at--) {
        int idx = n - at - 1;
        buff1.push_back(idx < a.size() ? a.data[idx] : 0);
        buff2.push_back(idx < b.size() ? b.data[idx] : 0);
    }
    intx j, l;
    j.data = buff1; l.data = buff2;
    intx ik = i * k, jl = j * l;
    intx res = ik.mult_radix(n) + ((i + j) * (k + l) - (ik + jl)).mult_radix(n2) + jl;
    res.normalize(a.sign * b.sign);
    return res;
}
intx operator /(const intx& n, const intx& d)
{
    assert(!(d.size() == 1 && d.data[0] == 0));
    intx q, r; q.data.assign(n.size(), 0);
    for (int i = n.size() - 1; i >= 0; i--) {
        r.data.insert(r.data.begin(), 0);
        intx y; y.data[0] = n.data[i];
        r = r + y;
        while (!(r < d)) r = r - d, q.data[i]++;
    }
    q.normalize(n.sign * d.sign);
    return q;
}
intx operator %(const intx& n, const intx& d) {
    intx r;
    for (int i = n.size() - 1; i >= 0; i--) {
        r.data.insert(r.data.begin(), 0);
        intx y; y.data[0] = n.data[i];
        r = r + y;
        while (!(r < d)) r = r - d;
    }
    r.normalize(n.sign * d.sign);
    return r;
}
