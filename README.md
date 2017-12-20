# GameTextModifyTool

En este git hay diferentes herramientas que pueden ayudar al momento de traducir un juego o novela visual

TextExtractor: En resumen este extractor identifica los caracteres que señalan el inicio del dialogo en un juego para luego
proceder a extraerlo en un archivo, de esta forma el usuario obtendra un archivo solamente con el texto para
poder traducir de forma optima sin tener que buscar linea por linea entre todo el codigo.
El programa tambien da la opcion de dividir este archivo de salida para que se pueda traducir por partes
o (en mi caso) no exceder el limite de lineas que me traduce google traductor

TextReplacer: Este programa se encargar de tomar los archivos con texto previamente extraido con el "TextExtractor" y posteriormente traducido, para luego unirlos(en caso de haber hecho varias partes) y reintroducirlo dentro del archivo del juego.
en el proceso tambien se encarga de quitar los tildes para evitar errores en pantalla.

EqualTextTester: Este tester se encarga de comprobar si hay archivos de texto iguales es util para comprobar si se esta introduciendo al juego un archivo con texto duplicado o si pegaste el mismo texto en dos archivos.
