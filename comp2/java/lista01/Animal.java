package comp2.java.lista01;

import java.util.ArrayList;

abstract class Animal implements Comparable<Animal> {
    protected String name;
    protected int age; 

    public Animal(String name, int age){
        if(name == null || name.isEmpty()){
            throw new IllegalArgumentException("The name cannot be null or empty.");
        }
        if (age < 0) {
            throw new IllegalArgumentException("The age must be a non-negative integer.");
        }
        this.name = name;
        this.age = age;
    }

    public String getName() {return name;}
    public int getAge() {return age;}

    public abstract void correr();
    public abstract void emitirSom();

    @Override
    public int compareTo(Animal outro){
        if(this.age > outro.age) return 1;
        if(this.age < outro.age) return -1;
        return 0;
    }

    @Override
    public String toString(){
        return "Nome: " + name + "\nIdade: " + age;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || getClass() != obj.getClass()) return false;
        Animal animal = (Animal) obj;
        if(animal.name == this.name) return true;
        return false;
    }
}

class Cachorro extends Animal {
    public Cachorro(String nome, int idade){
        super(nome, idade);
    }

    @Override
    public void emitirSom(){
        System.out.println("AU AU AU");
    }

    @Override
    public void correr(){
        System.out.println("Cachorro correndo!");
    }
}

class Cavalo extends Animal{
    public Cavalo(String name, int age){
        super(name, age);
    }

    @Override
    public void emitirSom(){
        System.out.println("IRRRINNN");
    }

    @Override
    public void correr(){
        System.out.println("Cavalo correndo");
    }
}

class Preguica extends Animal{
    public Preguica(String name, int age){
        super(name, age);
    }

    @Override
    public void emitirSom(){
        System.out.println("AAAAAAAHHHHHHHZZZZZZZ");
    }

    public void correr(){
        System.out.println("Preguica subindo em arquivos");
    }
}

class Zoologico{
    private ArrayList<Animal> animais;

    public Zoologico(){
        this.animais = new ArrayList<>();
    }

    public void add(Animal animal){
        animais.add(animal);
    }

    public void show(){
        for(Animal i : animais){
            System.out.println(i.toString());
            i.emitirSom();
            i.correr();
            System.out.println();
        }
    }

    public void sort(){
        for(int i = 0; i < animais.size(); i++){
            for(int j = 0; j < animais.size(); j++){
                if(animais.get(i).compareTo(animais.get(j)) < 0){
                    Animal temp = animais.get(i);
                    animais.set(i, animais.get(j));
                    animais.set(j, temp);
                }
            }
        }

    }

    public int find(Animal animal){
        for(int i = 0; i < animais.size(); i++){
            if(animais.get(i).equals(animal)){
                System.out.println("Achou no indice " + i);
                return i;
            }
        }
        System.out.println("Nao achou :(");
        return -1;
    }
    
}
