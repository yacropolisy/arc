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

string s;

// bit_sum O(log n) for a query
// 1. set n;
// 2. init bit[n+1];

const int MAX_N = 100000;

ll bit[MAX_N+1], n;

ll bit_sum(int i){
  ll s = 0;
  while(i > 0){
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void bit_add(int i, ll x){
  while(i <= n){
    bit[i] += x;
    i += i & -i;
  }
}


int main(){
  cin >> s;
  int len = s.size();
  int place[len];

  map<char, int> mp;
  REP(i, len) {
    mp[s[i]]++;
  }
  map<char, int> ct;
  bool kisuu = false;
  for (auto x : mp) {
    if(x.second % 2 == 1) {
      if(kisuu) {
        cout << -1 << endl;
        return 0;
      } else {
        kisuu = true;
      }
    }
  }

  string right, left;

  REP(i, len) {
    char c = s[i];
    ct[c]++;

    if(ct[c] <= mp[c] / 2) {
      place[i] = 3;
      left += c;
    } else if(mp[s[i]] % 2 == 1 && ct[c] == mp[c] / 2 + 1) {
      place[i] = 2;
    } else {
      place[i] = 1;
      right += c;
    }
  }

  ll bubble = 0;

  n = 3;
  REP(i, n + 1) {
    bit[i] = 0;
  }

  REP(i, len) {
    bubble += bit_sum(place[i] - 1);
    bit_add(place[i], 1);
  }

  // cout << "firsr bubble: " << bubble << endl;
  //
  // cout << "left: " << left << ", right: " << right << endl;

  ct.clear();
  map<char, map<int, int> > place_mp;
  REP(i, len / 2) {
    char c = left[i];
    ct[c] ++;
    place_mp[c][ct[c]] = len / 2 - i;
  }
  ct.clear();
  int forbubble[len / 2];
  REP(i, len / 2) {
    char c = right[len / 2 - 1 - i];
    ct[c] ++;
    forbubble[i] = place_mp[c][ct[c]];
  }
  //
  // REP(i, len / 2) cout << forbubble[i] << ",";
  // cout << endl;

  n = len / 2;
  REP(i, n + 1) {
    bit[i] = 0;
  }
  REP(i, len / 2) {
    bubble += bit_sum(forbubble[i] - 1);
    bit_add(forbubble[i], 1);
  }

  cout << bubble << endl;

  return 0;
}
