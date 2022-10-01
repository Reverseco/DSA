#include<bits/stdc++.h>
using namespace std;
 
#define             fast  cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#define             test ll t; cin>>t; while(t--)
#define             loop(i,a,b) for(ll i=a;i<b;i++)
#define             mod 1000000007
#define             INF 1e18
#define             push push_back
#define             pop pop_back
#define             all(X) X.begin(),X.end()
#define             allr(X) X.rbegin(),X.rend()
#define             F first
#define             S second
#define             yes cout << "YES" << endl
#define             no cout << "NO" << endl
 
typedef             long long int ll;
typedef             unsigned long long ull;
typedef             long double lld;
 
bool issafe(vector<vector<ll>>&v,ll x,ll y,ll n){
    if(x<n && y<n && v[x][y]==1){
        return true;
    }
    return false;
}

bool solve(vector<vector<ll>>&v,ll x,ll y,ll n,vector<vector<ll>>&sol){
    
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        return true;
    }
    if(issafe(v,x,y,n)){
        sol[x][y]=1;
        if(solve(v,x+1,y,n,sol)){
            return true;
        }
        if(solve(v,x,y+1,n,sol)){
            return true;
        }
        sol[x][y]=0;
        return false;
    }
    return false;
}
 
int main(){
    fast;
    
        ll n=3;
        vector<vector<ll>>v(100,vector<ll>(100,0));
        loop(i,0,n){
            loop(j,0,n){
                ll x; cin>>x;
                v[i][j]=x;
            }
        }
        vector<vector<ll>>sol(100,vector<ll>(100,0));
        if(solve(v,0,0,n,sol)){
        loop(i,0,n){
            loop(j,0,n){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        }else{
            cout<<"path not found"<<endl;
        }
}