/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package converttoprocessing;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class ConvertToProcessing {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        String a = nextX();
        String b = nextX();
        for(int i =0; i<28; i++){
            Scanner in = new Scanner(System.in);
            String temp = in.next();
            System.out.println("  "+a+temp+b);
        }
    }

    static String nextX () throws IOException {
        if (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

 
}
