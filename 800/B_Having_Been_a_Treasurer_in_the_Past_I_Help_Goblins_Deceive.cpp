#include <iostream>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int a = 0, b = 0;

    for (char c : s) {
        if (c == '_') a++;
        else b++;
    }

    if (b < 2 || a == 0) {
        cout << "0\n";
        return;
    }

    long long x = b / 2;
    long long y = (b + 1) / 2;
    cout << a * x * y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}