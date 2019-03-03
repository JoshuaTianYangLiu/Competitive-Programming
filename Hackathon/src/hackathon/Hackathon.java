/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hackathon;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Hackathon {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        List<timeWowFactor> a = new ArrayList<timeWowFactor>();
        for(int i=0; i<size; i++){
            a.add(new timeWowFactor(readInt(),readInt()));
        }
        Collections.sort(a);
        int q = readInt();
        int value=0;
        for(int i=0; i<q; i++){
            value = readInt();
            int pos = Collections.binarySearch(a, new timeWowFactor(value,-1));
            if(pos<0){
                if (pos==-1) pos=0;
                else pos=Math.abs(pos)-2;
             
            }
            
            System.out.println(a.get(pos).factor);
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
