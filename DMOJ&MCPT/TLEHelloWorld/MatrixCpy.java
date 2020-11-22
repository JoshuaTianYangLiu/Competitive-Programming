class Matrix{
    int rows,cols;
    float matrix[][];
    Matrix(int rows,int cols){
        this.rows=rows;
        this.cols=cols;
        matrix = new float[rows][cols];
        for(int i=0; i<rows;i++)
            for(int j=0;j<cols; j++)
                matrix[i][j]=0;
    }
    void randomize(){
        for(int i=0; i<rows;i++)
            for(int j=0;j<cols; j++)
                matrix[i][j]=(float)Math.random();
    }
    void multiply(float n){
        for(int i=0; i<rows;i++)
            for(int j=0;j<cols; j++)
                matrix[i][j]*=n;
    }
    void multiply(int n){
        multiply((float)n);
    }
    static Matrix multiply(Matrix a,Matrix b){
        //System.out.println(a.rows+" "+a.cols+" "+b.rows+" "+b.cols);
        Matrix r = new Matrix(a.rows,b.cols);
        for(int i=0; i<r.rows;i++)
            for(int j=0;j<r.cols; j++){
                float s =0;
                for(int k=0; k<a.cols; k++)
                    s+=a.matrix[i][k]*b.matrix[k][j];
                r.matrix[i][j]=s;
            }
        return r;
    }
    void hadamard(Matrix a){
        for(int i=0; i<rows;i++)
            for(int j=0;j<cols; j++)
                matrix[i][j]*=a.matrix[i][j];
    }
    void add(int n){
        for(int i=0; i<rows;i++)
            for(int j=0;j<cols; j++)
                matrix[i][j]+=n;
    }
    void add(Matrix n){
        for(int i=0; i<rows;i++)
            for(int j=0;j<cols; j++)
                matrix[i][j]+=n.matrix[i][j];
    }
    static Matrix sub(Matrix a,Matrix b){
        Matrix r = new Matrix(b.rows,b.cols);
        for(int i=0; i<r.rows;i++)
            for(int j=0;j<r.cols; j++)
                r.matrix[i][j]=a.matrix[i][j]-b.matrix[i][j];
        return r;
    }
    Matrix sub(Matrix b){
        return sub(b,this);
    }
    static Matrix transpose(Matrix a){
        Matrix r = new Matrix(a.cols,a.rows);
        for(int i=0; i<a.rows;i++)
            for(int j=0;j<a.cols; j++)
                r.matrix[j][i]=a.matrix[i][j];
        return r;
    }
    void print(){
        for(int i=0; i<rows;i++){
            for(int j=0;j<cols; j++)
                System.out.print(matrix[i][j]+" ");
            System.out.println();
        }
    }
    static Matrix fromArray(float[] a){
        Matrix b=new Matrix(a.length,1);
        for(int i=0; i<a.length; i++)
            b.matrix[i][0]=a[i];
        return b;
    }
    static Matrix fromArray(float[][] a){
        Matrix b = new Matrix(a.length,a[0].length);
        b.matrix=a;
        return b;
    }
    static float[][] toArray(Matrix a){
        float b[][] = new float[a.rows][a.cols];
        for(int i=0; i<a.rows; i++)
            for(int j=0; j<a.cols; j++)
            b[i][j]=a.matrix[i][j];
        return b;
    }
    float sigmoid(float x){
        return (float)(1/(1+Math.exp(-x)));
    }
    void sigmoidMap(){
        for(int i=0; i<rows;i++)
            for(int j=0;j<cols; j++)
                matrix[i][j]=sigmoid(matrix[i][j]);
    }
    void softmax(){
        float sum=0;
        for(int i=0; i<rows; i++)
            sum+=(float)Math.exp(matrix[i][0]);
        for(int i=0; i<rows; i++)
            matrix[i][0]=(float)(Math.exp(matrix[i][0])/sum);
    }
    static Matrix derivativeSigmoid(Matrix a){
        Matrix r = new Matrix(a.rows,a.cols);
        for(int i=0; i<a.rows;i++)
            for(int j=0; j<a.cols; j++)
                r.matrix[i][j]=a.matrix[i][j]*(1-a.matrix[i][j]);
        return r;
    }
    void activation(){
        sigmoidMap();
    }
    static Matrix derivativeActivation(Matrix a){
        return derivativeSigmoid(a);
    }
}