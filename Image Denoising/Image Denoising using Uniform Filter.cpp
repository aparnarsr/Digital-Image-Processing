// This sample code reads in image data from a RAW image file and
#include <math.h>

		// Read image (filename specified by first argument) into image data matrix

//Window size=N (Odd number)

	int N=7;


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
    }

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


//Assigning each pixel the average of the pixel values in the window

int den=N*N;
for(int i=((N-1)/2); i<(Size+(N-(((N-1)/2)+1)));i++){
    for(int j=((N-1)/2);j<(Size+(N-(((N-1)/2)+1)));j++){
            int sum=0;
            for(int x= (i-((N-1)/2)); x<=(i+((N-1)/2));x++ ){
                for(int y = (j-((N-1)/2)); y<=(j+((N-1)/2));y++){

                    sum=sum+(int)Imagedata[x][y][0];

                }
            }
        Imagedataoutput[i-((N-1)/2)][j-((N-1)/2)][0]=(int)(sum/den);
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

