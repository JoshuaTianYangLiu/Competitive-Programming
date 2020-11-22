/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package addupapples;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class AddUpApples {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int total;
    static int count=0;
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int in = readInt();
        total=in;
        a(in,in+"=",0);
        System.out.println("total="+count);
    }
    static void a(int in,String c,int b){
        if(in==0){
            System.out.println(c.subSequence(0, c.length()-1));
            count++;
        }
        for(int i=Math.max(1, b); i<(total==in?total:in+1); i++){
            a(in-i,c+""+i+"+",i);
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
