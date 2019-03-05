/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hsiung;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Hsiung {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int x = readInt();
        int y = readInt();
        int total = readInt();
        int xRange = (int) Math.ceil(total/x);
        int yRange = (int) Math.ceil(total/y);
        System.out.println(pos(x,y,xRange,yRange,total));
        
    }
    static int pos(int x, int y, int xRange, int yRange, int total){
        int max =0;
        for(int i=0; i<=xRange; i++){
            for(int j=0; j<=yRange; j++){
                if(x*i+y*j>max&&x*i+y*j<=total) max = x*i+j*y;
                if(max ==total) return max;
            }
        }
        return max;
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
