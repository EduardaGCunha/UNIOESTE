package comp2.java.prova01;

public class Main {
    public static void main(String args[]){
        Ponto p = new Ponto();
        Ponto p1 = new Ponto(4, 3);
        p.show();
        p1.show();
        System.out.println(p1.dist(p));
        p1 = p.clone();
        p1.show();
    }
}
