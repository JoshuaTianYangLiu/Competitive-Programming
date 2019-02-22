/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package fallinginlove;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class FallingInLove {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        List<Float> x = new ArrayList<Float>();
        List<Float> y = new ArrayList<Float>();
        int a[][] = new int[size][2];
        for(int i =0; i<size; i++){
            a[i][0]= readInt();
            a[i][1]= readInt();
        }
        float b[];
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                if(a[i][0]!=a[j][0]){
                    b = intersect(a[i][0],a[i][1],a[j][0],a[j][1]);
                    if(!contains(x,y,b[0],b[1])){
                        x.add(b[0]);
                        y.add(b[1]);
                    }
                }
            }
        }
        System.out.println(x.size());
    }
    static boolean contains(List<Float> x, List<Float> y,float a, float b){
        for(int i=0; i<x.size(); i++){
            if(a==x.get(i)&&b==y.get(i)){
                return true;
            }
        }
        return false;
    }
    static float[] intersect(int w,int x, int y, int z){
        float ret[] = new float[2];
        float a = w;
        float b = x;
        float c = y;
        float d = z;
        ret[0]=(d-b)/(a-c);
        ret[1]=(c*b-d*a)/(c-a);
        return ret;
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
