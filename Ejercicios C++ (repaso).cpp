#include <stdio.h>
main ()

{
	int num;
	
	do{
		printf ("\nIngrese el ejercicio (1-5): ");
		scanf ("%d", & num);
		
		switch(num)
		{
				case 1:
			{
				/* El director de una escuela está organizando un viaje de estudios, y requiere determinar cuánto debe cobrar a cada alumno y cuánto debe pagar a la compañía de viajes por el servicio. La forma de cobrar es la siguiente: 
				Si son 100 alumnos o más, el costo por cada alumno es de $ 500, de 50 a 99 alumnos, el costo es de $ 400  y  de 30 a 49, de $ 300. Pero si son menos de 30, el costo del alquiler del micro es de $ 6000.- sin importar el número de alumnos. 
				Realice un algoritmo que permita determinar el pago por el alquiler del micro y lo que debe pagar cada alumno por el viaje. */
				
				int cantidad, costo, costo_micro;
	
	            printf("Ingrese la cantidad de alumnos: ");
	            scanf("%d", &cantidad);
	
	            if (cantidad >= 100) {
	                costo = 500;
	            } else if (cantidad >= 50) {
	                costo = 400;
	            } else if (cantidad >= 30) {
	                costo = 300;
	            } else if (cantidad < 30) {
	                costo = 0;
	                costo_micro = 6000;
	            }
	
	            if (costo != 0) {
	                costo_micro = cantidad * costo;
	            }
	
	            printf("El costo por alumno es: %d\n", costo);
	            printf("El costo por el alquiler del micro es: %d\n", costo_micro);
				
				break;
			}
				case 2:
			{
				/* Un vendedor recibe un sueldo base más un 10% extra por comisión de sus ventas, el vendedor desea saber cuánto dinero obtendrá por concepto de comisiones por las tres ventas que realiza en el mes y el total que recibirá en el mes tomando en cuenta su sueldo base y comisiones. */
				
				float sueldoBase, comision, totalMes;
	
	            printf("Ingrese el sueldo base del vendedor: ");
	            scanf("%f", &sueldoBase);
	
	            comision = sueldoBase * 0.1;
	            totalMes = sueldoBase + (comision * 3);
	
	            printf("El total por concepto de comisiones en el mes es: %.2f\n", comision * 3);
	            printf("El total que recibira el vendedor en el mes es: %.2f\n", totalMes);
			
				break;
			}
				case 3:
			{
				/* Un alumno desea saber cuál será su calificación final en la materia de Algoritmos. Dicha calificación se compone de los siguientes porcentajes:
					55% del promedio de sus tres calificaciones parciales.
					30% de la calificación del examen final.
					15% de la calificación de un trabajo final. */
					
				float nota_parciales[3], nota_examen_final, nota_trabajo_final, prom = 0, nota_final;
			
			    for (int i = 0; i < 3; i++) {
			        printf("Ingrese la calificacion del parcial %d: ", i + 1);
			        scanf("%f", &nota_parciales[i]);
			    }
			
			    printf("Ingrese la calificacion del examen final: ");
			    scanf("%f", &nota_examen_final);
			
			    printf("Ingrese la calificacion del trabajo final: ");
			    scanf("%f", &nota_trabajo_final);
			
			    for (int i = 0; i < 3; i++) {
			        prom += nota_parciales[i];
			    }
			    prom /= 3;
			
			    nota_final = 0.55 * prom + 0.3 * nota_examen_final + 0.15 * nota_trabajo_final;
			
			    printf("La calificacion final es: %.2f\n", nota_final);
			
				break;
			}
				case 4:
			{
				/* Escribir un programa que imprima todos los números pares entre dos números que se le pida al usuario. */
				
				int inicial, final;

			    printf("Ingrese el numero inicial: ");
			    scanf("%d", &inicial);
			    printf("Ingrese el numero final: ");
			    scanf("%d", &final);
			
			    if (inicial % 2 != 0) {
			        inicial++;
			    }
			
			    printf("Numeros pares entre %d y %d:\n", inicial, final);
			    for (int i = inicial; i <= final; i += 2) {
			        printf("%d\n", i);
			    }
				
				break;
			}
				case 5:
			{
				/* Una persona se encuentra en el kilómetro 70 de una carretera, otra se encuentra en el km 150, los coches tienen sentido opuesto y tienen la misma velocidad. Realizar un programa para determinar en qué kilómetro de esa carretera se encontrarán. */
				
				int pos_auto1 = 70, pos_auto2 = 150, velocidad = 1, distancia = 0;
			
			    while (pos_auto1 != pos_auto2) {
			        if (pos_auto1 < pos_auto2) {
			            pos_auto1 += velocidad;
			        } else {
			            pos_auto2 += velocidad;
			        }
			        distancia += velocidad;
			    }
			
			    printf("Los coches se encontraran en el kilometro %d\n", pos_auto1);
			
				break;
			}
		}
	} while (num != 0);
	
	return 0;
}
