/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package slotmachine;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class SlotMachine {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int q = readInt();
        int s1 = readInt();
        int s2 = readInt();
        int s3 = readInt();
        int out =0;
        while(q!=0){
            q--;
            out++;
            s1++;
            if(s1==35){
                s1=0;
                q+=30;
            }
            if(q==0)break;
            q--;
            out++;
            s2++;
            if(s2==100){
                s2=0;
                q+=60;
            }
            if(q==0) break;
            q--;
            out++;
            s3++;
            if(s3==10){
                s3=0;
                q+=9;
            }
        }
        System.out.println("Martha plays "+out+" times before going broke.");
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
