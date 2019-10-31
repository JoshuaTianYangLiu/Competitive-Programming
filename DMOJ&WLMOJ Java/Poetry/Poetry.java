/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package poetry;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Poetry {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i=0 ;i<size; i++){
            String a = rhyme(readLastWord());
            String b = rhyme(readLastWord());
            String c = rhyme(readLastWord());
            String d = rhyme(readLastWord());
            if(a.toLowerCase().equals(b.toLowerCase())&&a.toLowerCase().equals(c.toLowerCase())&&a.toLowerCase().equals(d.toLowerCase()))System.out.println("perfect");
            else if(a.toLowerCase().equals(b.toLowerCase())&&c.toLowerCase().equals(d.toLowerCase())) System.out.println("even");
            else if(a.toLowerCase().equals(c.toLowerCase())&&b.toLowerCase().equals(d.toLowerCase())) System.out.println("cross");
            else if(a.toLowerCase().equals(d.toLowerCase())&&b.toLowerCase().equals(c.toLowerCase())) System.out.println("shell");
            else System.out.println("free");
            
        }
    }
    static String rhyme(String in){
        char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
        for(int j=in.length()-1; j>=0; j--){
            for(int i=0; i<10; i++){
                if(in.charAt(j)==vowels[i]){
                    return in.substring(j, in.length());
                }
            }
        }
        return in;
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
    
    static String readLastWord() throws IOException {
        st = new StringTokenizer(br.readLine());
        int a = st.countTokens();
        for(int i=1; i<a; i++){
            st.nextToken();
        }
        return st.nextToken();
    }
}
