import java.io.*;
import java.io.IOException;


public class Main {

    public static int cont_filas(String archivo){
        
        int var = 0;
        try {

            BufferedReader buff = new BufferedReader(new FileReader(archivo));
            String lin = buff.readLine();

            while (lin != null) {
                var++;
                lin = buff.readLine();
            }
            buff.close();
        
        } catch (IOException e){

            e.printStackTrace();
        
        } finally {

            System.out.println("Fua la revivis scubi");
        
        }
        return var;
    }


    public static libro[] crear_lista(String archivo, int n){

        BufferedReader bufferLectura = null;
        libro lista[] = new libro[n];

        try { // Dice: intentar esto sin mostrar una excepcion, si se muestra (lo de catch), entonces hacer finally

            bufferLectura = new BufferedReader(new FileReader(archivo));
            String linea = bufferLectura.readLine();

            int i = 0;

            while (linea != null) {

                String[] campos = linea.split(",");
                lista[i] = new libro(campos[0], campos[1], campos[2], campos[3], campos[4], campos[5], campos[6], campos[7]);

                linea = bufferLectura.readLine();
                i++;
            }

            System.out.println("Archivo Leido con exito, total: "+i+" lineas");

        } catch (IOException e) {
            e.printStackTrace();
        } finally {

            // Cierro el buffer de lectura
            if (bufferLectura != null) {
                try {
                    bufferLectura.close();

                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return lista;
    }

    public static void pprintNombre(libro lista[], int n){
        for(int c = 0; c < n; c++){
            System.out.println("Nombre "+(c+1)+": "+lista[c].getNombre());
        }
    } 
    public static void main(String args[]){
        
        String archivo = "biblio1.csv";
    
        int i = cont_filas(archivo);
        libro lista[] = crear_lista(archivo, i);

        pprintNombre(lista, i);

        System.out.println("Ctm corrio amiga siii");
    }

}
