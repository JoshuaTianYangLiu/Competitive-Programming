/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package prettyaverageprime;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class PrettyAveragePrime {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int cases = readInt();
        for(int i=0;i<cases;i++){
            int sum = 2*readInt();
            for(int j=2;j<sum; j++){
                if(isPrime(j)&&isPrime(sum-j)){
                    System.out.println(Integer.toString(j)+" "+Integer.toString(sum-j));
                    break;
                }
            }
        }
    }

    static boolean isPrime(int in){
        for(int i=2; i<=Math.sqrt(in); i++){
            if(in%i==0){
                return false;
            }
        }
        return true;
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
