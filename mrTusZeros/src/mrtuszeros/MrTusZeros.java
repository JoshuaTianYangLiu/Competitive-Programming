/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mrtuszeros;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class MrTusZeros {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int numOfTwo =0;
        int numOfFive =0;
        int a =0;
        for(int i=0; i<size; i++){
            a = readInt();
            if(a==0){
                System.out.println(1);
                System.exit(0);
            }
            numOfTwo += numOfFactor(a,2);
            numOfFive += numOfFactor(a,5);
            
        }
        System.out.println(Math.min(numOfTwo,numOfFive));
    }

    static int numOfFactor(int in,int factor){
        int num =0;
        while(in%factor==0){
            in/=factor;
            num++;
        }
        return num;
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
