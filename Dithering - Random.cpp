// This sample code reads in image data from a RAW image file and
#include <cstdlib>
	int Size2 = 600;
			Size2 = atoi(argv[5]);
	unsigned char Imagedataoutput[Size1][Size2][BytesPerPixel];

	for(int i=0;i<Size1;i++){
        for(int j=0; j<Size2;j++){

            int x= rand()%256;

            if((int)Imagedatainput[i][j][0]>=x){
               Imagedataoutput[i][j][0]=255;
            }
            else if((int)Imagedatainput[i][j][0]<x){
                Imagedataoutput[i][j][0]=0;
            }
        }
	}
