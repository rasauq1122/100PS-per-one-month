#include <bits/stdc++.h>

#define int long long

#define INF 2147483647
#define LINF 9223372036854775807LL
#define MOD 1000000007
#define MOD2 998244353

#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define FASTIO() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FIX(a) cout<<fixed;cout.precision(a);

#define rep(i,j,k) for(int i=(j);i<(k);i++)
#define repe(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(k)-1;i>=(j);i--)
#define pere(i,j,k) for(int i=(k);i>=(j);i--)
#define each(v,n) for(auto n:v)

#define yesif(x) cout<<((x)?"YES":"NO")<<'\n'
#define impif(x) if(x){cout<<-1<<'\n';continue;}

#define ff first
#define ss second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define itos to_string
#define endl '\n'

#define pqueue priority_queue
#define lbound lower_bound
#define ubound upper_bound

#define sz(a) (int)((a).size())
#define all(v) (v).begin(), (v).end()
#define uniq(v) sort((v).begin(), (v).end()); (v).erase(unique((v).begin(),(v).end()),(v).end()) 
#define mset(arr, n) memset(arr, sizeof(arr), n);

#define BIT(a,b) (((a)>>(b))&1)
#define dxdy(dx,dy) int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1}

#define fsi(f) freopen(f, "r", stdin) 
#define fso(f) freopen(f, "w", stdout)

#define RANDOM()         random_device rand;mt19937 seed(rand())
// int-random-value    : uniform_int_distribution<int> gen(min,max);
// double-random-value : uniform_real_distribution<double> gen(min,max);
// how-to-get-value    : gen(seed)

using namespace std;

template <typename T1, typename T2, typename T3> istream& operator>>(istream& in, tuple<T1, T2, T3>& t) {in >> get<0>(t) >> get<1>(t) >> get<2>(t); return in;}
template <typename T1, typename T2, typename T3, typename T4> istream& operator>>(istream& in, tuple<T1, T2, T3, T4>& t) {in >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t); return in;}
template <typename T1, typename T2, typename T3> ostream& operator<<(ostream& out, tuple<T1, T2, T3>& t) {out << '{' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << '}'; return out;}
template <typename T1, typename T2, typename T3, typename T4> ostream& operator<<(ostream& out, tuple<T1, T2, T3, T4>& t) {out << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ", " << get<3>(t) << '}'; return out;}
template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) {in >> p.first >> p.second; return in;}
template <typename T> istream& operator>>(istream& in, vector<T>& v) {int len = v.size(); for (int i = 0 ; i < len ; i++) in >> v[i]; return in;}
template <typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2>& p) {out << '{' << p.first << ", " << p.second << '}'; return out;}
template <typename T> ostream& operator<<(ostream& out, vector<T>& v) {int len = v.size(); for (int i = 0 ; i < len ; i++) out << v[i] << (i+1 == len ? '\n' : ' '); return out;}
template <typename T> ostream& operator<<(ostream& out, vector<vector<T>>& v) {int len = v.size(); for (int i = 0 ; i < len ; i++) out << v[i]; return out;}
template <typename T> void rd(T& arg) {cin >> arg;}
template <typename T, typename... Types> void rd(T& arg, Types&... args) {cin >> arg; rd(args...);}
template <typename T> void pf(T& arg) {cout << arg << '\n';}
template <typename T, typename... Types> void pf(T& arg, Types&... args) {cout << arg << ' '; pf(args...);}
template <typename T> vector<T> vec(int n, T m) {return vector<T>(n, m);}
template <typename T, typename... Types> auto vec(int n, Types... sz) {return vec<vector<T>>(n, vec<T>(sz...));}

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef tuple<int,int,int,int> tiiii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vp;
typedef vector<tuple<int,int,int>> vt;
typedef vector<string> vs;
typedef vector<vector<int>> wi;
typedef vector<vector<pair<int,int>>> wp;
typedef vector<vector<tuple<int,int,int>>> wt;

int pow(int a, int b, int c) {if (!b) {return 1;} int rtn = pow(a, b/2, c); rtn *= rtn, rtn %= c; if (b%2) {rtn *= a, rtn %= c;} return rtn;}
int gcd(int a, int b) {return b ? gcd(b,a%b) : a;}
int safe(int x, int y, int Mx, int My, int mx = 0, int my = 0) {return mx <= x && x < Mx && my <= y && y < My;}
int mivs(int a, int m) {int u = 0, v = 1, k = m; while (a != 0) {int t = k / a; k -= t * a; swap(a, k); u -= t * v; swap(u, v);} return (u+m)%m;}



signed main() {
    FASTIO();
    
}