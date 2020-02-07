// This sample code reads in image data from a RAW image file and
#include <math.h>

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
}