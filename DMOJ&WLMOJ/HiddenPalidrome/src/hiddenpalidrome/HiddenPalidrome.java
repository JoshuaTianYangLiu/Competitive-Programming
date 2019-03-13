/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hiddenpalidrome;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class HiddenPalidrome {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        String a = next();
        int total =0;
        for(int i =0; i<a.length();i++){
            for(int j=i+1; j<=a.length(); j++){
                if(isPalindrome(a.substring(i, j))&&total<j-i){
                    total = j-i;
                }
            }
        }
        System.out.println(total);
    }
    static boolean isPalindrome(String s) {
    int n = s.length();
        for (int i = 0; i < (n/2); ++i) {
                if (s.charAt(i) != s.charAt(n - i - 1)) {
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
