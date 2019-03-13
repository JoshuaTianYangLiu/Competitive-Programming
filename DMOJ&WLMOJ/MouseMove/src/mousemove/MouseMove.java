/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mousemove;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class MouseMove {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int xMax =readInt();
        int yMax = readInt();
        int x = 0;
        int y = 0;
        int xMove = readInt();
        int yMove = readInt();
        while(xMove!=0||yMove!=0){
            x+=xMove;
            y+=yMove;
            if(x>xMax)x=xMax;
            else if(x<0)x=0;
            if(y>yMax)y=yMax;
            else if(y<0)y=0;
            xMove=readInt();
            yMove=readInt();
            System.out.println(x+" "+y);
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
