#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		bool recursive(int current, int k, int sum, int *visited){
			if(sum > k)
				return true;
			for(vector<pair<int,int>>::iterator it = this->edges[current].begin(); it != this->edges[current].end(); it++){
				if(visited[it->first])
					continue;
				visited[it->first] = 1;
				if(recursive(it->first, k, sum + it->second, visited))
					return true;
				visited[it->first] = 0;
			}
			return false;
		}

	public:
		Graph(int vertexes){
			for(int i = 0; i < vertexes; i++)
				this->edges.push_back({});
			this->vertexes = vertexes;
		}

		bool if_there_path_more_than_k(int src, int k){
			int visited[this->vertexes] {0};
			return recursive(src, k, 0, visited);
		}
	
		void addEdge(int v, int u, int w){
			assert(v < this->vertexes && u < this->vertexes);
			this->edges[v].push_back(make_pair(u, w));
			this->edges[u].push_back(make_pair(v,w));
		}

		vector<vector<pair<int, int>>> edges;
		int vertexes = 0;
};

int main(){
	int V = 9;
	Graph g(V);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
	int src = 0;
	int k = 62;
	g.if_there_path_more_than_k(src, k) ? cout << "YES!\n" : cout << "NO!\n";
	k = 60;
	g.if_there_path_more_than_k(src, k) ? cout << "YES!\n" : cout << "NO!\n";
	return 0;
}
