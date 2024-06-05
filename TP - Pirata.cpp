#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define CYAN    "\033[36m"  //Se definen los colores que se van a utilizar (Celeste, Violeta, Azul, Amarillo, y Reset, que reinicia el color al normal) 
#define MAGENTA "\033[35m" 
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

	int H, V, Tam, i, j, BordeH, BordeV, PH, PV, TH, TV, Mov, Enc, MovT = 50, Op1, Jugar, JugarDeNuevo = 1, Fuera = 0; //Se declaran las variables
	
static void Tablero () //Funcion Tablero, el cual pregunta el tamaño del mapa, define valores para el funcionamiento del juego, y randomiza los valores.
{
	srand(time(NULL)); //Utilizado para randomizar los valores
	MovT = 50; //Movimientos totales
	printf ("{--------------------------------------------------------------------------------------------------------}\n");
	printf("Inserte el tamano del mapa para empezar el juego (se recomienda utilizar Num pad para mejor control): "); //Tamaño del mapa
	scanf("%d", &Tam); //Guarda el valor
	printf ("{--------------------------------------------------------------------------------------------------------}\n");
	
	Enc = 0;	//Valor de encontrado = 0 (1 para encontrado)
	Fuera = 0; //Valor de fuera = 0 (1 si se va fuera del mapa)
	while (Tam <= 3) //Si la matriz es muy chica, pedir otro valor
	{
		Tam == 4; //Para que no pregunte infinitamente, un valor temporal
		printf ("Inserte un valor valido, bribon: "); //Pedido de valor valido
		scanf ("%d", &Tam); //Guarda el valor, si es incorrecto, pide de vuelta
	}
	
	H = Tam; //Horizontal
	V = Tam; //Vertical o Altura
	BordeH = Tam - 1; //Borde derecho
	BordeV = Tam - 1; //Borde abajo
	
	PH = 1 + rand() % (Tam - 1); //Valor Horizontal del pirata
	PV = rand() % (Tam - 1); //Valor Vertical del pirata
	
	while (PH == 0 || PH == BordeH || PV == 0 || PV == BordeV) //Si Pirata aparece fuera de zona se vuelve a randomizar
	{
	PH = 1 + rand() % (Tam - 1); //Vuelve a randomizar valor Horizontal
	PV = rand() % (Tam - 1); //Vuelve a randomizar valor Vertical
	}
	
	TH = 1 + rand() % (Tam - 1); //Valor Horizontal del Tesoro
	TV = 1 + rand() % (Tam - 1);//Valor Vertical del Tesoro
	
	while (TH == 0 || TH == BordeH || TV == 0 || TV == BordeV || TV == PV && TH == PH) //Si cofre aparece fuera de zona o esta en el lugar del pirata randomizar
	{
	TH = 1 + rand() % (Tam - 1); //Vuelve a randomizar valor Horizontal
	TV = 1 + rand() % (Tam - 1); //Vuelve a randomizar valor Vertical
	}	
	
	
}
	
static void Dibujo () //Funcion Dibujo (Dibuja la matriz actual, y si se encontro el tesoro, cambia el valor para poder terminar el juego)
{
for (j = 0 ; j < V ; j++) //Vertical
	{
			
		for (i = 0 ; i < H ; i++) //Horizontal
		{
			if (PH == TH && PV == TV) //Si la posicion del pirata es igual a la del tesoro, cambiar valor de Enc
			{
			Enc = 1; //Cambia el valor para ganar
			}
	
			if (PH == i && PV == j) //Si la posicion del pirata es igual a la casilla que se escribe, poner Pirata
			{
			printf (MAGENTA" P ");
			}
		
			else if (j == 0 && i != BordeH) //Si Altura es la primera y no es el borde derecho
			{
			printf (CYAN" ~ ");
			}
			
			else if (j == 0 && i == H - 1) //Si Altura es la primera y es el borde derecho
			{
			printf (BLUE" # ");
			}
		
			else if (i == 0 && j != BordeV) //Si lo Horizontal es la primera y la Altura es distinta al borde de abajo
			{
			printf (CYAN" ~ ");
			}
			
			else if (i == 0 && j == BordeV) //Si lo Horizontal es la primera y la Altura es el borde de abajo
			{
			printf (BLUE" # ");
			}
			
			else if (j == BordeV && i != 0) // Si altura es igual a borde de abajo y lo Horizontal es distinto a la primera
			{
			printf (CYAN" ~ ");
			}
			
			else if (i == BordeH && j != 0 && j != BordeV) //Si lo Horizontal es el borde derecho y Altura es distinto a la primera y la ultima
			{
			printf (CYAN" ~ ");	
			}
			
			else if (H != PH && V != PV) //Si no es ninguno de los anteriores, es arena
			{
		    printf (YELLOW" - ");
			}
			
		}
			printf(RESET"\n");
	}
	printf ("{--------------------------------------------------------------------------------------------------------}\n");	

}	
	
