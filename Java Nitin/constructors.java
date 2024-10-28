class Level{
    int level;
    public Level(){
        System.out.println("Default Constructor is initialized !");
    }
    public Level(int x){
        level=x;
        System.out.println("Param. Constructor is initialized !");
    }
    public Level(Level x){
        level=x.level;
        System.out.println("Copy Constructor is initialized !");
    }
    void show(){
        System.out.println("Level: "+level);
    }
}
public class constructors {
    public static void main(String []args){
        Level l1=new Level();
        Level l2=new Level(2);
        Level l3=new Level(l2);
        l1.show();
        l2.show();
        l3.show();
    }
}
