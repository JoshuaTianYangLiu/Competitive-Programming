/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package veci;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Veci {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = readLine();
        int digit[] = new int[a.length()];
        for(int i=0; i<a.length(); i++){
            digit[i]=a.charAt(i)-'0';
        }
        int switchPos = findDecPos(digit);
        if(switchPos==-1){
            System.out.println(0);
        }else{
            int justLarger = switchPos+1;
            for(int i=switchPos+1; i<a.length(); i++){
                if(digit[i]<digit[justLarger]&&digit[i]>digit[switchPos]){
                    justLarger=i;
                }
            }
            int temp = digit[switchPos];
            digit[switchPos]=digit[justLarger];
            digit[justLarger]=temp;
            int digitPor[] = Arrays.copyOfRange(digit,switchPos+1,a.length());
            Arrays.sort(digitPor);
            String out = "";
            for(int i=0; i<=switchPos; i++){
                out+=digit[i];
            }
            for(int i=0; i<digitPor.length; i++){
                out+=digitPor[i];
            }
            System.out.println(out);
        }
    }
    static int findDecPos(int digit[]){
        for(int i = digit.length-2; i>=0; i--){
            if(digit[i]<digit[i+1]){
                return i;
            }
        }
        return -1;
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
