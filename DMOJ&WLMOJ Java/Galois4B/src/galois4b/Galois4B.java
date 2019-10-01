/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package galois4b;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Galois4B {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        System.out.println(isDigitBal(readInt()));
        int count=0;
        for(int i=1000; i<10000; i++){
            if(!isDigitBal(i)){
                count++;
                System.out.println(i);
            }
        }
        System.out.println(count);
    }
    static boolean isDigitBal(int a){
        int b=a;
        int num[] = new int[10];
        for(int i=0; i<4; i++){
            num[a%10]++;
            a/=10;
        }
        if(num[0]>0)return true;
        for(int i=0; i<10; i++){
            if(num[i]>i)return false;
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
