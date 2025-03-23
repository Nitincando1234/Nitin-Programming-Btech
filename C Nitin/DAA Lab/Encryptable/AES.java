import java.util.Base64;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

public class AES implements Encryptable{
    private String AES = "AES";
    private SecretKey secretKey;
    
    public AES() {
        try {
            KeyGenerator keyGen = KeyGenerator.getInstance(AES);
            keyGen.init(128);
            secretKey = keyGen.generateKey();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public String encryptText(String encryptData) {
        try {
            Cipher cipher = Cipher.getInstance(AES);
            cipher.init(Cipher.ENCRYPT_MODE, secretKey);
            byte[] encryptedString = cipher.doFinal(encryptData.getBytes());
            return Base64.getEncoder().encodeToString(encryptedString);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public String decryptText(String encryptedData) {
        try {
            Cipher cipher = Cipher.getInstance(AES);
            cipher.init(Cipher.DECRYPT_MODE, secretKey);
            byte[] encryptedBytes = Base64.getDecoder().decode(encryptedData);
            byte[] decrytedBytes = cipher.doFinal(encryptedBytes);
            return new String(decrytedBytes);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
