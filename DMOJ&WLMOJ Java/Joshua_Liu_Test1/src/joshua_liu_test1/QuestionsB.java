/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package joshua_liu_test1;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class QuestionsB {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        for(;;){
            int size = readInt();
            if(size==0) break;
            int a[] = new int[size];
            for(int i =0; i<size; i++){
                a[i] = readInt();
            }
            Arrays.sort(a);
            boolean possible = true;
            for(int i=0; i<size-1; i++){
                if(a[i+1]-a[i]>200){
                    possible = false;
                }
            }
            if(1422-a[size-1]>200){
                possible=false;
            }
            if(possible){
                System.out.println("POSSIBLE");
            }else{
                System.out.println("IMPOSSIBLE");
            }
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
