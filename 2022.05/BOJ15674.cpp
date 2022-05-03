////////////////////////////////////////
//   Today : Tue May  3 19:00:24 2022 //
//  Author : rasauq1122               //
// Problem : BOJ15674                 //
////////////////////////////////////////

#include <bits/stdc++.h>

#define int long long

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
#define uniq(v) (sort((v).begin(), (v).end()), (v).erase(unique((v).begin(),(v).end()),(v).end()))
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

typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef tuple<int,int,int,int> tII;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<pii> vp;
typedef vector<vp> wp;
typedef vector<tiii> vt;
typedef vector<vt> wt;

int pow(int a, int b, int c) {if (!b) return 1; int rtn = pow(a, b/2, c); rtn = rtn * rtn % c; if (b%2) {rtn = rtn * a % c;} return rtn;}
int safe(int x, int y, int Mx, int My, int mx = 0, int my = 0) {return mx <= x && x < Mx && my <= y && y < My;}
int mivs(int a, int m) {int u = 0, v = 1, k = m; while (a != 0) {int t = k / a; k -= t * a; swap(a, k); u -= t * v; swap(u, v);} return (u+m)%m;}

vi root; // root node includes i-th node.
vi diff; // root node includes a root node that has different tree of i-th node.

vi g; // how many cost 1st-tree at i-th building.
vi p; // how many cost 2nd-tree at i-th building.

vi sumA; // how many cost 1st-tree at buildings in set includes i-th node.
vi sumB; // how many cost 2nd-tree at buildings in set includes i-th node.
// sumA, sumB is only restored in root node, I guess...

int sum; // the minimum cost buying trees

int n, d, q;

int rfind(int idx) {
    if (root[idx] == idx) return idx;
    return root[idx] = rfind(root[idx]);
}

int qcost(int idx, int didx) {
    return min(sumA[idx]+sumB[didx], sumB[idx]+sumA[didx]);
}

// parent(root(j)) is root(i)
void insert(int i, int j, bool change = 1) {
    int rootI = rfind(i);
    int rootJ = rfind(j);
    int drootI = rfind(diff[rootI]);
    int drootJ = rfind(diff[rootJ]);

    if (change) {
        sum -= qcost(rootI, drootI);
        sum -= qcost(rootJ, drootJ);
    }

    root[rootJ] = rootI;

    if (drootJ) {
        if (drootI) {
            diff[drootJ] = 0;
            insert(drootI, drootJ, 0);
        }
        else {
            diff[rootI] = drootJ;
            diff[drootJ] = rootI;
            drootI = drootJ;
        }
    }

    sumA[rootI] += sumA[rootJ];
    sumB[rootI] += sumB[rootJ];
    // min-sum may change.    
    if (change) sum += qcost(rootI, drootI);
}

void hate(int i, int j) {
    int rootI = rfind(i);
    int rootJ = rfind(j);

    int drootI = rfind(diff[rootI]);
    int drootJ = rfind(diff[rootJ]);

    sum -= qcost(rootI, drootI);
    sum -= qcost(rootJ, drootJ);

    if (drootI) {
        diff[drootI] = 0;
        insert(rootJ, drootI, 0);
    }

    if (drootJ) {
        diff[drootJ] = 0;
        insert(rootI, drootJ, 0);
    }

    diff[rootI] = rootJ;
    diff[rootJ] = rootI;

    sum += qcost(rootI, rootJ);
}

void query(int c, int a, int b) {
    int root, droot;
    switch (c) {
        case 0:
        if (rfind(a) != rfind(b)) insert(a, b);
        break;

        case 1:
        root = rfind(a);
        droot = rfind(diff[rfind(b)]);
        if (root != droot) hate(a, b);
        break;

        case 2:
        root = rfind(a);
        droot = rfind(diff[root]);
        
        sum -= qcost(root, droot);
        sumA[root] += b - g[a];
        g[a] = b;
        
        sum += qcost(root, droot);
        break;

        case 3:
        root = rfind(a);
        droot = rfind(diff[root]);
        
        sum -= qcost(root, droot); 
        sumB[root] += b - p[a];
        p[a] = b;
        
        sum += qcost(root, droot);
        break;

        default:
        exit(-1);
    }
    
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> d;

    root = vi(n+1);
    diff = vi(n+1);

    g = vi(n+1);
    p = vi(n+1);

    sumA = vi(n+1);
    sumB = vi(n+1);

    repe(i, 1, n) root[i] = i;
    repe(i, 1, n) {
        cin >> g[i] >> p[i];
        
        sum += min(g[i], p[i]);
        
        sumA[i] = g[i];
        sumB[i] = p[i];
    }

    for (int c, a, b ; d-- ; ) cin >> c >> a >> b, query(c, a, b);
    cout << sum << endl;

    int q;
    cin >> q;
    for (int c, a, b ; q-- ; ) {
        cin >> c >> a >> b;
        query(c, a, b);
        cout << sum << endl;
    }
}