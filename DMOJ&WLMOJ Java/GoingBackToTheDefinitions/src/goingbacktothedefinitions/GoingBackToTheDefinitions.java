/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package goingbacktothedefinitions;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class GoingBackToTheDefinitions {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static class a implements Comparable<a>{
        String v;
        a(String b){
            v=b;
        }
        public int compareTo(a b){
            String c=v+b.v;
            String d=b.v+v;
            
            return Integer.compare(Integer.valueOf(c), Integer.valueOf(d));
        }
    }
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        List<a> l = new ArrayList<a>();
        for(int i=0; i<size; i++)l.add(new a(readLine()));
        Collections.sort(l);
        String out="";
        for(int i=size-1; i>=0; i--)out+=l.get(i).v;
        System.out.println(out);
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
