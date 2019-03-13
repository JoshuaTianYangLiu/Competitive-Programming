/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package bananas;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Bananas {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a= readLine();
        while(!a.equals("X")){
            if(isMonkey(a)){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
            a=readLine();
        }
    }
    static boolean isMonkey(String monkey){
        if(isA(monkey)){
            return true;
        }else{
            for(int i=0; i<monkey.length(); i++){
                if(monkey.charAt(i)=='N'){
                    if(isA(monkey.substring(0,i))&&isMonkey(monkey.substring(i+1, monkey.length()))){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    static boolean isA(String a){
        if(a.equals("A")){
            return true;
        }else if(a.length()>2&&a.charAt(0)=='B'&&isMonkey(a.substring(1, a.length()-1))&&a.charAt(a.length()-1)=='S'){
            return true;
        }else{
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
