/*
	
	Program to find the number of unreachable nodes in an undirected unweighted graph.
	
	Question:
	You have been given a graph consisting of N nodes and M edges. The nodes in this graph are enumerated from 1 to N . The graph can consist of self-loops as well as multiple edges. This graph consists of a special node called the head node. You need to consider this and the entry point of this graph. You need to find and print the number of nodes that are unreachable from this head node.
	
	An undirected graph is a graph in which the direction of an edge between the nodes doesn't matter.
	
	Example of Undirected Graph:
	
	(Node 1) -- (Node 2)
	This is same as (Node 2) -- (Node 1)
	
	Example of Directed Graph:
	
	(Node 1) --> (Node 2) 
	
	This is not same as (Node 2) --> (Node 1)
	
	Example of Unreachable node in an undirected graph:
	
	(Node 1) -- (Node 2) -- (Node 3)    (Node 4) -- (Node 5)    (Node 6)

	In the graph above, there are 6 nodes, with Node 1 as head node. The head node is connected to Node 2 and Node 3, however, there is no edge linking Node 1, Node 2 and Node 3 with Node 4, Node 5 or Node 6. Hence, Node 4, Node 5 and Node 6 are unreachable from head node i.e Node 1.
	
	Note: All graphs illustrated as examples are unweighted graphs.
	
	
	Author: Ravi Shankar
	Date: 04-05-2021
	
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

/*void dfs-recursive(int s){
    vis[s]=true;

    for(int i=0;i<v[s].size();i++){
        if(vis[s][i]==false){
            dfs(v[s][i]);
        }
    }
    return;
}*/

int main(){

	int nodes, edges;
	cin>>nodes>>edges;
	int x,count;
	vector<int> adj[nodes+1];
	vector<bool> vis(nodes+1,false);

	int a,b;

	for(int i=0;i<edges;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cin>>x;

    stack<int> s;

    s.push(x);
    vis[x]=true;

    while(!s.empty()){
        int p=s.top();
        s.pop();

        for(int i=0;i<adj[p].size();i++){
            if(vis[adj[p][i]]==false && count<1){
                s.push(adj[p][i]);
                vis[adj[p][i]]=true;
                }
            }
        } 
    
    for(int i=1;i<nodes+1;i++){
        if(vis[i]==false){
            count++;
        }
    }
    
    cout<<count;

    return 0;
}

