import java.util.*;

class basics{

    String Atributostr;
    int Atributoint;
    String setterctm;


    //////SETTERS Y GETTERS
    public void setAtributoint(int atributoint) {
        Atributoint = atributoint;
    }

    public void setAtributostr(String atributostr) {
        Atributostr = atributostr;
    }

    public int getAtributoint() {
        return Atributoint;
    }

    public String getAtributostr() {
        return Atributostr;
    }
    ////////////////////////


    void inputAtributostr(){
        Scanner input = new Scanner(System.in);

        System.out.print("Ingrese atributostr: ");

        this.Atributostr = input.nextLine();

        input.close();
    }

    //Metodo qlo charcha y simple
    int sumar(int a, int b){
        return a + b;
    }

}