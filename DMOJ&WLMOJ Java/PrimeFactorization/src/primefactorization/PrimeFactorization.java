/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package primefactorization;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

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
            BigInteger b = new BigInteger(readLine());
            int i=2;
            while(b.sqrt().compareTo(BigInteger.valueOf(i))!=-1||b.equals(new BigInteger("1"))){
                if(b.remainder(BigInteger.valueOf(i)).equals(new BigInteger("0"))){
                    System.out.print(i+" ");
                    b=b.divide(BigInteger.valueOf(i));
                }else{
                    i++;
                }
            }
            if(!b.equals(new BigInteger("1"))){
                System.out.print(b+"");
            }
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
