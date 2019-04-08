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
        int maxWeight = readInt();
        int size = readInt();
        Queue<Integer> onBridge = new LinkedList<Integer>();
        int totalWeight = 0;
        int carsPassed = 0;
        for(int i=0; i<Integer.min(4, size); i++){
            int carWeight = readInt();
            totalWeight+=carWeight;
            onBridge.add(carWeight);
            if(totalWeight>maxWeight){
                System.out.println(carsPassed);
                System.exit(0);
            }
            carsPassed++;
        }
        for(int i=0; i<size-4; i++){
            totalWeight-=onBridge.remove();
            int carWeight = readInt();
            totalWeight+=carWeight;
            onBridge.add(carWeight);
            if(totalWeight>maxWeight){
                System.out.println(carsPassed);
                System.exit(0);
            }
            carsPassed++;
        }
        System.out.println(size);
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