static void EncontrarTesoro () //Funcion para movimiento, pregunta hacia donde moverse, y si se va del mapa, cambia la variable Fuera

{
	printf ("Inserte hacia donde moverse (N, S, O, E / 8, 2, 4, 6):"); //Movimientos
	scanf ("%d", &Mov); //Guarda Mov
	while (Mov != 8 && Mov != 2 && Mov != 4 && Mov != 6) //Que los movimientos sean validos
	{
		printf ("Inserte un valor valido, bribon: "); //Pedir un valor valido si no es
		scanf ("%d", &Mov);	//Guarda Mov
	}
	
	if (Mov == 8) //Norte / Arriba
	{
		if (PV - 1 != 0) //Si pirata hacia esa direccion no es el agua, entonces:
		{
		PV = PV - 1; //Modifica el valor de Pirata Vertical

		}
		else //Si se va del mapa
		{
		printf ("- Pirata pata de palo tenia una sola pata, y en la otra un palo, no pudo sobrevivir a las fuertes olas - \n");	
		printf ("+ Perdiste el Juego... +\n");
	Fuera = 1;	//Se termino el juego
		}
	}

	else if (Mov == 2) //Sur / Abajo
	{
		if (PV + 1 != BordeV) //Si pirata hacia esa direccion no es el agua, entonces:
		{
		PV = PV + 1; //Cambia el valor de Pirata Vertical
	
		}
		else
		{
		printf ("- Pirata pata de palo tenia una sola pata, y en la otra un palo, no pudo sobrevivir a las fuertes olas - \n");	
		printf ("+ Perdiste el Juego... +\n");
	Fuera = 1;
		}
	}

	else if (Mov == 4) //Oeste / Izquierda
	{
		if (PH - 1 != 0) //Si pirata hacia esa direccion no es el agua, entonces:
		{
		PH = PH - 1;
		
		}
		else
		{
		printf ("- Pirata pata de palo tenia una sola pata, y en la otra un palo, no pudo sobrevivir a las fuertes olas - \n");	
		printf ("+ Perdiste el Juego... +\n");
	Fuera = 1;
		}
	}

	else if (Mov == 6) //Este / Derecha
	{
		if (PH + 1 != BordeH) //Si pirata hacia esa direccion no es el agua, entonces:
		{
		PH = PH + 1;	
		}
		else
		{
		printf ("- Pirata pata de palo tenia una sola pata, y en la otra un palo, no pudo sobrevivir a las fuertes olas - \n");	
		printf ("+ Perdiste el Juego... +\n");
	Fuera = 1;
		}
	}	
}


