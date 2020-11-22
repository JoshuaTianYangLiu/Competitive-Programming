class NN{
    float learningRate=0.01f;
    int in,hid,out;
    Matrix weightIH,weightHO;
    Matrix biasH,biasO;
    NN(int numIn,int numHid,int numOut){
        in=numIn;
        hid=numHid;
        out=numOut;
        weightIH=new Matrix(hid,in);
        weightHO=new Matrix(out,hid);
        weightIH.randomize();
        weightHO.randomize();
        biasH=new Matrix(hid,1);
        biasO= new Matrix(out,1);
        biasH.randomize();
        biasO.randomize();
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
}