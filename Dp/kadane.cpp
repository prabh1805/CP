#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;



// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")


//大きい

#define nl 		'\n'
#define mod 		1000000007
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


// ループ コントロール

#define FORA(I,A,B)  	for(int I=(A);I<=(B);I++)
#define FORR(I,A,B)	for(int I=(A);I>=(B);I--)


using ll=long long;
using ld=long double;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vd=vector<double>;
using vld=vector<ld>;
using pq_max=std::priority_queue<ll>;
using pq_min=std::priority_queue<ll,vi,std::greater<ll>>;

using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<double,double>;
using pld=pair<ld,ld>;

using vpii=vector<pii>;
using vpll=vector<pll>;
using vpld=vector<pld>;

using mii=map<int,int>;
using mll=map<ll,ll>;
using mib=map<int,bool>;

//PBDS
using ranked_pairset = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;
using ranked_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ranked_map = tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update>;



//Debugging____start

#ifndef LOCAL
#define cerr if (false) cerr
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
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define debugA(x, y) cerr << "[" << #x << "] = "; _printA(x, y)

//Debugging____end

//binary exponentiation

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


void setIO()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    
}


int main(){

	setIO();
	
	int n;
	cin>>n;

	vl arr(n);

	trav(x,arr){
	  cin>>x;
	}

	ll sum=0,ans=-inf;

	for(int i=0;i<n;i++){
	  sum=max(arr[i],sum+arr[i]);

	  ans=max(ans,sum);
	}
	cout<<ans<<nl;
	return 0;

}


