#include <bits/stdc++.h>
using namespace std;

template<class flow_t> struct HLPP{
	struct Edge{
		int to, inv;
		flow_t rem, cap;
	};
 
	vector<vector<Edge>> G; // Don't use basic_string here, it will fuck up your entire life
	vector<flow_t> excess;
	vector<int> hei, arc, prv, nxt, act, bot;
	queue<int> Q;
	int n, high, cut, work;
 
	// Initialize for n vertices
	HLPP(int k): G(k) {}
 
	int addEdge(int u, int v, flow_t cap, flow_t rcap = 0){
		G[u].push_back({v, (int)G[v].size(), cap, cap});
		G[v].push_back({u, (int)G[u].size() - 1, rcap, rcap});
		return (int)G[u].size() - 1;
	}
 
	void raise(int v, int h){
		prv[nxt[prv[v]] = nxt[v]] = prv[v];
		hei[v] = h;
		if(excess[v] > 0){
			bot[v] = act[h]; act[h] = v;
			high = max(high, h);
		}
		if(h < n) cut = max(cut, h+1);
		nxt[v] = nxt[prv[v] = h += n];
		prv[nxt[nxt[h] = v]] = v;
	}
 
	void global(int s, int t){
		hei.assign(n, n*2);
		act.assign(n*2, -1);
		iota(prv.begin(), prv.end(), 0);
		iota(nxt.begin(), nxt.end(), 0);
		hei[t] = high = cut = work = 0;
		hei[s] = n;
		for(int x: {t, s}){
			for(Q.push(x); !Q.empty(); Q.pop()){
				int v = Q.front();
				for(auto &e: G[v]){
					if(hei[e.to] == n * 2 && G[e.to][e.inv].rem){
						Q.push(e.to);
                        raise(e.to, hei[v] + 1);
                    }
				}
			}
        }
	}
 
	void push(int v, Edge& e, bool z){
		auto f = min(excess[v], e.rem);
		if(f > 0){
			if(z && !excess[e.to]){
				bot[e.to] = act[hei[e.to]];
				act[hei[e.to]] = e.to;
			}
			e.rem -= f; G[e.to][e.inv].rem += f;
			excess[v] -= f; excess[e.to] += f;
		}
	}
 
	void discharge(int v){
		int h = n*2, k = hei[v];
		
        for(int j=0; j<G[v].size(); j++){
			auto& e = G[v][arc[v]];
			if(e.rem){
				if(k == hei[e.to]+1){
					push(v, e, 1);
					if(excess[v] <= 0) return;
				}
                else h = min(h, hei[e.to] + 1);
			}
			if (++arc[v] >= G[v].size()) arc[v] = 0;
		}
 
		if(k < n && nxt[k+n] == prv[k+n]){
			for(int j=k; j<cut; j++){
			    while(nxt[j+n] < n){
				    raise(nxt[j+n], n);
                }
			}
			cut = k;
		}
        else raise(v, h), work++;
	}
 
	// Compute maximum flow from src to dst
	flow_t flow(int src, int dst){
		excess.assign(n = G.size(), 0);
		arc.assign(n, 0);
		prv.assign(n*3, 0);
		nxt.assign(n*3, 0);
		bot.assign(n, 0);
		for(auto &e : G[src]){
			excess[src] = e.rem;
            push(src, e, 0);
		}
 
		global(src, dst);
 
		for(; high; high--){
			while(act[high] != -1){
				int v = act[high];
				act[high] = bot[v];
				if(v != src && hei[v] == high){
					discharge(v);
					if(work > 4*n) global(src, dst);
				}
			}
        }
		return excess[dst];
	}
 
	// Get flow through e-th edge of vertex v
	flow_t getFlow(int v, int e){
		return G[v][e].cap - G[v][e].rem;
	}
 
	// Get if v belongs to cut component with src
	bool cutSide(int v) {return hei[v] >= n;}
};