////////////////////////////////////////
//   Today : Sun Apr 24 14:18:22 2022 //
//  Author : rasauq1122               //
// Problem : BOJ20930                 //
////////////////////////////////////////

#include <bits/stdc++.h>

#define INF ((1LL<<31)-1)
#define LINF ((1LL<<61)-1)
#define MOD 1000000007
#define MOD2 998244353

#define TC() int CASE_N;cin>>CASE_N;for(int CASE_I=1;CASE_I<=CASE_N;CASE_I++)
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
#define mt make_tuple
#define itos to_string
#define endl '\n'

#ifdef LOCAL
    #define print(x) cout << x
    #define BLS ' ' <<
    #define BLK << ' ' <<
    #define BLE << ' '
    #define NLE << '\n'
#else
    #define print(x)
    #define BLS
    #define BLK
    #define BLE
    #define NLE
#endif

#define sz(a) (int)((a).size())
#define all(v) (v).begin(), (v).end()
#define uniq(v) sort((v).begin(), (v).end()), (v).erase(unique((v).begin(),(v).end()),(v).end()) 
#define mset(arr, n) memset(arr, n, sizeof(arr));

#define BIT(a,b) (((a)>>(b))&1)
#define dxdy(dx,dy) int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1}

#define fsi(f) freopen(f, "r", stdin) 
#define fso(f) freopen(f, "w", stdout)

#define RANDOM()         random_device rand;mt19937 seed(rand())
// int-random-value    : uniform_int_distribution<int> gen(min,max);
// double-random-value : uniform_real_distribution<double> gen(min,max);
// how-to-get-value    : gen(seed)

using namespace std;

template <typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2>& p) {out << '{' << p.first << ", " << p.second << '}'; return out;}
template <typename T> ostream& operator<<(ostream& out, vector<T>& v) {int len = v.size(); for (int i = 0 ; i < len ; i++) out << v[i] << (i+1 == len ? '\n' : ' '); return out;}
template <typename T> ostream& operator<<(ostream& out, vector<vector<T>>& v) {int len = v.size(); for (int i = 0 ; i < len ; i++) out << v[i]; return out;}
template <typename T> vector<T> vec(int n) {return vector<T>(n);}
template <typename T, typename... Types> auto vec(int n, Types... sz) {auto nvec = vec<T>(sz...); return vector<decltype(nvec)>(n, nvec);}

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef tuple<int,int,int,int> tII;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<pii> vp;
typedef vector<vp> wp;
typedef vector<tiii> vt;
typedef vector<vt> wt;
typedef long long lli;
typedef pair<lli,lli> pll;
typedef tuple<lli,lli,lli> tlll;
typedef tuple<lli,lli,lli,lli> tLL;
typedef vector<lli> vl;
typedef vector<vl> wl;
typedef vector<pll> vpl;
typedef vector<vpl> wpl;
typedef vector<tlll> vtl;
typedef vector<vtl> wtl;

int pow(int a, int b, int c) {if (!b) return 1; int rtn = pow(a, b/2, c); rtn = rtn * rtn % c; if (b%2) {rtn = rtn * a % c;} return rtn;}
int safe(int x, int y, int Mx, int My, int mx = 0, int my = 0) {return mx <= x && x < Mx && my <= y && y < My;}
int mivs(int a, int m) {int u = 0, v = 1, k = m; while (a != 0) {int t = k / a; k -= t * a; swap(a, k); u -= t * v; swap(u, v);} return (u+m)%m;}

int dfs(int idx, wi& edge, vi& vis, vi& scc, int& node_cnt, int& scc_cnt, stack<int>& s) {
    int nin = vis[idx] = ++node_cnt;
    // vis[idx] : id of node
    // nin : least id of node that I can arrive.

    s.push(idx);
    // memorize path.

    each(edge[idx], nxt) {
        // to find least id of node that I can arrive.
        
        if (!vis[nxt]) nin = min(nin, dfs(nxt, edge, vis, scc, node_cnt, scc_cnt, s));
        else if (!scc[nxt]) nin = min(nin, vis[nxt]); // I found cycle!
    }

    // nin < vis[idx] : I found cycle!
    if (nin == vis[idx]) {
        // I am the least id of node in cycle.        

        scc_cnt++;
        bool okay = true;
        for ( ; !s.empty() && okay ; s.pop()) {
            // stack memorizes path.
            // all nodes in stack is in cycle.
            
            scc[s.top()] = scc_cnt;
            if (s.top() == idx) okay = false; // end of cycle.
        }
    }

    return nin;
}

vi get_scc(int n, wi& edge) {
    vi scc(n+1);
    vi vis(n+1);
    stack<int> s;
    int node_cnt = 0, scc_cnt = 0;   

    repe(i, 1, n) if (!vis[i]) dfs(i, edge, vis, scc, node_cnt, scc_cnt, s);

    return scc;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    wi edge(n+1);

    vt c[2];
    repe(i, 1, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        
        c[0].pb({x1, x2, i});
        c[1].pb({y1, y2, i});
    }

    rep(t, 0, 2) {
        sort(all(c[t]));
        auto [tmp, nax, par] = c[t][0];
        rep(i, 1, n) {
            auto [c1, c2, now] = c[t][i];
            if (nax < c1) {
                nax = c2;
                par = now;
            }
            else {
                nax = max(nax, c2);
                edge[par].pb(now);
                edge[now].pb(par);
            }
        }
    }
    
    vi scc = get_scc(n, edge);
    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        cout << (scc[a] == scc[b]) << endl;
    }
}