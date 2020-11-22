/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package genevaconfection;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class GenevaConfection {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        //last case is wrong
        int size = readInt();
        for(int i=0;i<size; i++){
            
            int cars = readInt();
            Stack<Integer> in = new Stack<Integer>();
            for(int j=cars-1;j>=0;j--){
                in.push(readInt());
            }
            
            if(ab(in, cars)){
                System.out.println("Y");
            }else System.out.println("N");
        }
    }
    static boolean ab(Stack<Integer> in, int cars){
        Stack<Integer> hold = new Stack<Integer>();
        int b = 1;
        int c[] = new int[cars];
        while(!in.empty()||!hold.empty()){
            if(!in.empty()&&in.peek()==b){
                in.pop();
                b++;
            }else if(!hold.empty()&&hold.peek()==b){
                hold.pop();
                b++;
            }else if(!in.empty()){
                hold.push(in.pop());
            }else return false;
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
