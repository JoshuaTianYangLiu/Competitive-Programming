import java.io.*;
import java.util.*;

class NN{
    float learningRate=0.01f;
    int in,hid,out;
    Matrix weightIH,weightHO;
    Matrix biasH,biasO;
    NN(int numIn,int numHid,int numOut){
        // 784 10 10
        in=numIn;
        hid=numHid;
        out=numOut;
        weightIH=new Matrix(hid,in); // 30 784
        weightHO=new Matrix(out,hid); //10 30
        weightIH.randomize(-1,1);
        weightHO.randomize(-1,1);
        biasH=new Matrix(hid,1);
        biasO= new Matrix(out,1);
        biasH.randomize(-1,1);
        biasO.randomize(-1,1);
    }
    float[] feedForward(float[] inputArr){
        Matrix input=Matrix.fromArray(inputArr);
        Matrix hidden=Matrix.multiply(weightIH,input);
        hidden.add(biasH);
        hidden.activation();
        Matrix output = Matrix.multiply(weightHO,hidden);
        output.add(biasO);
        output.softmax();
        return Matrix.toArray(Matrix.transpose(output))[0];
    }
    void train(float[] inputArr,float[] targetArr){
        Matrix input=Matrix.fromArray(inputArr);
        Matrix hidden=Matrix.multiply(weightIH,input);
        hidden.add(biasH);
        hidden.activation();
        Matrix output = Matrix.multiply(weightHO,hidden);
        output.add(biasO);
        output.softmax();
        Matrix target = Matrix.fromArray(targetArr);
        Matrix outputErr=Matrix.sub(target,output);
        //outputErr.print();
        //Praise Daniel Shiffman for going through the insanity of this and not me
        Matrix grad =Matrix.derivativeActivation(output);
        grad.hadamard(outputErr);
        grad.multiply(learningRate);
        Matrix whoD=Matrix.multiply(grad,Matrix.transpose(hidden));
        weightHO.add(whoD);
        biasO.add(grad);
        Matrix hiddenErr=Matrix.multiply(Matrix.transpose(weightHO),outputErr);
        Matrix hiddenGrad=Matrix.derivativeActivation(hidden);
        hiddenGrad.hadamard(hiddenErr);
        hiddenGrad.multiply(learningRate);
        Matrix wihD=Matrix.multiply(hiddenGrad,Matrix.transpose(input));
        weightIH.add(wihD);
        biasH.add(hiddenGrad);
    }
    void print()throws Exception{
        weightIH.print("weightIH");
        weightHO.print("weightHO");
        biasH.print("biasH");
        biasO.print("biasO");
    }
}