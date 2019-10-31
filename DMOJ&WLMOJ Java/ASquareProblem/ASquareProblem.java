/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package asquareproblem;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class ASquareProblem {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int size = readInt();
        int hold [][]=new int[size][size];
        for(int i =0; i<size; i++){
            String a = readLine();
            for(int j=0; j<size; j++){
                if(a.charAt(j)>64){
                    hold[i][j]=a.charAt(j)-55;
                }else{
                    hold[i][j]=Integer.parseInt(String.valueOf(a.charAt(j)));
                }
            }
        }
        boolean xInc = xIncrease(hold, size);
        boolean yInc = yIncrease(hold, size);
        boolean latin = isLatin(hold,size);
        if(!latin){
            System.out.println("No");
        }else if(xInc&&yInc){
            System.out.println("Reduced");
        }else{
            System.out.println("Latin");
        }
    }
    static boolean isLatin(int hold[][],int size){
        for(int i=0; i<size; i++){
            boolean numbers[] = new boolean[36];
            for(int j=0; j<size; j++){
                if(!numbers[hold[i][j]]){
                    numbers[hold[i][j]]=true;
                }else{
                    return false;
                }
            }
        }
        for(int i=0; i<size; i++){
            boolean numbers[] = new boolean[36];
            for(int j=0; j<size; j++){
                if(!numbers[hold[j][i]]){
                    numbers[hold[j][i]]=true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    static boolean xIncrease(int hold[][],int size){
        for(int i=1; i<size;i++){
            if(hold[0][i-1]>hold[0][i]){
                return false;
            }
        }
        return true;
    }
    static boolean yIncrease(int hold[][],int size){
        for(int i=1; i<size;i++){
            if(hold[i-1][0]>hold[i][0]){
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
