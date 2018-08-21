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

const ll MAX_P = 90000000000;
ll N, A, B;

int main(){
  cin >> N >> B >> A;
  if(A + B - 1 > N || A * B < N) {
    cout << -1 << endl;
    return 0;
  }
  if(B == 1) {
    REP(i, N) {
      cout << N - i << " ";
    }
    cout << endl;
    return 0;
  }

  vi p[B];
  int N_ = N - (A + B - 1);
  int num = 1;
  REP(i, B) {
    // cout << i << endl;
    if(i == 0) {
      REP(j, A) {
        p[i].push_back(num);
        num++;
      }
    } else if(i < N_ % (B - 1) + 1) {
      REP(j, N_ / (B - 1) + 2) {
        p[i].push_back(num);
        num++;
      }
    } else {
      REP(j, N_ / (B - 1) + 1) {
        p[i].push_back(num);
        num++;
      }
    }
  }

  REP(i, B) {
    REP(j, p[i].size()) {
      cout << p[i][p[i].size() - j - 1] << " ";
    }
  }
  cout << endl;

  return 0;
}
