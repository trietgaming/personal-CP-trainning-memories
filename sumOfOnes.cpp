vector<long long> v, ones;
long long res = 0, gl, gr;

void calc(long long l, long long r, long long i) {
    if (i >= v.size() || r < gl || l > gr) return;
    long long m = l + (r - l) / 2, one = ones[i];
    if (l == m && m == r) {
        res += 1;
        return;
    }
    if (m <= gr && m >= gl) res += v[i];
    if (l >= gl && r <= gr) res += one;
    else {
        calc(l, m - 1, i + 1);
        calc(m + 1, r, i + 1);
    }
}

long long sumOfOnes(long long n, long long l, long long r)
{
    for (long long &i = n; i > 0; i /= 2) v.push_back(i % 2);
    ones = vector<long long>(v.size(), 0);
    long long len = 1;
    for (long long i = v.size() - 2, temp = 2; i >= 0; --i, temp *= 2) {
        len += temp;
        ones[i] = ones[i+1] * 2 + v[i + 1];
    };
    for (auto &i: ones) i*= 2;
    gl = l;
    gr = r;
    calc(1, len, 0);
    return res;
}
