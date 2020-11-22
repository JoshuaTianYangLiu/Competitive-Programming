import java.io.*;
import java.util.*;

public class TestCaseGenerator {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) throws Exception{
        String subject[] = {"I","you","James","John","Jake","Joe","Josh","everybody","nobody"};
        String predicate[] ={"run","like","smile","hurt","walk","swim","jog","say"};
        String object[] = {"there","here","yes"};
        System.out.println(40);
        for(int a=0; a<40; a++){
            for(int i=0; i<100; i++){
                String s = subject[(int)(9*Math.random())];
                String p = predicate[(int)(8*Math.random())];
                String o = object[(int)(3*Math.random())];
                int c = (int)(3*Math.random());
                if(c==0){
                    //statement
                    c = (int)(2*Math.random());
                    if(c==0||s.equals("everybody")||s.equals("nobody")){
                        c = (int)(2*Math.random());
                        if(c==0) System.out.printf("%s %s %s.\n",s,addS(p,s),o);
                        else System.out.printf("%s %s %s.\n",s,addS(p,s),o);
                    }else{
                        c = (int)(2*Math.random());
                        if(c==0) System.out.printf("%s %s %s %s.\n",s,parseNegative(s),p,o);
                        else System.out.printf("%s %s %s.\n",s,parseNegative(s),p);
                    }
                }else{
                    //question
                    s = subject[(int)(7*Math.random())];
                    c = (int)(3*Math.random());
                    if(c==0){
                        c = (int)(2*Math.random());
                        if(c==0) System.out.printf("%s %s %s %s?\n",doOrDoes(s),s,p,o);
                        else System.out.printf("%s %s %s?\n",doOrDoes(s),s,p);
                    }else if(c==1){
                        c = (int)(2*Math.random());
                        if(c==0) System.out.printf("who %ss %s?\n",p,o);
                        else System.out.printf("who %ss?\n",p);
                    }else{
                        System.out.printf("what %s %s do?\n",doOrDoes(s),s);
                    }
                }
            }
            System.out.printf("test!\n");
        }
    }
    static String parseNegative(String subject){
        if(subject.equals("I")||subject.equals("you"))return "don't";
        return "doesn't";
    }
    static String addS(String v,String sub){
        if(sub.equals("I")||sub.equals("you"))return v;
        return v+"s";
    }
    static String doOrDoes(String sub){
        if(sub.equals("I")||sub.equals("you"))return "do";
        return "does";
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