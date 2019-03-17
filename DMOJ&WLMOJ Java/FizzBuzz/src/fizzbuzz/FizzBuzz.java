/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package fizzbuzz;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class FizzBuzz {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size= readInt();
        for(int i=1;i<=size; i++){
            if(i%3==0||i%5==0){
                String a = "";
                if(i%3==0){
                    a+="fizz";
                }
                if(i%5==0){
                    a+="buzz";
                }
                System.out.println(a);
            }else{
                System.out.println(i);
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
