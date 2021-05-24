import java.io.*;
import java.util.Random;
import java.util.*;

public class App2 {

  public static void printfln(String arg){
    System.out.println(arg);
  }

  public static void printf(String arg){
    System.out.print(arg);
  }

  public static void limpiar_cmd(boolean var){
    
    if (var) System.out.print("\033[H\033[2J\u001B[36m\n--------------------------------------"
          +"\n              Biblioteca"
          +"\n--------------------------------------\n\u001B[0m");

  }

  public static boolean warning(boolean var){
    if (var) System.out.println("\u001B[31mIngrese opcion válida\u001B[0m");
    
    var = false;

    return var;
  }

  public static void enter(){

    String str;
    Scanner enter = new Scanner(System.in);
    
    System.out.print("\u001B[34mPresione enter para continuar\u001B[0m");

    try{
      str = enter.nextLine();
    }
    catch(Exception e){}
  }

  public static String existencia(String call, libro[] Biblioteca, Scanner input){
    
    while(lectura.buscar_libro(call,Biblioteca,false)){

      limpiar_cmd(true);

      printf("\n\n\u001B[31mEste libro ya existe\n\u001B[0mIngrese el nombre del libro: ");
      
      call = input.nextLine();
    }
    
    return call;
  }

  public static String noexistencia(String call, libro[] Biblioteca, Scanner input){
    
    while(!lectura.buscar_libro(call,Biblioteca,false)){

      printf("\033[H\033[2J\n\n\u001B[31mEste libro no existe\n\u001B[0mIngrese el nombre del libro: ");
      
      call = input.nextLine();

    }
  
    return call;
  }

  public static void programa_cargando(){
    //Detalle Estetico 
        try{
            Random num = new Random();
            System.out.print("\033[H\033[2JCargando");

            for(int i = 0; i < num.nextInt(15)+5;i++){
                Thread.sleep(250);
                System.out.print(".");
                if (i%4==0) System.out.print("\033[H\033[2JCargando");
            }
            System.out.print("\033[H\033[2J");
        }catch(Exception e){
        }
    }


