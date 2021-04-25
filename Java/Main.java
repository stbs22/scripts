import java.util.Vector;

class Main {
  public static void main(String[] args) {
    Vector v = new Vector();

    ctm p1= new ctm("john","1-9");
    ctm p2= new ctm("Luis","2-7");
    ctm p3= new ctm("Diego","3-6");
    
    v.add(p1);
    v.add(p2);
    v.add(p3);

    ctm p4= new ctm("elctm","2-2");

    System.out.println(v);
    System.out.println(v.contains(p4));

    Vector v2 = new Vector();
    v2.add("Juan");
    v2.add("Luis");
    v2.add("Diego");
    System.out.println(v2.contains("Juan"));
    v.add(p4);

    System.out.println(v);
    System.out.println(v.lastElement());
  }
}