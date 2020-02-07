// This sample code reads in image data from a RAW image file and// writes it into another file// NOTE:	The code assumes that the image is of size 256 x 256 and is in the//			RAW format. You will need to make corresponding changes to//			accommodate images of different sizes and/or types#include <stdio.h>#include <iostream>#include <stdlib.h>
#include <math.h>using namespace std;int main(int argc, char *argv[]){	// Define file pointer and variables	FILE *file;	int BytesPerPixel;	int Size = 400;	// Check for proper syntax	if (argc < 3){		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;		cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;		return 0;	}	// Check if image is grayscale or color	if (argc < 4){		BytesPerPixel = 1; // default is grey image	}	else {		BytesPerPixel = atoi(argv[3]);		// Check if size is specified		if (argc >= 5){			Size = atoi(argv[4]);		}	}	// Allocate image data array	unsigned char Imagedata[Size][Size][BytesPerPixel];	// Read image (filename specified by first argument) into image data matrix	if (!(file=fopen(argv[1],"rb"))) {		cout << "Cannot open file: " << argv[1] <<endl;		exit(1);	}	fread(Imagedata, sizeof(unsigned char), Size*Size*BytesPerPixel, file);	fclose(file);	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////

//Initaializing arrays

unsigned char Imagedataoutput[Size][Size][BytesPerPixel];

long long int histarray[256];
long double histprobarray[256];
long double histcdfarray[256];
long double mulhistarray[256];
long double finalhistarray[256];

long long int histarrayo[256];
long double histprobarrayo[256];
long double histcdfarrayo[256];
long double mulhistarrayo[256];
long double finalhistarrayo[256];

//Assigning all values in histarray to be 0
	for(int i=0;i<256;i++)
	{
            histarray[i]=0;
    }

//Histogram
	for(int i=0;i<Size;i++){
        for(int j=0;j<Size; j++)
            {
                int l=(int)Imagedata[i][j][0];

                        histarray[l]=(int)histarray[l]+1;
            }
        }

//Probability
        for(int i=0; i<256;i++){
            histprobarray[i]=(double)(histarray[i]/160000.0);
        }

//Cumulative distributive function
for(int i=0;i<256;i++){
    histcdfarray[i]=histprobarray[i];
}
for(int i=1;i<256;i++){
    histcdfarray[i]=histcdfarray[i]+histcdfarray[i-1];

}

//Multiplying cdf by 255

for(int i=0;i<256;i++){
    mulhistarray[i]=255*histcdfarray[i];
}

//Rounding down the cdf values

for(int i=0;i<256;i++){
    finalhistarray[i]=floor(mulhistarray[i]);
}

//final image
	for(int i=0;i<Size;i++){
        for(int j=0;j<Size; j++)
            {
                int l=(int)Imagedata[i][j][0];
                Imagedataoutput[i][j][0]=(finalhistarray[l]);
            }
        }


//Finding values for Output image to plot the CDF graph

//Histogram
	for(int i=0;i<Size;i++){
        for(int j=0;j<Size; j++)
            {
                int l=(int)Imagedataoutput[i][j][0];

                        histarrayo[l]=(int)histarrayo[l]+1;
            }
        }

//Probability
        for(int i=0; i<256;i++){
            histprobarrayo[i]=(double)(histarrayo[i]/160000.0);
        }

//Cumulative distributive function
for(int i=0;i<256;i++){
    histcdfarrayo[i]=histprobarrayo[i];
}
for(int i=1;i<256;i++){
    histcdfarrayo[i]=histcdfarrayo[i]+histcdfarrayo[i-1];
}

//Multiplying cdf by 255

for(int i=0;i<256;i++){
    mulhistarrayo[i]=255*histcdfarrayo[i];
}

//Rounding down the cdf values

for(int i=0;i<256;i++){
    finalhistarrayo[i]=floor(mulhistarrayo[i]);
}
for(int i=0;i<256;i++){
cout<<finalhistarrayo[i]<<endl;
}	// Write image data (filename specified by second argument) from image data matrix	if (!(file=fopen(argv[2],"wb"))) {		cout << "Cannot open file: " << argv[2] << endl;		exit(1);	}	fwrite(Imagedataoutput, sizeof(unsigned char), Size*Size*BytesPerPixel, file);	fclose(file);	return 0;}
