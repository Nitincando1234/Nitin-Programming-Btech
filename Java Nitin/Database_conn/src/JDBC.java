import java.sql.*;
import java.util.Scanner;
public class JDBC {
    private final static String url="jdbc:mysql://localhost:3306/mydb";
    private final static String username="root";
    private final static String passwd="123456";
    public static void main(String []args){
        Scanner in= new Scanner(System.in);
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("Connection Successful !");
        }
        catch (ClassNotFoundException e){
            e.printStackTrace();
        }
        try{
            Connection con= DriverManager.getConnection(url,username,passwd);
            Statement st=con.createStatement();
            String query="SELECT * FROM student;";
            ResultSet res= st.executeQuery(query);
            int column1=0;
            while(res.next()){
                column1=res.getInt("id");
                String column2=res.getString("name");
                String column3=res.getString("address");
                System.out.println(column1+"\t\t\t"+column2+"\t\t\t"+column3);
            }
            char choice;
            while(true){
            System.out.println("Want to insert new data: y) yes n) no");
            choice=in.next().charAt(0);
            if (choice=='y'){
                System.out.println("Enter the name of the student:");
                String name=in.next();
                System.out.println("Enter the address of the student:");
                String add=in.next();
                int rowAffected=st.executeUpdate(String.format("INSERT INTO student (id,name,address) VALUES (%d ,\"%s\", \"%s\")",column1+1,name,add));
                System.out.println("Row Affected: "+rowAffected);
                column1++;
            }
            else{
                break;
            }}
            //prepared statement
            while(true){
                System.out.println("Want to insert new data using the prepared statement: y) yes n) no");
                choice=in.next().charAt(0);
                if (choice=='y'){
                String queryPrepared="INSERT INTO student VALUES (?,?,?)";
                PreparedStatement pst= con.prepareStatement(queryPrepared);
                System.out.println("Enter the name of the student:");
                String name=in.next();
                System.out.println("Enter the address of the student:");
                String add=in.next();
                pst.setInt(1,++column1);
                pst.setString(2,name);
                pst.setString(3,add);
                pst.executeUpdate();
                }
                else{
                    break;
                }}
            //batch processing
            con.close();
        }catch (SQLException s){
            s.printStackTrace(); //for printing the tree of the error(Exceptions) generated !
        }
    }
}
