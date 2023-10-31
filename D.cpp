#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"


void solve() {
    int n,k; cin >> n >> k;
    vector<pair<int,int>> a(n);
    for(auto &p : a) cin >> p.first >> p.second;
    sort(a.begin(), a.end());
    multiset<int> st,end;
    int ans = 0LL;
    for(int i=0; i<k; i++) {
        st.insert(a[i].first);
        end.insert(a[i].second);
    }
    int term = (*end.begin() - *st.rbegin())+1;
    // cout << term << " ";
    ans = max(ans, max(0LL, term));
    for(int i = k; i < n; i++) {
        st.erase(st.find(a[i-k].first));
        end.erase(end.find(a[i-k].second));

        st.insert(a[i].first);
        end.insert(a[i].second);
        term = (*end.begin() - *st.rbegin())+1;
        ans = max(ans, max(0LL, term));
        // cout << term <<" ";
    }
    cout << ans <<endl;
}


int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(6);
    
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}       
