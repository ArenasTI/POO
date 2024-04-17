#include <stdio.h>

int main() {
    int num;

    do {
        printf("\nIngrese el ejercicio (1-5): "); // Solicitar al usuario el numero del ejercicio
        scanf("%d", &num);

        switch (num) {
            case 1: {
                int ano;
                printf("Ingrese un ano: "); // Solicitar al usuario el ano
                scanf("%d", &ano);

                // Comprobar si el ano es bisiesto
                if (ano % 4 == 0) {
                    if (ano % 100 == 0) {
                        if (ano % 400 == 0) {
                            printf("%d es un ano bisiesto.\n", ano); // Imprimir resultado
                        } else {
                            printf("%d no es un ano bisiesto.\n", ano); // Imprimir resultado
                        }
                    } else {
                        printf("%d es un ano bisiesto.\n", ano); // Imprimir resultado
                    }
                } else {
                    printf("%d no es un ano bisiesto.\n", ano); // Imprimir resultado
                }

                break;
            }

            case 2: {
                int numero;
                printf("Ingrese un numero entero y positivo: "); // Solicitar al usuario un numero
                scanf("%d", &numero);

                // Imprimir la tabla de multiplicacion del numero ingresado
                if (numero > 0) {
                    for (int i = 1; i <= 10; i++) {
                        printf("%d x %d = %d\n", numero, i, numero * i); // Imprimir cada multiplicacion
                    }
                } else {
                    printf("El numero ingresado no es valido.\n"); // Imprimir mensaje de error
                }

                break;
            }

            case 3: {
               
			    int cantidad, costo;
			
			    printf("Ingrese la cantidad de entradas (maximo 4): ");
			    scanf("%d", &cantidad);
			
			    printf("Ingrese el precio de la entrada: ");
			    scanf("%d", &costo);
			
			    // Calcular el costo total de las entradas según la cantidad
			    if (cantidad >= 1 && cantidad <= 4) {
					if (cantidad == 1) {
						costo *= 1;
					} else if (cantidad == 2) {
			            costo *= 2 * 0.9; // Aplicar descuento del 10% para 2 entradas
			        } else if (cantidad == 3) {
			            costo *= 3 * 0.85; // Aplicar descuento del 15% para 3 entradas
			        } else {
			            costo *= 4 * 0.8; // Aplicar descuento del 20% para 4 entradas
			        }
			        printf("El costo a pagar por las entradas es: %d\n", costo); // Imprimir costo total
			    } else {
			        printf("Cantidad de entradas no valida.\n"); // Imprimir mensaje de error
			    }
			    
			    break;
            }

            case 4: {
                int personas;
                printf("Ingrese la cantidad de personas: "); // Solicitar al usuario la cantidad de personas
                scanf("%d", &personas);

                double costo;

                // Calcular el costo total del catering segun la cantidad de personas
                if (personas > 300) {
                    costo = 4500.0;
                } else if (personas > 200) {
                    costo = 5500.0;
                } else {
                    costo = 6500.0;
                }

                double total = costo * personas;
                printf("El costo total del catering es: %.2f\n", total); // Imprimir costo total

                break;
            }

            case 5: {
			    int tipo, tamano;
			    float precio;
			    float kilos;
			
			    printf("Ingrese el tipo de uva (1 para tipo A, 2 para tipo B): ");
			    scanf("%d", &tipo);
			
			    printf("Ingrese el tamano de la uva (1 para tamano 1, 2 para tamano 2): ");
			    scanf("%d", &tamano);
			
			    printf("Ingrese la cantidad de kilos de uva que entregara: ");
			    scanf("%f", &kilos);
			
			    if (tipo == 1) {
			        if (tamano == 1) {
			            precio = 200.0;
			        } else if (tamano == 2) {
			            precio = 300.0;
			        } else {
			            printf("Tamano de uva invalido.\n");
			            return 0;
			        }
			    } else if (tipo == 2) {
			        if (tamano == 1) {
			            precio = 300.0;
			        } else if (tamano == 2) {
			            precio = 500.0;
			        } else {
			            printf("Tamano de uva invalido.\n");
			            return 0;
			        }
			    } else {
			        printf("Tipo de uva invalido.\n");
			        return 0;
			    }
			
			    float monto = precio * kilos;
			    printf("El productor recibira $%.2f por la entrega de %.2f kilos de uva.\n", monto, kilos);

                break;
            }

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (num != 0);

    return 0;
}
