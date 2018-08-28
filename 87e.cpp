#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

const int MAX_N = 100000;

int N;
ll L;
string s[MAX_N];

vi trie[MAX_N + 1];
char c[MAX_N + 1];

bool used[MAX_N + 1];

ll ans = 0;

ll divide(ll n){
  int k = 1;
	while(n % 2 == 0){
		k++;
		n /= 2;
	}
	return k;
}

void dfs(int v, ll d) {
  used[v] = true;
  if(trie[v].size() == 1) ans ^= divide(L - d);

  REP(i, trie[v].size()) {
    if(!used[trie[v][i]]) dfs(trie[v][i], d + 1);
  }
  return;
}

int main(){
  cin >> N >> L;
  int k = 0;
  REP(i, N) {
    cin >> s[i];
    int y = 0;
    REP(j, s[i].size()) {
      bool flag = false;
      REP(l, trie[y].size()) {
        if(c[trie[y][l]] == s[i][j]) {
          y = trie[y][l];
          flag = true;
          break;
        }
      }
      if(!flag) {
        k++;
        trie[y].push_back(k);
        c[k] = s[i][j];
        y = k;

      }
    }
  }

  REP(i, MAX_N) used[i] = false;
  dfs(0, 0);

  if(ans == 0) cout << "Bob" << endl;
  else cout << "Alice" << endl;

  return 0;
}
