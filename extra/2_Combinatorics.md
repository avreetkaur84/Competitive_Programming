### Combinatorics

#### [Using Pascal Triangle](https://usaco.guide/gold/combo?lang=cpp#method-1-pascals-triangle-dynamic-programming---mathcalon2)

```
nCr = n!/(n-r)! * r!
nCr = (n-1)C(r-1) + (n-1)C(r)
```

```
    int binomial(int n, int k) {
        if (k == 0 || k == n) { return 1; }
        return (binomial(n - 1, k - 1) + binomial(n - 1, k));
    }
```