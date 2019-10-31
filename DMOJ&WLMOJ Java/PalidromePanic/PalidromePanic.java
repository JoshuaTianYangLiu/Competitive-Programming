/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package palidromepanic;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class PalidromePanic {
    public static class Manacher {
    private int[]  p;
    private String s;
    private char[] t;
    public Manacher(String s) {
        this.s = s;
        preprocess();
        p = new int[t.length];
        int center = 0, right = 0;
        for (int i = 1; i < t.length-1; i++) {
            int mirror = 2*center - i;
            if (right > i)
                p[i] = Math.min(right - i, p[mirror]);
            while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
                p[i]++;
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
    }
    private void preprocess() {
        t = new char[s.length()*2 + 3];
        t[0] = '$';
        t[s.length()*2 + 2] = '@';
        for (int i = 0; i < s.length(); i++) {
            t[2*i + 1] = '#';
            t[2*i + 2] = s.charAt(i);
        }
        t[s.length()*2 + 1] = '#';
    }
    public String longestPalindromicSubstring() {
        int length = 0;   
        int center = 0;   
        for (int i = 1; i < p.length-1; i++) {
            if (p[i] > length) {
                length = p[i];
                center = i;
            }
        }
        return s.substring((center - 1 - length) / 2, (center - 1 + length) / 2);
    }
    // test client
//    public static void main(String[] args) {
//        String s = args[0];
//        Manacher manacher = new Manacher(s);
//        System.out.println(manacher.longestPalindromicSubstring());
//        for (int i = 0; i < 2*s.length(); i++)
//            StdOut.println(i +  ": " + manacher.longestPalindromicSubstring(i));
//         
//    }
}
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        for(int i=0; i<10; i++){
            String a = readLine();
            Manacher m = new Manacher(a);
            
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
