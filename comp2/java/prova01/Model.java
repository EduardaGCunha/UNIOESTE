package comp2.java.prova01;

import java.lang.reflect.Field;

public abstract class Model {
    public abstract Model getNewModel();

    public void set(String name, Object value) throws NoSuchFieldException, IllegalAccessException{
        Field field = this.getClass().getDeclaredField(name);
        field.setAccessible(true);
        field.set(this, value);
    }

    public Object get(String name) throws NoSuchFieldException, IllegalAccessException{
        Field field = this.getClass().getDeclaredField(name);
        field.setAccessible(true);
        return field.get(this);
    }

    public Field[] getAttributes() throws NoSuchFieldException{
        Field[] field = this.getClass().getDeclaredFields();
        return field;
    }

    public void show() throws NoSuchFieldException {
        Field[] field = getAttributes();
        for(Field i : field){
            System.out.println(i.getName());
        }
    }
}