#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> v[n];
    for(int i=0;i<n;i++){
        int a,b,wt;cin>>a>>b>>wt;
        v[a].push_back({b,wt});
        v[b].push_back({a,wt});
    }

    int src;cin>>src;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> d(n+1,INT_MAX);

    pq.push({0,src});
    d[src]=0;

    while(!pq.empty()){
        pair<int,int> t=pq.top();pq.pop();
        int dist=t.first;
        int prev=t.second;

        vector<pair<int,int>>::iterator it;
        for(it=v[prev].begin();it!=v[prev].end();it++){
            int next=it->first;
            int nextdis=it->second;

            if(d[next]>d[prev]+nextdis){
                d[next]=d[prev]+nextdis;
                pq.push({d[next],next});
            }
        }
    }
    cout<<src<<endl;
    for(int i=1;i<=n;i++) cout<<i<<" "<<d[i]<<endl;
    return 0;
}