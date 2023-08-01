#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define LOCAL
    #define deb(x) x
#endif
#ifndef DEBUG
    #define deb(x) 0
#endif

#define int long long
#define INF INT32_MAX
#define LINF INT64_MAX
#define MOD 1000000007
#define MOD2 998244353

#define FIX(a) cout<<fixed;cout.precision(a);

#define ff first
#define ss second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define endl '\n'
#define sz(a) (int)((a).size())
#define all(v) (v).begin(), (v).end()

#define pf(x) cout << x << endl
#define sc(x) cin >> x
#define dxdy(dx, dy) int dx[16] = {1, 0, -1, 0, 1, 1, -1, -1, 1, 2, 2, 1, -1, -2, -2, -1}, dy[16] = {0, 1, 0, -1, 1, -1, 1, -1, 2, 1, -1, -2, -2, -1, 1, 2}

#define pii pair<int,int> 
#define vi vector<int> 
#define wi vector<vi>
#define vp vector<pii>
#define wp vector<vp>

int pow(int a, int b, int c) {if (!b) return 1; int rtn = pow(a, b/2, c); rtn = rtn * rtn % c; if (b%2) {rtn = rtn * a % c;} return rtn;}
int gcd(int x, int y) {if (x < y) {swap(x, y);} return y ? gcd(y, x%y) : x;}

class Solver{
private:



public:

signed solve() {




    return 0;
};

};

void init() {
    
}

signed main() {
#ifdef LOCAL
    freopen("ps.in", "r", stdin);
    freopen("ps.out", "w", stdout);
#endif
#ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int testcase = 1;
    cin >> testcase;

    init();
    for (int test_i = 1 ; test_i <= testcase ; test_i++) {
        #ifdef DEBUG
            cout << "Test Case #" << test_i << " Start" << endl;
        #endif
        Solver solver;
        solver.solve();
        #ifdef DEBUG
            cout << "Test Case #" << test_i << " End" << endl;
        #endif
    }
}