  public static void main(String[] args){

    String rojo = "\u001B[31m";
    String verde = "\u001B[32m";
    String azul = "\u001B[34m";
    String reset = "\u001B[0m";

    if(args.length == 0){
      System.out.println("\u001B[31mFATAL: Ingrese argumentos al programa\u001B[0m");
      System.exit(0);
    }
    
    String archivotitulo = args[0];

    libro Biblioteca[] = lectura.crear_lista(archivotitulo);

    if(Biblioteca.length == 0){
      System.out.println("\u001B[31mFATAL: No se ha podidop abrir el programa\u001B[0m");
      System.exit(0);
    }
    
    Scanner input = new Scanner(System.in);
    Scanner name = new Scanner(System.in);

    String[] pisos = selecciones.listPisos(Biblioteca);
    String[] secciones = selecciones.listSecciones(Biblioteca);
    String[] sedes = selecciones.listSedes(Biblioteca);

    boolean var = false;

    boolean clean = true; //limpiar pantalla, cambiar para desactivar

    programa_cargando();

    while(true){

      try{
        
        limpiar_cmd(clean);
        clean = true;

        var = warning(var);

        printfln("\n1. Buscar Libro"
          +"\n\n2. Agregar"
          +"\n\n3. Editar Libro "
          +"\n\n4. Eliminar"
          +"\n\n5. Creditos"
          +"\n\n6. Salir y Guardar\n\n"
          );

        printf("Ingrese una opción: ");

        int opcion = input.nextInt();

        switch(opcion){
            
          case 1:{ //Buscar
              
            limpiar_cmd(clean);

            printfln("\n\u001B[90m[Dejar en blanco y presionar enter para volver]\u001B[0m");
            printf("Ingrese el libro que desea buscar: ");

            String nombre = name.nextLine();

            if(nombre.equals("")){
              break;

            } if (lectura.buscar_libro(nombre,Biblioteca,false)){

              limpiar_cmd(clean);
              printf(verde+"\nLibro encontrado:\n"+reset);

              lectura.buscar_libro(nombre,Biblioteca,true);
              enter();
              
            } else {

              limpiar_cmd(clean);
              clean = false;
              printf(rojo+"No se ha encontrado el libro\n"+reset);

            }
            break;
              
          }

          case 2:{ //Agregar - Agregar - Agregar - Agregar - Agregar - Agregar

            limpiar_cmd(clean);

            var = warning(var);

            printfln("\n1. Libro Completo"
              +"\n\n2. Sede"
              +"\n\n3. Sección"
              +"\n\n4. Piso"
              +"\n\n5. Volver"
              );

            printf("\n\nIngrese selección a agregar: ");

            int opcion2 = input.nextInt();

            switch(opcion2){

              case 1:{

                  limpiar_cmd(clean);
                  printfln("\n\u001B[90m[Dejar en blanco y presionar enter para volver]\u001B[0m");
                  printf("Escriba el nombre del nuevo libro: ");
                  String nnombre = name.nextLine();
                  if (nnombre.equals("")) break;
                  nnombre = existencia(nnombre, Biblioteca, name);
                  nnombre = "\""+nnombre+"\"";

                  printf("\n\nEscriba el/los autores del libro: ");
                  String nautor = "\""+name.nextLine()+"\"";

                  printf("\n\nEscriba el año del libro: ");
                  String nanio = name.nextLine();

                  printf("\n\nEscriba el numero estante del libro: ");
                  String nen = name.nextLine();

                  limpiar_cmd(clean);
                  selecciones.selectprint(secciones);
                  printf("\n\nIngrese el numero de la seccion del libro: "); //seleccion ingresar opcion que exista
                  int nes2 = input.nextInt();
                  String nes = secciones[nes2 - 1];
                  
                  limpiar_cmd(clean);
                  selecciones.selectprint(pisos);
                  printf("\n\nIngrese numero del piso del libro: "); //seleccion
                  int npiso2 = input.nextInt();
                  String npiso = pisos[npiso2 - 1];

                  printf("\n\nEscriba el edificio del libro: ");
                  String nedi = "\""+name.nextLine()+"\"";

                  limpiar_cmd(clean);
                  selecciones.selectprint(sedes);
                  printf("\n\nIngrese numero de la sede del libro: "); //seleccion
                 
                  int nsede2 = input.nextInt();
                  String nsede = sedes[nsede2 - 1];
                  
                  Biblioteca = libro.newlibro(Biblioteca,Biblioteca.length,nnombre,nautor,nanio,nen,nes,npiso,nedi,nsede);

                  limpiar_cmd(clean);
                  printf(verde+"Libro guardado con exito\n"+reset);
                  lectura.display(Biblioteca[Biblioteca.length - 1]);

                  enter();
                  
                  break;
              }

              case 2:{
                  limpiar_cmd(clean);
                  printf("\nExistentes:");
                  selecciones.selectprint(sedes);

                  printfln("\n\u001B[90m[Dejar en blanco y presionar enter para volver]\u001B[0m");
                  printf("Escriba el nombre de la nueva sede: ");

                  String nuevasede = name.nextLine();

                  if (nuevasede.equals("")) break;

                  nuevasede = "\""+nuevasede+"\"";

                  List<String> sedes2 = new ArrayList<>(Arrays.asList(sedes));
                  
                  if(selecciones.repetidos_todos(nuevasede,sedes)==false){
                    sedes2.add(nuevasede);
                    sedes = new String[ sedes2.size() ];
                    sedes2.toArray(sedes);
                  
                  }else{
                    enter();
                    break;

                  }
                  
                  limpiar_cmd(clean);
                  printf(verde+"Sede guardada con exito\n"+reset);
                  selecciones.selectprint(sedes);
                  enter();

                  break;
              }

              case 3:{
                  limpiar_cmd(clean);

                  printf("\nExistentes: \n");
                  selecciones.selectprint(secciones);
                  printfln("\n\u001B[90m[Dejar en blanco y presionar enter para volver]\u001B[0m");
                  printf("Escriba el nombre de la nueva seccion: ");

                  String nuevaseccion = name.nextLine();
                  
                  if (nuevaseccion.equals("")) break;

                  nuevaseccion = "\""+nuevaseccion+"\"";
                  List<String> secciones2 = new ArrayList<>(Arrays.asList(secciones));

                  if(selecciones.repetidos_todos(nuevaseccion,secciones)==false){
                    secciones2.add(nuevaseccion);
                    secciones = new String[ secciones2.size() ];
                    secciones2.toArray(secciones);

                  }else{
                    enter();
                    break;
                  }

                  limpiar_cmd(clean);
                  printf(verde+"Seccion guardada con exito\n"+reset);
                  selecciones.selectprint(secciones);
                  enter();

                  
                  break;
              }

              case 4:{

                  limpiar_cmd(clean);

                  printf("\nExistentes: \n");
                  selecciones.selectprint(pisos);
                  printfln("\n\u001B[90m[Dejar en blanco y presionar enter para volver]\u001B[0m");
                  printf("Escriba el nuevo piso: ");

                  String nuevapiso = name.nextLine();
                  if (nuevapiso.equals("")) break;

                  List<String> pisos2 = new ArrayList<>(Arrays.asList(pisos));
                  
                  if(selecciones.repetidos_todos(nuevapiso,pisos)==false){
                    pisos2.add(nuevapiso);
                    pisos = new String[ pisos2.size() ];
                    pisos2.toArray(pisos);

                  }else{
                    enter();
                    break;
                  }

                  limpiar_cmd(clean);
                  printf(verde+"Piso guardado con exito\n"+reset);
                  selecciones.selectprint(pisos);
                  enter();
                  break;
              }
              
              case 5:{

                break;
              
              }

              default: var = true;
            
            }
            break;
          }

          case 3:{ //Editar - Editar - Editar - Editar - Editar - Editar
              
            limpiar_cmd(clean);
            printfln("\n\u001B[90m[Dejar en blanco y presionar enter para volver]\u001B[0m");
            printf("Ingrese libro que desea editar: ");
            
            String nom = name.nextLine();
            if(nom.equals("")){
              break;
            }

            if(lectura.buscar_libro(nom,Biblioteca,false)){

              limpiar_cmd(clean);
              printf(azul+"Libro escogido: "+nom+"\n"+reset);

              int indice = lectura.posicion(nom, Biblioteca);
              lectura.display(Biblioteca[lectura.posicion(nom,Biblioteca)]);
              
              printfln("\n1. Nombre"
                +"\n\n2. Seccion"
                +"\n\n3. Piso"
                +"\n\n4. Sede"
                );
              printf("\n\nIngrese atributo que desea editar: ");
              int opcion3 = input.nextInt();

              switch(opcion3){
                case 1:{
                  limpiar_cmd(clean);
                  printf("Ingrese el nuevo Nombre: ");

                  String nnnombre = name.nextLine();
                  
                  nnnombre = existencia(nnnombre, Biblioteca, name);

                  Biblioteca[indice].setNombre(nnnombre,true);

                  limpiar_cmd(clean);

                  lectura.display(Biblioteca[indice]);
                  enter();

                  break;
                }
                
                case 2:{
                  limpiar_cmd(clean);

                  selecciones.selectprint(secciones);
                  printf("Ingrese numero de sección: ");

                  int nnnsecc = input.nextInt();
                  String antes = Biblioteca[indice].getEs();

                  Biblioteca[indice].setEs(secciones[nnnsecc - 1]);

                  limpiar_cmd(clean);
                  printfln(verde+"Cambio realizado:\n"+antes+" ---> "+secciones[nnnsecc - 1] +reset);
                  lectura.display(Biblioteca[indice]);
                  enter();

                  break;
                }
                
                case 3:{
                  limpiar_cmd(clean);
                  selecciones.selectprint(pisos);
                  printf("Ingrese numero de Piso: ");

                  int nnnpiso = input.nextInt();
                  String antes = Biblioteca[indice].getPiso();
                  
                  Biblioteca[indice].setPiso(pisos[nnnpiso - 1]);
                  limpiar_cmd(clean);

                  printfln(verde+"Cambio realizado:\n"+antes+" ---> "+pisos[nnnpiso - 1] +reset);
                  lectura.display(Biblioteca[indice]);
                  enter();

                  break;
                }

                case 4:{
                  limpiar_cmd(clean);
                  selecciones.selectprint(sedes);
                  printf("Ingrese numero de Sede: ");
                  
                  int nnnsede = input.nextInt();
                  String antes = Biblioteca[indice].getSede();

                  Biblioteca[indice].setSede(sedes[nnnsede - 1]);
                  limpiar_cmd(clean);

                  printfln(verde+"Cambio realizado:\n"+antes+" ---> "+sedes[nnnsede - 1]+reset);

                  lectura.display(Biblioteca[indice]);
                  enter();

                  break;
                }
                

              }

            }else{
              
              limpiar_cmd(clean);
              clean = false;
              printf(rojo+"No se ha encontrado el libro\n"+reset);

            }
            
            break;
          }

          case 4:{ //Eliminar - Eliminar - Eliminar - Eliminar - Eliminar - Eliminar

              limpiar_cmd(clean);
              var = warning(var);

              printfln("\n1. Libro Completo"
                +"\n\n2. Sede"
                +"\n\n3. Sección"
                +"\n\n4. Piso"
                +"\n\n5. Volver"
                );

              printf("\n\nIngrese numero de atributo a eliminar: ");

              int opcion3 = input.nextInt();
              
              switch(opcion3){

                case 1:{
                  limpiar_cmd(clean);

                  printfln("\n\u001B[90m[Dejar en blanco y presionar enter para volver]\u001B[0m");
                  printf("Ingrese el nombre del libro: ");

                  String nnombre = name.nextLine();

                  if(nnombre.equals("")){
                    break;
                  }

                  nnombre = noexistencia(nnombre, Biblioteca, name);

                  Biblioteca[lectura.posicion(nnombre,Biblioteca)].borrar();

                  limpiar_cmd(clean);

                  printf(verde+"\nEl libro se ha eliminado con éxito\n"+reset);
                  clean = false;

                  break;

                }

                case 2:{
                  // Elimina sede sin libro asociado
                  limpiar_cmd(clean);

                  selecciones.selectprint(sedes);
                  printfln("\n\u001B[90m[Ingresar 0 para volver]\u001B[0m");
                  printf("Ingrese numero de sede a eliminar: ");

                  int esede = input.nextInt();

                  esede = selecciones.existeSede(sedes[esede-1], Biblioteca, input, esede);

                  if(esede == 0){
                    break;
                  }

                  String temp = sedes[esede-1];
                  sedes = selecciones.eliminar_seleccion(sedes[esede-1],esede,sedes);

                  printf("Se ha eliminado: "+temp+"\n\n");
                  selecciones.selectprint(sedes);
                  
                  enter();

                  break;
                }

                case 3:{
                  // Elimina seccion sin libro asociado
                  limpiar_cmd(clean);

                  selecciones.selectprint(secciones);

                  printfln("\n\u001B[90m[Ingresar 0 para volver]\u001B[0m");
                  printf("Ingrese numero de seccion a eliminar: ");
                  
                  int ees = input.nextInt();

                  ees = selecciones.existeSeccion(secciones[ees-1], Biblioteca, input, ees);
                  
                  if(ees == 0){
                    break;
                  }

                  String temp = secciones[ees-1];
                  secciones = selecciones.eliminar_seleccion(secciones[ees-1],ees,secciones);

                  printf("Se ha eliminado: "+temp);
                  selecciones.selectprint(secciones);
                  
                  enter();

                  break;
                }
                
                case 4:{
                  // Elimina piso sin libro asociado
                  limpiar_cmd(clean);

                  selecciones.selectprint(pisos);

                  printfln("\n\u001B[90m[Ingresar 0 para volver]\u001B[0m");
                  printf("Ingrese numero de piso a eliminar: ");

                  int episo = input.nextInt();

                  episo = selecciones.existePiso(pisos[episo-1], Biblioteca, input, episo);

                  if(episo == 0){
                    break;
                  }

                  String temp = pisos[episo-1];
                  pisos = selecciones.eliminar_seleccion(pisos[episo-1],episo,pisos);

                  printf("Se ha eliminado el piso: "+temp);
                  selecciones.selectprint(pisos);
                  
                  enter();


                  break;
                }
                case 5:{
                  break;
                }
                
                default: var = true;
              }
              break;
          }

          case 5:{ //creditos
            limpiar_cmd(clean);
            
            printf(verde+"\n--------------------------------------\n Grupo 14\n--------------------------------------\nAplicación 2 Inventario de Libros\nOrientado a Objetos\n\nTrabajo realizado por: \n - Andres Guevara \n - Matías Hermosilla\n - Esteban Hernández \n\nProfesor:\n - Felipe Aguilera\n\nCurso Lenguaje y Paradigmas de la\nprogramacion TICS200\n---------------------------------------\n\n"+reset);
            enter();

            break;
          }

          case 6:{ //Salir 

              limpiar_cmd(clean);
              var = warning(var);

              printfln("\n1. Guardar y Salir"
                +"\n\n2. Salir sin guardar"
                +"\n\n3. Volver"
                );
              
              printf("\n\nIngrese selección: ");
              int opcion5 = input.nextInt();
              
              switch(opcion5){

                case 1:{
                  limpiar_cmd(clean);
                  
                  lectura.fguardar(Biblioteca, archivotitulo);

                  printfln(verde+"\nLa base de datos se ha guardado correctamente\n"+reset+"\nTerminando programa");
                  input.close(); name.close(); System.exit(0); 
                  
                }

                case 2:{
                  limpiar_cmd(clean);

                  printfln("\nTerminando programa");
                  input.close(); name.close(); System.exit(0); 
                
                }

                case 3:{
                  //Volver
                  break;
                
                }
                
                default: var = true;

              }
              break;
          }

          default: var = true;
        }

      }catch(Exception e){
        
        limpiar_cmd(clean);
        
        System.out.println(rojo+"FATAL ~ Excepción:\nSe esperaba numero como input\n\n"+reset+"Favor de reiniciar el programa\n");
        enter();
        System.exit(0);
        
      }
      
      
    }
  }
}