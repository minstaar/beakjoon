#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sd second
#define pii pair<ll,ll>
typedef long long ll;
vector<pii> adj[5001];
vector<pii> nadj[5001];
ll n, b, s, r;
ll d[5001];
ll ps[5001];
ll dp[5001];
ll numOfInterval[5001],q[5001],c[5001];

struct Node {
	ll d;
	ll num;
	bool operator<(const Node& a)const {
		return d > a.d;
	}
};
Node node[5001];

void scan() {
	cin >> n >> b >> s >> r;
	while (r--) {
		ll a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b,w });
		nadj[b].push_back({ a,w });
	}
}

void dijkstra(ll st,bool f) {
	for (ll i = 1; i <= n; ++i)node[i].d = LLONG_MAX;
	node[st].d = 0;
	priority_queue<Node> pq;
	pq.push(node[st]);
	while (pq.size()) {
		Node cur = pq.top();
		pq.pop();
		if (node[cur.num].d < cur.d)continue;
		for (auto& [nxt,w] : (f?adj[cur.num]:nadj[cur.num])) {
			if (node[nxt].d > cur.d + w) {
				node[nxt].d = cur.d + w;
				pq.push(node[nxt]);
			}
		}
	}
}

ll cost(ll a, ll b) {
	return (b - a - 1) * (ps[b] - ps[a]);
}

ll func(ll l, ll r){
    return dp[l]+cost(l,r);
}

ll cross(ll i, ll j){
    ll l = j+1, r=b+1;
    while(l<r){
        ll mid = l+r>>1;
        if (func(i,mid)<=func(j,mid)) l = mid+1;
        else r=mid;
    }
    return l-1;
}

void optimization(ll m){
    ll front=0,rear=1;
    q[0]=0,c[0]=b;
    for(int i=1; i<=b; ++i){
        while(c[front]<i)++front;
        dp[i]=func(q[front],i)+m;
        numOfInterval[i]=numOfInterval[q[front]]+1;
        while(front+1<rear && cross(q[rear-1],i)<c[rear-2])--rear;
        c[rear-1]=cross(q[rear-1],i);
        q[rear]=i;
        c[rear++]=b;
    }
}
void chunmae() {
	scan();
	for (int i = 1; i <= n; ++i)node[i].num = i;
	dijkstra(b + 1, 1);
	for (ll i = 1; i <= b; ++i) {
		d[i] = node[i].d;
	}
	dijkstra(b + 1, 0);
	for (ll i = 1; i <= b; ++i) {
		d[i] += node[i].d;
	}
	sort(d + 1, d + (b + 1));
	for (int i = 1; i <= b; ++i) {
		ps[i] = ps[i - 1] + 2*d[i];
	}
    ll l=0, r=1e17;
    while(l<r){
        ll mid = l+r>>1;
        optimization(2*mid+1);
        //cout<<"mid="<<mid<<" ,numOfInterval[b]:"<<numOfInterval[b]<<", dp[b]"<<dp[b]<<endl;
        if(numOfInterval[b]<s)r=mid;
        else if(numOfInterval[b]>s) l=mid+1;
		else {
			cout<<(dp[b]-(mid*2+1)*s >> 1); return;
		}
    }
	optimization(r*2);
    //cout<<"numOfInterval[b]:"<<numOfInterval[b]<<endl;
	cout << (dp[b]-r*2*s>>1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	chunmae();
}