// This sample code reads in image data from a RAW image file and// writes it into another file// NOTE:	The code assumes that the image is of size 256 x 256 and is in the//			RAW format. You will need to make corresponding changes to//			accommodate images of different sizes and/or types#include <stdio.h>#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <cmath>using namespace std;


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

int main(int argc, char *argv[]){	// Define file pointer and variables	FILE *file;	int BytesPerPixel;	int Size1 = 400;
	int Size2 = 600;	// Check for proper syntax	if (argc < 3){		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;		cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;		return 0;	}	// Check if image is grayscale or color	if (argc < 4){		BytesPerPixel = 1; // default is grey image	}	else {		BytesPerPixel = atoi(argv[3]);		// Check if size is specified		if (argc >= 5){			Size1 = atoi(argv[4]);
			Size2 = atoi(argv[5]);		}	}	// Allocate image data array	unsigned char Imagedatainput[Size1][Size2];	// Read image (filename specified by first argument) into image data matrix	if (!(file=fopen(argv[1],"rb"))) {		cout << "Cannot open file: " << argv[1] <<endl;		exit(1);	}	fread(Imagedatainput, sizeof(unsigned char), Size1*Size2*BytesPerPixel, file);	fclose(file);	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////
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
	// Write image data (filename specified by second argument) from image data matrix	if (!(file=fopen(argv[2],"wb"))) {		cout << "Cannot open file: " << argv[2] << endl;		exit(1);	}	fwrite(Imagedataoutput, sizeof(unsigned char), Size1*Size2*BytesPerPixel, file);	fclose(file);	return 0;}

