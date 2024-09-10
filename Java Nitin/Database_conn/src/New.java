import java.sql.*;
public class New {
    private static final String user = "root";
    private static final String passwd = "123456";
    private static final String url = "jdbc:mysql://localhost:3306/test";

    public static void main(String [] argString){
       try {
           Class.forName("com.mysql.cj.jdbc.Driver");
           Connection connection = DriverManager.getConnection(url,user,passwd);
           Statement statement = connection.createStatement();
           ResultSet res = statement.executeQuery("SELECT * FROM students;");
           while (res.next()){
               System.out.println(res.getInt("rollno")+"\t\t\t"+res.getString("name")+"\t\t\t"+res.getString("address")+"\t\t\t"+res.getLong("phone")+"\t\t\t"+res.getInt("age"));
           }
       }
       catch (ClassNotFoundException | SQLException e){
           System.out.println(e.getMessage());
       }
    }
}
