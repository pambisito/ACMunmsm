Pseudocódigo Dijkstra...
######################################################################################################################
método Dijkstra(Grafo,origen):
2      creamos una cola de prioridad Q
3      agregamos origen a la cola de prioridad Q
4      mientras Q no este vacío:
5          sacamos un elemento de la cola Q llamado u
6          si u ya fue visitado continuo sacando elementos de Q    
7          marcamos como visitado u
8          para cada vértice v adyacente a u en el Grafo:
9              sea w el peso entre vértices ( u , v )  
10             si v no ah sido visitado:
11                Relajacion( u , v , w )

1  método Relajacion( actual , adyacente , peso ):
2      si distancia[ actual ] + peso < distancia[ adyacente ]
3         distancia[ adyacente ] = distancia[ actual ] + peso
4         agregamos adyacente a la cola de prioridad Q


######################################################################################################################
######################################################################################################################
######################################################################################################################



######################################################################################################################
MI PROPIO CÓDIGO DEL ALGORITMO DIJKSTRA......
######################################################################################################################
#define Node pair< int , long long >
#define INF 1<<30

struct cmp {
	bool operator() ( const Node &a , const Node &b ) {
		return a.second > b.second;
	}
};

// "S" ---> Nodo de partida
// "T" ---> Nodo de llegada
// ady[] ---> Grafo de lista adyacente generado en el main()
// "n" ---> "tamaño"
// u = nodo actual ; v = nodo adyacente ; d = peso(distancia entre nodos)

int dijkstra( int S, int T , vector<Node> ady[] , int n ) {
	priority_queue< Node , vector<Node> , cmp > Q;
	
	vector<long long> distance( n + 5 , INF );
	
	bool visited[ n + 5 ];
	for( int i = 0 ; i <= n ; ++i ) { visited[ i ] = false; }
	
	Q.push( Node( S , 0 ) );
	distance[S] = 0 ;
	
	int u, v;
	long long d;
	
	while( !Q.empty() ) {
		u = Q.top().first;
		Q.pop();
		
		if( visited[u] ) { continue; }
		visited[u] = true;
		
		for( int i = 0 ; i < int( ady[u].size() ) ; i++ ) {
			v = ady[u][i].first;
			d = ady[u][i].second;
			
			if( !visited[v] && distance[u] + d < distance[v] ) {
				distance[v] = distance[u] + d;
				Q.push( Node( v , distance[v] ) );	
			}
		}
	}
	
	return distance[T];
}
