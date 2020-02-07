// This sample code reads in image data from a RAW image file and
#include <cstdlib>
#include <vector>
#include <math.h>
#include <cmath>


int** matrix(int n){

    if(n==2){
    int** I =  new int*[2];
    I[0] = new int[2];
    I[1] = new int[2];

    I[0][0] = 1;
    I[0][1] = 2;
    I[1][0] = 3;
    I[1][1] = 0;

    return I;
    }

    else{
        int** mat=new int*[n];
        for(int i=0; i<n; i++){
            mat[i] = new int[n];
        }
        int** arr;
        arr=matrix(n/2);
            for(int i=0;i<n/2;i++){

                for(int j=0;j<n/2;j++){
                        mat[i][j]=4*arr[i][j]+1;
                }
            }
            for(int i=0;i<n/2;i++){
                for(int j=n/2;j<n;j++){
                        mat[i][j]=4*arr[i][j-(n/2)]+2;
                }
            }
            for(int i=n/2;i<n;i++){
                for(int j=0;j<n/2;j++){
                        mat[i][j]=4*arr[i-(n/2)][j]+3;
                }
            }
            for(int i=n/2;i<n;i++){
                for(int j=n/2;j<n;j++){
                        mat[i][j]=4*arr[i-(n/2)][j-(n/2)];
                }
            }
            return mat;

    }



}


	int Size2 = 600;
			Size2 = atoi(argv[5]);
unsigned char Imagedataoutput[Size1][Size2];

int** dog;
dog=matrix(32);


double threshold[32][32];
for(int i=0;i<32;i++){
    for(int j=0;j<32;j++){
threshold[i][j]=((dog[i][j]+0.5)*255)/(1024);
    }
}


double a; double b;
for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){

         a=threshold[i % 32][j % 32];

         b=((int)Imagedatainput[i][j]);


            if( a>=b){
               Imagedataoutput[i][j]=(unsigned char)0;
            }
            else{
               Imagedataoutput[i][j]=(unsigned char)255;
            }

    }
}

