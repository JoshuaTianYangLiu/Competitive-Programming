/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pkg0123456789;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int a = readInt();
        switch(a){
            case 0:
                top();
                midTopLR();
                l();
                midTopLR();
                top();
                break;
            case 1:
                midTopR();
                l();
                midTopR();
                break;
            case 2:
                top();
                midTopR();
                top();
                midTopL();
                top();
                break;
            case 3:
                top();
                midTopR();
                top();
                midTopR();
                top();
                break;
            case 4:
                midTopLR();
                top();
                midTopR();
                break;
            case 5:
                top();
                midTopL();
                top();
                midTopR();
                top();
                break;
            case 6:
                top();
                midTopL();
                top();
                midTopLR();
                top();
                break;
            case 7:
                top();
                midTopR();
                l();
                midTopR();
                break;
            case 8:
                top();
                midTopLR();
                top();
                midTopLR();
                top();
                break;
            case 9:
                top();
                midTopLR();
                top();
                midTopR();
                top();
                break;
        }
    }
    static void l(){
        System.out.println();
    }
    static void top(){
        System.out.println(" * * *");
    }
    static void midTopL(){
        System.out.println("*");
        System.out.println("*");
        System.out.println("*");
    }
    static void midTopR(){
        System.out.println("      *");
        System.out.println("      *");
        System.out.println("      *");
    }
    static void midTopLR(){
        System.out.println("*     *");
        System.out.println("*     *");
        System.out.println("*     *");
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
