
public class Ejercicio_22 {
 
    public static void main(String[] args) {
 
        String cadena="La lluvia en Sevilla es una maravilla";
 
        int contador=0;
        for (int i=0;i<cadena.length();i++){
            if(cadena.charAt(i)=='a' || 
                    cadena.charAt(i)=='e' || 
                    cadena.charAt(i)=='i' || 
                    cadena.charAt(i)=='o' || 
                    cadena.charAt(i)=='u'){
                contador++;
            }
        }
 
        System.out.println("Hay "+contador+" vocales");
    }
}