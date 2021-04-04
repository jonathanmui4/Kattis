#include <bits/stdc++.h>
using namespace std;

typedef vector<int> v_Int; //Defining this term to be type "int vectors"

//Depth First Search
void dfs(int x, vector <v_Int>& Adjacency_List, v_Int& visited) {
	visited[x] = 1; //Mark current vertex as visited
	// for (int i = 0; i < Adjacency_List[x].size(); i++) { //Iterate through all neighbours of vertex x
	// 	if (visited[i] != 1) { //If neighbour not visited, recursively go there
	// 		dfs(i, Adjacency_List, visited);
	// 	}
	// }
	for (auto &v : Adjacency_List[x]) { //Iterate through all neighbours of vertex x
		if (!visited[v]) {
			dfs(v, Adjacency_List, visited); //If neighbour not visited, recursively go there
		}
	}
}

int main() {
	vector <v_Int> Adjacency_List;
	v_Int visited;
	int N, M; //N is no of houses, M is no of internet cables connecting the houses
	//N is no of nodes, M is no of edges
	cin >> N >> M;
	Adjacency_List.assign(N, v_Int()); //Assigning N integer vectors (LinkedLists) to the adjacency list
	for (int i = 0; i < M; i++) {
		int a, b; //a and b are house numbers. Input here means a is connected to b by a cable
		cin >> a >> b; 
		a--; //0 indexing
		b--;
		Adjacency_List[a].push_back(b); //adds b in linked list a of adjacency list, symbolising a has neighbour vertex b
		Adjacency_List[b].push_back(a); //adds a in linked list b of adjacency list, symbolising b has neighbour vertex a
	}
	visited.assign(N, 0); //Sets size of visited array to N
	dfs(0, Adjacency_List, visited); //Starting depth first search from vertex 0 to look for houses connected to each other

	bool disconnected = false;
	for (int i = 0; i < N; i++) { //Iterate through all houses
		if (!visited[i]) { //If vertexes not visited from DFS, means they are not connected to internet
			disconnected = true;
			cout << i + 1 << endl;
		}
	}
	if (!disconnected) {
		cout << "Connected\n";
	}
	return 0;
}