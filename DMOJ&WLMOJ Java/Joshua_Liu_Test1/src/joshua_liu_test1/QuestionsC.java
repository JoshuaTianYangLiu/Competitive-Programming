/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package joshua_liu_test1;


import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class QuestionsC {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String club ="";
        endCode:
        for(;;){
            HashMap<String, Integer> clubs = new HashMap<>();
            HashMap<String, ArrayList<String>> names = new HashMap<>();
            List<String> nameList = new ArrayList<String>();
            for(;;){
                String a = readLine();
                if(a.equals("1")){
                    break;
                }else if(a.equals("0")){
                    break endCode;
                }else if(a.charAt(0)<96){
                    club=a;
                    clubs.put(club, 0);
                }else{
                    if(!names.containsKey(a)){
                        names.put(a,new ArrayList<String>());
                        nameList.add(a);
                    }
                    names.get(a).add(club);
                    clubs.put(club, clubs.get(club).intValue()+1);
                }
            }
            //Processing
            int clubSize =clubs.size();
            int nameSize = names.size();
            for(int i=0; i<nameSize; i++){
                if(names.get(nameList.get(i)).size()>1){
                    for(int j=0; j<names.get(nameList.get(i)).size(); j++){
                        clubs.put(names.get(nameList.get(i)).get(j), clubs.get(names.get(nameList.get(i)).get(j)).intValue()-1);
                        //fun... lowers the club member values by 1
                    }
                }
            }
            System.out.println(clubs);
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
