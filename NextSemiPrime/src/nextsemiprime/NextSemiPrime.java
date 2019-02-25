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
            while(!isSemiPrime(a)){
                a++;
            }
            System.out.println(a);
        }
    }
    static boolean isSemiPrime(int b){
        String a = "";
        int i=2;
        int counter = 0;
        while(i<=Math.sqrt(b)||b==1){
            if(b%i==0){
                a+=i+" ";
                b/=i;
                counter++;
            }else{
                i++;
            }
            if(counter>2){
                return false;
            }
        }
        if(b!=1){
            counter++;
        }
        if(counter==2){
        return true;
        }
        return false;
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
