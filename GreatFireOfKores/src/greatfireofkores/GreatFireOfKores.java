/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package greatfireofkores;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class GreatFireOfKores {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int size = readInt();
        int x[] = new int[size];
        int y[] = new int[size];
        
        int total =0;
        for(int i=0; i<size; i++){
            x[i]= readInt();
            y[i]= readInt();
        }
        int find = readInt();
        int x1[] = new int[find];
        int y1[] = new int[find];
        for(int i=0; i<find; i++){
            x1[i]= readInt();
            y1[i]= readInt();
        }
        int best=0;
        for(int i=0; i<size;i++){
            for(int j=0; j<find; j++){
                if((x[i]-x1[j])*(x[i]-x1[j])+(y[i]-y1[j])*(y[i]-y1[j])<(x[i]-x1[best])*(x[i]-x1[best])+(y[i]-y1[best])*(y[i]-y1[best])){
                    best = j;
                }
            }
            total+= Math.abs(x[i]-x1[best]);
            total+= Math.abs(y[i]-y1[best]);
            best=0;
        }
        System.out.println(total);
        
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
