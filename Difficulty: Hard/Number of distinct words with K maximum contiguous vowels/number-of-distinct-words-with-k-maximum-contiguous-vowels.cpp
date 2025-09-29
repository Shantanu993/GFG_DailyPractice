// User function Template for C++

class Solution {
  public:
    typedef long long LL;
int kvowelwords(int N, int K) {
    const LL MOD = 1e9+7, NC = 21, NV = 5;
    vector<LL> C(N+1, 1), V(N+1), PV(K+1, 1);
    for (int i = 1; i <= K; i++)
        PV[i] = PV[i-1] * NV % MOD;
    C[1] = NC; V[1] = K ? NV : 0;
    for (int i = 2; i <= N; i++) {
        C[i] = (C[i-1] + V[i-1]) * NC % MOD;
        for (int j = max(i-K,0); j < i; j++)
            V[i] = (V[i] + C[j] * PV[i-j]) % MOD;
    }
    return (C[N] + V[N]) % MOD;
}
};
