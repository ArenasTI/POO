#include <stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	srand(time(NULL));	//Necesario para el valor random
	int Bot, Yo, BotPT=0, YoPT=0, BotP=0, YoP=0, i=0, n=5, m=3, j=0; 
	
	for (j=0; j<n; j++) //Bucles Juegos
	{
		for (i=0; i<m; i++){ //Bucles Rounds
		Bot = 1 + rand() % (4 - 1); //Valor random de botberto
		printf ("\nJuego: Jugador: %d - Bot: %d\n", YoPT, BotPT); //Muestra de puntuacion actual
		printf ("Ronda: Jugador: %d - Bot: %d\n", YoP, BotP);	//Puntuacion de la ronda actual
		printf ("Piedra Papel o Tijeras (1-2-3) (Juego %d): ", j+1); //Menu de eleccion + numero de juego
		scanf("%d", &Yo);
		
		//Verificar si el valor es invalido, si no es, sigue al juego
		if (Yo < 1 || Yo > 3){
		    printf("Perdiste la ronda por tramposo\n"); //Si el valor es invalido, entonces botberto gana un punto
			BotP = BotP + 1;
		}
		
		//Si el valor es valido.
		else{	
		//Dialogo (para meterle mas inmersion y ver mejor la situacion)
		switch (Yo) 
		{	//Dialogo Jugador segun eleccion
			case 1:
			{
			printf("Vos: Piedra\n"); //Dialogo Piedra Jugador
			break;
			}
			case 2:
			{
			printf("Vos: Papel\n"); //Dialogo Papel Jugador
			break;
			}
			case 3:
			printf("Vos: Tijera\n"); //Dialogo Tijera Jugador
			break;
		}
		
		switch(Bot) //Dialogo Bot segun random
		{
			case 1:
			{
			printf("Botberto: Piedra\n"); //Dialogo Piedra Bot
			break;
			}
			case 2:
			{
			printf ("Botberto: Papel\n"); //Dialogo Papel Bot
			break;
			}
			case 3:
			{
			printf ("Botberto: Tijera\n"); //Dialogo Tijera Bot
			break;	
			}
		}
			switch(Yo) //Rutas para verificar si se gano, perdio, o empato segun lo que selecciono el jugador
			{
			//Ruta tomada	
				case 1: //Ruta con Piedra (Jugador - Bot)
				{
					switch(Bot) //Verificar seleccion del bot
					{
						case 1: //Piedra - Piedra
						{
						printf("- Empate, va de vuelta -\n"); //Aviso de empate, se sigue en el mismo lugar.
						i = i - 1; //Si se empata, se vuelve a hacer el turno
						break;
						}	
						
						case 2: //Piedra - Papel
						{
						printf("- Perdiste la ronda -\n"); //Aviso de Perder ronda (2 rondas ganadas es 1 Juego o Puntos Totales ganado)
						BotP = BotP + 1; //Si Botberto gana se suma puntos a el (2 puntos para sumar un Punto Total)
						break;			
						}
						
						case 3: //Piedra - Tijera
						{
						printf("- Ganaste la ronda -\n"); //Aviso de Ganar ronda (2 rondas ganadas es 1 Juego o Puntos Totales ganados)
						YoP = YoP + 1; //Si el Jugador gana se suma putos a el (2 puntos para sumar un Punto Total)
						break;
						}
					}
				break;
				}
				case 2: //Ruta con Papel (Jugador - Bot)
				{
					switch(Bot) //Lo mismo que en el caso de arriba pero con papel.
					{
						case 1: //Papel - Piedra
						{
						printf("- Ganaste la ronda -\n");
						YoP = YoP + 1;
						break;
						}	
						
						case 2: //Papel - Papel
						{
						printf("- Empate, va de vuelta -\n");
						i = i - 1;
						break;		
						}
						
						case 3: //Papel - Tijera
						{
						printf("- Perdiste la ronda -\n");
						BotP = BotP + 1;
						break;
						}
					}
				break;
				}
				case 3: //Tijera
				{
					switch(Bot)  //Lo mismo que los casos anteriores pero con Tijera.
					{
						case 1: //Tijera - Piedra
						{
						printf("- Perdiste la ronda -\n");;
						BotP = BotP + 1;
						break;
						}	
						
						case 2: //Tijera - Papel
						{
						printf("- Ganaste la ronda -\n");
						YoP = YoP + 1;
						break;			
						}
						
						case 3: //Tijera - Tijera
						{
						printf("- Empate, va de vuelta -\n");
						i = i - 1;
						break;
						}
					}
				break;
				}		
			}
		
		}
		//Chequeo de si gano el juego
		if (YoP == 2){ //Si Jugador tiene 2 puntos
			YoP = 0; //Reiniciar puntos
			BotP = 0;
			YoPT = YoPT + 1; //Sumar Puntos Totales
			printf ("+ Ganaste el juego +\n"); //Aviso de que ganaste un Juego osea Punto Total (3 Juegos para ganar la partida)
			printf("--------------------\n"); //Barrita para mejor entendimiento
			i = 3; //Continuar al siguiente juego
		}
		else if (BotP == 2){ //Si Botberto tiene 2 puntos
			YoP = 0; //Reiniciar puntos
			BotP = 0;
			BotPT = BotPT + 1; //Sumar Puntos Totales a mi querido Botberto
			printf ("+ Botberto gano el juego +\n"); //Aviso de que Botberto gano el Juego
			printf("--------------------\n");
			i = 3; //Continuar al siguiente juego
		}
	}
	if (YoPT == 3){ //Chequeo si gano la partida, si Jugador tiene 3 Puntos Totales, es decir 3 Juegos ganados, gano la partida.
    	printf ("Ganaste la partida"); 	//Aviso de ganar la partida
    	j = 5; //Se termino.
    	break;
	}		
	else if (BotPT == 3){ //Chequeo si gano la partida, si Botberto tiene 3 Puntos Totales, es decir 3 Juegos ganados, gano la partida.
    	printf ("El Botberto gano la partida"); //Aviso de que Botberto gano la partida
    	j = 5; //Se termino.
		break;	
	}		
			
	}
	
	}

