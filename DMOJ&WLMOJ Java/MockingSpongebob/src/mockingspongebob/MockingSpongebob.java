/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mockingspongebob;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class MockingSpongebob {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int a =readInt();
        for(int i=0; i<a; i++){
            mock(readLine());
        }
    }
    static void mock(String a){
        String b="";
        a=a.toLowerCase();
        boolean upCase = false;
        for(int i=0; i<a.length(); i++){
            if(a.charAt(i)<123&&a.charAt(i)>96){
                if(upCase){
                    b+=(char)(a.charAt(i)-32);
                }else{
                    b+=a.charAt(i);
                }
                upCase=!upCase;
            }else{
                b+=a.charAt(i);
            }
        }
        System.out.println(b);
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
