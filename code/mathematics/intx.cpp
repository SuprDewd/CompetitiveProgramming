struct intx {
    intx() { normalize(1); }
    intx(string n) { init(n); }
    intx(int n) { stringstream ss; ss << n; init(ss.str()); }
    intx(const intx& other) : sign(other.sign), data(other.data) { }

    int sign;
    vector<unsigned int> data;
    static const int dcnt = 9;
    static const unsigned int radix = 1000000000U;
    int size() const { return data.size(); }
    void init(string n) {
        intx res; res.data.clear();
        if (n.empty()) n = "0";
        if (n[0] == '-') res.sign = -1, n = n.substr(1);
        for (int i = n.size() - 1; i >= 0; i -= intx::dcnt) {
            unsigned int digit = 0;
            for (int j = intx::dcnt - 1; j >= 0; j--) {
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
        for (int i = data.size() - 1; i > 0 && data[i] == 0; i--)
            data.erase(data.begin() + i);
        sign = data.size() == 1 && data[0] == 0 ? 1 : nsign;
    }
    intx mult_radix(int n) {
        vector<unsigned int> d(n + data.size(), 0);
        for (int i = 0; i < size(); i++) d[i + n] = data[i];
        intx res; res.data = d; res.normalize(sign);
        return res;
    }
    friend ostream& operator <<(ostream& outs, const intx& n) {
        if (n.sign == -1) outs << '-';
        bool first = true;
        for (int i = n.size() - 1; i >= 0; i--) {
            if (first) outs << n.data[i], first = false;
            else {
                unsigned int cur = n.data[i];
                stringstream ss; ss << cur;
                string s = ss.str();
                int len = s.size();
                while (len < intx::dcnt) outs << '0', len++;
                outs << s;
            }
        }
        return outs;
    }
    bool operator <(const intx& b) const {
        if (sign != b.sign) return sign < b.sign;
        if (size() != b.size())
            return sign == 1 ? size() < b.size() : size() > b.size();
        for (int i = size() - 1; i >= 0; i--) if (data[i] != b.data[i])
                return sign == 1 ? data[i] < b.data[i] : data[i] > b.data[i];
        return false;
    }
    intx operator +(const intx& b) const {
        if (sign != b.sign) return -(-*this - b);
        intx c; c.data.clear();
        unsigned long long carry = 0;
        for (int i = 0; i < size() || i < b.size() || carry; i++) {
            carry += (i < size() ? data[i] : 0ULL) +
                (i < b.size() ? b.data[i] : 0ULL);
            c.data.push_back(carry % intx::radix);
            carry /= intx::radix;
        }
        c.normalize(sign);
        return c;
    }
    intx operator -() const { intx res(*this); res.sign *= -1; return res; }
    intx operator -(const intx& b) const {
        if (sign != b.sign) return intx() - (intx() - *this + b);
        if (*this < b) return -(b - *this);
        intx c; c.data.clear();
        long long borrow = 0;
        for (int i = 0; i < size(); i++) {
            borrow = data[i] - borrow - (i < b.size() ? b.data[i] : 0ULL);
            c.data.push_back(borrow < 0 ? intx::radix + borrow : borrow);
            borrow = borrow < 0 ? 1 : 0;
        }
        c.normalize(sign);
        return c;
    }
    intx operator *(const intx& b) const {
        int n = max(size(), b.size());
        if (n == 1) {
            unsigned long long res = data[0];
            res *= b.data[0];
            stringstream ss; ss << res;
            intx result(ss.str());
            result.normalize(sign * b.sign);
            return result;
        }
        if (n & 1) n++;
        int n2 = n >> 1;
        vector<unsigned int> buff1, buff2;
        buff1.reserve(n2); buff2.reserve(n2);
        for (int at = n2 - 1; at >= 0; at--) {
            int idx = n - at - 1;
            buff1.push_back(idx < size() ? data[idx] : 0);
            buff2.push_back(idx < b.size() ? b.data[idx] : 0);
        }
        intx i, k;
        i.data = buff1; k.data = buff2;
        buff1.clear(); buff2.clear();
        for (int at = n - 1; at >= n2; at--) {
            int idx = n - at - 1;
            buff1.push_back(idx < size() ? data[idx] : 0);
            buff2.push_back(idx < b.size() ? b.data[idx] : 0);
        }
        intx j, l;
        j.data = buff1; l.data = buff2;
        intx ik = i * k, jl = j * l;
        intx res = ik.mult_radix(n) +
            ((i + j) * (k + l) - (ik + jl)).mult_radix(n2) + jl;
        res.normalize(sign * b.sign);
        return res;
    }
    friend intx abs(const intx &n) { return n < 0 ? -n : n; }
    friend pair<intx,intx> divmod(const intx& n, const intx& d) {
        assert(!(d.size() == 1 && d.data[0] == 0));
        intx q, r; q.data.assign(n.size(), 0);
        for (int i = n.size() - 1; i >= 0; i--) {
            r.data.insert(r.data.begin(), 0);
            r = r + n.data[i];
            long long k = 0;
            if (d.size() < r.size())
                k = (long long)intx::radix * r.data[d.size()];
            if (d.size() - 1 < r.size()) k += r.data[d.size() - 1];
            k /= d.data.back();
            r = r - abs(d) * k;
            while (r < 0) r = r + abs(d), k--;
            q.data[i] = k;
        }
        q.normalize(n.sign * d.sign);
        return pair<intx,intx>(q,r);
    }
    intx operator /(const intx& d) const {
        pair<intx, intx> res = divmod(*this,d);
        return res.first; }
    intx operator %(const intx& d) const {
        pair<intx, intx> res = divmod(*this,d);
        return res.second; }
};
