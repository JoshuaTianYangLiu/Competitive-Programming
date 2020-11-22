import java.io.*;
import java.util.*;

public class Unicode {
    public static void main(String[] args) throws Exception {
        Random r = new Random();
        while(true){
            int bits = Float.floatToIntBits(-1*r.nextFloat());
            int charA = bits&0xFFFF;
            int charB = (bits>>16)&0xFFFF;
            String out = Character.toString((char)charB)+Character.toString((char)charA);
            // System.out.println(out);
            System.out.println(charA+" "+charB);
            System.out.println(Integer.toBinaryString(charA)+" "+Integer.toBinaryString(charB));
            String unicodeMessage = "\u4e16\u754c\u4f60\u597d\uff01";
            // System.out.println(unicodeMessage);
        }
    }
}