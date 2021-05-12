public class Main {
    public static void main(String args[]){
        
        basics culo = new basics(); // crear objeto desde contructor
        
        int s = culo.sumar(123, 23);
        
        culo.setAtributoint(s);

        culo.inputAtributostr();

        System.out.println("\nGuardaste:\n- "+culo.Atributostr+"\n- "+culo.getAtributoint());

        System.out.println(culo.setterctm);
    }

}
