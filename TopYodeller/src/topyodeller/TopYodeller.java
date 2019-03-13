/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package topyodeller;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class TopYodeller {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static class OldIndex implements Comparable<OldIndex>{
        int v;
        int i;
        OldIndex(int value, int index){
            v=value;
            i=index;
        }
        public int compareTo(OldIndex a){
            return Integer.compare(v, a.v)*-1;
        }
    }
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
//        int size = readInt();
//        int rounds = readInt();
//        int score[][] = new int[rounds][size];
//        
//        
//        for(int i=0; i<rounds; i++){
//            for(int j=0; j<size; j++){
//                score[i][j]=readInt();
//            }
//               
//        }
//        int highestIndex =0;
//        int highestTotal = totalScore(score, highestIndex, rounds);   
//        
//        for (int i=1; i<size;i++)
//        {
//            if (totalScore(score, i, rounds)>highestTotal)
//            {
//                highestIndex = i;
//                highestTotal = totalScore(score, i, rounds);
//            }
//        }
//        for(int i=0; i<size; i++){
//            if(totalScore(score, i, rounds)==highestTotal) System.out.println("Yodeller "+(i+1)+" is the TopYodeller: score "+highestTotal+", worst rank "+worstRank(score,i, rounds,size) );
//        }
//            
////        for(int i=0; i<size; i++){
////            if(score[max]==score[i]){
////                System.out.println("Yodeller "+(i+1)+" is the TopYodeller: score "+score[i]+", worst rank "+(lowest[i]+1));
////            }
////        }
//    }
//    static int totalScore(int[][] score, int index, int rounds)
//    {
//        int total =0;
//        for (int i=0;i<rounds;i++)
//        {
//        total += score[i][index];
//        }
//        return total;
//    }
//    
//    static int worstRank(int[][] score, int personIndex, int rounds, int size)
//    {
//        int sum[] =new int[size];
//        for (int i=0;i<size;i++)
//            sum[i] = score[0][i];
//        int rank =RankEachRound(sum, personIndex, size);
//
//        for (int i=1;i<rounds;i++)
//        {
//             for (int j=0;j<size;j++)
//                sum[j] += score[i][j];
//             
//            int currentRank = RankEachRound(sum, personIndex, size);
//            if(currentRank>rank)
//            {
//                rank = currentRank;
//                
//            }
//        
//        }
//        return rank+1;
//    }
//static int RankEachRound(int sum[],  int personIndex, int size)
//{
//        int rank=0;
//        for (int i=0;i<size;i++)
//        {
//            if (sum[i]>sum[personIndex])
//                rank++;
//            
//        }
//        return rank;

        // TODO code application logic here
        int size = readInt();
        int rounds = readInt();
        int score[] = new int[size];
        int lowest[] = new int[size];
        OldIndex a[] = new OldIndex[size];
        for(int i=0; i<rounds; i++){
            for(int j=0; j<size; j++){
                int b = readInt();
                a[j]=new OldIndex(b,j);
                score[j] += b;   
            }
            Arrays.sort(a);
            int bufferCounter =0;
            int k =0;
            for(int j=0; j<size; j++){
                if(j!=0&&k-1==lowest[a[j-1].i]){
                    lowest[a[j].i]=k-1;
                    bufferCounter++;
                }else if(k>=lowest[a[j].i]){
                    lowest[a[j].i]=k;
                    k+=bufferCounter;
                    k++;
                    bufferCounter=0;
                }
            }
            
        }
        int max =0;
        for(int i=1; i<size; i++){
            if(score[max]<score[i]){
                max=i;
            }
        }
        for(int i=0; i<size; i++){
            if(score[max]==score[i]){
                System.out.println("Yodeller "+(i+1)+" is the TopYodeller: score "+score[i]+", worst rank "+(lowest[i]+1));
            }
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
