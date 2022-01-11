/*
  Problem Link

  https://codeforces.com/contest/1373/problem/D
*/

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;



// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")


//大きい

#define nl 		'\n'
#define mod 		1000007
#define inf 		2e18
#define PI 		3.141592653589793238462

#define eb 		empalce_back
#define pb 		push_back
#define mp 		make_pair
#define ff 		first
#define ss 		second
#define sz(x) 		(int)x.size()
#define mk(arr,n,type)  type *arr=new type[n];
#define mem(arr,x)	memset(arr,x,sizeof x;)
#define case_g(c) 	cout<<"Case #"<<x<<":"
#define all(v) 		v.begin(),v.end()
#define rall(x) 	x.rbegin(),x.rend()
#define trav(a,x) 	for(auto &a:x)
#define YN(val) 	cout<<((val) ? "Yes":"No")<<nl;
#define mid(l,r) 	(l+(r-l)/2)
#define setbits(x) 	__builtin_popcountll(x)
#define ps(x,y) 	fixed<<setprecision(y)<<x
#define ins		insert


// ループ コントロール

#define FORA(I,A,B)  	for(int I=(A);I<=(B);I++)
#define FORR(I,A,B)	for(int I=(A);I>=(B);I--)

using ll=long long;
using ld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

//PBDS
/*
using ranked_pairset = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;
using ranked_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ranked_map = tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
*/


//Debugging____start

#ifndef DLOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x);cerr<<endl;
#define debugA(x, y) cerr << "[" << #x << "] = "; _printA(x, y)
#endif

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename T>
void _printA(T *t, long long sz) { cout<<" { "; for (long long i=0; i<sz; i++) cout<<"["<<i<<"] = "<< t[i]<<endl; cout<<" } \n";}


//Debugging____end

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;



mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


void setIO()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    
}

void solve(){
  
  int n;
  cin>>n;

  //so reversing and odd length subarray wont change anything as parity remains same
  //so we have to reverse subrray of even length
  //say we reverse an even subaaray of length x starting at l
  //since subarray is continugous we can say that reversing subarray of length x is same as reversing subarray of length 2 from l x/2 times
  //so if we compute the difference b/w adjancent elements the problem is reduced to find the maximum sum of subarray which can be done with kadane's algorithm
  //also we need to do that 2 times one while considering diifernce starting from even index and one from odd index
  //when we start from from even index the i+1th element will becom even and the ith will become odd so we will build differnce array considering difference as arr[i+1]-arr[i]
  //in case of odd position ith element will become even and i+1h will become odd so the difference array wil be fromed using arr[i]-arr[i+1].. as this much value will be increased
  //so we need to add the maximum of two difference array to the answer

  vector<int> arr(n);
  ll sum=0;

  for(int i=0;i<n;i++){
	cin>>arr[i];

	if(i%2==0)
	  sum+=arr[i];
  }
	
  vector<ll>v1,v2;

  for(int i=0;i<n-1;i+=2)
	v1.pb(arr[i+1]-arr[i]);

  for(int i=1;i<n-1;i+=2)
	v2.pb(arr[i]-arr[i+1]);

  ll curr=0,mx=0;

  for(ll i:v1){
	curr=max(i,curr+i);
	mx=max(mx,curr);
  }

  curr=0;

  for(ll i:v2){
	curr=max(i,curr+i);
	mx=max(mx,curr);
  }

  cout<<sum+mx<<nl;
}


int main(){

	setIO();
	
	int T;
	cin>>T;
	
	while(T--){
		solve();
	}	
	
	return 0;

}


