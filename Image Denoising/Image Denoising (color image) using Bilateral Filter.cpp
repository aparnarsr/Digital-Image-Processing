
// This sample code reads in image data from a RAW image file and
// writes it into another file

// NOTE:	The code assumes that the image is of size 256 x 256 and is in the
//			RAW format. You will need to make corresponding changes to
//			accommodate images of different sizes and/or types

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])

{
	// Define file pointer and variables
	FILE *file;
	int BytesPerPixel;
	int Size = 256;

	// Check for proper syntax
	if (argc < 3){
		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
		cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;
		return 0;
	}

	// Check if image is grayscale or color
	if (argc < 4){
		BytesPerPixel = 3; // default is grey image
	}
	else {
		BytesPerPixel = atoi(argv[3]);
		// Check if size is specified
		if (argc >= 5){
			Size = atoi(argv[4]);
		}
	}

	// Allocate image data array
	unsigned char Imagedatainput[Size][Size][BytesPerPixel];

		// Read image (filename specified by first argument) into image data matrix
	if (!(file=fopen(argv[1],"rb"))) {
		cout << "Cannot open file: " << argv[1] <<endl;
		exit(1);
	}
	fread(Imagedatainput, sizeof(unsigned char), Size*Size*BytesPerPixel, file);
	fclose(file);

	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////

//N=Window Size

	int N=5;

//Assigning a Boundary extended matrix
    unsigned char Imagedata[Size+N-1][Size+N-1][BytesPerPixel];
    unsigned char Imagedataoutput[Size][Size][BytesPerPixel];

//Boundary extension for the columns
    int l=(N-1)/2;
    for(int j=0;j<((N-1)/2);j++){
        for(int i= ((N-1)/2); i<(Size+(N-(((N-1)/2)+1))); i++){
                for(int k=0;k<3;k++){
            Imagedata[i][j][k]=Imagedatainput[i-((N-1)/2)][l][k];
            Imagedata[i][Size+(N-2)-j][k]=Imagedatainput[i-((N-1)/2)][Size-(l+1)][k];
                }
        }
        l--;
    }

//Boundary extension for the rows
     l=(N-1)/2;
    for(int j=0;j<(((N-1)/2)+1);j++){
        for(int i= ((N-1)/2); i<(Size+(N-(((N-1)/2)+1))); i++){
                 for(int k=0;k<3;k++){
            Imagedata[j][i][k]=Imagedatainput[l][i-((N-1)/2)][k];
            Imagedata[Size+(N-2)-j][i][k]=Imagedatainput[Size-(l+1)][i-((N-1)/2)][k];

        }}
        l--;
    }
//Values taken for Imagedata from Imagedatainput
    for(int i=((N-1)/2); i<(Size+(N-(((N-1)/2)+1)));i++){
        for(int j=((N-1)/2); j<(Size+(N-(((N-1)/2)+1))); j++){
                 for(int k=0;k<3;k++){
            Imagedata[i][j][k]=(int)Imagedatainput[i-((N-1)/2)][j-((N-1)/2)][k];
       } }
    }

//Corner matrices formed for Imagedata

//Top left
 int p=(N-1);
    for(int i=0;i<((N-1)/2);i++){
        for(int j=0;j<((N-1)/2);j++){
                 for(int k=0;k<3;k++){
            Imagedata[i][j][0]=Imagedata[i][p][k];
            p--;
      } } p=(N-1);
    }
//Top right
     int q=(Size+(N-(((N-1)/2)+1)))-2;
    for(int i=0;i<((N-1)/2);i++){
        for(int j=(Size+(N-(((N-1)/2)+1)));j<(Size-1+N);j++){
                 for(int k=0;k<3;k++){
            Imagedata[i][j][k]=Imagedata[i][q][k];
            q=q-2;
      }  } q=(Size+(N-(((N-1)/2)+1)))-2;
    }

//Bottom left
       int r=N-1;
    for(int i=(Size+(N-(((N-1)/2)+1)));i<((N-1)/2);i++){
        for(int j=0;j<((N-1)/2);j++){
                 for(int k=0;k<3;k++){
            Imagedata[i][j][k]=Imagedata[i][r][k];
            r--;
     }   } r=(N-1);
    }

//Bottom right
       int s=(Size+(N-(((N-1)/2)+1)))-2;
    for(int i=(Size+(N-(((N-1)/2)+1)));i<(Size-1+N);i++){
        for(int j=(Size+(N-(((N-1)/2)+1)));j<(Size-1+N);j++){
             for(int k=0;k<3;k++){
            Imagedata[i][j][k]=Imagedata[i][s][k];
            s=s-2;
       } } s=(Size+(N-(((N-1)/2)+1)))-2;
    }

//sigmac and sigmas are the spread parameters

double sigmac=100;
double sigmas=100;

//Bilateral Filter

int den=N*N;
for(int i=((N-1)/2); i<(Size+(N-(((N-1)/2)+1)));i++){
    for(int j=((N-1)/2);j<(Size+(N-(((N-1)/2)+1)));j++){
            double sum0=0;double sum1=0;double sum2=0;double tot0=0;double tot1=0;double tot2=0; double wijkl0=0;double wijkl1=0;double wijkl2=0;
            for(int x= (i-((N-1)/2)); x<=(i+((N-1)/2));x++){
                for(int y = (j-((N-1)/2)); y<=(j+((N-1)/2));y++){

                    wijkl0=exp(-(((pow((i-x),2))+(pow((j-y),2)))/(2*pow(sigmac,2)))-((pow(abs((int)Imagedata[i][j][0]-(int)Imagedata[x][y][0]),2))/((2*pow(sigmas,2)))));
                    wijkl1=exp(-(((pow((i-x),2))+(pow((j-y),2)))/(2*pow(sigmac,2)))-((pow(abs((int)Imagedata[i][j][1]-(int)Imagedata[x][y][1]),2))/((2*pow(sigmas,2)))));
                    wijkl2=exp(-(((pow((i-x),2))+(pow((j-y),2)))/(2*pow(sigmac,2)))-((pow(abs((int)Imagedata[i][j][2]-(int)Imagedata[x][y][2]),2))/((2*pow(sigmas,2)))));
                    tot0=tot0+wijkl0;
                    tot1=tot1+wijkl1;
                    tot2=tot2+wijkl2;
                    sum0=sum0+((int)Imagedata[x][y][0]*wijkl0);
                    sum1=sum1+((int)Imagedata[x][y][1]*wijkl1);
                    sum2=sum2+((int)Imagedata[x][y][2]*wijkl2);
                }
            }
        Imagedataoutput[i-((N-1)/2)][j-((N-1)/2)][0]=(int)(sum0/tot0);
        Imagedataoutput[i-((N-1)/2)][j-((N-1)/2)][1]=(int)(sum1/tot1);
        Imagedataoutput[i-((N-1)/2)][j-((N-1)/2)][2]=(int)(sum2/tot2);
    }
}

	// Write image data (filename specified by second argument) from image data matrix

	if (!(file=fopen(argv[2],"wb"))) {
		cout << "Cannot open file: " << argv[2] << endl;
		exit(1);
	}
	fwrite(Imagedataoutput, sizeof(unsigned char), Size*Size*BytesPerPixel, file);
	fclose(file);

	return 0;
}





