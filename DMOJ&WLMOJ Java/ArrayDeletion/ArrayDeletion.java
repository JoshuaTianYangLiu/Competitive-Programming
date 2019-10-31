/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package arraydeletion;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ArrayDeletion {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int removing = readInt();
        List<Integer> a = new ArrayList<Integer>();
        for(int i =0; i<size; i++){
            a.add(i+1);
        }
        List<Integer> b = new ArrayList<Integer>();
        try{
        for(int i=0; i<removing; i++){
            int x = readInt()-1;
            b.add(a.get(x));
            a.remove(x);
        }
        }catch(Exception e){
            System.out.println("Out of bounds");
            System.exit(0);
        }
        //Collections.sort(b);
        String out = "";
        for(int i=0; i<removing; i++){
            out += Integer.toString(b.get(i))+" ";
        }
        System.out.println(out.trim());
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
