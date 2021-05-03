/*
	Program to find the number of unreachable nodes in a graph.
	
	Author: Ravi Shankar
	Date: 04-05-2021
	
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

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

