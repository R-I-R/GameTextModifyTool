/*
https://github.com/R-I-R/GameTextModifyTool
Este codigo fue hecho por RIR
Este programa se encargar de tomar los archivos con texto previamente extraido con el "TextExtractor" y posteriormente traducido,
para luego unirlos(en caso de haber hecho varias partes) y reintroducirlo dentro del archivo del juego.
en el proceso tambien se encarga de quitar los tildes para evitar errores en pantalla.

*/
#include<bits/stdc++.h>

using namespace std;

int main(){
	char especiales[9] = {'á','é','í','ó','ú','ñ','ü','¿','¡'};
	char normales[9] = {'Á','É','Í','Ó','Ú','Ñ','Ü','×','·'};
	char ar[300];
	
	char inicio;
	bool respuesta = false;
	printf("Bienvenido al reemplazador de dialogos de novelas ligeras by RIR\n");
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
	
	printf("Por favor pon el archivo de texto dialogos.txt en la misma carpeta de este ejecutable junto con el archivo 0.txt en el cual sobreescribiremos los dialogos\n");
	system("pause");
	printf("El archivo de dialogos esta dividido?\n");
	printf("s/n: ");
	char c;
	scanf("%c",&c);
	getchar();
	int lineasdiv;
	bool dividir;
	if(c == 's' || c == 'S'){
		dividir = true;
		printf("Ingresa en cuantas lineas por archivo dividiste: ");
		scanf("%d",&lineasdiv);
		getchar();
	}else dividir = false;
	
	printf("Bien, Empecemos.\n\n");
	
	ifstream base("0.txt",ios::in);
	
	ofstream salida;
	ifstream archivo;
	string s,st;
	int cont = 0,partes = 1;
	
	if(dividir){
		sprintf(ar,"dialogos%d.txt",partes);
		archivo.open(ar,ios::out);
	}else{
		archivo.open("dialogos.txt",ios::in);
	}
	
	salida.open("resultado.txt",ios::out);
	
	int lineas = 0, dialogos = 0;
	while(getline(base,s)){
		if(cont == lineasdiv && dividir){
			partes++;
			sprintf(ar,"dialogos%d.txt",partes);
			archivo.close();
			archivo.open(ar,ios::out);
			cont = 0;
		}
		
		if(s[0] == inicio){
			getline(archivo,st);
			for(int a = 0; a < st.size(); a++){
				for(int b = 0; b < 9; b++){
					if(st[a] == especiales[b]){
						st[a] = normales[b];
						break;
					}
				}
			}
			salida << st <<endl;
			dialogos++;
			cont++;
		}else{
			salida << s << endl;
		}
		lineas++;
		
		if(dividir) printf("\r lineas leidas: %d		Dialogos sobreescritos: %d		Partes leidas: %d",lineas,dialogos,partes);
		else printf("\r lineas leidas: %d		Dialogos sobreescritos: %d",lineas,dialogos);
	}
	printf("%c",7);//beep
	printf("\n\n Listo, los dialogos han sido escritos y puestos en el archivo resultado.txt\n Hasta la proxima :3");
	getchar();
	salida.close();
	archivo.close();
	base.close();
	system("pause");
	cin.get();
	
	return 0;
}
