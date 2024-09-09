import javax.swing.JOptionPane;
public class Ejercicio_28 {

    public static void main(String[] args) {
        
        String texto=JOptionPane.showInputDialog(null, 
                                                "Inserta una frase", 
                                                "Inserción", 
                                                JOptionPane.INFORMATION_MESSAGE);
        
        String texto_sin_espacios="";
        
        char caracterActual;
        
        for(int i=0;i<texto.length();i++){
            
            caracterActual=texto.charAt(i);
            
            if(caracterActual!=' '){
                texto_sin_espacios+=String.valueOf(caracterActual);   
            }
            
        }
        
         JOptionPane.showMessageDialog(null, 
                                      "La frase tiene sin espacios es "+texto_sin_espacios, 
                                      "Resultado", 
                                      JOptionPane.INFORMATION_MESSAGE);
        
    }
    
}