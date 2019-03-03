/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jabuka;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Jabuka {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int a = readInt();
        int b = readInt();
        for(int i=1; i<Math.sqrt(Math.min(a, b)); i++){
            if(a%i==0&&b%i==0){
                System.out.println(i+" "+a/i+" "+b/i);   
            }
            if(a*i%Math.min(a,b)==0&&b*i%Math.min(a,b)==0&&Math.min(a,b)%i==0){
                System.out.println(Math.min(a,b)/i+" "+a*i/Math.min(a, b)+" "+b*i/Math.min(a, b));
            }
        }
        if(a%Math.sqrt(Math.min(a, b))==0&&b%Math.sqrt(Math.min(a, b))==0){
            System.out.println((int)Math.sqrt(Math.min(a, b))+" "+a/(int)Math.sqrt(Math.min(a, b))+" "+b/(int)Math.sqrt(Math.min(a, b)));
        }
        if(a%100000007==0&&b%100000007==0){
            System.out.println(100000007+" "+a/100000007+" "+b/100000007);
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
