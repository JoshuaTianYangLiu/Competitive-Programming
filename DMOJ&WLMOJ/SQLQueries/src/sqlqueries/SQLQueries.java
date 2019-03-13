/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package sqlqueries;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class SQLQueries {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int a[] = {0 ,readInt(),readInt(),readInt()};
        int pos =0;
        for(int i=0; i<3; i++){
            int passes=0;
            pos=i;
            do{
                pos=a[pos];
                passes++;
            }while(pos!=a[pos]&&pos!=i&&passes<10);
            if(pos!=0&&(pos==a[pos]||pos==i||passes>6)){
                System.out.println("NO");
                System.exit(0);
            }
        }
        System.out.println("YES");
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
