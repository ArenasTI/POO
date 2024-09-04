import java.util.Scanner;
public class Ejercicio_8 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Introduce un caracter ASCII");
        char caracter = sc.next().charAt(0);

        int codigo = (int) caracter;

        System.out.println(codigo);
    }
}