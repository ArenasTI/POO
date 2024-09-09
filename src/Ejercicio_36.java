import java.util.Scanner;
public class Ejercicio_36 {

public enum DiasSemana {
    LUNES(true),
    MARTES(true),
    MIERCOLES(true),
    JUEVES(true),
    VIERNES(true),
    SABADO(false),
    DOMINGO(false);
    
    private boolean laborable;
    
    private DiasSemana(boolean laborable){
        this.laborable = laborable;
    }

    public String toString() {
        
        if(laborable){
            return "El dia "+ this.name().toLowerCase() +" es laborable";
        }else{
            return "El dia "+  this.name().toLowerCase() +" no es laborable";
        }
        
    }
}
	
public static void main(String[] args) {
       
       Scanner sn = new Scanner(System.in);
       System.out.println("Escribe un dia de la semana");
       String dia = sn.next();
       
       DiasSemana diaS = DiasSemana.valueOf(dia.toUpperCase());
       
       System.out.println(diaS.toString());
       
   }
    
}