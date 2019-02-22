/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package amusementanticipation;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class AmusementAnticipation {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        for(int i=0;i<531;i++){
            int a = readInt();
            int counter =0;
            int diff =0;
            int b = readInt();
            for(int j=1; j<a; j++){
                int c =readInt();
                if(diff==c-b){
                    counter++;
                }else{
                    diff=c-b;
                    counter=1;
                }
                b=c;
            }
            System.out.println(a-counter);
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
