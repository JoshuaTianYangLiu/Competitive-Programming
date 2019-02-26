/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package bridgetransport;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class BridgeTransport {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int totalSupport = readInt();
        int size = readInt();
        Queue<Integer> onBridge = new LinkedList<Integer>();
        int totalWeight=0;
        for(int i=0; i<4; i++){
            int read = readInt();
            totalWeight+=read;
            onBridge.add(read);
        }
        for(int i=0; i<size-4; i++){
            if(totalSupport<totalWeight){
                System.out.println(i);
                System.exit(0);
            }
            totalWeight-=onBridge.remove();
            int read = readInt();
            totalWeight+=read;
            onBridge.add(read);
        }
        System.out.println(size-1);
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
