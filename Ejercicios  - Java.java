package Ejercicios;

public class Ejercicios_Java {    
    public static void main(String[] args) {
        // Parte 1: Números del 1 al 100 e informar si el número es par
        System.out.println("Números del 1 al 100 y si son pares:");
        for (int i = 1; i <= 100; i++) {
            if (i % 2 == 0) {
                System.out.println(i + " es par.");
            }
        }






        // Parte 2: Números del 50 al 100 e informar si el número es primo o sus divisores
        System.out.println("\nNúmeros del 50 al 100 y si son primos o sus divisores:");
        for (int i = 50; i <= 100; i++) {
            if (isPrime(i)) {
                System.out.println(i + " es primo.");
            } else {
                System.out.print(i + " no es primo, sus divisores son: ");
                printDivisors(i);
            }
        }









        // Parte 3: Pedir números hasta que uno sea mayor a 100 y primo
        System.out.println("\nIntroduce números (se detendrá cuando uno sea mayor a 100 y primo):");
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int num;
        do {
            num = scanner.nextInt();
        } while (num <= 100 || !isPrime(num));

        System.out.println(num + " es mayor a 100 y es primo.");









        // Parte 4: Calculadora con operaciones aritméticas simples
        System.out.println("\nCalculadora simple:");
        System.out.println("Introduce dos números:");
        double num1 = scanner.nextDouble();
        double num2 = scanner.nextDouble();
        System.out.println("Introduce la operación (+, -, *, /):");
        char operation = scanner.next().charAt(0);
        double result = calculate(num1, num2, operation);
        System.out.println("Resultado: " + result);










        // Parte 5: Ejemplo del uso del for-each
        System.out.println("\nEjemplo de uso del for-each:");
        int[] numbers = {1, 2, 3, 4, 5};
        for (int number : numbers) {
            System.out.println(number);
        }
    }

    // Método para verificar si un número es primo
    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // Método para imprimir los divisores de un número
    public static void printDivisors(int num) {
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                System.out.print(i + " ");
            }
        }
        System.out.println(num); // El número mismo es divisor de sí mismo
    }

    // Método para realizar cálculos básicos
    public static double calculate(double num1, double num2, char operation) {
        switch (operation) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 != 0) {
                    return num1 / num2;
                } else {
                    System.out.println("Error: División por cero.");
                    return Double.NaN;
                }
            default:
                System.out.println("Operación no válida.");
                return Double.NaN;
        }
    }
}
