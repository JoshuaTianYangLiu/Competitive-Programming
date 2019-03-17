/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package snowcalls;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class SnowCalls {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        
        for(int i=0; i<size; i++){
            String a = readLine().replaceAll("[-]", "");
            String out = "";
            a = a.substring(0, 10);
            for(int j=0; j<10; j++){
                char b = a.charAt(j);
                if(b>64){
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
                }
                out+=b;
            }
            out=out.substring(0, 3)+"-"+out.substring(3,6)+"-"+out.substring(6, 10);
            System.out.println(out);
            
        }
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
