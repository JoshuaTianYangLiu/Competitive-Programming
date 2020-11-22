import java.io.*;
import java.util.*;

public class TLEHelloWorld {

    public static void main(String[] args) throws Exception {
        //Data Compression With CNN
        NN nn = new NN(784,30,10);
        DataInputStream dataInputStream = new DataInputStream(new BufferedInputStream(new FileInputStream("train-images.idx3-ubyte")));
        int magicNumber = dataInputStream.readInt();
        int numberOfItems = dataInputStream.readInt();
        int nRows = dataInputStream.readInt();
        int nCols = dataInputStream.readInt();
        System.out.println("magic number is " + magicNumber);
        System.out.println("number of items is " + numberOfItems);
        System.out.println("number of rows is: " + nRows);
        System.out.println("number of cols is: " + nCols);
        DataInputStream labelInputStream = new DataInputStream(new BufferedInputStream(new FileInputStream("train-labels.idx1-ubyte")));
        int labelMagicNumber = labelInputStream.readInt();
        int numberOfLabels = labelInputStream.readInt();
        System.out.println("labels magic number is: " + labelMagicNumber);
        System.out.println("number of labels is: " + numberOfLabels);
        ArrayList<float[]> img = new ArrayList<float[]>();
        ArrayList<float[]> labelArr = new ArrayList<float[]>();
        for(int i = 0; i < numberOfItems; i++) {
            float[] input = new float[nRows*nCols];
            float[] target = new float[10];
            img.add(new float[nRows*nCols]);
            labelArr.add(new float[10]);
            // target[labelInputStream.readUnsignedByte()]++;
            labelArr.get(i)[labelInputStream.readUnsignedByte()]++;
            for (int r = 0; r < nRows; r++) {
                for (int c = 0; c < nCols; c++) {
                    int t=dataInputStream.readUnsignedByte();
                    // input[r*nCols+c]=(float)(t/255.0);
                    img.get(i)[r*nCols+c]=(float)(t/255.0);
                }
            }
            // nn.train(input,target);
        }
        for(int i=0; i<2000000; i++){
            int n=(int)(Math.random()*60000);
            nn.train(img.get(n),labelArr.get(n));
        }
        dataInputStream.close();
        labelInputStream.close();


        dataInputStream = new DataInputStream(new BufferedInputStream(new FileInputStream("t10k-images.idx3-ubyte")));
        magicNumber = dataInputStream.readInt();
        numberOfItems = dataInputStream.readInt();
        nRows = dataInputStream.readInt();
        nCols = dataInputStream.readInt();
        System.out.println("number of items is " + numberOfItems);
        labelInputStream = new DataInputStream(new BufferedInputStream(new FileInputStream("t10k-labels.idx1-ubyte")));
        labelMagicNumber = labelInputStream.readInt();
        numberOfLabels = labelInputStream.readInt();
        System.out.println("number of labels is: " + numberOfLabels);
        int accuracy=0;
        for(int i = 1; i < numberOfItems; i++) {
            float[] input = new float[nRows*nCols];
            for (int r = 0; r < nRows; r++) {
                for (int c = 0; c < nCols; c++) {
                    int t=dataInputStream.readUnsignedByte();
                    //System.out.println(t);
                    input[r*nCols+c]=(float)(t/255.0);
                }
            }
            float[] result=nn.feedForward(input);
            int ans=0;
            for(int j=0; j<10; j++){
                if(result[j]>result[ans])ans=j;
            }
            int label=labelInputStream.readUnsignedByte();
            if(ans==label)accuracy++;
        }
        dataInputStream.close();
        labelInputStream.close();
        System.out.println(accuracy*100.0/10000+" "+accuracy+" 10000");
        nn.print();
        // for(int i=0; i<60000; i++){
        // nn.train(trainingInputs,trainingOutputs);
        // }


        // float outputs[] = nn.feedForward(testData);
        // for(int i=0; i<outputs.length; i++)
        //     System.out.println(outputs[i]);
    }
}