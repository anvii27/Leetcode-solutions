class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;

    bool check(int mid,
               vector<vector<pair<int,int>>> &g,
               vector<bool> &online,
               ll k,
               int n){

        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>,
                       vector<pair<ll,int>>,
                       greater<pair<ll,int>>> pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){

            auto [d,u] = pq.top();
            pq.pop();

            if(d != dist[u]) continue;

            if(d > k) continue;

            if(u == n-1)
                return true;

            for(auto &[v,w] : g[u]){

                if(w < mid)
                    continue;

                if(v != n-1 && !online[v])
                    continue;

                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> g(n);

        int mn = INT_MAX;
        int mx = 0;

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(u != 0 && u != n-1 && !online[u])
                continue;

            if(v != 0 && v != n-1 && !online[v])
                continue;

            g[u].push_back({v,w});

            mn = min(mn,w);
            mx = max(mx,w);
        }

        if(mn == INT_MAX)
            return -1;

        if(!check(mn,g,online,k,n))
            return -1;

        int ans = mn;

        int low = mn;
        int high = mx;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(check(mid,g,online,k,n)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }
};