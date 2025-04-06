import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.util.Base64;

import javax.crypto.Cipher;

public class RSA implements Encryptable {
    private final String RSA = "RSA";
    private KeyPair keyPair;
    public RSA() {
        try {
            KeyPairGenerator keyPairGen = KeyPairGenerator.getInstance(RSA);
            keyPairGen.initialize(2048);
            keyPair = keyPairGen.genKeyPair();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String encryptText(String encryptData) {
        try {
            Cipher cipher = Cipher.getInstance(RSA);
            // encryption using the public key of the reciver
            cipher.init(Cipher.ENCRYPT_MODE, keyPair.getPublic());
            byte[] encryptDataBytes = cipher.doFinal(encryptData.getBytes());
            return Base64.getEncoder().encodeToString(encryptDataBytes);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
    public String decryptText(String encryptedData) {
        try {
            Cipher cipher = Cipher.getInstance(RSA);
            // decryption using the private key of the reciever
            cipher.init(Cipher.DECRYPT_MODE, keyPair.getPrivate());
            byte[] encryptedBytes = Base64.getDecoder().decode(encryptedData);
            byte[] decrytedBytes = cipher.doFinal(encryptedBytes);
            return new String(decrytedBytes);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
