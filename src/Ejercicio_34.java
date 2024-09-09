import java.util.Scanner;
public class Ejercicio_34 {

    public static void main(String[] args) {
     
        Scanner sn = new Scanner(System.in);
        sn.useDelimiter("\n");
        
        System.out.println("Escribe una frase");
        String frase=sn.next();
        
        String palabras[] = frase.split(" ");
        
        for(int i=0;i<palabras.length;i++){
            System.out.println(palabras[i]);
        }
        
    }
    
}