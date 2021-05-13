public class libro {
    public String autor;
    public String nombre;
    public String es;
    public String sede;
    public String edi;
    public String anio;
    public String en;
    public String piso;
  

    libro(String nombre, String autor, String es, String sede, String edi, String anio, String en, String piso) {
        this.nombre = nombre;
        this.autor = autor;
        this.es = es;
        this.sede = sede;
        this.edi = edi;
        this.anio = anio;
        this.en = en;
        this.piso = piso; 
    }

    // Seccion para preguntar alguna caracteristica correspondiente

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

    // Seccion para editar o asignar alguna caracteristica correspondiente

    public void setNombre(String nombre) {
        this.nombre = nombre;
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
}
