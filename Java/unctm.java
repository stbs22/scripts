
public class unctm {

    private String raja;
    private String kwea;
    private String uxiono;
    private int obo;

    unctm() //un contructor
    {
        raja = "a1";
        uxiono = "b2";
        kwea = "c3";
    }
    
    public void setObo(int wea)
    {
        obo = wea;
    }

    //Método para establecer la edad del animal
    public void setRaja(String mojon)
    {
        raja = mojon;
    }


    //Método para obtener la edad del animal
    public int getObo()
    {
        return obo;
    }

    //Método para obtener el nombre del animal
    public String getUxiono()
    {
        return uxiono;
    }

    public String getRaja(){
        return raja;
    }

}
