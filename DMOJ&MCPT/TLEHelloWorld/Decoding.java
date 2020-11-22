public class Decoding {

    public static void main(String[] args) throws Exception{
        convertToArr();
        // for(int i=0; i<10; i++)System.out.print(biasHT[i]+" ");
        // System.out.println();
        for(int i=0; i<10; i++)System.out.print(biasOT[i]);
        System.out.println();
    }
    static void convertToArr(){
        biasHT=new float[10];
        biasOT=new float[10];
        for(int i=0; i<biasHS.length(); i+=2){
            int a = biasHS.charAt(i);
            int b = biasHS.charAt(i+1);
            int c = ((b<<16)&0xFFFF0000)+(a&0xFFFF);
            // System.out.println(a+" "+b);
            System.out.println(Integer.toBinaryString(a)+" "+Integer.toBinaryString(b)+" "+Integer.toBinaryString(c));
            biasHT[i/2]=Float.intBitsToFloat(c);

        }
        for(int i=0; i<biasOS.length(); i+=2){
            int a = biasOS.charAt(i);
            int b = biasOS.charAt(i+1);
            int c = ((b<<16)&0xFFFF0000)+(a&0xFFFF);
            biasOT[i/2]=Float.intBitsToFloat(c);
        }
    }
    static float biasHT[];
    static String biasHS="⟠䁓害뿦넘뽺ᅐ뻮㼸꺦삉㹼㾃횻쁘ༀ㿨";
    static float biasOT[];
    static String biasOS="≹䁂ਤ㿀꺗㿡鐪䁾曗㾋뺸䂙ྍ䁅ὂ䁒噩䂀쿖䁈";

    //3.0333541.50030951.76314063.97779321.08907594.8045313.07907413.28315784.0105483.1376853
    
}