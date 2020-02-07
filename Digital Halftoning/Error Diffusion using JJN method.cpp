// This sample code reads in image data from a RAW image file and// writes it into another file// NOTE:	The code assumes that the image is of size 256 x 256 and is in the//			RAW format. You will need to make corresponding changes to//			accommodate images of different sizes and/or types#include <stdio.h>#include <iostream>#include <stdlib.h>using namespace std;int main(int argc, char *argv[]){	// Define file pointer and variables	FILE *file;	int BytesPerPixel;	int Size1 = 400;
	int Size2 = 600;	// Check for proper syntax	if (argc < 3){		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;		cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;		return 0;	}	// Check if image is grayscale or color	if (argc < 4){		BytesPerPixel = 1; // default is grey image	}	else {		BytesPerPixel = atoi(argv[3]);		// Check if size is specified		if (argc >= 5){			Size1 = atoi(argv[4]);
			Size2 = atoi(argv[5]);		}	}	// Allocate image data array	unsigned char Imagedatainput[Size1][Size2];	// Read image (filename specified by first argument) into image data matrix	if (!(file=fopen(argv[1],"rb"))) {		cout << "Cannot open file: " << argv[1] <<endl;		exit(1);	}	fread(Imagedatainput, sizeof(unsigned char), Size1*Size2, file);	fclose(file);	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////
unsigned char Imagedata[Size1+4][Size2+4];

//Boundary extension for the columns
    for(int j=0;j<2;j++){
        for(int i= 2; i<(Size1+2); i++){
            Imagedata[i][j]=0;
            Imagedata[i][Size2+3-j]=0;

        }
    }

//Boundary extension for the rows
    for(int j=0;j<2;j++){
        for(int i=2; i<(Size2+2); i++){
            Imagedata[j][i]=Imagedatainput[2][i-2];
            Imagedata[Size1+3-j][i]=Imagedatainput[Size1-3][i-2];

        }
    }
//Values taken for Imagedata from Imagedatainput
    for(int i=2; i<(Size1+2);i++){
        for(int j=2; j<(Size2+2); j++){
            Imagedata[i][j]=Imagedatainput[i-2][j-2];
        }
    }//Corner matrices formed for Imagedata

//Top left
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            Imagedata[i][j]=0;
        }
    }
//Top right
    for(int i=0;i<2;i++){
        for(int j=(Size2+2);j<(Size2+4);j++){
            Imagedata[i][j]=0;
        }
    }

//Bottom left
    for(int i=Size1+2;i<2;i++){
        for(int j=0;j<2;j++){
            Imagedata[i][j]=0;
        }
    }

//Bottom right
    for(int i=Size1+2;i<(Size1+4);i++){
        for(int j=(Size2+2);j<(Size2+4);j++){
            Imagedata[i][j]=0;
        }
    }

unsigned char Imagedatadif[Size1+2][Size2+2];
unsigned char Imagedataoutput[Size1][Size2];

for(int i=0;i<Size1+4;i++){
    for(int j=0;j<Size2+4;j++){
        Imagedatadif[i][j]=Imagedata[i][j];
    }
}

for(int i=2;i<Size1+1;i+=2){
    for(int j=2;j<Size2+1;j++){
        int pixel=Imagedatadif[i][j];
        int temp;
        if(pixel>=127){
                temp=255;
        }
        else{
            temp=0;
        }
        int e=Imagedatadif[i][j]-temp;
        Imagedatadif[i][j+1]=Imagedatadif[i][j+1]+(((e)*7)/48);
        Imagedatadif[i][j+2]=Imagedatadif[i][j+2]+(((e)*5)/48);
        Imagedatadif[i+1][j+2]=Imagedatadif[i+1][j+2]+(((e)*3)/48);
        Imagedatadif[i+1][j+1]=Imagedatadif[i+1][j+1]+(((e)*5)/48);
        Imagedatadif[i+1][j]=Imagedatadif[i+1][j]+(((e)*7)/48);
        Imagedatadif[i+1][j-1]=Imagedatadif[i+1][j-1]+(((e)*5)/48);
        Imagedatadif[i+1][j-2]=Imagedatadif[i+1][j-2]+(((e)*3)/48);
        Imagedatadif[i+2][j-2]=Imagedatadif[i+2][j-2]+(((e)*1)/48);
        Imagedatadif[i+2][j-1]=Imagedatadif[i+2][j-1]+(((e)*3)/48);
        Imagedatadif[i+2][j]=Imagedatadif[i+2][j]+(((e)*5)/48);
        Imagedatadif[i+2][j+1]=Imagedatadif[i+2][j+1]+(((e)*3)/48);
        Imagedatadif[i+2][j+2]=Imagedatadif[i+2][j+2]+(((e)*1)/48);

    }
        int p=i+1;
        for(int q=Size2;q>0;q--){
            int pixel=Imagedatadif[p][q];
        int temp;
        if(pixel>=127){
                temp=255;
        }
        else{
            temp=0;
        }
        int e=Imagedatadif[p][q]-temp;
        Imagedatadif[p][q-1]=Imagedatadif[p][q-1]+(((e)*7)/48);
        Imagedatadif[p][q-2]=Imagedatadif[p][q-2]+(((e)*5)/48);
        Imagedatadif[p+1][q+2]=Imagedatadif[p+1][q+2]+(((e)*3)/48);
        Imagedatadif[p+1][q+1]=Imagedatadif[p+1][q+1]+(((e)*5)/48);
        Imagedatadif[p+1][q]=Imagedatadif[p+1][q]+(((e)*7)/48);
        Imagedatadif[p+1][q-1]=Imagedatadif[p+1][q-1]+(((e)*5)/48);
        Imagedatadif[p+1][q-2]=Imagedatadif[p+1][q-2]+(((e)*3)/48);
        Imagedatadif[p+2][q-2]=Imagedatadif[p+2][q-2]+(((e)*1)/48);
        Imagedatadif[p+2][q-1]=Imagedatadif[p+2][q-1]+(((e)*3)/48);
        Imagedatadif[p+2][q]=Imagedatadif[p+2][q]+(((e)*5)/48);
        Imagedatadif[p+2][q+1]=Imagedatadif[p+2][q+1]+(((e)*3)/48);
        Imagedatadif[p+2][q+2]=Imagedatadif[p+2][q+2]+(((e)*1)/48);
        }

}


for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){

        Imagedataoutput[i][j]=Imagedatadif[i+2][j+2];

    }
}
for(int i=0; i<Size1;i++){
    for(int j=0; j<Size2; j++){
        if(Imagedataoutput[i][j]>=127){
            Imagedataoutput[i][j]=255;
        }
        else
            Imagedataoutput[i][j]=0;
    }
}	// Write image data (filename specified by second argument) from image data matrix	if (!(file=fopen(argv[2],"wb"))) {		cout << "Cannot open file: " << argv[2] << endl;		exit(1);	}	fwrite(Imagedataoutput, sizeof(unsigned char), Size1*Size2, file);	fclose(file);	return 0;}

