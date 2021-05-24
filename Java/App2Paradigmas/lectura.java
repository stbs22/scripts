
import java.io.*;
import java.io.IOException;
import java.util.*;

public class lectura{

  public static void fguardar(libro biblio[], String archivo){
    FileWriter fnuevo = null;
    try {

      fnuevo = new FileWriter(archivo);
      int cont = biblio.length-1;

      for (int i = 0; i < biblio.length; i++){

        if(biblio[i].getLive()){
          
          if (i != 0) fnuevo.write("\n");
          fnuevo.write(biblio[i].nombre+","+biblio[i].autor+","+biblio[i].anio+","+biblio[i].en+","+biblio[i].es+","+biblio[i].piso+","+biblio[i].edi+","+biblio[i].sede);
        }
      }

      fnuevo.close();
    }
    catch (Exception e) {
        System.out.println("Error de Guardado");
    }

  }

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
      
      }
      return var;
  }

  public static int posicion(String nombre, libro biblio[]){
    
    nombre = "\""+nombre+"\"";
    for(int c = 0; c < biblio.length; c++){

        if( (nombre.equals(biblio[c].getNombre())) && (biblio[c].live) ){
          return c;
        }
    }
    System.out.println("FATAL: El libro no existe");
    return -1;
  }


  public static libro[] crear_lista(String archivo){
    
      BufferedReader bufferLectura = null;

      libro lista[] = new libro[ cont_filas(archivo) ];
      
      try { // Dice: intentar esto sin mostrar una excepcion indicada en catch, si se muestra, entonces hacer finally como alternativa

          bufferLectura = new BufferedReader(new FileReader(archivo));
          String linea = bufferLectura.readLine();

          int i = 0;
          while (linea != null) {

              String[] campos = linea.split(",");
              String temp = "";
              int p = campos.length - 1;

              for (int k=1; k<(p-5); k=k+1){

                if (k != 1){
                  temp = temp.concat(",");
                }
                temp =  temp.concat(campos[k]);
              
              }

              lista[i] = new libro(campos[0], temp, campos[p-5], campos[p-4], campos[p-3], campos[p-2], campos[p-1], campos[p]);
              
              linea = bufferLectura.readLine();
              temp.isEmpty();
              i++;

          }

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

  public static void display(libro objeto){

    System.out.println(
      "\n-------------"
      +"\nNombre: "+objeto.nombre
      +"\n\nAutor: "+objeto.autor
      +"\n\nAño: "+objeto.anio
      +"\n\nSección: "+objeto.es
      +"\n\nNumero de Estante: "+objeto.en
      +"\n\nSede: "+objeto.sede
      +"\n\nEdificio: "+objeto.edi
      +"\n\nPiso: "+objeto.piso
      +"\n-------------\n"
    );
            
  }

  public static void display_sel(libro objeto){

    System.out.println(
      "\n-------------"
      +"\n1. Nombre: "+objeto.nombre
      +"\n\n2. Sede: "+objeto.sede
      +"\n\n3. Edificio: "+objeto.edi
      +"\n\n4. Piso: "+objeto.piso
      +"\n-------------\n"
    );
  
  }
            

  public static boolean buscar_libro(String nombre, libro lista[], boolean mostrar){

      boolean check = false;
      nombre = "\"" + nombre + "\"";

      for(int c = 0; c < lista.length; c++){
        
          if(  nombre.equals(lista[c].getNombre())  &&  lista[c].live  ){
            
            check = true;
            
            if (mostrar){
              display(lista[c]);
            }

          }
      }
      return check;
  }

}
  
