import java.io.*;
import java.util.*;

public class Hotline {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static Statement state[];
    static int stateLen;
    static boolean hasContradictions;
    static Statement stateBuf;
    public static void main(String[] args) throws Exception{
        int t=readInt();
        for(int i=1; i<=t; i++){
            hasContradictions=false;
            state = new Statement[105];
            stateLen=0;
            System.out.printf("Dialogue #%d:\n",i);
            String input = readLine();
            while(lastChar(input)!='!'){
                if(lastChar(input)=='.'){
                    if(!hasContradictions){
                        stateBuf=new Statement(input);
                        checkContradictions();
                        //stateLen++;
                    }
                }else if(lastChar(input)=='?'){
                    System.out.println(input);
                    if(hasContradictions){
                        System.out.println("I am abroad.");
                    }else{
                        Question q = new Question(input);
                        q.answer(state,stateLen);
                    }
                    System.out.println();
                }
                input = readLine();
            }
            System.out.println(input+"\n");
        }
    }
    static void checkContradictions(){
        for(int i=0; i<stateLen; i++){
            if(!state[i].eqlPO(stateBuf))continue;
            //same predicate and object
            if(stateBuf.equalSubject("everybody")){
                if(stateBuf.isPositive!=state[i].isPositive){
                    hasContradictions=true;
                }
            }
            if(state[i].equalSubject("everybody")){
                if(stateBuf.isPositive!=state[i].isPositive) hasContradictions=true;
                return;
            }
            if(state[i].equalSubject(stateBuf.subject)){
                if(stateBuf.isPositive!=state[i].isPositive) hasContradictions=true;
                return;
            }
        }
        state[stateLen++]=stateBuf;
    }
    static char lastChar(String a){
        return a.charAt(a.length()-1);
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