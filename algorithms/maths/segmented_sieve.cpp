#include <bits/stdc++.h>
using namespace std;

int main() {
    long long L, R;
    cin >> L >> R;

    long long limit = sqrt(R) + 1;
    vector<bool> isPrime(limit, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < limit; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i < limit; i++)
        if (isPrime[i])
            primes.push_back(i);

    vector<bool> isPrimeSeg(R - L + 1, true);

    for (int p : primes) {
        long long start = max(
            (long long)p * p,
            ((L + p - 1) / p) * p
        );

        for (long long j = start; j <= R; j += p)
            isPrimeSeg[j - L] = false;
    }

    if (L == 1)
        isPrimeSeg[0] = false;

    for (int i = 0; i <= R - L; i++) {
        if (isPrimeSeg[i])
            cout << (L + i) << " ";
    }

    return 0;
}