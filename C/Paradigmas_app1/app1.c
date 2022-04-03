#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// Aplicacion Trabajo de Datos Biblioteca

// Andres Guevara
// Esteban Hernandez
// Matias Hermosilla

// Crea un char de una fila con el nombre del libro cambiado.
// dir -> nombre del archivo.
// libro -> nombre del libro por cambiar.
// nlibro -> nombre del libro que desea poner.
char *enombre(char dir[], char libro[], char nlibro[]) {
  FILE *archivo = fopen(dir, "r");
  char file[300];
  int pp = 0, ll = 0;
  char com[2] = "\"";
  char *txt = malloc(30 * sizeof(char));
  char *kkl = malloc(200 * sizeof(char));
  strcat(txt, com);
  strcat(txt, libro);
  strcat(txt, com);
  strcat(kkl, com);
  strcat(kkl, nlibro);
  strcat(kkl, com);
  while (fgets(file, 300, archivo)) {
    char *temp;
    temp = strtok(file, ",");
    if (strcmp(temp, kkl) == 0) {
      printf("El libro %s ya esta registrado.\n", kkl);
      return NULL;
    }
    if (strcmp(temp, txt) == 0) {
      ll++;
      temp = strtok(NULL, ",");
      while (temp != NULL) {
        strcat(kkl, ",");
        strcat(kkl, temp);
        temp = strtok(NULL, ",");
        pp++;
      }
    }
  }

  if (ll == 0) {
    printf("No existe el libro de nombre: %s\n", libro);
    return NULL;
  }

  char *newl = malloc(200 * sizeof(char));
  int lo = strlen(kkl) - 1;
  strncpy(newl, kkl, lo);
  free(kkl);

  return newl;
}
//
//Rehacer un fichero con string sobrescribiendolo
void fsavestr(char dir[],char *txt){
    FILE *archivo;
    archivo = fopen(dir,"w");
    /*for(int i = 0; i < (strlen(txt)) ; i++){
        if(txt[i] != 0){ // evitar espacios no asignados     
            fprintf(archivo,"%c",txt[i]); //escribir caracter por caracter
        }
    }*/
    fprintf(archivo,"%s",txt);
    fclose(archivo);}




//
// Crea un char con los datos unicos de una fila
// dir -> nombre del archivo.
// j -> tipo de columna a ocupar. (j=1 -> Seccion)(j=2 -> Piso)(j=3 -> Edificio)(j=4 -> Sedes)
char *unicc(char dir[],int j) {

  FILE *archivo2 = fopen(dir, "r");  // Contar las filas mediante p
  int c = 0, p = 0;
  while ((c = fgetc(archivo2)) != EOF) {
    if (c == '\n') {
      p++;
    }
  }
  fclose(archivo2);
  int o;

  if (j == 1) {  // Estante Seccion
    o = 4;
  }
  if (j == 2) {  // Pisos
    o = 5;
  }
  if (j == 3) {  // Edificio
    o = 6;
  }
  if (j == 4) {  // Sedes
    o = 8;
  }

  struct sds {
    char sede[150];
  };

  struct sds n[p];

  FILE *archivo = fopen(dir, "r");  // Guardar las variables en un struct
  char file[300];
  int pp = 0;
  while (fgets(file, 300, archivo)) {
    char *temp;
    temp = strtok(file, "\"");
    for (int i = 0; i < o; i++) {
      temp = strtok(NULL, "\"");
    }
    if (temp != NULL) {
      strcpy(n[pp].sede, temp);  // Guarda la variable de una fila repetidas
      temp = strtok(NULL, "\"");
    }
    pp++;
  }

  char *pepe = malloc(30 * p * sizeof(char));
  char *def = malloc(30 * p * sizeof(char));
  strcat(pepe, n[1].sede);
  strcat(pepe, ",");

  int ff = 1;  // Comparar las variables para seleccionar las unicas
  for (int tt = 2; tt <= p; tt++) {
    int gg = 0;
    for (int kk = 1; kk <= ff; kk++) {  // Compara cada variable
      if (strcmp(n[tt].sede, n[kk].sede) == 0) {
        gg++;
        break;
      }
    }
    if (gg == 0) {  // Guarda las variables unicas
      strcat(pepe, n[tt].sede);
      strcat(pepe, ",");
    }
    ff++;
  }
  int lo = strlen(pepe) - 1;
  strncpy(def, pepe, lo);
  free(pepe);

  if (j == 2) {
    char *pst;
    char *fpst = malloc(30 * p * sizeof(char));
    char *defpst = malloc(30 * p * sizeof(char));
    pst = strtok(def, ",");
    while (pst != NULL) {
      strcat(fpst, pst);
      strcat(fpst, ",");
      pst = strtok(NULL, ",");
    }
    int lol = strlen(fpst) - 1;
    strncpy(defpst, fpst, lol);
    free(fpst);
    return defpst;
  }
  if (j != 2) {
    return def;
  }
}

