// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 50;

int g[MAX][MAX];
int share_nei[MAX][MAX];
int N;

int opk(vector<int>& v){
    for (int& i: v){
        for (int &j: v){
            if (j==i) continue;
            if (share_nei[i][j]) return 0;
        }
    } 
    return 1;
}

int generateSubsets(vector<int>& subset, int k, int start) {
    if (subset.size() == k) {
        // Call the function to brute force the solution on the generated subset
        return opk(subset);
    }

    // Generate subsets recursively
    int ans=0;
    for (int i = start; i <= N; ++i) {
        subset.push_back(i);
        ans = ans or generateSubsets(subset, k, i + 1);
        subset.pop_back();
    }
    return ans;
}

int ok(int m){
    vector<int> subsets;
    return generateSubsets(subsets, m, 1);
}

void print_share_nei(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cout << share_nei[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv){ _
    cin >> N;
    for (int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        g[u][v]=1;
        g[v][u]=1;
    }
    for (int i = 1; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            for (int k = 1; k <= N; k++){
                if (g[i][k] and g[j][k]){
                    share_nei[i][j]=1;
                    share_nei[j][i]=1;
                } 
            }
        }
    }
    int l=1,r=N;
    int res=-1;
    while (l < r){
        int m = (l+r)/2;
        if (ok(m)){
            res=m;
            l=m+1;
        }else {
            r=m;
        }
    }
    cout << res << endl;
    exit(0);
}
