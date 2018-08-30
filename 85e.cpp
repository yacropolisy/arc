#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string.h>
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

const int MAX_N = 300000;

int N, K;

int s[MAX_N];

int crt;

void step () {
  if(s[crt] == 1) {
    s[crt] = 0;
    crt--;
  } else {
    s[crt]--;
    while(crt < N - 1) {
      s[++crt] = K;
    }
  }
}

int main(){
  cin >> K >> N;

  if(K % 2 == 0) {
    cout << K / 2;
    REP(i, N - 1) cout << " " << K << endl;
    return 0;
  }

  REP(i, N) s[i] = K / 2 + 1;

  crt = N - 1;
  REP(i, N / 2) {
    step();
  }

  REP(i, N) {
    if(s[i] == 0) {
      cout << endl;
      return 0;
    }
    cout << s[i] << " ";
  }
  cout << endl;
  return 0;
}
