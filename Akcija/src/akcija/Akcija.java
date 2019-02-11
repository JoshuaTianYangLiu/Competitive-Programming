/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package akcija;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class Akcija {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        List<Integer> list = new ArrayList<Integer>();
        int size = readInt();
        int a = (size%3);
        int total = 0;
        int j=0;
        for(int i=0; i<size; i++){
            list.add(readInt());
        }
        Collections.sort(list);
        for(int i=0; i<a; i++){
            total+=list.get(j);
            j++;
        }
        for(int i=0; i<(size-a)/3; i++){
            j++;
            total+=list.get(j);
            j++;
            total+=list.get(j);
            j++;
        }
        System.out.println(total);
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
