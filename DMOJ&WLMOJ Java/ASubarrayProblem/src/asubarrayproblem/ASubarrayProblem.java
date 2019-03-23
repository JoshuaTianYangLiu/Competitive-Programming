/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package asubarrayproblem;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

/**
 *
 * @author Joshua
 */


public class ASubarrayProblem {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int a[] = new int[size];
        for(int i=0; i<size; i++){
            a[i]=readInt();
        }
        Stack<Integer> s = new Stack<Integer>();
        int b[] = new int[size];
        int b1[] = new int[size];
        for(int i=0; i<size; ++i){
            while(!s.isEmpty()&&a[i]<=a[s.peek()]) s.pop();
            if(s.isEmpty()) b[i]=-1;
            else b[i] = s.peek();
            s.push(i);
        }
        s=new Stack<Integer>();
        for(int i=size-1; i>=0; i--){
            while(!s.isEmpty()&&a[i]<a[s.peek()]) s.pop();
            if(s.isEmpty()) b1[i]=size;
            else b1[i]=s.peek();
            s.push(i);
        }
        long out=0;
        BigInteger o = new BigInteger("0");
        for(int i=0; i<size; ++i){
            o=o.add(BigInteger.valueOf((i-b[i])*(b1[i]-i)*a[i]));
        }
        System.out.println(o);
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
