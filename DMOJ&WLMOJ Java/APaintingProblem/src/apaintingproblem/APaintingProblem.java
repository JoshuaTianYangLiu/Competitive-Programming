/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package apaintingproblem;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class APaintingProblem {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = Integer.toBinaryString(readInt());
        String b = Integer.toBinaryString(readInt());
        int c = readInt();
        int blue =0;
        int purple = 0;
        for(int i=0; i<c; i++){
            if(contains(a,i)&&contains(b,i)){
                if(a.charAt(a.length()-1-i)==b.charAt(b.length()-1-i)){
                    purple++;
                }else{
                    blue++;
                }
            }else if(contains(a,i)){
                    if(a.charAt(a.length()-i-1)=='1'){
                        blue++;
                    }else{
                        purple++;
                    }
            }else if(contains(b,i)){
                if(b.charAt(b.length()-1-i)=='1'){
                    blue++;
                }else{
                    purple++;
                }
            }else{
                purple++;
            }
        }
        System.out.println(blue+" "+purple);
    }
    static boolean contains(String in, int pos){
        try{
            in.charAt(in.length()-1-pos);
            return true;
        }catch(Exception e){
            return false;
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
