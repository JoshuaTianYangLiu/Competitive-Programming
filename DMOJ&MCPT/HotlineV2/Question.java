import java.io.*;
import java.util.*;
class Question{
    String question;
    String subject="",predicate="",object="";
    Question(String buf){
        if(buf.charAt(0)=='d')aDo(buf);
        else if(buf.charAt(2)=='o')aWho(buf);
        else if(buf.charAt(2)=='a')aWhat(buf);
    }
    void aDo(String buf){
        StringTokenizer st=new StringTokenizer(buf," ");
        question=st.nextToken();
        subject=st.nextToken();
        predicate=tossMark(st.nextToken());
        while(st.hasMoreTokens()){ //Optional adds object
            object+=st.nextToken()+" ";
        }
        object=tossMark(object.trim());
    }
    void aWho(String buf){
        StringTokenizer st=new StringTokenizer(buf," ");
        question=st.nextToken();
        predicate=tossMark(st.nextToken());
        predicate=predicate.substring(0,predicate.length()-1);
        while(st.hasMoreTokens()){ //Optional adds object
            object+=st.nextToken()+" ";
        }
        object=tossMark(object.trim());
    }
    void aWhat(String buf){
        StringTokenizer st=new StringTokenizer(buf," ");
        question=st.nextToken();
        st.nextToken();
        subject=st.nextToken();
    }
    String tossMark(String a){
        if(a.isEmpty())return "";
        if(a.charAt(a.length()-1)=='?')return a.substring(0,a.length()-1);
        return a;
    }
    void answer(Statement st[],int len){
        if(question.charAt(0)=='d')outDo(st,len);
        else if(question.charAt(2)=='o')outWho(st,len);
        else outWhat(st,len);
    }
    String flipSubject(String a){
        if(a.equals("I"))return "you";
        if(a.equals("you"))return "I";
        return a;
    }
    String addInf(String sub){
        if(sub.equals("I")||sub.equals("you"))return "";
        return "s";
    }
    String parseObject(String object){
        if(object.isEmpty())return "";
        return " "+object;
    }
    String parseNegative(String subject){
        if(subject.equals("I")||subject.equals("you"))return "don't";
        return "doesn't";
    }
    void outDo(Statement st[],int len){
        for(int i=0; i<len; i++){
            if(!st[i].eqlPO(predicate,object))continue;
            if(!st[i].equalSubject(subject)&&!st[i].equalSubject("everybody"))continue;
            subject=flipSubject(subject);
            if(st[i].isPositive)System.out.printf("yes, %s %s%s.\n",subject,predicate+addInf(subject),parseObject(object));
            else System.out.printf("no, %s %s %s%s.\n",subject,parseNegative(subject),predicate,parseObject(object));
            return;
        }
        System.out.println("maybe.");
    }
    void outWho(Statement st[],int len){
        int cntLen=0;
        Statement state[]=new Statement[125];
        boolean t=false;
        for(int i=0; i<len ;i++){
            if(!st[i].eqlPO(predicate,object))continue;
            if(st[i].isPositive){
                if(st[i].equalSubject("everybody")){
                    System.out.printf("everybody %ss%s.\n",predicate,parseObject(object));
                    return;
                }
                boolean isUnique=true;
                for(int j=0; j<cntLen; j++){
                    if(st[i].equalSubject(state[j].subject))isUnique=false;
                }
                if(isUnique) state[cntLen++]=st[i];
            }else if(st[i].equalSubject("everybody")){
                t=true;
            }
        }
        if(cntLen==0){
            if(t){
                System.out.printf("nobody %ss%s.\n",predicate,parseObject(object));
                return;
            }
            System.out.println("I don't know.");
            return;
        }
        String addS=cntLen==1?"s":"";
        int numOfSub=cntLen;
        for(int i=0; i<numOfSub; i++){
            if(state[i].equalSubject("I")||state[i].equalSubject("you")){
                addS="";
            }
            if(cntLen<numOfSub){
                if(cntLen==1)   System.out.printf(" and ");
                else    System.out.printf(", ");
            }
            System.out.printf("%s",flipSubject(state[i].subject));
            cntLen--;
        }
        System.out.printf(" %s%s.\n",predicate+addS,parseObject(object));
    }
    void outWhat(Statement st[],int len){
        Statement state[]=new Statement[125];
        int cntLen=0;
        for(int i=0; i<len; i++){
            if(!st[i].equalSubject(subject)&&!st[i].equalSubject("everybody"))continue;
            boolean isUnique=true;
            for(int j=0; j<cntLen; j++){
                if(st[i].eqlPO(state[j]))isUnique=false;
            }
            if(isUnique) state[cntLen++]=st[i];
        }
        if(cntLen==0){
            System.out.println("I don't know.");
            return;
        }
        System.out.printf("%s ",flipSubject(subject));
        int numOfSub=cntLen;
        for(int i=0; i<numOfSub; i++){
            if(!state[i].equalSubject(subject)&&!state[i].equalSubject("everybody"))continue;
            if(cntLen<numOfSub){
                if(cntLen==1)   System.out.printf(", and ");
                else    System.out.printf(", ");
            }
            if(state[i].isPositive){
                System.out.printf("%s%s",state[i].predicate+addInf(subject),parseObject(state[i].object));
            }else{
                System.out.printf("%s %s%s",parseNegative(subject),state[i].predicate,parseObject(state[i].object));
            }
            cntLen--;
        }
        System.out.println(".");
    }
}