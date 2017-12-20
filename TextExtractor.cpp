/*
https://github.com/R-I-R/GameTextModifyTool
Este codigo fue hecho por RIR
En resumen este extractor identifica los caracteres que señalan el inicio del dialogo en un juego para luego
proceder a extraerlo en un archivo, de esta forma el usuario obtendra un archivo solamente con el texto para
poder traducir de forma optima sin tener que buscar linea por linea entre todo el codigo.
El programa tambien da la opcion de dividir este archivo de salida para que se pueda traducir por partes
o (en mi caso) no exceder el limite de lineas que me traduce google traductor
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
	char inicio;
	bool respuesta = false;
	printf("Bienvenido al extractor de dialogos de novelas ligeras by RIR\n");
	printf("Este es un ejemplo de dialogo\n >Reveal yourself to me. \\ \n como notaras los dialogos de esta novela empiezan con el caracter '>'\n");
	printf("en todos los dialogos de las novelas hay un caracter que marca el inicio de un dialogo\n");
	
	do{
		printf("Por favor introduce el caracter de inicio: ");
		scanf("%c",&inicio);
		getchar();
		printf("el caracter con el que inician tus dialogos es este?: %c\n",inicio);
		printf("s/n: ");
		char c;
		scanf("%c",&c);
		getchar();
		if(c == 's' || c == 'S')respuesta = true;
		else respuesta = false;
	}while(!respuesta);
	
	printf("Por favor pon el archivo de texto de la novela en la misma carpeta de este ejecutable y nombralo 0.txt\n");
	system("pause");
	printf("quieres dividir el archivo en varias partes para facilitar su traduccion?\n");
	printf("s/n: ");
	char c;
	scanf("%c",&c);
	getchar();
	int lineasdiv;
	bool dividir;
	if(c == 's' || c == 'S'){
		dividir = true;
		printf("Ingresa cuantas lineas debe tener cada archivo (google traductor acepta maximo 600): ");
		scanf("%d",&lineasdiv);
		getchar();
	}else dividir = false;
		
	printf("Bien, Empecemos.\n\n");
	
	freopen("0.txt","r",stdin);
	
	string s;
	int lineas = 0, dialogos = 0,partes = 1,cont = 0;
	char ar[300];
	ofstream archivo;
	if(dividir){
		sprintf(ar,"dialogos%d.txt",partes);
		archivo.open(ar,ios::out);
	}else{
		archivo.open("dialogos.txt",ios::out);
	}
	
	while(getline(cin,s)){
		if(cont == lineasdiv && dividir){
			partes++;
			sprintf(ar,"dialogos%d.txt",partes);
			archivo.close();
			archivo.open(ar,ios::out);
			cont = 0;
		}
		
		if(s[0] == inicio){
			archivo << s <<endl;
			dialogos++;
			cont++;
		}
		lineas++;
		
		if(dividir){
			printf("\r lineas leidas: %d	Dialogos encontrados: %d			Partes creadas: %d",lineas,dialogos,partes);
		}else{
			printf("\r lineas leidas: %d	Dialogos encontrados: %d",lineas,dialogos);
		}
		
	}
	printf("\n\n Listo, los dialogos han sido extraidos y puestos en el archivo dialogos.txt\n Hasta la proxima :3");
	system("pause");
	return 0;
}
