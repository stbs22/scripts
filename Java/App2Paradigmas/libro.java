import java.util.Arrays;

public class libro {
  
    public String autor;
    public String nombre;
    public String es;
    public String sede;
    public String edi;
    public String anio;
    public String en;
    public String piso;
    public boolean live;
  

    libro(String nombre, String autor, String anio, String en, String es, String piso, String edi, String sede) {

        this.nombre = nombre;
        this.autor = autor;
        this.es = es;//
        this.sede = sede;//
        this.edi = edi;
        this.anio = anio;
        this.en = en;
        this.piso = piso;//
        this.live = true;
    }

    // Seccion getter para preguntar alguna caracteristica correspondiente

    public String getNombre() {
        return nombre;
    }

    public String getAutor() {
        return autor;
    }

    public String getEs() {
        return es;
    }

    public String getSede() {
        return sede;
    }

    public String getEdi() {
        return edi;
    }

    public String getAnio() {
        return anio;
    }

    public String getEn() {
        return en;
    }

    public String getPiso() {
        return piso;
    }

    public boolean getLive(){
      return live;
    }

    // Seccion setter para editar o asignar alguna caracteristica correspondiente

    public void setNombre(String nombre, boolean var) {
        if (var) this.nombre = "\""+nombre+"\"";
        else this.nombre = nombre;
    }
    
    public void setAutor(String autor) {
        this.autor = autor;
    }

    public void setEs(String es) {
        this.es = es;
    }

    public void setSede(String sede) {
        this.sede = sede;
    }

    public void setEdi(String edi) {
        this.edi = edi;
    }

    public void setAnio(String anio) {
        this.anio = anio;
    }

    public void setEn(String en) {
        this.en = en;
    }

    public void setPiso(String piso) {
        this.piso = piso;
    }

    public void borrar() {
        this.live = false;
    }

    public static libro[] newlibro(libro[] lista, int n, String nombre, String autor, String anio, String en, String es, String piso, String edi, String sede){
      
      lista = Arrays.copyOf(lista, n + 1);

      lista[n] = new libro(nombre, autor, anio, en, es, piso, edi, sede);
    
      return lista;
    }
}
