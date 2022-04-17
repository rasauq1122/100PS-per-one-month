#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int j = n/2;
    int k = 0;
    for (int i = 0 ; i <= n/2-1 ; i++) {
        while (j < n && v[i]*2 > v[j]) j++;
        if (j++ == n) break;
        k++;
    }

    cout << n - k << endl;
}