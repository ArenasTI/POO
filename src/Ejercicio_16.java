import java.util.Scanner;
public class Ejercicio_16 {
 
    public static void main(String[] args) {
 
        Scanner sc = new Scanner(System.in);
        String contrase�a="eureka";
 
        final int INTENTOS = 3;
        
        boolean acierto=false;
 
        String password;
        for (int i=0;i<INTENTOS && !acierto;i++){
            System.out.println("Introduce una contrase�a");
            password = sc.next();
 
            if (password.equals(contrase�a)){
                System.out.println("Enhorabuena, acertaste");
                acierto=true;
            }
        }
    }
}