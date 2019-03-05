/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package nextsemiprime;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class NextSemiPrime {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i=0; i<size; i++){
            int a = readInt()+1;
            semiprime(a);
//            while(!semiPrime(a)){
//                a++;
//            }
//            System.out.println(a);
        }
    }
    static int checkSemiprime(int num){ 
        int cnt = 0; 
      
        for (int i = 2; cnt < 2 && i * i <= num; ++i){
                       
            while (num % i == 0){ 
                num /= i; 
                ++cnt; 
                } 
        }
        if (num > 1) ++cnt; 
        return cnt == 2 ? 1 : 0; 
    }
    static void semiprime(int n){ 
        if (checkSemiprime(n) != 0) System.out.printf("True\n"); 
        else System.out.printf("False\n"); 
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
