// This sample code reads in image data from a RAW image file and// writes it into another file// NOTE:	The code assumes that the image is of size 256 x 256 and is in the//			RAW format. You will need to make corresponding changes to//			accommodate images of different sizes and/or types#include <stdio.h>#include <iostream>#include <stdlib.h>
#include <math.h>using namespace std;int main(int argc, char *argv[]){	// Define file pointer and variables	FILE *file;	int BytesPerPixel;	int Size = 256;	// Check for proper syntax	if (argc < 3){		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;		cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;		return 0;	}	// Check if image is grayscale or color	if (argc < 4){		BytesPerPixel = 1; // default is grey image	}	else {		BytesPerPixel = atoi(argv[3]);		// Check if size is specified		if (argc >= 5){			Size = atoi(argv[4]);		}	}	// Allocate image data array	unsigned char Imagedatainput[Size][Size][BytesPerPixel];

		// Read image (filename specified by first argument) into image data matrix	if (!(file=fopen(argv[1],"rb"))) {		cout << "Cannot open file: " << argv[1] <<endl;		exit(1);	}	fread(Imagedatainput, sizeof(unsigned char), Size*Size*BytesPerPixel, file);	fclose(file);	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////
//N= Window Size

	int N=7;

//sd= Standard deviation

	int sd=1;

//Assigning a Boundary extended matrix
    unsigned char Imagedata[Size+N-1][Size+N-1][BytesPerPixel];
    unsigned char Imagedataoutput[Size][Size][BytesPerPixel];

//Boundary extension for the columns
    int l=(N-1)/2;
    for(int j=0;j<((N-1)/2);j++){
        for(int i= ((N-1)/2); i<(Size+(N-(((N-1)/2)+1))); i++){
            Imagedata[i][j][0]=Imagedatainput[i-((N-1)/2)][l][0];
            Imagedata[i][Size+(N-2)-j][0]=Imagedatainput[i-((N-1)/2)][Size-(l+1)][0];

        }
        l--;
    }

//Boundary extension for the rows
     l=(N-1)/2;
    for(int j=0;j<(((N-1)/2)+1);j++){
        for(int i= ((N-1)/2); i<(Size+(N-(((N-1)/2)+1))); i++){
            Imagedata[j][i][0]=Imagedatainput[l][i-((N-1)/2)][0];
            Imagedata[Size+(N-2)-j][i][0]=Imagedatainput[Size-(l+1)][i-((N-1)/2)][0];

        }
        l--;
    }
//Values taken for Imagedata from Imagedatainput
    for(int i=((N-1)/2); i<(Size+(N-(((N-1)/2)+1)));i++){
        for(int j=((N-1)/2); j<(Size+(N-(((N-1)/2)+1))); j++){
            Imagedata[i][j][0]=(int)Imagedatainput[i-((N-1)/2)][j-((N-1)/2)][0];
        }
    }//Corner matrices formed for Imagedata

//Top left
 int p=(N-1);
    for(int i=0;i<((N-1)/2);i++){
        for(int j=0;j<((N-1)/2);j++){
            Imagedata[i][j][0]=Imagedata[i][p][0];
            p--;
        } p=(N-1);
    }
//Top right
     int q=(Size+(N-(((N-1)/2)+1)))-2;
    for(int i=0;i<((N-1)/2);i++){
        for(int j=(Size+(N-(((N-1)/2)+1)));j<(Size-1+N);j++){
            Imagedata[i][j][0]=Imagedata[i][q][0];
            q=q-2;
        } q=(Size+(N-(((N-1)/2)+1)))-2;
    }

//Bottom left
       int r=N-1;
    for(int i=(Size+(N-(((N-1)/2)+1)));i<((N-1)/2);i++){
        for(int j=0;j<((N-1)/2);j++){
            Imagedata[i][j][0]=Imagedata[i][r][0];
            r--;
        } r=(N-1);
    }

//Bottom right
       int s=(Size+(N-(((N-1)/2)+1)))-2;
    for(int i=(Size+(N-(((N-1)/2)+1)));i<(Size-1+N);i++){
        for(int j=(Size+(N-(((N-1)/2)+1)));j<(Size-1+N);j++){
            Imagedata[i][j][0]=Imagedata[i][s][0];
            s=s-2;
        } s=(Size+(N-(((N-1)/2)+1)))-2;
    }

//Assigning the pixels the Gaussian weighted average of the pixels in the window

double wijkl;
int den=N*N;
for(int i=((N-1)/2); i<(Size+(N-(((N-1)/2)+1)));i++){
    for(int j=((N-1)/2);j<(Size+(N-(((N-1)/2)+1)));j++){
            double sum=0;double tot=0; wijkl=0;
            for(int x= (i-((N-1)/2)); x<=(i+((N-1)/2));x++){
                for(int y = (j-((N-1)/2)); y<=(j+((N-1)/2));y++){

                    wijkl=(1/((sqrt(2*M_PI))*sd))*exp(-(pow((x-i),2)+(pow((y-j),2))/(2*pow(sd,2))));
                    tot=tot+wijkl;
                    sum=sum+((int)Imagedata[x][y][0]*wijkl);

                }
            }
        Imagedataoutput[i-((N-1)/2)][j-((N-1)/2)][0]=(int)(sum/tot);
    }
}

//Calculating PSNR

int totmse=0;
int max=255;
double psnr;
double mse;
for(int i=0;i<Size;i++){
    for(int j=0;j<Size;j++){
        mse=(pow((Imagedataoutput[i][j][0]-Imagedatainput[i][j][0]),2))/(pow(Size,2));
        totmse= totmse+mse;
    }
}
psnr= 10* log10((pow(max,2))/mse);

	// Write image data (filename specified by second argument) from image data matrix	if (!(file=fopen(argv[2],"wb"))) {		cout << "Cannot open file: " << argv[2] << endl;		exit(1);	}	fwrite(Imagedataoutput, sizeof(unsigned char), Size*Size*BytesPerPixel, file);	fclose(file);	return 0;}


