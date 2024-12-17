package comp2.java.lista01;
public class App {
    public static void main(String [] args){
        Cachorro cachorro = new Cachorro("Sarah", 3);
        Cavalo cavalo = new Cavalo("Dora", 5);
        Preguica preguica = new Preguica("Dudu", 100);
        Preguica preg = new Preguica("Dudu2", 9);
        Zoologico zoo = new Zoologico();
        zoo.add(cavalo);
        zoo.add(preguica);
        zoo.add(cachorro);
        zoo.show();
        zoo.sort();
        zoo.show();
        zoo.find(preguica);
        zoo.find(cavalo);
        zoo.find(cachorro);
        zoo.find(preg);

    }
}