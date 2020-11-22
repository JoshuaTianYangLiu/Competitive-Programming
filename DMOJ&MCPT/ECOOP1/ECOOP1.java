import java.io.*;
import java.util.*;

public class ECOOP1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static String notes[] = new String[]{"C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C"};
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int t=readInt();
        for(int i=0; i<t; i++){
            String a=next();
            String b=next();
            String c=next();
            String d=next();
            int e=cntSemi(a,b);
            int f=cntSemi(b,c);
            int g=cntSemi(c,d);
            if(e==4&&f==3&&g==3){
                System.out.println("root");
                continue;
            }
            String tt=d;
            d=c;
            c=b;
            b=a;
            a=tt;
            e=cntSemi(a,b);
            f=cntSemi(b,c);
            g=cntSemi(c,d);
            if(e==4&&f==3&&g==3){
                System.out.println("first");
                continue;
            }
            tt=d;
            d=c;
            c=b;
            b=a;
            a=tt;
            e=cntSemi(a,b);
            f=cntSemi(b,c);
            g=cntSemi(c,d);
            if(e==4&&f==3&&g==3){
                System.out.println("second");
                continue;
            }
            tt=d;
            d=c;
            c=b;
            b=a;
            a=tt;
            e=cntSemi(a,b);
            f=cntSemi(b,c);
            g=cntSemi(c,d);
            if(e==4&&f==3&&g==3){
                System.out.println("third");
                continue;
            }
            System.out.println("invalid");
        }
    }
    static int cntSemi(String a,String b){
        int c=find(a);
        int d=find(b);
        if(d>c)return d-c;
        else return -1+(13+d-c)%13;
    }
    static int find(String a){
        for(int i=0; i<13; i++){
            if(a.equals(notes[i]))return i;
        }
        return -1;
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