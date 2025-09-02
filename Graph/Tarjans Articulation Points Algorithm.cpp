#include<bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int, vector<int>> adj;

void DFS(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &articulation_Point){
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;
    int children = 0;

    for(auto v: adj[u]){
        
        if(disc[v] == -1){
            children+=1;     
            parent[v] = u;
            DFS(v, disc, low, parent, articulation_Point);
            low[v] = min(low[u], low[v]);    //for normal tree edge we update low by this formula

            if(parent[u] ==-1 && children>1){ //case-1 if u is a root node and it has more then one children then its a apoint..
                articulation_Point[u] = true; 
            }
            if(parent[u] !=-1 && (low[v]>=disc[u])){ //case-2 if u is not root and v ka low is greater then u (which means its not connected with anyother , the lowest access is u only or its own disc time)
                articulation_Point[u] = true;
            }
        }
        else if(parent[u] != v){ // if v is already visited and its not the parent of u then it means it has a backedge with some ancient node apart from its parent node ( so in case of backedge we use this formula)
            low[u] = min(disc[v], low[u]);
        }
    }
}

void findAPs_Tarjan(){
    vector<int> disc(V, -1), low(V,-1);
    vector<int> parent(V, -1);
    vector<bool> articulation_Point(V, false);

    for(int i=0; i<V; i++)
        if(disc[i] == -1)
            DFS(i, disc, low, parent, articulation_Point);
    
    cout<<"Articulation points: ";
    for(int i=0; i<V; i++)
        if(articulation_Point[i] == true)
            cout<< i ;
}

int main()
{
	adj[0].pb(2);
	adj[2].pb(0);
	adj[0].pb(3);
	adj[3].pb(0);
	adj[1].pb(0);
	adj[0].pb(1);
	adj[2].pb(1);
	//adj[2].pb(4);
	//adj[4].pb(2);
	adj[1].pb(2);
	adj[3].pb(4);
	adj[4].pb(3);

	findAPs_Tarjan();
	return 0;
}



// original:)
// #include<bits/stdc++.h>
// using namespace std;
// #define V 5
// #define pb push_back

// unordered_map<int,vector<int>> adj;

// void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<bool>& articulation_Point)
// {
// 	static int time = 0;
// 	disc[u] = low[u] = time;
// 	time+=1;
// 	int children = 0;

// 	for(int v: adj[u])
// 	{
// 		if(disc[v]==-1)	//If v is not visited
// 		{
// 			children += 1;
// 			parent[v] = u;
// 			DFS(v,disc,low,parent,articulation_Point);
// 			low[u] = min(low[u],low[v]);

// 			if(parent[u]==-1 and children>1)	//Case-1: U is root
// 				articulation_Point[u] = true;

// 			if(parent[u]!=-1 and low[v]>=disc[u])	//Case-2: Atleast 1 component will get separated
// 				articulation_Point[u] = true;
// 		}
// 		else if(v!=parent[u])	//Ignore child to parent edge
// 			low[u] = min(low[u],disc[v]);
// 	}	
// }

// void findAPs_Tarjan()
// {
// 	vector<int> disc(V,-1),low(V,-1),parent(V,-1);
// 	vector<bool> articulation_Point(V,false);	//Avoids cross-edge

// 	for(int i=0;i<V;++i)
// 		if(disc[i]==-1)
// 			DFS(i,disc,low,parent,articulation_Point);

// 	cout<<"Articulation Points are: ";
// 	for(int i=0;i<V;++i)
// 		if(articulation_Point[i]==true)
// 			cout<<i<<" ";
// }

// int main()
// {
// 	adj[0].pb(2);
// 	adj[2].pb(0);
// 	adj[0].pb(3);
// 	adj[3].pb(0);
// 	adj[1].pb(0);
// 	adj[0].pb(1);
// 	adj[2].pb(1);
// 	//adj[2].pb(4);
// 	//adj[4].pb(2);
// 	adj[1].pb(2);
// 	adj[3].pb(4);
// 	adj[4].pb(3);

// 	findAPs_Tarjan();
// 	return 0;
// }

// //TIME COMPLEXITY: O(V+E)
