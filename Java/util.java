import java.io.*;
import java.util.Random;
import java.util.*;

public class util{

    public static void enter(){
        String str;
        Scanner enter = new Scanner(System.in);
        
        System.out.print("\u001B[34mPresione enter para continuar\u001B[0m");
    
        try{
          str = enter.nextLine();
        }
        catch(Exception e){}
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
    
    public static void main(String args[]){
        programa_cargando();
        System.out.println("Programa cargado con esfuerzo y exito\n");
        enter();
    }
}