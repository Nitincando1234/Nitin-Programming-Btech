class Level{
    int level;
    public Level(int x){
        level=x;
    }
}
class Height extends Level{
    int height;
    public Height(int z,int x){
        super(z);
        height=x;
    }
    public void show(){
        System.out.println("Level: "+level+"\n"+"Height: "+height);
    }
}
public class inheritance {
    public static void main(String []args){
    Height h= new Height(2, 3);
    h.show();}
}
