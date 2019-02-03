/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tudorbuysevenmoretea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

/**
 *
 * @author liuti
 */
public class TudorBuysEvenMoreTea {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input;
        String base = "";
        String have = "";
        int result=0;
         
        int pos=0;
        try{
            input = new BufferedReader(new InputStreamReader(System.in));
            base = input.readLine();
            have = input.readLine();
        }catch(IOException e){}
        StringBuilder sb = new StringBuilder(have);
        int length = base.length();
        char[] base1 = base.toCharArray();
        for(int i = 0; i<length; i++){
            pos = sb.indexOf(Character.toString(base1[i]));
            
            if (pos>=0)
            {
                sb.setCharAt(pos, ' ');
            }
            else
            {
                result++;
            }
        }
        System.out.println(result);
    }
}
//    public static void main(String[] args) {
//        // TODO code application logic here
//        BufferedReader input;
//        String base = "";
//        String have = "";
//        String base1 = "";
//        try{
//            input = new BufferedReader(new InputStreamReader(System.in));
//            base = input.readLine();
//            have = input.readLine();
//        }catch(IOException e){}
//        int length = base.length();
//        int location = -1;
//        for(int i = 0; i<length; i++){
//            location = have.indexOf(Character.toString(base.charAt(i)));
//            if (location >= 0 )
//            {
//                if (location ==0)
//                    have= have.substring(location+1);
//                else
//                    have= have.substring(0,location) + have.substring(location+1);
//            }
//            else
//            {
//                base1 += Character.toString(base.charAt(i));
//            }
//        }
//        System.out.println(base1.length());
//    }
//    
//}
