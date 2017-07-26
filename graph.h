//Below code is used to generate connected undirected graphs
//E ~ 2 * V but can be set accordingly
#define TIMING_H
#include<bits/stdc++.h>
#define lim_n 100000

using namespace std ;
typedef long long LL;

class graph_gen{
public:
	int visited[lim_n+1];

vector<int> adj[lim_n+1];

//check whether the graph is connected or not
    void check_graph(int n) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
			if (!visited[*it]) {
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	
	bool connected = true;
	for(int i=1; i<=n; ++i) {
		connected &= visited[i];
	}

	assert(connected);
}

//Output is space separated vertices pairs which contain an edge
//There is extra line after every test case
    void generate_unweighted(int n, int m) {
	set< pair<int,int> > duplicates;
	vector< pair<int,int> > graph;

	//form spanning tree first
	for(int i=2; i<=n; ++i) {
		int x = i;
		int y = rand() % (i - 1) + 1;
		if (i % 10 == 0) {
			swap(x, y);
		}
		assert (1 <= x <= n);
		assert (1 <= y <= n);
		assert (x != y);
		if (duplicates.find(make_pair(x, y)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		if (duplicates.find(make_pair(y, x)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		duplicates.insert(make_pair(x, y));
		adj[x].push_back(y);
		adj[y].push_back(x);
		graph.push_back(make_pair(x, y));
	}

	//add some extra edges
	for(int i=n; i<=m; ++i) {
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		if (i % 10 == 0) {
			swap(x, y);
		}
		assert (1 <= x <= n);
		assert (1 <= y <= n);
		while (x == y) {
			y = rand() % n + 1;
		}
		assert (x != y);
		if (duplicates.find(make_pair(x, y)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		if (duplicates.find(make_pair(y, x)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		duplicates.insert(make_pair(x, y));
		adj[x].push_back(y);
		adj[y].push_back(x);
		graph.push_back(make_pair(x, y));
	}

	random_shuffle(graph.begin(), graph.end());

	assert (graph.size() == m);
	for(int i=0; i<graph.size(); ++i) {
		printf("%d %d\n", graph[i].first, graph[i].second);
	}

	//check whether the graph made is connected or not
	check_graph(n);
	
	for(int i=1; i<=n; ++i) {
		adj[i].clear();
	}
	
}

void generate_unweighted_linear(int n) {
	vector<int> perm;
	vector< pair<int,int> > graph;
	for(int i=1; i<n; ++i) {
		int x = i;
		int y = i + 1;
		if (i % 10 == 0) {
			swap(x, y);
		}
		graph.push_back(make_pair(x, y));
		perm.push_back(i);
	}
	perm.push_back(n);

	random_shuffle(perm.begin(), perm.end());
	random_shuffle(graph.begin(), graph.end());

	for(int i=0; i<n-1; ++i) {
		int x = perm[graph[i].first - 1];
		int y = perm[graph[i].second - 1];
		assert(1 <= x <= n);
		assert(1 <= y <= n);
		assert(x != y);
		printf("%d %d\n", x, y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	//check whether the graph made is connected or not
	check_graph(n);
	
	for(int i=1; i<=n; ++i) {
		adj[i].clear();
	}
}


	static void generate_graph()
	{
		int test_cases = 1 ;
		srand(unsigned(time(0)));
		for(int t=1; t<=test_cases; ++t) 
		{
		
			//get random value of "n" between (1, lim_n)
			int n = rand() % lim_n + 1;
			int m = rand() % n + 1 + n;
			graph_gen *xx = new graph_gen() ;
			xx->generate_unweighted(n, m);
			
		}

	}
	static void generate_graph(int n , int m )
	{

		srand(unsigned(time(0)));

		int test_cases = 1;
		for(int t=1; t<=test_cases; ++t) 
		{
			graph_gen *xx = new graph_gen() ;
			xx->generate_unweighted(n, m);
			
		}

	}	
	
	
};
