package comp2.java.prova01;

public class Circulo extends Ponto implements Comparable<Circulo>{
    private double r;

    public Circulo (Ponto other, double nr){
        super(other);
        this.r = nr;
    }
    public Circulo (double raio){
        super();
        this.r = raio;
    }
    public double getRaio(){
        return this.r;
    }

    public void inflar(double aumento){
        this.r += aumento;
    }
    public void desinflar(double diminuir){
        this.r -= diminuir;
    }
    public double getArea(){
        return (3.14 * this.r * this.r);
    }

    @Override
    public int compareTo(Circulo other){
        Circulo o = (Circulo) other;
        double area = o.getArea();
        double area2 = this.getArea();
        if (area < area2) return -1;
        if (area == area2) return 0;
        return 1;
    }
    // @Override
    // public void show(){
    //     super.show();
    //     System.out.println(this.r);
    // }
    // @Override
    // public circulo clonar(){
    //     return new circulo(raio, this);
    // }

}