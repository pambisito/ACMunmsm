#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; //Límite inferior
	int m; //Límite superior
	cin>>n>>m;
	
	srand( time(NULL) ); //Para añadir la función de número aleatorio
	
	//Sintaxis para generar un número aleatorio
	// lim_inf + rand() % ( lim_sup+1 - lim_inf );
	int x = n + rand() % ( m + 1 - n );
	
	cout<<x;
				
	return 0;
}