//
//buscar libro en directorio
void fbuscar(char dir[],char libro[]){
  int n = strlen(libro) + 5;
  char *txt = malloc(n*sizeof(char));
  char *com = "\"";
  int f = 0;

  FILE *archivo = fopen(dir,"r");
  printf("Buscando %s\n\n--%d--\n",libro,n);
  
  strcat(txt,com);strcat(txt,libro);strcat(txt,com);
  //Comillas
  char *fila = malloc(200*sizeof(char));printf("\nDespues: %s\n",fila);
  
  if (archivo != NULL){

      while(fgets(fila,200,archivo)){
          char *temp;
          temp = strtok(fila,","); //recorrer cada fila hasta encontrar txt
          f++;
          if(strcmp(temp,txt) == 0){
              printf("\x1b[32mENCONTRADO %s en linea %d\x1b[0m\n\nDatos:\n\n",libro,f); int n = 0;      
              while(temp!=NULL){
                  char *col[] = {"Titulo: ","Autor: ","Anio: ","Numero de Estante: ","Seccion: ","Piso: ","Edificio: ","Sede: "};
                  printf("%s\n",col[n]);
                  printf(">>%s\n\n",temp);
                  temp = strtok(NULL,",");
                  n++;
              }
              free(txt);
              free(fila);
              return; 
          }

      }
      printf("No se ha encontrado %s\n",libro);
  }
  free(txt);
  free(fila);
  return;}

//
//Imprimir bonito texto separado por comas
void pprint(char *texto){
  printf("\n-");
  for(int i = 0; i < strlen(texto); i++){
      if(("%d",texto[i]) == 44){
          printf("\n-");
      }
      if(("%d",texto[i]) != 44){
          printf("%c",texto[i]);
      }
  }}

//
// Devolver 0 si encuentra un string en texto y 1 si no 
//[ var = 2 avisa si no encuentra ]
//[ var = 1 avisa si encuentra ]
//[ var = 0 para no avisar ]
int fencontrar(char *ftxt, char *algo, int var){
  if (strstr(ftxt,algo) != NULL) {
    if(var == 1)printf("\x1b[31mYa existe %s\n\x1b[0m", algo);
    return 0;
  } 
  if (strstr(ftxt,algo) == NULL){
    if(var == 2)printf("\x1b[31mNo se ha encontrado %s\x1b[0m\n",algo);
    return 1;
  }}

//
//Pasar por completo a string un Fichero abierto
char *fstr(FILE *archivo, int cont_caracteres){
  char *ftxt = malloc(cont_caracteres*sizeof(char));
  int cont = 0;
  while(!feof(archivo)){
      char c = fgetc(archivo);
      if( ("%d",c) != -1 ){
          //printf("\n%c - %d",c,c);
          ftxt[cont] = c;
      } cont++;
  } rewind(archivo); return ftxt;}
  
