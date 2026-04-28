//#include "setup.h"
#include<bits/stdc++.h>
using namespace std;
#define  ll  long long
#define int long long
//ll modu=1e9+7;
//ll modu=998244353;
//ll inf=1e18+69;
//const ll maxxx=5e5 + 69;
//int val[maxxx];
//using t=pair<int,int>;
//vector<int>adj[maxxx];
//vector<int>adj2[maxxx];
//map<int,int>mpp[maxxx];
//vector<int>val(maxxx);
//int fact[maxxx],invfact[maxxx];

/*


*/

map<int,int>ItemsQuantity;
map<int,int>UserBalance;
map<int,int>ItemsPrice;
bool PlaceOrder(int user , int item ){
   if(UserBalance[user]<ItemsPrice[item])  return false;
   if(ItemsQuantity[item]==0) return false;
   UserBalance[user]-=ItemsPrice[item];
   ItemsQuantity[item]--;
   return true;
}
bool facadeOrder(int user , int item ){
    return PlaceOrder(user,item);
}
void solve() {
int NumberOfUsers; cin>>NumberOfUsers;
int user , userbalance;
for(int i=0;i<NumberOfUsers;i++){
 cin>>user>>userbalance;
 UserBalance[user]=UserBalance[user]+userbalance;

}
int warehouse;
cin>>warehouse;
int item, itemprice;
for(int i=0;i<warehouse;i++){
    cin>>item>>itemprice;
    ItemsQuantity[item]++;
    ItemsPrice[item]=itemprice;
}
int orders;
cin>>orders;
int u , it;
for(int i=0;i<orders;i++){
    cin>>u>>it;
    if(facadeOrder(u,it)) cout<<"Success\n";
    else cout<<"Failure\n";
}
}


int32_t main() {
//    setup();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
//    doo();
//     precompute();
//    cin>>t ;
    while(t--)  solve();
}