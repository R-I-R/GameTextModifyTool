/*
https://github.com/R-I-R/GameTextModifyTool
Este codigo fue hecho por RIR
Este tester se encarga de comprobar si hay archivos de texto iguales
es util para comprobar si se esta introduciendo al juego un archivo con texto duplicado
*/

#include<bits/stdc++.h>

using namespace std;
typedef pair<string,string> ss;

int main(){
	char nombre[300], name[300];
	int archivos;
	printf("Bienvenido al Tester de texto by RIR\n");
	printf("Este es un ejemplo de archivo:	 dialogo1.txt \n como notaras el archivo se llama dialogo y su numero es 1\n");
	printf("Por favor ingresa el nombre del archivo(asumo que es un .txt asi que no ingreses eso ni el numero): ");
	scanf("%s",nombre);
	getchar();
	printf("ahora ingresa cuantos archivos son(asumo que estan ordenados crecientemente desde el 1): ");
	scanf("%d",&archivos);
	getchar();
	
	printf("Por favor pon los archivos de texto en la misma ubicacion de este ejecutable\n");
	system("pause");
	
	printf("Bien, Empecemos.\n\n");
	
	ifstream archivo;
	//ofstream frases;
	//frases.open("frases.txt",ios::out);
	vector<ss> palabras;
	palabras.assign(archivos,ss());
	
	for(int a = 0; a < archivos; a++){
		sprintf(name,"%s%d.txt",nombre,a+1);
		archivo.open(name,ios::in);
		int palabra = 0;
		string past;
		
		while(!archivo.eof()){
			string st;
			getline(archivo,st);
			if(palabra == 0)palabras[a].first = st;
			if(palabra != 0)palabras[a].second = past;
			past = st;
			palabra++;
		}
		//frases << palabras[a].first << endl << palabras[a].second << endl << endl;
		archivo.close();
	}
	
	for(int a = 0; a < archivos; a++){
		for(int b = 0; b < archivos; b++){
			if(b == a)continue;
			if(!palabras[a].first.compare(palabras[b].first) && !palabras[a].second.compare(palabras[b].second))printf("el archivo %s%d es igual al %s%d\n",nombre,a+1,nombre,b+1);
		}
	}
	system("pause");
	return 0;
}
