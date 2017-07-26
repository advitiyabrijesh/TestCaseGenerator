#include "bits/stdc++.h"
#include "Integer.h"
#include "tree.h"
#include "graph.h"
#include "array.h"
using namespace std;
#define Integer num_gen::Integer
#define tree tree::Tree
#define graph graph_gen::generate_graph
#define range_space_separated generate_array::range_space_separated
#define distint_space_separated generate_array::distint_space_separated
int main()
{
	int i,j,t;
	srand(time(NULL)) ;

	int n = Integer(1,100000) ;
	int m = Integer(n-1,100000) ;
	int k = Integer(1,min(n,1000)) ;
	
	printf("%d %d %d\n",n,m,k) ;
	graph(n,m);
	distint_space_separated(k,1,n) ;	
	return 0;
}