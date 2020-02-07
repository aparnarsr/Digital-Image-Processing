// This sample code reads in image data from a RAW image file and
#include <math.h>

		// Read image (filename specified by first argument) into image data matrix

	int N=5;
//	int sd=1;



    cout<<N<<"\n";

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

//Displaying values in Imagedata and Imagedatainput
   for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<(int)Imagedata[i][j][0]<<" ";
        }
        cout<<endl;
    }

    cout<<"\n"<<"Input Array: "<<"\n";



    for(int i=0;i<9;i++){
        for(int j=0;j<9 ;j++){
            cout<<(int)Imagedatainput[i][j][0]<<" ";
        }
        cout<<endl;
    }

/*
//Assigning values for W array
for(int i=0;i<Size;i++){
    for(int j=0;j<Size;j++){
W[i][j]=Imagedatainput[i][j][0];
wijkl[i][j]=(W[i][j])/(w1*w2);
    }
}
*/

double sigmac=100;
double sigmas=100;

int den=N*N;
for(int i=((N-1)/2); i<(Size+(N-(((N-1)/2)+1)));i++){
    for(int j=((N-1)/2);j<(Size+(N-(((N-1)/2)+1)));j++){
            double sum=0;double tot=0;  double wijkl=0;
            for(int x= (i-((N-1)/2)); x<=(i+((N-1)/2));x++){
                for(int y = (j-((N-1)/2)); y<=(j+((N-1)/2));y++){

                    wijkl=exp(-(((pow((i-x),2))+(pow((j-y),2)))/(2*pow(sigmac,2)))-((pow(abs((int)Imagedata[i][j][0]-(int)Imagedata[x][y][0]),2))/((2*pow(sigmas,2)))));
                    tot=tot+wijkl;
                    sum=sum+((int)Imagedata[x][y][0]*wijkl);

                }
            }
        Imagedataoutput[i-((N-1)/2)][j-((N-1)/2)][0]=(int)(sum/tot);
    }
}



