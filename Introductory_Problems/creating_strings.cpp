   /*
           Author: Himanshu M. Mude

           Date: 
   */


    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    #include <functional>
    using namespace std;
    using namespace __gnu_pbds;
    #define ll long long
    #define gcj "Case #"    
    #define pb push_back
    #define all(_obj) _obj.begin(), _obj.end()
    #define F first
    #define S second
    #define pll pair<ll, ll>
    #define vll vector<ll>
    #define yes cout<<"YES\n"
    #define no cout<<"NO\n"
    ll INF = 1e18;
    const int mod = 1e9 + 7;
    #define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    /*------------------Macros end here------------------*/

    /*-----------------Debugger------------------*/
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

    template <class T> using multi_ordered_set = tree<T, null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

    template <class T> using ordered_set = tree<T, null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

    template<typename T, typename V>
    void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
    template<typename T>
    void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
    void _print() {cerr << "]\n";}
    template <typename T, typename... V>
    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
    #ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    #else
    #define debug(x...)
    #endif
    /*----------------------Debugger ends here-------------------*/




    /*------------------- Code Starts Here --------------------*/


    
    void solve(){
        string s;
        cin>>s;
        sort(all(s));
        ll cnt=0;
        vector<string>res;
        while(next_permutation(all(s)))
        {
            cnt++;
            res.pb(s);
        }

        cout<<cnt<<"\n";
        for(auto &i:res)
        {
            cout<<i<<"\n";
        }

    }




    int main()
    {
        
        fastio;
        long long int t;
        // cin>>t;
        t=1;
        while(t--)
        {
            solve();
        }
        return 0;
    }