//
//Contar filas de Fichero r abierto
int fcont_filas(FILE *archivo){
    int n = 0; char fila[200];
    while(!feof(archivo)){
        n++; fgets(fila,200,archivo);
    }
    rewind(archivo);
    return n;}

//
//Contar caracteres de Fichero r abierto
int fcont_char(FILE *archivo){
    int n = 0;
    while(!feof(archivo)){
        char c = fgetc(archivo);
        n++;
    }
    rewind(archivo);
    return n;}

//
//Imprime caracter por caracter de un string
void printfstr(char str[]){
    for(int i = 0; i < strlen(str); i++)printf("%c",str[i]);}
//
//Compara caracter por caracter de dos punteros
int realstrcmp(char *txt1, char *txt2){
  if(strlen(txt1) != strlen(txt2)){
      return 1;
  }
  for(int i = 0; i < strlen(txt1); i++){
      if( txt1[i] != txt2[i]){
          return 1;
      }
  }
  return 0;}


//
//Agregar n= 0 para separadores 
char *agregar(char *seleccion_original,char *nuevas_selecciones, int n){
  char *separador=",";
  char *auxiliar = malloc(100*sizeof(char));
  strcat(auxiliar,seleccion_original);
  if(n == 0)strcat(auxiliar,separador);
  strcat(auxiliar,nuevas_selecciones);
  return auxiliar;}



//
//Elimina una fila del string a trabajar
char *delfila(char *ftxt, char libro[]){
  char *nftxt = malloc(strlen(ftxt)*sizeof(char));
  strcpy(nftxt,ftxt);//evitar cambios inesperados
  char *newtxt = malloc(strlen(ftxt)*sizeof(char));
  char *temp;
  temp = strtok(nftxt,"\n");
  while(temp != NULL){
    char *ftemp = malloc(50*sizeof(char));
    strcpy(ftemp,temp);
    if(fencontrar(temp,libro,0) != 0){
      strcat(newtxt,ftemp);
      strcat(newtxt,"\n");
    }    
    temp = strtok(NULL,"\n");
    free(ftemp);
  }
  return newtxt;}

//
//Retorna puntero a string puesto por usuario con espacios

//
//revizar y reemplazar comas con [;]
char *rcoma(char *txt){
  if(fencontrar(txt,",",0) == 0){
    char *straux = malloc(strlen(txt)*sizeof(char));
    printf("\x1B[34mReemplazando [,] con [;]\x1B[0m\n");
    for(int i = 0; i < strlen(txt); i++){
      if(("%c",txt[i]) != 44){
        char c = txt[i];
        straux[i] = c;
      }
      if(("%c",txt[i]) == 44){
        straux[i] = ';';
      }
    }
    char *txt = straux;
    return straux;
  }
  return txt;}

//
//Scanf preparado para espacios y comas
char *scanfreal(int largo){
  char *str1 = malloc(largo*sizeof(char));
  fgets(str1,largo*sizeof(char),stdin); 
  scanf("%[^\n]%*c", str1);
  str1 = rcoma(str1);
  if( ("%c",str1[ strlen(str1) - 1 ]) == 10 ){
    char *str2 = malloc(largo*sizeof(char));
    int l = strlen(str1) - 1;
    strncpy(str2,str1,l); 
    return str2;
  }
  return str1;}
int cont_elementos(char *cadena){
  char *auxcadena = malloc(strlen(cadena)*sizeof(char));
  strcpy(auxcadena,cadena);
  int contador = 0;
  char *temp;
  temp = strtok(auxcadena,",");
  while(temp!=NULL){
    temp = strtok(NULL,",");
    contador++;
  }
  return contador;
}
char *delsc(char *cadena, char *deltxt){
  
  int contador = cont_elementos(cadena);
  char *auxcadena = malloc(strlen(cadena)*sizeof(char));
  strcpy(auxcadena,cadena);


  char *newcadena = malloc(strlen(cadena)*sizeof(char));

  char *temp = strtok(auxcadena,",");
  
  
  printf("Cantidad de elementos: %i\n",contador);

  for(int i = 0; i < contador ;i++){
    if(strcmp(temp,deltxt) != 0){
      strcat(newcadena,temp);
      if(i != contador - 1)strcat(newcadena,",");
    }
    temp = strtok(NULL,",");
  }
  return newcadena;
}

