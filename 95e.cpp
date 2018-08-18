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

const int MAX_H = 12;

int H, W;
string S[MAX_H];

bool synmetry (string s1, string s2) {
  int n = s1.size();
  REP(i, n) {
    if(s1[i] != s2[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

bool check(string s[]) {
  bool used[W];
  REP(j, W) used[j] = false;
  bool center_is_remain = false;
  if(W % 2 == 1) center_is_remain = true;
  REP(j, W) {
    if(used[j]) continue;
    bool flag = false;
    REP(k, W) {
      if(k == j || used[k]) continue;
      if(synmetry(s[j], s[k])) {
        flag = true;
        used[j] = true;
        used[k] = true;
        break;
      }
    }
    if(!flag) {
      if(center_is_remain && synmetry(s[j], s[j])) {
        center_is_remain = false;
        flag = true;
        used[j] = true;
      }
    }
    if(!flag) return false;
  }
  return true;
}

bool dfs(bool used[], vpi swaps, int crt) {
  // cout << "crt " << crt << endl << "used ";
  // REP(i, H) cout << used[i] << ",";
  // cout << endl << "swaps ";
  // REP(i, swaps.size()) cout << swaps[i].first << "-" << swaps[i].second << ", ";
  // cout << endl;

  if(crt == H) {
    string swapped[H];
    REP(i, H) swapped[i] = S[i];
    REP(i, swaps.size()) {
      swap(swapped[swaps[i].first], swapped[swaps[i].second]);
    }
    string s[W];
    REP(i, H) {
      REP(j, W) {
        s[j].push_back(swapped[i][j]);
      }
    }
    // cout << endl << "swaps ";
    // REP(i, swaps.size()) cout << swaps[i].first << "-" << swaps[i].second << ", ";
    // cout << endl;
    // REP(j, W) cout << s[j] << endl;
    // cout << "check " << check(s) << endl;
    return check(s);
  }
  if(used[crt]) {
    return dfs(used, swaps, crt + 1);
  }
  used[crt] = true;
  REP(i, H) {
    if(used[i]) continue;
    vpi tmp_swaps = swaps;
    bool tmp_used[H];
    REP(j, H) tmp_used[j] = used[j];
    tmp_swaps.push_back(pi(crt, i));
    tmp_used[i] = true;
    if(dfs(tmp_used, tmp_swaps, crt + 1)) return true;
  }
  return dfs(used, swaps, crt + 1);
}

int main(){
  cin >> H >> W;
  REP(i, H) cin >> S[i];

  bool used[H];
  REP(i, H) used[i] = false;
  vpi swaps;
  if(dfs(used, swaps, 0)) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
