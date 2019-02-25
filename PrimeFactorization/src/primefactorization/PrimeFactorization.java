/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package primefactorization;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class PrimeFactorization {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        // TODO code application logic here
        //Too slow
        int size = readInt();
        for(int c=0; c<size; c++){
            String a = "";
            int b = readInt();
            int i=2;
            while(i<=Math.sqrt(b)||b==1){
                if(b%i==0){
                    a+=i+" ";
                    b/=i;
                }else{
                    i++;
                }
            }
            if(b!=1){
                a+=b+"";
            }
            System.out.println(a.trim());
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
