/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pkg00272;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = br.readLine();
        boolean alt = true;
        while(a!=null){
            String out ="";
            for(int i=0; i<a.length(); i++){
                if(a.charAt(i)=='"'){
                    if(alt) out+="``";
                    else out+="''";
                    alt=!alt;
                }else{
                    out+=a.charAt(i);
                }
            }
            System.out.println(out);
            a=br.readLine();
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
