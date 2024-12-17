package comp2.java.prova01;

public class Ponto {
    protected double x;
    protected double y;

    public Ponto(){
        this.x = 0.0;
        this.y = 0.0;
    }

    public Ponto(double x, double y){
        this.x = x;
        this.y = y;
    }

    public Ponto(Ponto p){
        this.x = p.x;
        this.y = p.y;
    }

    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }
    
    public void setX(double x){
    	this.x = x;
    }
    
    public void setY(double y){
    	this.y = y;
    }
    
    public void move(){
        this.x += 0;
        this.y += 0;
    }
    
    public void move(double x, double y){
    	this.x = x;
    	this.y = y;
    }
    
    public void move(Ponto p){
    	this.x = p.x;
    	this.y = p.y;
    }
    
    @Override
    public boolean equals(Object p){
    	if(this == p) return true;
    	return false;
    }
    
    public void show(){
    	System.out.println("Coordenada x: " + this.x + " coordenada y: " + this.y);
    }
    
    public double dist(Ponto p){
    	double z = (p.x - this.x)*(p.x - this.x) + (p.y - this.y)*(p.y - this.y);
    	return z;
    }

    public Ponto clone(){
        return new Ponto(this.x, this.y);
    }
    
}
