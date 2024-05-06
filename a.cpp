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

#define USED 0
#define FORBIDDEN 1
#define FREE 2

int g[MAX][MAX];
int share_nei[MAX][MAX];
int N;
int status[MAX];
int id[MAX];
int nxt;

void bfs(int u){
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        auto v = q.front();q.pop();
        if (id[v]) continue;
        id[v]=nxt;
        nxt++;
        for (int j = 1; j <= N; j++){
            if (g[v][j]){
                q.push(j);
            }
        }
    }
}

int main(){ _
    cin >> N;
    memset(id, 0, sizeof id);
    for (int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        g[u][v]=1;
        g[v][u]=1;
    }    
    nxt=1;
    bfs(1);

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (i==j) continue;
            for (int k = 1; k <= N; k++){
                if (g[i][k] and g[j][k]){
                    share_nei[id[i]][id[j]]=1;
                    share_nei[id[j]][id[i]]=1;
                }
            }
        }
    }

    vi solucao; 
    memset(status, FREE, sizeof status);
    for (int i = N; i >= 1; i--){
        if (status[i]==USED or status[i]==FORBIDDEN) continue;
        status[i]=USED;
        solucao.pb(i); 
        for (int j = 1; j <= N; j++){
            if (share_nei[i][j]){
                status[j]=FORBIDDEN;
            }
        }
    }
    cout << solucao.size() << endl;
    exit(0);
}
