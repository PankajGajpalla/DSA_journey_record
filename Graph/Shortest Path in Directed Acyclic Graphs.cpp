#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;
    
    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }
    
    void printedge(){
        for(auto i: adj){
            cout<< i.first << " -> ";
            for(auto j: i.second){
                cout<< "("<< j.first<<","<< j.second<<")";
            }
            cout<<endl;
        }
    }
    
    void toposort(stack<int> &s, int node, vector<int>& visited){
        visited[node] = 1;
            
        for(auto neighbour: adj[node]){
            if(!visited[neighbour.first]){
                toposort(s, neighbour.first,  visited);
            }
        }
            
        s.push(node);
    }
    
    void toposortPrint(stack<int> s){
        while(!s.empty()){
            cout<<s.top()<<" -> ";
            s.pop();
        }
        cout<<endl;
    }
    
    void getShortestPath(int src_node, vector<int> &dist, stack<int> &s){
        dist[src_node] = 0;
        
        while(!s.empty()){
    	    int t = s.top();
    	    s.pop();
    	    
    	    if(dist[t] == INT_MAX) continue;
    	    
    	    for(auto p: adj[t]){
    	        if( (p.second + dist[t]) < dist[p.first]){
    	            dist[p.first] = dist[t] + p.second;
    	        }
    	    }
        }
    }
    
};

int main() {
	
	Graph g;
	
	g.addEdge(0, 1, 5);
	g.addEdge(0,2,3);
	g.addEdge(1,2,2);
	g.addEdge(1,3,6);
	g.addEdge(2,3,7);
	g.addEdge(2,4,4);
	g.addEdge(2,5,2);
	g.addEdge(3,4,-1);
	g.addEdge(4,5,-2);
	
	g.printedge();
	
	int n = 6;
	
	vector<int> visited(n, 0);
	stack<int> s;
	
	for(int i=0; i<n; i++){
	    if(!visited[i]){
	        g.toposort(s, i, visited);
	    }
	}
	
	g.toposortPrint(s);
	
	// -------------------------
	vector<int> dist(n, INT_MAX);
	int src_node = 1;
	
	g.getShortestPath(src_node, dist, s);
	
	for(int i=0; i<n; i++){
	    cout<< dist[i] << " - ";
	}
	
	return 0;
	
}
