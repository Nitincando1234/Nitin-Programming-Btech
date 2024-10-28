import java.sql.*;
import java.util.Scanner;

public class Transaction {
    private final static String url="jdbc:mysql://localhost:3306/transactions";
    private final static String userName="nitin";
    private final static String password="123456";
    public static void main(String[] args){
        Scanner in =new Scanner(System.in);
        //batch processing
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, userName, password);
            con.setAutoCommit(false);
            //also can use Statement
            Statement st=con.createStatement();
            int curramtdebit=0,curramtcredit=0;
            System.out.println("Enter the amount to trxfr from one a.c to another:");
            int amount=in.nextInt();
            Statement stN= con.createStatement();
            ResultSet res=stN.executeQuery("SELECT amount FROM account WHERE id=1;");
            if(res.next()){
            curramtdebit=res.getInt("amount");
            System.out.println(curramtdebit);}
            res=stN.executeQuery("SELECT amount FROM account WHERE id=2;");
            if(res.next()){
            curramtcredit=res.getInt("amount");
            System.out.println(curramtcredit);}
            PreparedStatement ps1=con.prepareStatement("UPDATE account SET amount=? WHERE id=?;");
            PreparedStatement ps2=con.prepareStatement("UPDATE account SET amount=? WHERE id=?;");
            if(curramtdebit-amount!=0 && curramtdebit>amount){
                System.out.println(amount+" credited successfully !");
                ps1.setInt(1,curramtdebit-amount);
                ps2.setInt(1,curramtcredit+amount);
                ps1.setInt(2,1);
                ps2.setInt(2,2);
                ps1.executeUpdate();
                ps2.executeUpdate();
                con.commit();
            }
            else{
                System.out.println("Transaction failed !\nAmount Is Exceeded the balance in your a.c !!!");
                con.rollback();
            }

        }
        catch (SQLException | ClassNotFoundException e){
            e.printStackTrace();
        }
    }
}
