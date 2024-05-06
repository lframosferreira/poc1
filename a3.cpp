// pescoço pra baixo é canela
// total domination number in trees

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

const int MAX = 5000;

#define BOUND 0
#define REQUIRED 1
#define FREE 2
#define NEEDED 3

int g[MAX][MAX];
int N;
int parent[MAX];
int status[MAX];
int id[MAX];
int nxt;

void bfs(int u){
    queue<ii> q;
    q.push({u, 0});
    while (!q.empty()){
        auto [v, p] = q.front();q.pop();
        if (id[v]) continue;
        id[v]=nxt;
        nxt++;
        parent[id[v]]=id[p];
        for (int j = 1; j <= N; j++){
            if (g[v][j]){
                q.push({j, v});
            }
        }
    }
}


int main(){ _
    cin >> N;
    memset(id, 0, sizeof id);
    memset(parent, 0, sizeof parent);
    for (int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        g[u][v]=1;
        g[v][u]=1;
    }    
    nxt=1;
    bfs(1);

    vi solucao; 
    memset(status, BOUND, sizeof status);
    for (int i = N; i >= 2; i--){
        if (status[i]==BOUND and status[parent[i]]==BOUND){
            status[parent[i]] = REQUIRED;
        }
        else if (status[i]==BOUND and status[parent[i]]==FREE){
            status[parent[i]] = NEEDED;
        }
        else if (status[i]==REQUIRED){
            status[parent[i]] = NEEDED;
        }
        else if (status[i]==NEEDED and status[parent[i]]==BOUND){
            status[parent[i]] = FREE;
        }
        else if (status[i]==NEEDED and status[parent[i]]==REQUIRED){
            status[parent[i]] = NEEDED;
        }
    }

    if (status[1]==REQUIRED or status[1]==BOUND) status[2]=REQUIRED;

    for (int i = 1; i <= N; i++) if (status[i]==NEEDED or status[i]==REQUIRED) solucao.pb(i);

    cout << solucao.size() << endl;
    exit(0);
}
