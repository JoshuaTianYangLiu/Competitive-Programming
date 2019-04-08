/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package assigningpartners;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class AssigningPartners {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        //Not Finished
        int size=readInt();
        List<String> a=new ArrayList<String>();
        List<String> b=new ArrayList<String>();
        for(int i=0; i<size; i++){
            a.add(next());
        }
        for(int i=0; i<size; i++){
            b.add(next());
        }
        for(int i=0; i<size; i++){
            int pos = a.indexOf(b.get(i));
            if (!a.get(i).equals(b.get(pos))|| pos == i){
                System.out.println("bad");
                System.exit(0);
            }
        }
        System.out.println("good");
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
