/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rovarspraket;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 *
 * @author liuti
 */
public class Rovarspraket {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String word = in.readLine();
        int vowels[] = {97,101,105,111,117,128};
        String out = "";
        for(int i =0; i<word.length(); i++){
            out+=word.charAt(i);
            if(!isVowel(word.charAt(i))){
                for(int j=5; j>=0; j--){
                    if((int) word.charAt(i)>vowels[j]){
                        if(Math.abs(vowels[j]-(int) word.charAt(i))<=vowels[j+1]-(int) word.charAt(i)){
                            out+=(char)vowels[j];
                            break;
                        }else{
                            out+=(char)vowels[j+1];
                            break;
                        }
                    }
                }
                for(int j=0; j<5; j++){
                    if(word.charAt(i)=='z'){
                        out+="z";
                        break;
                    }else{
                        if(isVowel((char)((int)word.charAt(i)+1))){
                            out+=(char)((int)word.charAt(i)+2);
                            break;
                        }else{
                            out+=(char)((int)word.charAt(i)+1);
                            break;
                        }
                    }
                }
            }
        }
        System.out.println(out);
    }
    static boolean isVowel(char a){
        int vowels[] = {97,101,105,111,117};
        for(int i=0; i<5; i++){
            if((int)a==vowels[i]) return true;
        }
        return false;
    }
    
}
