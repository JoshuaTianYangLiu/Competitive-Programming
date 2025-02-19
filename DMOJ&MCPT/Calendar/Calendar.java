/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package calendar;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class Calendar {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int start = readInt();
        int days = readInt();
        System.out.println("Sun Mon Tue Wed Thr Fri Sat");
        String a = "";
        for(int i=1; i<start; i++){
            a+="    ";
        }
        for(int i = 1; i<Math.min(10, days+1); i++){
            a+="  "+i+" ";
            if(a.length()==28){
                System.out.println(a.substring(0, 27));
                a="";
            }
        }
        for(int i=10; i<days+1; i++){
            a+=" "+i+" ";
            if(a.length()==28){
                System.out.println(a.substring(0,Math.min(27, a.length())));
                a="";
            }
        }
        if(a.length()>0){
            System.out.println(a.substring(0,Math.min(27, a.length()-1)));
        }
        System.out.println();
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
