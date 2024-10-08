import javax.swing.JOptionPane;
public class Ejercicio_30 {

    public static void main(String[] args) {
        
        String texto=JOptionPane.showInputDialog(null, 
                                                "Por favor, introduce una frase", 
                                                "Introducción", 
                                                JOptionPane.INFORMATION_MESSAGE);
        
        String cadenaResultante="";
        
        boolean isMayus;
        final int DIFERENCIA=32;
        
        String[] opciones={"Mayusculas", "Minusculas"};
        int eleccion=JOptionPane.showOptionDialog(null, 
                                                  "Elige tu opcion", 
                                                  "Eleccion", 
                                                  JOptionPane.YES_NO_OPTION, 
                                                  JOptionPane.QUESTION_MESSAGE, 
                                                  null, 
                                                  opciones, 
                                                  opciones[0]);
        
        
        isMayus= (eleccion==JOptionPane.YES_OPTION);
        
        char caracterActual;
        
        for(int i=0;i<texto.length();i++){
            
            caracterActual=texto.charAt(i);
            
            if(isMayus){
                
                if(caracterActual>=97 && caracterActual<=122){
                    cadenaResultante+=(char)(caracterActual-DIFERENCIA);
                }else{
                    cadenaResultante+=caracterActual;
                }
                
            }else{
                
                if(caracterActual>=65 && caracterActual<=90){
                    cadenaResultante+=(char)(caracterActual+DIFERENCIA);
                }else{
                    cadenaResultante+=caracterActual;
                }
                
            }
        }
        
        JOptionPane.showMessageDialog(null, 
                                        cadenaResultante, 
                                        "Resultado", 
                                        JOptionPane.INFORMATION_MESSAGE);
        
    }
    
}