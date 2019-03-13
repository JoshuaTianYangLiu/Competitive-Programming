/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package joshua_liu_test1;

import java.util.*;
import java.io.*;
import java.text.DecimalFormat;
/**
 *
 * @author Joshua
 */
public class QuestionsD {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        System.out.println(readLine());
        System.out.println("====================");
        DecimalFormat dc = new DecimalFormat("#.000");
        double oneHitsT =0;
        double atBatT =0;
        double runsT =0;
        double twoHitsT =0;
        double threeHitsT =0;
        double homeRunsT =0;
        for(int i=0; i<10; i++){
            String teamName = next();
            int gamesPlayed = readInt();
            int atBat = readInt();
            int runs = readInt();
            int tHits = readInt();
            int twoHits = readInt();
            int threeHits = readInt();
            int homeRuns = readInt();
            int oneHits = tHits-twoHits-threeHits-homeRuns;
            atBatT+=atBat;
            runsT+=runs;
            oneHitsT+=oneHits;
            twoHitsT+=twoHits;
            threeHitsT+=threeHits;
            homeRunsT+=homeRuns;
            double bA = ((double)oneHits+twoHits+threeHits+homeRuns)/(double)atBat;
            double sA = ((double)oneHits+2*twoHits+3*threeHits+4*homeRuns)/(double)atBat;
            System.out.println(teamName+": "+dc.format(bA) + " "+ dc.format(sA));
        }
        double bAT = ((double)oneHitsT+twoHitsT+threeHitsT+homeRunsT)/(double)atBatT;
        double sAT = ((double)oneHitsT+2*twoHitsT+3*threeHitsT+4*homeRunsT)/(double)atBatT;
        System.out.println("====================");
        System.out.println("Big 10 Av: "+dc.format(bAT)+" "+dc.format(sAT));
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
