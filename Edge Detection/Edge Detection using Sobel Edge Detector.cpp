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
	int Size1 = 321;
	int Size2 = 481;

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
			Size1 = atoi(argv[4]);
			Size2 = atoi(argv[5]);
		}
	}

	// Allocate image data array
	unsigned char Imagedatainput[Size1][Size2][BytesPerPixel];

	// Read image (filename specified by first argument) into image data matrix
	if (!(file=fopen(argv[1],"rb"))) {
		cout << "Cannot open file: " << argv[1] <<endl;
		exit(1);
	}
	fread(Imagedatainput, sizeof(unsigned char), Size1*Size2*BytesPerPixel, file);
	fclose(file);

	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////
unsigned char Imagedatagray[Size1][Size2];
unsigned char Imagedata[Size1+2][Size2+2];
unsigned char Imagedatax[Size1][Size2];
unsigned char Imagedatay[Size1][Size2];
unsigned char Imagedatag[Size1][Size2];

for(int i=0;i<Size1;i++){
    for(int j=0; j<Size2;j++){
        Imagedatagray[i][j]=(double)Imagedatagray[i][j];
        Imagedatax[i][j]=(double)Imagedatax[i][j];
        Imagedatay[i][j]=(double)Imagedatay[i][j];
    }
}
for(int i=0;i<Size1+1;i++){
    for(int j=0; j<Size2+1;j++){
        Imagedatagray[i][j]=(double)Imagedatagray[i][j];
        Imagedata[i][j]=(double)Imagedata[i][j];
    }
}

for(int i=0;i<Size1;i++){
    for(int j=0; j<Size2; j++){
        Imagedatagray[i][j]=(((double)Imagedatainput[i][j][0]*(0.2989))+((double)Imagedatainput[i][j][1]*(0.5870))+((double)Imagedatainput[i][j][2]*(0.1140)));
    }
}


//Boundary extension for the columns

for(int i= 0; i<(Size1+1); i++){
    Imagedata[i][0]=0;
    Imagedata[i][Size2+1]=0;

}

//Boundary extension for the rows
        for(int i= 0; i<(Size2+1); i++){
            Imagedata[0][i]=0;
            Imagedata[Size1+1][i]=0;

        }

//Values taken for Imagedata from Imagedatainput
    for(int i=1; i<(Size1);i++){
        for(int j=1; j<(Size2+1); j++){
            Imagedata[i][j]=Imagedatagray[i-1][j-1];
        }
    }


double minx=255; double maxx=0;
double miny=255; double maxy=0;
double ming=255; double maxg=0;

for(int i=1;i<Size1+1;i++){
    for(int j=1;j<Size2+1; j++){
        double Gx=((Imagedata[i-1][j+1])+((2.0)*Imagedata[i][j+1])+(Imagedata[i+1][j+1])-(Imagedata[i-1][j-1])-((2.0)*Imagedata[i][j-1])-(Imagedata[i+1][j-1]))/4.0;
        Imagedatax[i-1][j-1]=Gx;
        if(Gx<=minx){minx=Gx;}
        if(Gx>=maxx){maxx=Gx;}

        double Gy=((Imagedata[i-1][j-1])+((2.0)*Imagedata[i-1][j])+(Imagedata[i-1][j+1])-(Imagedata[i+1][j-1])-((2.0)*Imagedata[i+1][j])-(Imagedata[i+1][j+1]))/4.0;
        Imagedatay[i-1][j-1]=Gy/2;
        if(Gy<=miny){miny=Gy;}
        if(Gy>=maxy){maxy=Gy;}

        double G=sqrt(pow(Gx,2)+pow(Gy,2));
        Imagedatag[i-1][j-1]=G;

        if(G<=ming){ming=G;}
        if(G>=maxg){maxg=G;}
    }
}



cout<<"minx "<<minx<<" "<<"maxx "<<maxx<<endl;
cout<<"miny "<<miny<<" "<<"maxy "<<maxy<<endl;
cout<<"ming "<<ming<<" "<<"maxg "<<maxg<<endl;

for(int i=0;i<Size1;i++){
    for(int j=0; j<Size2;j++){
        Imagedatax[i][j]=((((Imagedatax[i][j])-minx)*(255.0))/(maxx-minx));
        Imagedatay[i][j]=(((Imagedatay[i][j]-miny)*(255.0))/(maxy-miny));
        Imagedatag[i][j]=(((Imagedatag[i][j]-ming)*(255.0))/(maxg-ming));
    }
}


int minog=1000; int maxog=-1000;
for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){
            int x=Imagedatag[i][j];
            if(x<=minog){minog=x;}
            if(x>=maxog){maxog=x;}
    }
}
int minox=1000; int maxox=-1000;
for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){
            int x=Imagedatax[i][j];
            if(x<=minox){minox=x;}
            if(x>=maxox){maxox=x;}
    }
}
int minoy=1000; int maxoy=-1000;
for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){
            int x=Imagedatay[i][j];
            if(x<=minoy){minoy=x;}
            if(x>=maxoy){maxoy=x;}
    }
}


cout<<"minox "<<minox<<" "<<"maxox "<<maxox<<endl;
cout<<"minoy "<<minoy<<" "<<"maxoy "<<maxoy<<endl;
cout<<"minog "<<minog<<" "<<"maxog "<<maxog<<endl;

for(int i=0; i<Size1; i++){
    for(int j=0; j<Size2; j++){
        if(Imagedatag[i][j]>=45){
            Imagedatag[i][j]=0;
        }
        else
            Imagedatag[i][j]=255;
    }
}
for(int i=0;i<Size1;i++){
    for(int j=0; j<Size2;j++){
        Imagedatagray[i][j]=(unsigned char)Imagedatagray[i][j];
        Imagedatax[i][j]=(unsigned char)Imagedatax[i][j];
        Imagedatay[i][j]=(unsigned char)Imagedatay[i][j];
    }
}
for(int i=0;i<Size1+1;i++){
    for(int j=0; j<Size2+1;j++){
        Imagedatagray[i][j]=(unsigned char)Imagedatagray[i][j];
        Imagedata[i][j]=(unsigned char)Imagedata[i][j];
        Imagedata[i][j]=(unsigned char)Imagedata[i][j];
    }
}

	// Write image data (filename specified by second argument) from image data matrix

	if (!(file=fopen(argv[2],"wb"))) {
		cout << "Cannot open file: " << argv[2] << endl;
		exit(1);
	}
	fwrite(Imagedatag, sizeof(unsigned char), Size1*Size2, file);
	fclose(file);

	return 0;
}



