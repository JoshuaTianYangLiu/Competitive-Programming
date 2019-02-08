/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package attackoftheciphers;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 *
 * @author Joshua
 */
public class AttackOfTheCiphers {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input;
        String plain = null;
        String coded = null;
        String cipher = null;
        char[] cipherList = new char[27];
        try{
            input = new BufferedReader(new InputStreamReader(System.in));
            plain = input.readLine();
            coded = input.readLine();
            cipher = input.readLine();
        }catch(Exception e){}
        for(int i = 0; i<26; i++){
            try{   
                cipherList[i]=plain.charAt(coded.indexOf((char)(i+65)));
            }catch(Exception e){
                cipherList[i]='.';
            }
        }
        try{
            cipherList[26]=plain.charAt(coded.indexOf(" "));
        }catch(Exception e){
            cipherList[26]='.';
        }            
        String finalCipher="";
        int pos;
        for(int i = 0; i<cipher.length();i++){
            try{
                pos=(int)cipher.charAt(i);
                if (pos == 32 ){
                    finalCipher+=cipherList[26];
                }else{
                    finalCipher+=cipherList[pos-65];
                }
            }catch(Exception e){}
        }
        System.out.println(finalCipher);
    }
}