/////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv){

  if(argv[1] == NULL){
  printf("\x1b[31m$ No se ha indexado archivo\n\x1b[0m");
    return 0;}
  
  FILE *archivo = fopen(argv[1],"r+");
  if(archivo == NULL){
    printf("\x1b[31m$ El archivo no existe\n\x1b[0m");
    return 0;}
  
  //printf("\x1b[2J\x1b[1;1f\x1b[0m");
  int selec1, selec2,selec3, selec4, selec5;
  int var = 0;
  char *puntero;
  char *x = "-e";
  char *texto;

  char *scsede = unicc(argv[1], 4);
  char *scseccion = unicc(argv[1], 1);
  char *scedificio = unicc(argv[1], 3);
  char *scpiso = unicc(argv[1], 2);

  char *archivo_texto = fstr(archivo,fcont_char(archivo));
  
  do{ 
    printf("\n\n\n\n\x1b[36m>>> Menu de Opciones\n--------------------\x1b[0m\n\n1.Agregar\n \n2.Editar selección en libros\n \n3.Eliminar\n \n4.Editar Nombre de Libro\n \n5.Buscar libro\n \n6.Creditos\n \n7.Salir.\n\n\nSelección: ");
    scanf("%d",&selec1);
    switch(selec1){
//Agregar//
      case 1:{
        do{
          if(var == 0){
            //printf("\x1b[2J\x1b[1;1f\x1b[0m");
          }
          var = 0;
          printf("\n\n\n\x1b[36m>>> Menu de Agregado\n--------------------\x1b[0m\n\n1.Agregar Sede \n\n2.Agregar Sección\n\n3.Agregar Piso \n\n4.Agregar Libro \n\n5.Volver\n\n\nSeleccion: ");
          scanf("%d",&selec2);
          switch(selec2){
            case 1:{
              //printf("\x1b[2J\x1b[1;1f\x1b[0m");
              char *texto;
              do{
                printf("\n\nActualmente guardadas: ");
                pprint(scsede);
                printf("\n\nIngrese nueva sede: ");
                texto = scanfreal(25);
              }while(fencontrar(scsede,texto,1) == 0);

              scsede = agregar(scsede,texto,0);
              printf("\n\n\x1b[32m \nSe guardó con éxito la sede: ");
              printfstr(texto);
              printf("\x1b[0m\n");
            }break;

            case 2:{
              //printf("\x1b[2J\x1b[1;1f\x1b[0m");
              char *texto; 
              do{
                printf("\n\nActualmente guardadas: ");
                pprint(scseccion);
                printf("\n\nIngrese nueva seccion: ");
                texto = scanfreal(25);
              }while(fencontrar(scseccion,texto,1) == 0);

              scseccion = agregar(scseccion,texto,0);
              printf("\n\n\x1b[32m \nSe guardó con éxito la sección: ");
              printfstr(texto);
              printf("\x1b[0m\n");
            }break;

            case 3:{
              //printf("\x1b[2J\x1b[1;1f\x1b[0m");
              do{
                printf("\n\nActualmente guardados: ");
                pprint(scpiso);
                printf("\n\nIngrese nuevo piso: ");
                texto = scanfreal(25);
              }while(fencontrar(scpiso,texto,1) == 0);

              scpiso = agregar(scpiso,texto,0);
              printf("\n\n\x1b[32m \nSe guardó con éxito el piso: ");
              printfstr(texto);
              printf("\x1b[0m\n");        
            }break;
            
            case 4:{
              //printf("\x1b[2J\x1b[1;1f\x1b[0m");
              char *nombre;
              do{

                printf("\n\x1b[37;2m\n\nEscribir [-e] para cancelar\x1b[0m\nIngrese respectivo dato.\n");
                printf("\n>> Nombre: ");
                nombre = scanfreal(25);

              }while(fencontrar(archivo_texto,nombre,1) == 0);
              if(realstrcmp(nombre,x) == 0){printf("\nCancelado\n");break;}
              
              printf("\n>> Autor: ");
              char *autor = scanfreal(25);
              
              printf("\n>> Año: ");
              char *anio = scanfreal(5);
              
              printf("\n>> Numero de Estante: ");
              char *est_n = scanfreal(5);

              char *est_s;
              do{
                printf("\n\n>> Seccion de Estante \n\nOpciones: \n");
                pprint(scseccion);
                printf("\n\nSeleccion: ");
                est_s = scanfreal(20);
              }while(fencontrar(scseccion,est_s,2) == 1);

              char *npiso;
              do{
                printf("\n\n>> Piso disponibles: \n\nOpciones: \n");
                pprint(scpiso);
                printf("\n\nSeleccion: ");
                npiso =  scanfreal(4);
              }while(fencontrar(scpiso,npiso,2) == 1);

              char *edificio;
              do{
                printf("\n\n>> Edificio \n\nOpciones: \n");
                pprint(scedificio);
                printf("\n\nSeleccion: ");
                edificio = scanfreal(4);
              }while(fencontrar(scedificio,edificio,2) == 1);

              char *sede;
              do{
                printf("\n\n>> Sedes \n\nOpciones: \n");
                pprint(scsede);
                printf("\n\nSeleccion: ");
                sede = scanfreal(20);
              }while(fencontrar(scsede,sede,2) == 1);

              printf("\n");

              char *sep = ",";
              char *comi = "\"";
              char *salto = "\n";
              
              char *txtcat = malloc(500*sizeof(char));

              
              
              strcat(txtcat,salto);
              
              strcat(txtcat,comi);
              strcat(txtcat,nombre);
              strcat(txtcat,comi);
              
              strcat(txtcat,sep);

              strcat(txtcat,comi);
              strcat(txtcat,autor);
              strcat(txtcat,comi);
              
              strcat(txtcat,sep);
              
              strcat(txtcat,anio);

              strcat(txtcat,sep);
              
              strcat(txtcat,est_n);

              strcat(txtcat,sep);

              strcat(txtcat,comi);
              strcat(txtcat,est_s);
              strcat(txtcat,comi);

              strcat(txtcat,sep);

              strcat(txtcat,npiso);

              strcat(txtcat,sep);

              strcat(txtcat,comi);
              strcat(txtcat,edificio);
              strcat(txtcat,comi);

              strcat(txtcat,sep);

              strcat(txtcat,comi);
              strcat(txtcat,sede);
              strcat(txtcat,comi);

              //strcpy(txtcat2,txtcat);
              //strcat(archivo_texto,txtcat);

              //printf("\x1b[2J\x1b[1;1f\x1b[0m");
              
              printf("\x1b[35m>>> RESUMEN:\n------------\n\n\x1b[0m");

              char *col[] = {"Titulo: ","Autor: ","Anio: ","Numero de Estante: ","Seccion: ","Piso: ","Edificio: ","Sede: "};

              char *txteval = malloc(500*sizeof(char));
              strcpy(txteval,txtcat);

              char *temp;
              temp = strtok(txteval,",");
              
              printf(">> %s",col[0]);
              printf("%s\n\n",temp);

              for(int i = 1; i < 8; i++){
                temp = strtok(NULL,",");
                printf(">> %s\n",col[i]);
                printf("%s\n\n",temp);}
              
              archivo_texto = agregar(archivo_texto,txtcat,1);
              var = 1;
            }break;  
          }
        }while(selec2 != 5);
      }break;

//Editar Seleccion//
      case 2:{
        do{ 
          printf("\n\nIngrese [-e] para Volver \nIngrese Libro a cambiar: ");
          char *var = scanfreal(25);

          if(realstrcmp(var,x) == 0){
            printf("Cancelado \n\n");
            break;
          }

          printf("\n\n\n\n\x1b[36m>>> Menu de Opciones\n--------------------\x1b[0m\n\n1.Editar Sede \n\n2.Editar Sección\n\n3.Editar Piso\n\n4.Volver\n\n\n\nSeleccion: ");
          scanf("%i",&selec3);
          switch(selec3){
            do{
              case 1:{
                char *sede;
                printf("\n\nIngrese una sede\n\nOpciones: ");
                pprint(scedificio);
                printf("\n\nSeleccion: ");
                sede = scanfreal(20);
                printf("\n\nSe cambió a la sede: %s",sede);
              }break;
              
              case 2:{
                printf("\n\nIngrese una seccion\n\nOpciones: ");
                pprint(scedificio);
                printf("\n\nSeleccion: ");
                char *seccion = scanfreal(20);
                //##
                printf("\n\nSe cambió a la seccion: %s",seccion);
              }break;
              
              case 3:{
                printf("\n\nIngrese una seccion:\n\nOpciones: ");
                pprint(scedificio);
                printf("\n\nSeleccion: ");
                char *seccion = scanfreal(20);
                //##
                printf("\n\nSe cambió a la seccion: %s",seccion);
                break;
              }

            }while(selec3 != 4);
          }
        }while(selec3 != 4);
      }break;
      
//Eliminar//
      case 3:{
        do{
          printf("\n\n>>> Menu de Selecciones\n------------------------\n\n1.Eliminar Libro \n\n2.Eliminar Sede\n\n3.Eliminar Sección\n\n4.Eliminar Piso\n\n5. Volver \n\n\nSeleccion: ");
          scanf("%d",&selec4);
          int n = 0;
          switch(selec4){
            case 1:{
              char *libro;
              do{
                printf("\n\x1b[37;2m\n\nEscribir [-e] para cancelar\x1b[0m\n\nIngrese Libro: ");
                libro = scanfreal(25);
              }while(fencontrar(archivo_texto,libro,2) == 1);
              if(realstrcmp(libro,x) == 0){printf("\nCancelado\n");break;}

              archivo_texto = delfila(archivo_texto, libro);
              printf("\n\n\x1b[32m \nSe eliminó con éxito el libro: ");
              printfstr(libro);
              printf("\x1b[0m\n");
              
            }break;

            case 2:{
              char *sede;
              do{
                if(n == 1)printf("\x1b[0mNo se ha podido eliminar sede\x1b[0m");
                printf("\n\nOciones:");
                pprint(scsede);
                printf("\n\nIngrese Sede: ");
                sede = scanfreal(25);
                n = 1;
              }while( (fencontrar(scsede,sede,0) == 1) || (fencontrar(scsede,sede,0) == 0) );
              n = 0;
              cont_elementos(scsede);
              scsede = delsc(scsede,sede);
              printf("\n\n\x1b[32m \nSe eliminó con éxito la Sede: ");
              printfstr(sede);
              printf("\x1b[0m\n");
            }break;

            case 3:{

              char *seccion;
              do{
                if(n == 1)printf("\x1b[0mNo se ha podido eliminar seccion\x1b[0m");
                printf("Ociones:\n\n");
                pprint(scseccion);
                printf("\n\nIngrese Sección: ");
                char *seccion = scanfreal(25);
              }while( (fencontrar(scseccion,seccion,0) == 1) && (fencontrar(scseccion,seccion,0) == 0) );

              n = 0;
              cont_elementos(scseccion);
              scseccion=delsc(scseccion, seccion);
              printf("\n\n\x1b[32m \nSe eliminó con éxito la Sección: ");
              printfstr(seccion);
              printf("\x1b[0m\n");
            }break;
            
            case 4:{
              char *piso;
              do{
                if(n == 1)printf("\x1b[0mNo se ha podido eliminar piso\x1b[0m");
                printf("Ociones:\n\n");
                pprint(scpiso);
                printf("\n\nIngrese el piso: ");
                piso = scanfreal(25);
                n = 1;
              }while( (fencontrar(scpiso,piso,0) == 1) && (fencontrar(scpiso,piso,0) == 0) );
              n = 0;
              cont_elementos(scpiso);
              scpiso=delsc(scpiso,piso);
              printf("\n\n\x1b[32m \nSe eliminó con éxito el piso: ");
              printfstr(piso);
              printf("\x1b[0m\n");
            }break;
          }
        }while(selec4!=5);


      }break;

//Editar Nombre Libro//

      case 4:{
        
        char *libroviejo;
        do{
          printf("\n\x1b[37;2m\n\nEscribir [-e] para cancelar\x1b[0m");
          printf("\nIngrese nombre del libro que desea editar: ");
          libroviejo = scanfreal(30);
          if(realstrcmp(libroviejo,x) == 0){printf("\nCancelado\n");break;}
        }while(fencontrar(archivo_texto,libroviejo,2) == 1);
        if(realstrcmp(libroviejo,x) == 0){break;}

        char *libronuevo;
        do{
          printf("\n\nIngrese nuevo nombre: ");
          libronuevo = scanfreal(30);
          if(realstrcmp(libroviejo,libronuevo) == 0)printf("Ingrese otro nombre");
        }while(realstrcmp(libroviejo,libronuevo) == 0);

        char *nfila = enombre(argv[1], libroviejo, libronuevo);
        archivo_texto = delfila(archivo_texto, libroviejo);
        strcat(archivo_texto,nfila);

        printf("\n\n\x1b[32m \nSe han realizado los cambios con éxito del Libro: ");
        printfstr(libroviejo);
        printf("\x1b[0m\n");
      }break;

//Buscar Libro//

      case 5:{
        char *libro;
        do{

          printf("\n\x1b[37;2m\n\nEscribir [-e] para cancelar\x1b[0m\n\nIngrese nombre de libro: ");
          libro = scanfreal(25);
          if(realstrcmp(libro,x) == 0){printf("\nCancelado\n");break;}

        }while(fencontrar(archivo_texto,libro,2) == 1);

        if(realstrcmp(libro,x) == 0)break;
        printf("Buscando libro");
        fbuscar(argv[1],libro);

      }break;

//Creditos//
      case 6:{
        do{
          printf("\n\x1b[32;2m\n-------------------\nTrabajo realizado por: \n - Andres Guevara \n - Matías Hermosilla \n - Esteban Hernández\n\nProfesor:\n - Felipe Aguilera\n\nCurso Lenguaje y Paradigmas de la programacion\nTICS200\n--------------------\n\x1b[0m");
          break;
        }while(1);
      }break;

//Salir//
      case 7:{
        do{
          printf("\n\nTextoexto:\n");
          printfstr(archivo_texto);
          printf("\n\n\n\n1. Guardar y Salir. \n\n2. Salir sin Guardar.\n\n3. Volver.\n\n\nSelección: ");
          scanf("%d",&selec5);
          switch(selec5){
            case 1:{
              FILE* file = fopen(argv[1],"w");
              for(int i = 0; i < strlen(archivo_texto); i++){
                printf("Posicion: %i - Char %c - %i\n",i,archivo_texto[i],archivo_texto[i]);
                if( (("%d",archivo_texto[i]) != 2) ){
                  fputc(archivo_texto[i],file);
                }
                
              }
              return 0;
            }break;
          
            case 2:{
              return 0;
            }break;

            case 3:{
              
            }break;
            
          }
        }while(selec5 != 3);      
      }break;

    }
  }while(1);
}
