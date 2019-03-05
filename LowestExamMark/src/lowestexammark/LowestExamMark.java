/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lowestexammark;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class LowestExamMark {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int curMark = readInt();
        int finalMark = readInt();
        int weight = readInt();
        double examW = weight/100.0;
        double markW = (100.0-weight)/100.0;
        if(passable(curMark,finalMark,examW,markW)==-1){
            System.out.println("DROP THE COURSE");
        }else{
            System.out.println(passable(curMark,finalMark,examW,markW));
        }
    }

    static int passable(int curMark, int finalMark, double examW,double markW){
        for(int i=0; i<=100; i++){
            if(Math.round(i*examW +markW*curMark)>=finalMark){
                return i;
            }
        }
        return -1;
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
