import java.io.*;
import java.util.*;
class Question{
    boolean hasObject=false;
    String subject;
    String predicate;
    String object="";
    String prefix;
    String suffix;
    Question(String a){
        if(a.charAt(0)=='d')parseDo(a);
        else if(a.charAt(2)=='o')parseWho(a);
        else if(a.charAt(2)=='a')parseWhat(a);
    }
    void parseDo(String a){
        StringTokenizer st=new StringTokenizer(a);
        String temp=st.nextToken();
        prefix=temp;
        temp=st.nextToken();
        subject=temp;
        temp=st.nextToken();
        predicate=temp;
        if(st.hasMoreTokens()){
            temp="";
            while(st.hasMoreTokens()){
                temp+=st.nextToken()+" ";
            }
            temp=temp.trim();
            if(temp.length()>1)object=temp.substring(0,temp.length()-1);
            hasObject=true;
        }else{
            predicate=predicate.substring(0,predicate.length()-1);
        }
    }
    void parseWho(String a){
        StringTokenizer st=new StringTokenizer(a);
        String temp=st.nextToken();
        prefix=temp;
        temp=st.nextToken();
        if(temp.charAt(temp.length()-1)=='s'){
            predicate=temp.substring(0,temp.length()-1);
        }
        else predicate=temp;
        if(st.hasMoreTokens()){
            temp="";
            while(st.hasMoreTokens()){
                temp+=st.nextToken()+" ";
            }
            temp=temp.trim();
            if(temp.length()>1)object=temp.substring(0,temp.length()-1);
            hasObject=true;
        }else{
            if(predicate.charAt(predicate.length()-2)=='s'){
                predicate=predicate.substring(0,predicate.length()-2);
            }else{
                predicate=predicate.substring(0,predicate.length()-1);
            }
        }
    }
    void parseWhat(String a){
        StringTokenizer st=new StringTokenizer(a);
        prefix=st.nextToken()+" "+st.nextToken();
        String temp="";
        while(st.countTokens()>1){
            temp+=st.nextToken()+" ";
        }
        subject=temp.trim();
        suffix="do";
    }
    void print(){
        /* System.out.printf("<<%s %s %s\n",subject,predicate,object);*/
    }
    void answerQuestion(Statement[] st,int len){

        if(prefix.charAt(0)=='d')answerDo(st,len);
        else if(prefix.charAt(2)=='o')answerWho(st,len);
        else if(prefix.charAt(2)=='a')answerWhat(st,len);
    }
    String addInf(String sub){
        if(sub.equals("I")||sub.equals("you"))return "";
        return "s";
    }
    String parseSubject(String sub){
        if(sub.equals("I"))return "you";
        if(sub.equals("you"))return "I";
        return sub;
    }
    String parseNegative(String sub){
        if(sub.equals("I"))return "don't";
        if(sub.equals("you"))return "don't";
        return "doesn't";
    }
    String parseObject(String object){
        return object.equals("")?"":" "+object;
    }
    void answerDo(Statement[] st,int len){
        /*Hot mess*/
        for(int i=0; i<len; i++){
            if(!st[i].isPredicate(predicate)||!st[i].isObject(object))continue;
            if(!st[i].isSubOrEvery(subject))continue;
            subject=parseSubject(subject);
            if(st[i].isPositive()){
                System.out.printf("yes, %s %s%s.\n",subject,predicate+addInf(subject),parseObject(object));
            }else{
                System.out.printf("no, %s %s%s.\n",subject,predicate+addInf(subject),parseObject(object));
            }
            return;
        }
        System.out.println("maybe.");
    }
    void answerWho(Statement[] st,int len){
        boolean containsEverybody=false;
        boolean containsNobody=false;
        int numOfSub=0;
        for(int i=0; i<len; i++){
            if(st[i].isPredicate(predicate)){
                //if(st[i].isPositive()){
                    if(hasObject){
                        if(st[i].isObject(object)){
                            if(st[i].isEverybody())containsEverybody=true;
                            if(st[i].isNobody())containsNobody=true;
                            numOfSub++;
                        }
                    }else{
                        if(st[i].isEverybody())containsEverybody=true;
                        if(st[i].isNobody())containsNobody=true;
                        numOfSub++;
                    }
                //}
            }
        }
        if(numOfSub>0&&!containsNobody){
            if(containsEverybody){
                if(hasObject)System.out.printf("everybody %s %s.\n",predicate+"s",object);
                else System.out.printf("everybody %s.\n",predicate+"s");
                /*parseSubject(subject),parseNegative(subject),predicate+addInf(subject)*/
                return;
            }else if(numOfSub==1){
                for(int i=0; i<len; i++){
                    if(st[i].isPredicate(predicate)&&st[i].isPositive()){
                        if(hasObject){
                            if(st[i].isObject(object)){
                                System.out.printf("%s %s %s.\n",st[i].subject,predicate+addInf(st[i].subject),object);
                                return;
                            }
                        }else{
                            System.out.printf("%s %s.\n",st[i].subject,predicate+addInf(st[i].subject));
                            return;
                        }
                    }
                }
            }else{
                int counter=numOfSub;
                for(int i=0; i<len; i++){
                    if(st[i].isPredicate(predicate)&&st[i].isPositive()){
                        if(hasObject){
                            if(st[i].isObject(object)){
                                if(counter==numOfSub)System.out.printf("%s",st[i].subject);
                                else if(counter>1)System.out.printf(", %s",st[i].subject);
                                if(counter==2)System.out.printf(" and ");
                                else if(counter==1)System.out.printf("%s ",st[i].subject);
                                counter--;
                            }
                        }else{
                            if(counter==numOfSub)System.out.printf("%s",st[i].subject);
                            else if(counter>1)System.out.printf(", %s",st[i].subject);
                            if(counter==2)System.out.printf(" and ");
                            else if(counter==1)System.out.printf("%s ",st[i].subject);
                            counter--;
                        }
                    }
                }
                if(hasObject)System.out.printf("%s %s.\n",predicate,object);
                else System.out.printf("%s.\n",predicate);
                return;
            }
        }
        if(containsNobody){
            if(hasObject) System.out.printf("nobody %s %s.\n",predicate+"s",object);
            else System.out.printf("nobody %s.\n",predicate+"s");
            return;
        }
        System.out.println("I don't know.");
    }
    void parseWhatOut(String subj,Statement a){
        if(a.isPositive){
            if(!a.hasObject) System.out.printf("%s",a.predicate+addInf(subj));
            else System.out.printf("%s %s",a.predicate+addInf(subj),a.object);
        }else{
            if(!a.hasObject) System.out.printf("%s %s",parseNegative(subj),a.predicate);
            else System.out.printf("%s %s %s",parseNegative(subj),a.predicate,a.object);
        }
    }
    void answerWhat(Statement[] st,int len){
        Statement state[] = new Statement[105];
        int stateCount=0;
        for(int i=0; i<len; i++){
            if(st[i].isSubject(subject)){
                boolean anyMatches=false;
                for(int j=0; j<stateCount; j++){
                    if(state[j].isPredicate(st[i].predicate)){
                        if(st[i].hasObject&&state[j].hasObject){
                            if(state[j].isObject(st[i].object)){
                                anyMatches=true;
                                break;
                            }
                        }else if(!st[i].hasObject&&!state[j].hasObject){
                            anyMatches=true;
                            break;
                        }
                    }
                }
                if(!anyMatches){
                    state[stateCount++]=st[i];
                }
            }
        }
        if(stateCount>0){
            System.out.printf("%s ",parseSubject(subject));
            for(int i=0;i<stateCount; i++){
                parseWhatOut(subject, state[i]);
                if(stateCount-i==1)System.out.printf(".\n");
                else if(stateCount-i==2)System.out.printf(", and ");
                else System.out.printf(", ");
            }
            return;
        }
        /*
        subject [ ~ don't|doesn't] ~ predicate1[s] [ ~ object1] ,

                [ ~ don't|doesn't] ~ predicate2[s] [ ~ object2] ,

        ~ and   [ ~ don't|doesn't] ~ predicate3[s] [ ~ object3] .

        subject [ ~ don't|doesn't] ~ predicate1[s] [ ~ object1] ,

        ~ and   [ ~ don't|doesn't] ~ predicate2[s] [ ~ object2] .

        subject [ ~ don't|doesn't] ~ predicate[s] [ ~ object] .
        */
        System.out.println("I don't know.");
    }
}