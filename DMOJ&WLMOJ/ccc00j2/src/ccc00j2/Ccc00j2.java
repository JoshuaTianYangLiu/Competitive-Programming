/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package ccc00j2;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


//For questions "9966"
public class Ccc00j2 {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int start = readInt();
        int end = readInt();
        int total =0;
        for(int i = start; i<=end; i++){
            String a = Integer.toString(i);
            if(a(a)){
                total++;
            }
        }
        System.out.println(total);
    }
    static boolean a(String a){
    for(int j=0; j<a.length(); j++){

            if((a.charAt(j)=='8'&&a.charAt(a.length()-j-1)=='8')||(a.charAt(j)=='0'&&a.charAt(a.length()-j-1)=='0')||(a.charAt(j)=='1'&&a.charAt(a.length()-j-1)=='1')||(a.charAt(j)=='9'&&a.charAt(a.length()-j-1)=='6')||(a.charAt(j)=='6'&&a.charAt(a.length()-j-1)=='9')){

            }else{
                return false;
            }

        }
    return true;
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
