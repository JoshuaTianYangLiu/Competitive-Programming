/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cellphonemessaging;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class CellPhoneMessaging {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String in = readLine();
        while(!in.equals("halt")){
            int total =0;
            int size = in.length();
            for(int i=0; i<size; i++){
                if(in.charAt(i)<112){
                    total+=(in.charAt(i)-97)%3+1;
                }else if(in.charAt(i)<116){
                    total+=(in.charAt(i)-111);
                }else if(in.charAt(i)<119){
                    total+=(in.charAt(i)-115);
                }else if(in.charAt(i)<123){
                    total+=(in.charAt(i)-118);
                }
                if(i>0&&num((char)(in.charAt(i)-32))==num((char)(in.charAt(i-1)-32))){
                    total+=2;
                }
            }
            System.out.println(total);
            in =readLine();
        }
    }
    static int num(char b){
        if(b<68){
            b='2';
        }else if(b<71){
            b='3';
        }else if(b<74){
            b='4';
        }else if(b<77){
            b='5';
        }else if(b<80){
            b='6';
        }else if(b<84){
            b='7';
        }else if(b<87){
            b='8';
        }else if(b<91){
            b='9';
        }
        return b;
    }

    static String next () throws IOException {
        if (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
         return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
         return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
          return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}
