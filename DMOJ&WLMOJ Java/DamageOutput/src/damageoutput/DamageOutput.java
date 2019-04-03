/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package damageoutput;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class DamageOutput {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        long k = readLong();
        Queue<Integer> subArr = new LinkedList<Integer>();
        long total=0;
        int min=-1;
        int a[] = new int[size];
        for(int i=0; i<size; i++)a[i]=readInt();
        for(int i=0; i<size; ){
            if(total>=k){
                if(min==-1||subArr.size()<min)min=subArr.size();
                total-=subArr.remove();
            }else{
                subArr.add(a[i]);
                total+=a[i];
                i++;
            }
        }
        while(total>=k){
            if(min==-1||subArr.size()<min)min=subArr.size();
            total-=subArr.remove();
        }
        System.out.println(min);
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
