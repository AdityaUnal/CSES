#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, long long> counts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        counts[x]++;
    }

    long long ans = 1;
    long long MOD = 1e9 + 7;

    for (auto const& [val, count] : counts) {
        ans = (ans * (count + 1)) % MOD;
    }

    // Subtract the empty subsequence and handle modulo arithmetic
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << "\n";

    return 0;
}

/*
5
1 1 1 1 1
*/