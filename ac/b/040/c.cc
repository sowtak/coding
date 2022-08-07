#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <cstring>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
template <typename T> inline bool chmin(T &a, T &b) {if (a>b){a=b; return true;} else return false;}
template <typename T> inline bool chmax(T &a, T &b) {if (a<b){a=b; return true;} else return false;}
using namespace std;

const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAX = 2147483647;
int dx4[4]={1,0,-1,0};
int dy4[4]={0,1,0,-1};
int dx8[8]={0,1,0,-1,1,1,-1,-1};
int dy8[8]={1,0,-1,0,1,-1,1,-1};


int N, a[100000];
ll min_cost_to_ith_step[100000];
int main() {
  cin>>N;rep(i,0,N)cin>>a[i];
  vector<int> dp(N+1, MAX);

  min_cost_to_ith_step[0] = 0;
  min_cost_to_ith_step[1] = abs(a[1]-a[0]);
  rep(i,2,N)
  {
    int diff_adjascent_steps = abs(a[i]-a[i-1]);
    int diff_two_steps = abs(a[i-2] - a[i]);
    min_cost_to_ith_step[i] =
      min(min_cost_to_ith_step[i-1] + diff_adjascent_steps
        , min_cost_to_ith_step[i-2] + diff_two_steps);
  }
  
  cout<<min_cost_to_ith_step[N-1]<<endl;
}