main()
{
		
//-------------------------------------------------------------------------------------------------------------------------	
	printf ("Bienvenido!!! \n"); //Menu de inicio
	printf ("1 - Empezar a Jugar \n"); //Opcion 1
	printf ("2 - Leer las Reglas \n"); //Opcion 2
	printf ("Seleccione una Opcion: "); //Pregunta la seleccion
	scanf ("%d", &Op1); //Guarda seleccion
	while (Op1 != 1 && Op1 != 2) //Que se inserte un valor valido, y si no, volver a pedir un valor
	{
	Op1 = 1;
	printf ("Inserte un valor valido, pirata de agua dulce ");	//Vuelve a pedir valor
	scanf ("%d", &Op1); //Guarda seleccion
	}
	switch (Op1) //Opciones del menu
{
	case 1: //Si seleccionaste 1 (Empezar Juego)
	{
	Jugar = 1; //Do (todo el juego) While Jugar sea 1
	break;
	}
	case 2: //Si seleccionaste 2 (Reglas)
	{
	printf ("{--------------------------------------------------------------------------------------------------------}\n");
	printf ("Reglas del juego: En este juego tendras que mover al pirata por las diversas casillas \n"); //Todas las reglas
	printf ("esto utilizando los Numeros indicados que valen Norte, Sur, Oeste y Este respectivamente \n");
	printf ("se recomienda utilizar el NumPad para una mayor facilidad de movimiento, ya que este tiene flechas \n");
	printf ("si el pirata encuentra la casilla donde esta el tesoro gana el juego, por otro lado si se queda sin \n");
	printf ("movimientos o toca el agua este perdera el juego. \n");
	
	printf ("Pulse 1 para empezar el Juego!!! "); //Boton para empezar el juego luego de leer las reglas
	scanf("%d", &Op1); //Guardar opcion
	while (Op1 != 1) //Que inserte un valor valido si este no lo es
	{
	printf ("Pulse 1 para empezar el Juego!!! ");  //Vuelve a avisar
	scanf("%d", &Op1);//Guarda opcion
	}
	break;
	}
}
while (JugarDeNuevo != 0) //While que permite volver a jugar
{
JugarDeNuevo = 1; //Necesario cambiarlo para que funcione correctamente
do //Comienzo del juego, este do se hace si Jugar = 1
{	

Tablero(); //Llama a la funcion tablero

Dibujo(); //Se llama a la funcion Dibujo
	
	while (Enc == 0 && MovT != 0 && Fuera != 1) //Que no pida hacia donde moverse si se encontro el tesoro, se quedo sin movimientos, o se fue de la zona de juego
{ 

EncontrarTesoro(); //Se llama a la funcion EncontrarTesoro (Movimientos)

printf ("Movimientos Restantes: %d \n", MovT - 1);	//Aviso de los movimientos restantes

Dibujo(); //Se llama a la funcion Dibujo luego de seleccionar hacia donde moverse
MovT = MovT - 1; //Cambiar los movimientos totales luego de moverse
	
}

if (Fuera == 1) //Si fuera es 1, entonces se termina el juego
{
Jugar = 0;	//Se termina el juego
}

else if (Enc == 1) //Mensaje de que gano
{
	Enc = 1;
	printf ("- Pata de palo encontro el tesoro... y pata de palo descubrio que el tesoro eran los amigos que hicimos en el camino - \n"); 
	printf ("+ Ganaste el Juego!!! +\n"); //Aviso de que se gano el juego
	Jugar = 0; //Se termina el juego
}
else if (MovT == 0 && Enc == 0) //Mensaje de que se quedo sin movimientos
{
	printf ("- Pata de palo se quedo sin comida y no pudo encontrar el tesoro... Fue encontrado 3 dias despues por su tripulacion - \n");
	printf ("+ Perdiste el Juego... +\n"); //Aviso de que se perdio el juego
	Jugar = 0; //Se termina el juego
}


} //Final del do
while (Jugar == 1); //La condicion del do

	printf ("Quiere volver a jugar? (1 / 0 | (Si / No): "); //Pregunta de si quiere volver a jugar
	scanf ("%d", &JugarDeNuevo); //Guarda opcion

while (JugarDeNuevo != 1 && JugarDeNuevo != 0) //Si es un valor invalido, que vuelva a preguntar
{
printf("Valor no valido...\n");
printf ("Quiere volver a jugar? (1 / 0 | (Si / No): "); //Vuelve a preguntar
scanf ("%d", &JugarDeNuevo); //Guarda opcion
}
if (JugarDeNuevo == 0) //Si se selecciono que no, termina
{
printf ("+ Fin del Juego +"); //Si no quiere volver a jugar, fin del juego
}
}
}
//Final del main
