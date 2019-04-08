/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package stats;

import java.util.*;
import java.io.*;
import sun.text.normalizer.UBiDiProps;

/**
 *
 * @author Joshua
 */
public class Stats {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int size = readInt();
        List<Double> in = new ArrayList<Double>();
        double mean = 0;
        for(int i=0; i<size; i++){
            double b = readDouble();
            in.add(b);
            mean+=b;
        }
        mean/=size;
        Collections.sort(in);
        double median =0;
        if(size%2==0){
             median=(in.get(size/2)+in.get((size/2)-1))/2;
        }else{
            median = in.get(size/2);
        }
        System.out.println(mean);
        System.out.println(median);
        if(in.size()>1){
            List<Integer> mode = new ArrayList<Integer>();
            List<Double> modeNum = new ArrayList<Double>();
            int pos =1;
            double mem = in.get(0);
            for(int i=1; i<size; i++){
                if(in.get(i)==mem){
                    pos++;
                    if(i==size-1){
                        mode.add(pos);
                        modeNum.add(mem);
                    }
                }else{
                    mode.add(pos);
                    pos =1;
                    modeNum.add(mem);
                    mem = in.get(i);
                    if(i==size-1){
                        mode.add(1);
                        modeNum.add(mem);
                   }
                }
            }
            int max = 0;
            for(int i=0; i<mode.size(); i++){
                if(max<mode.get(i)){
                    max=mode.get(i);
                }
            }
            List<Double> modeMax = new ArrayList<Double>();
            for(int i=0;i<mode.size(); i++){
                if(mode.get(i)==max){
                    modeMax.add(modeNum.get(i));
                }
            }
            for(int i=0; i<modeMax.size()-1;i++){
                System.out.print(modeMax.get(i)+" ");
            }
            System.out.println(modeMax.get(modeMax.size()-1));
        }else{
            System.out.println(in.get(0));
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
