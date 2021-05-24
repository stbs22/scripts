import java.util.*;

public class selecciones {

  public static String[] listSedes(libro biblio[]){

    List<String> sedes = new ArrayList<String>();

    for(int i=1;i<=(biblio.length-1);i++){
      sedes.add(biblio[i].sede);
    }
    
    Set<String> hashSet = new HashSet<String>(sedes);
    
    sedes.clear();
    sedes.addAll(hashSet);

    String[] seleccion = new String[sedes.size()];

    for (int i = 0; i < sedes.size(); i++){
      seleccion[i] = sedes.get(i);
    }

    return seleccion;
  }


  public static String[] listPisos(libro biblio[]){

    List<String> pisos = new ArrayList<String>();

    for(int i=1;i<=(biblio.length-1);i++){
      pisos.add(biblio[i].piso);
    }
    
    Set<String> hashSet = new HashSet<String>(pisos);
    
    pisos.clear();
    pisos.addAll(hashSet);

    String[] seleccion = new String[pisos.size()];

    for (int i = 0; i<pisos.size(); i++){
      seleccion[i] = pisos.get(i);
    }
    
    return seleccion;
  }


  public static String[] listSecciones(libro biblio[]){

    List<String> secciones = new ArrayList<String>();

    for(int i=1;i<=(biblio.length-1);i++){
      secciones.add(biblio[i].es);
    }
    
    Set<String> hashSet = new HashSet<String>(secciones);
    
    secciones.clear();
    secciones.addAll(hashSet);

    String[] seleccion = new String[secciones.size()];

    for (int i = 0; i<secciones.size(); i++){
      seleccion[i] = secciones.get(i);
    }
    return seleccion;
  }

  public static void selectprint(String[] seleccion){
    
      System.out.println("\n____________________");

      for (int i = 0; i < seleccion.length; i++){
          System.out.println("\n"+"\u001B[33m"+(i+1)+"\u001B[0m"+". "+seleccion[i].replace("\"", ""));
      }

      System.out.println("\n____________________");
  }

  public static String[] addseleccion(String[] lista, String seleccion){
      
      String[] lista2 = Arrays.copyOf(lista, lista.length + 1);

      lista2[lista.length + 1] = seleccion;

      return lista2;
  }

  public static String[] eliminar_seleccion(String nom, int indice, String[] lista){

    List<String> lista2 = new ArrayList<>(Arrays.asList(lista));

    lista2.remove(indice-1);

    lista = new String[ lista2.size() ];
    lista2.toArray(lista);

    return lista;
  }


  public static boolean encontrarPiso(libro biblio[], String select){
     //buscar el str en biblioteca
      boolean encontrado = false;//encuentra o no encuentra
      for(int c = 0; c < biblio.length; c++){
          if( select.equals(biblio[c].piso) && biblio[c].getLive() ){
            encontrado = true;
          }
      }
      return encontrado;
  } 
  public static int existePiso(String call, libro[] Biblioteca, Scanner input, int seleccion){
    while(encontrarPiso(Biblioteca,call)){
      System.out.print("\n\n\u001B[31mEste Piso pertenece a un libro\n\u001B[0mEscribe uno que no exista: ");
      seleccion = input.nextInt();
      if(seleccion == 0){
        break;
      }
    }
    return seleccion;
  }


  public static boolean encontrarSede(libro biblio[], String select){
     //buscar el str en biblioteca
      boolean encontrado = false;//encuentra o no encuentra
      for(int c = 0; c < biblio.length; c++){
          if( select.equals(biblio[c].sede) && biblio[c].getLive() ){
            encontrado = true;
          }
      }
      return encontrado;
  } 
  public static int existeSede(String call, libro[] Biblioteca, Scanner input, int seleccion){
    while(encontrarSede(Biblioteca,call)){
      ////limpiar
      System.out.print("\n\n\u001B[31mEsta Sede pertenece a un libro\n\u001B[0mIngrese una que no exista: ");
      seleccion = input.nextInt();
      if(seleccion == 0){
        break;
      }
    }
    return seleccion;
  }


  public static boolean encontrarSeccion(libro biblio[], String select){
     //buscar el str en biblioteca
      boolean encontrado = false;//encuentra o no encuentra
      for(int c = 0; c < biblio.length; c++){
          if( select.equals(biblio[c].es) && biblio[c].getLive() ){
            encontrado = true;
          }
      }
      return encontrado;
  } 
  public static int existeSeccion(String call, libro[] Biblioteca, Scanner input, int seleccion){
    while(encontrarSeccion(Biblioteca,call)){
      ////limpiar
      System.out.print("\n\n\u001B[31mEsta Seccion pertenece a un libro\n\u001B[0mEscriba una que no exista: ");
      seleccion = input.nextInt();
      if(seleccion == 0){
        return seleccion;
      }
    }
    return seleccion;
  }
  
  public static boolean repetidos_todos(String nuevo, String[] lista){
    boolean repet=false;
    for(int i=0;i<lista.length;i++){
      if (nuevo.equals(lista[i])){
        System.out.println("\u001B[31m\n\nEl elemento ingresado ya existe, ingrese uno válido\n\u001B[0m");

        repet = true;
      }
    }
    return repet;
  }

} 
