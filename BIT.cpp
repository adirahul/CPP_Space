/**
 *    author:  aditya_raj   
**/    
#include "bits/stdc++.h"
using namespace std; 
#define int                            long long
using ll                               = long long;
#define sz(x)                          (int)(x).size()
#define pb                             push_back
#define pi                             pair<int, int>
#define vi                             vector<int>
#define vvi                            vector<vector<int>>
#define vpi                            vector<pi>
#define F                              first
#define mp                             make_pair
#define S                              second
const ll mod                           = 1000000007;
#define all(a)                         (a).begin(), (a).end()
#define rep(i, a, n)                   for (int i = a; i < n; i++)
template <class T>                     void print(T &a) {cout<< a <<endl;}
template <class T>                     void printYN(T &a) {cout<<( a? "Yes\n" : "No\n");}
#define mset(arr, v)                   memset(arr, v, sizeof(arr))
template <class T, class C>            void self_max(T &a, C b) { a > b ?: a = b; }
template <class T, class C>            void self_min(T &a, C b) { a < b ?: a = b; }
ll binexp(ll a, ll b, ll md =mod)      {ll res = 1; while(b) {if(b& 1) {res=(a*res)%md;} a=(a*a)%md; b>>=1;} return(res);}

/* Debug Begins */ 
# define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
  stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

string to_string(char c) { return "'" + string(1, c) + "'";}
string to_string(string s) { return '"' + s + '"';}
string to_string(bool f) { if(f) return "True"; else return "False";}
string to_string(const char* s) { return to_string((string) s);}

template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p){
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";}
template<typename A> string to_string(A v) {bool f = false; string r = "{"; 
  for (auto x: v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";}
template<typename A> string to_string(vector<vector<A>> v) {string r; 
  for (auto x: v) r += "\n" + to_string(x); return r;}

int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}

#define Lu(...) [&] (auto &&u) { return __VA_ARGS__; }
#define Luv(...) [&] (auto &&u, auto &&v) { return __VA_ARGS__; }
/***************************************************************/




template <typename T>
  struct binary_indexed_tree{
          int N;
          vector<T> BIT;                    //BIT[i] =  stores sum of range [j + 1, i], j = removed last bit of i  =  i - i & -i (last setbit of i) 
          binary_indexed_tree(int n){
                  N = 1;
                  while(N < n){
                      N *= 2;
                  }
                  BIT = vector<T> (N + 1, 0);
          }
          void add(int i, T x){             // to add x at ind i we need to add x to all those ind whose last set bit removed has ind i in range
                  i++;
                  while(i <= N){
                      BIT[i] += x;
                      i += i & -i;
                  }
          }

          T sum(int i){                   // gives sum of array in range [0, i]  if i = 1101, we need BIT[13] {13, 13} + BIT[12] {9, 12} + BIT[8] {1, 8}
                  T ans = 0;
                  while(i > 0){
                      ans += BIT[i];
                      i -= i & -i;
                  }
                  return ans;
          }

          T query(int L, int R){
                  return sum(R) - sum(L);
          }
          T get_id_val(int i){
                  return BIT[i];
          }
            /*    // to count no of inv we take every element of array as index of bit
            vi a = {4, 5, 1, 2, 3};
            binary_indexed_tree<ll> BIT(10); // size greater than max element in the array , if size exceeds 1e5, do coordinate compression.
              int count_inv = 0;
           
            for(int i = 0; i < 5; i++){
                  count_inv += BIT.sum(9) - BIT.sum(a[i]);
                  BIT.add(a[i], 1);
            }
            //count_inv => 6
            
             */
  };




int32_t main()
{
  ios::sync_with_stdio(false); cin.tie(nullptr);
  
  vi a = {4, 5, 1, 2, 3};
  binary_indexed_tree<ll> bit(6);
  for(int i = 0; i < 5; i++){
    bit.add(i, a[i]);
  }
  rep(i, 0, 6)
  cout << bit.query(0, i) << ' ';    // 0 4 9 10 12 15
  
}