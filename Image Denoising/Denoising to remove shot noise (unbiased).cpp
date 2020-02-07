// This sample code reads in image data from a RAW image file and
#include <math.h>

		// Read image (filename specified by first argument) into image data matrix


//Transformation of Imagedatainput
int z; int fz;
unsigned char Imagedatatransformed[Size][Size][BytesPerPixel];
for(int i=0;i<Size;i++){
        for(int j=0;j<Size;j++){
            z=(int)Imagedatainput[i][j][0];
             //fz=2*(z+(3/8));
            fz = (((8*z)+3)/4);
            Imagedatatransformed[i][j][0]=fz;
}}
//Applying Gaussian filter to Imagedatatransformed
	int N=5;
	int sd=25;

    cout<<N<<"\n";

//Assigning a Boundary extended matrix
    unsigned char Imagedata[Size+N-1][Size+N-1][BytesPerPixel];
    unsigned char Imagedatafiltered[Size][Size][BytesPerPixel];

//Boundary extension for the columns
    int l=(N-1)/2;
    for(int j=0;j<((N-1)/2);j++){
        for(int i= ((N-1)/2); i<(Size+(N-(((N-1)/2)+1))); i++){
            Imagedata[i][j][0]=Imagedatatransformed[i-((N-1)/2)][l][0];
            Imagedata[i][Size+(N-2)-j][0]=Imagedatatransformed[i-((N-1)/2)][Size-(l+1)][0];

        }
        l--;
    }

//Boundary extension for the rows
     l=(N-1)/2;
    for(int j=0;j<(((N-1)/2)+1);j++){
        for(int i= ((N-1)/2); i<(Size+(N-(((N-1)/2)+1))); i++){
            Imagedata[j][i][0]=Imagedatatransformed[l][i-((N-1)/2)][0];
            Imagedata[Size+(N-2)-j][i][0]=Imagedatatransformed[Size-(l+1)][i-((N-1)/2)][0];

        }
        l--;
    }
//Values taken for Imagedata from Imagedatainput
    for(int i=((N-1)/2); i<(Size+(N-(((N-1)/2)+1)));i++){
        for(int j=((N-1)/2); j<(Size+(N-(((N-1)/2)+1))); j++){
            Imagedata[i][j][0]=(int)Imagedatatransformed[i-((N-1)/2)][j-((N-1)/2)][0];
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
        Imagedatafiltered[i-((N-1)/2)][j-((N-1)/2)][0]=(int)(sum/tot);
    }
}



//Inverse transform of Imagedatafiltered

unsigned char Imagedataoutput[Size][Size][BytesPerPixel];
for(int i=0;i<Size;i++){
    for(int j=0;j<Size;j++){
        Imagedataoutput[i][j][0]= ((2*(pow((int)Imagedatafiltered[i][j][0],2)))-1)/8;
    }
}


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
cout<<psnr;




