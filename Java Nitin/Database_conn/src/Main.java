import java.sql.*;
import java.util.Scanner;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    private final static String url="jdbc:mysql://localhost:3306/student";
    private final static String userName="nitin";
    private final static String password="123456";
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        //batch processing
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, userName, password);
            //also can use Statement
            Statement st=con.createStatement();
            st.executeQuery("SELECT * FROM fee;");
            PreparedStatement pst= con.prepareStatement("INSERT INTO fee VALUES (?,?);");
            while (true){
                System.out.print("Enter the name of the student: ");
                String name=in.next();
                System.out.print("Enter the fee of the student: ");
                int fee=in.nextInt();
                pst.setString(1,name);
                pst.setInt(2,fee);
                pst.addBatch();
                System.out.println("Want to add more data: y/n");
                char choice=in.next().charAt(0);
                if(choice=='n')break;
            }
            int[] affectedRows=pst.executeBatch();//array of 1 and 0 ;1 for successful update ,0 for unsuccessful
            for (int i=0;i<affectedRows.length;i++){
                if(affectedRows[i]==0)
                    System.out.println("Query: "+i+" not excuted successfully !");
            }
//
        }
        catch(SQLException | ClassNotFoundException e){
            e.printStackTrace();
            System.out.println();
            System.out.println(e.getMessage());
        }
    }
}