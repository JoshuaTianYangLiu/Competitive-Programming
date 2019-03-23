/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package returnofaplusb;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ReturnOfAPlusB {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i=0; i<size; i++){
            String a=next();
            String b=next();
            int c=0;
            int d=0;
            char aC;
            char bC;
            if(a.length()==1){
                aC=a.charAt(0);
                if((int)aC==22235)c=4;
                else if((int)aC==19968)c=1;
                else if((int)aC==20108)c=2;
                else if((int)aC==19977)c=3;
                else if((int)aC==20116)c=5;
                else if((int)aC==20845)c=6;
                else if((int)aC==19971)c=7;
                else if((int)aC==20843)c=8;
                else if((int)aC==20061)c=9;
                else if((int)aC==21313)c=10;
                else if((int)aC==38646)c=0;
                else if(aC=='0')c=0;
                else if(aC=='1')c=1;
                else if(aC=='2')c=2;
                else if(aC=='3')c=3;
                else if(aC=='4')c=4;
                else if(aC=='5')c=5;
                else if(aC=='6')c=6;
                else if(aC=='7')c=7;
                else if(aC=='8')c=8;
                else if(aC=='9')c=9;
            }else{
                if(a.equals("10"))c=10;
                else if(a.equals("zero"))c=0;
                else if(a.equals("one"))c=1;
                else if(a.equals("two"))c=2;
                else if(a.equals("three"))c=3;
                else if(a.equals("four"))c=4;
                else if(a.equals("five"))c=5;
                else if(a.equals("six"))c=6;
                else if(a.equals("seven"))c=7;
                else if(a.equals("eight"))c=8;
                else if(a.equals("nine"))c=9;
                else if(a.equals("ten"))c=10;
            }
            if(b.length()==1){
                aC=b.charAt(0);
                if((int)aC==22235)d=4;
                else if((int)aC==19968)d=1;
                else if((int)aC==20108)d=2;
                else if((int)aC==19977)d=3;
                else if((int)aC==20116)d=5;
                else if((int)aC==20845)d=6;
                else if((int)aC==19971)d=7;
                else if((int)aC==20843)d=8;
                else if((int)aC==20061)d=9;
                else if((int)aC==21313)d=10;
                else if((int)aC==38646)d=0;
                else if(aC=='0')d=0;
                else if(aC=='1')d=1;
                else if(aC=='2')d=2;
                else if(aC=='3')d=3;
                else if(aC=='4')d=4;
                else if(aC=='5')d=5;
                else if(aC=='6')d=6;
                else if(aC=='7')d=7;
                else if(aC=='8')d=8;
                else if(aC=='9')d=9;
            }else{
                if(b.equals("10"))d=10;
                else if(b.equals("zero"))d=0;
                else if(b.equals("one"))d=1;
                else if(b.equals("two"))d=2;
                else if(b.equals("three"))d=3;
                else if(b.equals("four"))d=4;
                else if(b.equals("five"))d=5;
                else if(b.equals("six"))d=6;
                else if(b.equals("seven"))d=7;
                else if(b.equals("eight"))d=8;
                else if(b.equals("nine"))d=9;
                else if(b.equals("ten"))d=10;
            }
            System.out.println(c+d);
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
