/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package luggage;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Luggage {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size=readInt();
        int k=readInt();
        List<Integer> a=new ArrayList<Integer>();
        for(int i=0; i<size; i++)a.add(readInt());
        Collections.sort(a);
        int max=0;
        int point=0;
        for(int i=0; i<size; i++){
            while(point<i&&a.get(i)-a.get(point)>k){
                point++;
            }
//            if(a.get(point))
            max=(i-point)>max?(i-point):max;
            
        }
        System.out.println(max+1);
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
