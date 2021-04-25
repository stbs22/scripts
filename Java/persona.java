class ctm {
  String nombre;
  String rut;
  public ctm(String nombre, String rut){
    this.nombre = nombre;
    this.rut = rut;
  }
  
  public String toString(){
    return this.rut+" "+this.nombre;
  }

  public boolean equals(Object p){
    if (this.rut.equals( ((ctm)p).rut ))
      return true;
    else 
      return false;
  }

}