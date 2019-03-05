/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package flipper;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Flipper {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int num [][] = new int [2][2];
        num[0][0]=1;
        num[0][1]=2;
        num[1][0]=3;
        num[1][1]=4;
        String a = readLine();
        boolean b[] = new boolean[2];
        for(int i=0; i<a.length(); i++){
            if(a.charAt(i)=='V'){
                b[0]=!b[0];
            }else{
                b[1]=!b[1];
            }
        }
        //vertical
        if(b[0]){
            for(int i=0; i<2; i++){
                int c =0;
                c=num[i][0];
                num[i][0]=num[i][1];
                num[i][1]=c;
            }
        }
        if(b[1]){
            for(int i=0; i<2; i++){
                int c =0;
                c=num[0][i];
                num[0][i]=num[1][i];
                num[1][i]=c;
            }
        }
        System.out.println(num[0][0]+" "+num[0][1]);
        System.out.println(num[1][0]+" "+num[1][1]);
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
