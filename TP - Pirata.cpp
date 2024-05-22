#include <stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
srand(time(NULL));
	int H, V, Tam, i, j, BordeH, BordeV, PH, PV, TH, TV, Mov, Enc, MovT = 50, Op1, Jugar, JugarDeNuevo = 1; //Int
	
	printf ("Bienvenido!!! \n"); //Menu de inicio
	printf ("1 - Empezar a Jugar \n");
	printf ("2 - Leer las Reglas \n");
	printf ("Seleccione una Opcion: ");
	scanf ("%d", &Op1);
	while (Op1 != 1 && Op1 != 2) //Que se inserte un valor valido, y si no, volver a pedir un valor
	{
	Op1 = 1;
	printf ("Inserte un valor valido, pirata de agua dulce ");	
	scanf ("%d", &Op1);
	}
	switch (Op1) //Opciones del menu
{
	case 1: //Jugar
	{
	Jugar = 1; //Do (todo el juego) While Jugar sea 1
	break;
	}
	case 2: //Reglas
	{
	printf ("{--------------------------------------------------------------------------------------------------------}\n");
	printf ("Reglas del juego: En este juego tendras que mover al pirata por las diversas casillas \n");
	printf ("esto utilizando los Numeros indicados que valen Norte, Sur, Oeste y Este respectivamente \n");
	printf ("se recomienda utilizar el NumPad para una mayor facilidad de movimiento, ya que este tiene flechas \n");
	printf ("si el pirata encuentra la casilla donde esta el tesoro gana el juego, por otro lado si se queda sin \n");
	printf ("movimientos o toca el agua este perdera el juego. \n");
	
	printf ("Pulse 1 para empezar el Juego!!! "); //Boton para empezar el juego luego de leer las reglas
	scanf("%d", &Op1);
	while (Op1 != 1) //Que inserte un valor valido
	{
	printf ("Pulse 1 para empezar el Juego!!! "); 
	scanf("%d", &Op1);		
	}
	
	break;
	}
}
while (JugarDeNuevo != 0) //While que permite volver a jugar
{
JugarDeNuevo = 1; //Necesario cambiarlo para que funcione correctamente
do //Do
{	
	printf ("{--------------------------------------------------------------------------------------------------------}\n");
	printf("Inserte el tamano del mapa para empezar el juego (se recomienda utilizar Num pad para mejor control): "); //Tamaño del mapa
	scanf("%d", &Tam); //Detectar
	printf ("{--------------------------------------------------------------------------------------------------------}\n");
	
	Enc = 0; //Valor de encontrado = 0 (1 para encontrado)
	while (Tam <= 3) //Si la matriz es muy chica, pedir otro valor
	{
		Tam == 4;
		printf ("Inserte un valor valido, bribon: ");
		scanf ("%d", &Tam);
	}
	
	H = Tam; //Horizontal
	V = Tam; //Vertical o Altura
	BordeH = Tam - 1; //Borde derecho
	BordeV = Tam - 1; //Borde abajo
	
	PH = 1 + rand() % (Tam - 1); //Valor Horizontal del pirata
	PV = rand() % (Tam - 1); //Valor Vertical del pirata
	
	while (PH == 0 || PH == BordeH || PV == 0 || PV == BordeV) //Si Pirata aparece fuera de zona se vuelve a randomizar
	{
	PH = 1 + rand() % (Tam - 1); 
	PV = rand() % (Tam - 1); 
	}
	
	TH = 1 + rand() % (Tam - 1); //Valor Horizontal del Tesoro
	TV = 1 + rand() % (Tam - 1);//Valor Vertical del Tesoro
	
	while (TH == 0 || TH == BordeH || TV == 0 || TV == BordeV || TV == PV && TH == PH) //Si cofre aparece fuera de zona o esta en el lugar del pirata randomizar
	{
	TH = 1 + rand() % (Tam - 1);
	TV = 1 + rand() % (Tam - 1);
	}
	
//////////////////////////////////////////////////////////////
	
	//Primer dibujo del mapa
	
for (j = 0 ; j < V ; j++) //Vertical
	{
			
		for (i = 0 ; i < H ; i++) //Horizontal
		{
			if (PH == i && PV == j) //Si la posicion del pirata es igual a la casilla que se escribe, poner Pirata
			{
			printf (" P ");
			}
		
			else if (j == 0 && i != BordeH) //Si Altura es la primera y no es el borde derecho
			{
			printf (" ~ ");
			}
			
			else if (j == 0 && i == H - 1) //Si Altura es la primera y es el borde derecho
			{
			printf (" # ");
			}
		
			else if (i == 0 && j != BordeV) //Si lo Horizontal es la primera y la Altura es distinta al borde de abajo
			{
			printf (" ~ ");
			}
			
			else if (i == 0 && j == BordeV) //Si lo Horizontal es la primera y la Altura es el borde de abajo
			{
			printf (" # ");
			}
			
			else if (j == BordeV && i != 0) // Si altura es igual a borde de abajo y lo Horizontal es distinto a la primera
			{
			printf (" ~ ");
			}
			
			else if (i == BordeH && j != 0 && j != BordeV) //Si lo Horizontal es el borde derecho y Altura es distinto a la primera y la ultima
			{
			printf (" ~ ");	
			}
			
			else if (H != PH && V != PV)
			{
		    printf (" - ");
			}
			
		}
			printf("\n");
	}
	printf ("{--------------------------------------------------------------------------------------------------------}\n");
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Si no se encontro y quedan movimiento entonces elegir a donde ir
	
	while (Enc == 0 && MovT != 0) //Que no pida hacia donde moverse si se encontro el tesoro o se quedo sin movimientos
{ 
	printf ("Inserte hacia donde moverse (N, S, O, E / 8, 2, 4, 6):"); //Movimientos
	scanf ("%d", &Mov);
	while (Mov != 8 && Mov != 2 && Mov != 4 && Mov != 6) //Que los movimientos sean validos
	{
		printf ("Inserte un valor valido, bribon: ");
		scanf ("%d", &Mov);	
	}
	
	if (Mov == 8) //Norte / Arriba
	{
		if (PV - 1 != 0) //Utilizado para los movimientos
		{
		PV = PV - 1;

		}
		else 
		{
		printf ("- Pirata pata de palo tenia una sola pata, y en la otra un palo, no pudo sobrevivir a las fuertes olas - \n");	//Si pirata cayo en el agua, avisar de que se perdio el juego
		printf ("+ Perdiste el Juego... +\n");
		Jugar = 0; //Se termino el juego
		break;
		}
	}

	else if (Mov == 2) //Sur / Abajo
	{
		if (PV + 1 != BordeV)
		{
		PV = PV + 1;
	
		}
		else
		{
		printf ("- Pirata pata de palo tenia una sola pata, y en la otra un palo, no pudo sobrevivir a las fuertes olas - \n");	
		printf ("+ Perdiste el Juego... +\n");
		Jugar = 0;
		break;
		}
	}

	else if (Mov == 4) //Oeste / Izquierda
	{
		if (PH - 1 != 0)
		{
		PH = PH - 1;
		
		}
		else
		{
		printf ("- Pirata pata de palo tenia una sola pata, y en la otra un palo, no pudo sobrevivir a las fuertes olas - \n");	
		printf ("+ Perdiste el Juego... +\n");
		Jugar = 0;
		break;
		}
	}

	else if (Mov == 6) //Este / Derecha
	{
		if (PH + 1 != BordeH)
		{
		PH = PH + 1;	
		}
		else
		{
		printf ("- Pirata pata de palo tenia una sola pata, y en la otra un palo, no pudo sobrevivir a las fuertes olas - \n");	
		printf ("+ Perdiste el Juego... +\n");
		Jugar = 0;
		break;
		}
	}

	printf ("Movimientos Restantes: %d \n", MovT - 1);	//Aviso de los movimientos restantes

//Segundo dibujo de la matriz, el cual se va a repetir

	for (j = 0 ; j < V ; j++) //Vertical
	{
			
		for (i = 0 ; i < H ; i++) //Horizontal
		{
			if (PH == TH && PV == TV)
			{
			Enc = 1;
			}
			
			if (PH == i && PV == j) //Si la posicion del pirata es igual a la casilla que se escribe, poner Pirata
			{
			printf (" P ");
			}
		
			else if (j == 0 && i != BordeH) //Si Altura es la primera y no es el borde derecho
			{
			printf (" ~ ");
			}
			
			else if (j == 0 && i == H - 1) //Si Altura es la primera y es el borde derecho
			{
			printf (" # ");
			}
		
			else if (i == 0 && j != BordeV) //Si lo Horizontal es la primera y la Altura es distinta al borde de abajo
			{
			printf (" ~ ");
			}
			
			else if (i == 0 && j == BordeV) //Si lo Horizontal es la primera y la Altura es el borde de abajo
			{
			printf (" # ");
			}
			
			else if (j == BordeV && i != 0) // Si altura es igual a borde de abajo y lo Horizontal es distinto a la primera
			{
			printf (" ~ ");
			}
			
			else if (i == BordeH && j != 0 && j != BordeV) //Si lo Horizontal es el borde derecho y Altura es distinto a la primera y la ultima
			{
			printf (" ~ ");	
			}
			
			else if (H != PH && V != PV)
			{
		    printf (" - ");
			}
			
		}
			printf("\n");
	}
	printf ("{--------------------------------------------------------------------------------------------------------}\n");
	MovT = MovT - 1; //Cambiar los movimientos totales
}

if (Enc == 1) //Mensaje de que gano
{
	Enc = 1;
	printf ("- Pata de palo encontro el tesoro... y pata de palo descubrio que el tesoro eran los amigos que hicimos en el camino - \n");
	printf ("+ Ganaste el Juego!!! +\n");
	Jugar = 0;
}
else if (MovT == 0 && Enc == 0) //Mensaje de que se quedo sin movimientos
{
	printf ("- Pata de palo se quedo sin comida y no pudo encontrar el tesoro... Fue encontrado 3 dias despues por su tripulacion - \n");
	printf ("+ Perdiste el Juego... +\n");
	Jugar = 0;
}

} //Final del do
while (Jugar == 1);

	printf ("Quiere volver a jugar? (1 / 0 | (Si / No): "); //Pregunta de si quiere volver a jugar
	scanf ("%d", &JugarDeNuevo);

while (JugarDeNuevo != 1 && JugarDeNuevo != 0) //Valor valido
{
printf("Valor no valido...\n");
printf ("Quiere volver a jugar? (1 / 0 | (Si / No): ");
scanf ("%d", &JugarDeNuevo);	
}
if (JugarDeNuevo == 0)
{
printf ("+ Fin del Juego +"); //Si no quiere volver a jugar, fin del juego
}
}
}
 //Final del main
