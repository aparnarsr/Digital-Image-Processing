// This sample code reads in image data from a RAW image file and
// writes it into another file

// NOTE:	The code assumes that the image is of size 256 x 256 and is in the
//			RAW format. You will need to make corresponding changes to
//			accommodate images of different sizes and/or types
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


int pyramid(double r,double g,double b){
int a1=1; //cmyw
int a2=2; //mygc
int a3=3; //rgmy
int a4=4; //krgb
int a5=5; //rgbm
int a6=6; //cmgb

    if((r+g)>255){
        if((g+b)>255){
            if((r+g+b)>510){
                return a1; //cmyw
            }
            else{
                return a2; //mygc
            }
        }
        else{
            return a3;  //rgmy
        }
    }
    else{
        if(!((g+b)>255)){
            if(!((r+g+b)>255)){
                return a4; //krgb
            }
            else{
                return a5; //rgbm
            }
        }
        else{
            return a6; //cmgb
        }
    }
}

int* getNearestVertex(int mbvq, double R, double G, double B){

    int* vertex= new int[3];

    if (mbvq == 1){
                    //white
                    vertex[0]= 255;
                    vertex[1]= 255;
                    vertex[2]= 255;

        if (B < 128){
            if (B <= R){
                if (B <= G){
                     //yellow
                    vertex[0]= 255;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
            }
        }
        if (G < 128){
            if (G <= B){
                if (G <= R){
                     //magenta
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
            }
        }
        if (R < 128){
            if (R <= B){
                if (R <= G){
                     //cyan
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 255;
                }
            }
        }
    }


//MYGC
    if (mbvq == 2){
                    //magenta
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 255;
        if (G >= B){
            if (R >= B){
                if (R >= 128){
                    //yellow
                    vertex[0]= 255;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
                else{
                    //green
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
            }
        }

        if (G >= R){
            if (B >= R){
                if (B >= 128){
                    //cyan
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 255;
                }
                else{
                    //green
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
            }
        }
    }


//RGMY
    if (mbvq == 3){
        if (B > 128){
            if (R > 128){
                if (B >= G){
                    //magenta
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
                else{
                    //yellow
                    vertex[0]= 255;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
            }
            else{
                if (G > B + R){
                    //green
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
                else{
                    //magenta
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
            }
        }
        else{
            if (R >= 128){
                if (G >= 128){
                    //yellow
                    vertex[0]= 255;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
                else{
                    //red
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 0;
                }
            }
            else{
                if (R >= G){
                    //red
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 0;
                }
                else{
                    //green
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
            }
        }
    }


//KRGB
    if (mbvq == 4){
        //black
                    vertex[0]= 0;
                    vertex[1]= 0;
                    vertex[2]= 0;
        if (B > 128){
            if (B >= R){
                if (B >= G){
                    //blue
                    vertex[0]= 0;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
            }
        }
        if (G > 128){
            if (G >= B){
                if (G >= R){
                    //green
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
            }
        }
        if (R >128){
            if (R >= B){
                if (R >= G){
                    //red
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 0;
                }
            }
        }
    }


//RGBM
    if (mbvq == 5){
        //green
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 0;
        if (R > G){
            if (R >= B){
                if (B < 128){
                    //red
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 0;
                }
                else{
                    //magenta
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
            }
        }
        if (B > G){
            if (B >= R){
                if (R < 128){
                    //blue
                    vertex[0]= 0;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
                else{
                    //magenta
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
            }
        }
    }


//CMGB
    if (mbvq == 6){
        if (B > 128){
            if ( R > 128){
                if (G >= R){
                   //cyan
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 255;
                }
                else{
                    //magenta
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
            }
            else{
                if (G > 128){
                    //cyan
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 255;
                }
                else{
                    //blue
                    vertex[0]= 0;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
            }
        }
        else{
            if ( R > 128){
                if ((R - G + B) >= 128){
                    //magenta
                    vertex[0]= 255;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
                else{
                    //green
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
            }
            else{
                if (G >= B){
                    //green
                    vertex[0]= 0;
                    vertex[1]= 255;
                    vertex[2]= 0;
                }
                else{
                    //blue
                    vertex[0]= 0;
                    vertex[1]= 0;
                    vertex[2]= 255;
                }
            }
        }
    }
return vertex;

}
int main(int argc, char *argv[])

{
	// Define file pointer and variables
	FILE *file;
	int BytesPerPixel;
	int Size1 = 375;
	int Size2 = 500;

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
	unsigned char Imagedatainput[Size1][Size2][3];

	// Read image (filename specified by first argument) into image data matrix
	if (!(file=fopen(argv[1],"rb"))) {
		cout << "Cannot open file: " << argv[1] <<endl;
		exit(1);
	}
	fread(Imagedatainput, sizeof(unsigned char), Size1*Size2*BytesPerPixel, file);
	fclose(file);

	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////

unsigned char Imagedatadif[Size1+2][Size2+2][3];
unsigned char Imagedataoutput[Size1][Size2][3];
unsigned char Imagedatanew[Size1][Size2][3];
unsigned char Imagedatafinal[Size1][Size2][3];
for(int i=0;i<Size1+2;i++){
    for(int j=0;j<Size2+2;j++){
        for(int k=0;k<3;k++){
            Imagedatadif[i][j][k]=(double)Imagedatadif[i][j][k];
        }
    }
}

for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){
        for(int k=0;k<3;k++){
            Imagedataoutput[i][j][k]=(double)Imagedataoutput[i][j][k];
        }
    }
}

for(int i= 0; i<(Size1+2); i++){
    for(int k=0;k<3;k++){
        Imagedatadif[i][0][k]=0;
        Imagedatadif[i][Size2+1][k]=0;
    }
}

//Boundary extension for the rows
for(int j= 0; j<(Size2+2); j++){
    for(int k=0;k<3;k++){
        Imagedatadif[0][j][k]=0;
        Imagedatadif[Size1+1][j][k]=0;
    }
}

//Values taken for Imagedata from Imagedatainput
for(int i=1; i<(Size1+1);i++){
    for(int j=1; j<(Size2+1); j++){
        for(int k=0;k<3;k++){
            Imagedatadif[i][j][k]=(double)(Imagedatainput[i-1][j-1][k]);
        }
    }
}

double r,g,b;
for(int i=1; i<Size1+1; i+=2){

    for(int j=1; j<Size2+1; j++){

        r=Imagedatadif[i][j][0];
        g=Imagedatadif[i][j][1];
        b=Imagedatadif[i][j][2];

        int mbvq=pyramid(r,g,b);
  //      cout<<mbvq<<" ";
        int *v;
        v=getNearestVertex(mbvq, r,g,b);
        //cout<<(int)v[0]<<endl;
        double errorred=r-v[0];
        double errorgreen=g-v[1];
        double errorblue=b-v[2];

        Imagedataoutput[i-1][j-1][0]=v[0];
        Imagedataoutput[i-1][j-1][1]=v[1];
        Imagedataoutput[i-1][j-1][2]=v[2];

        Imagedatadif[i][j+1][0]=(Imagedatadif[i][j+1][0]+((errorred*7)/16));
        Imagedatadif[i+1][j+1][0]=(Imagedatadif[i+1][j+1][0]+((errorred*1)/16));
        Imagedatadif[i+1][j][0]=(Imagedatadif[i+1][j][0]+((errorred*5)/16));
        Imagedatadif[i+1][j-1][0]=(Imagedatadif[i+1][j-1][0]+((errorred*3)/16));

        Imagedatadif[i][j+1][1]=(Imagedatadif[i][j+1][1]+((errorgreen*7)/16));
        Imagedatadif[i+1][j+1][1]=(Imagedatadif[i+1][j+1][1]+((errorgreen*1)/16));
        Imagedatadif[i+1][j][1]=(Imagedatadif[i+1][j][1]+((errorgreen*5)/16));
        Imagedatadif[i+1][j-1][1]=(Imagedatadif[i+1][j-1][1]+((errorgreen*3)/16));

        Imagedatadif[i][j+1][2]=(Imagedatadif[i][j+1][2]+((errorblue*7)/16));
        Imagedatadif[i+1][j+1][2]=(Imagedatadif[i+1][j+1][2]+((errorblue*1)/16));
        Imagedatadif[i+1][j][2]=(Imagedatadif[i+1][j][2]+((errorblue*5)/16));
        Imagedatadif[i+1][j-1][2]=(Imagedatadif[i+1][j-1][2]+((errorblue*3)/16));

        }

        int p=i+1;
        for(int q=Size2;q>0;q--){
            double r,g,b;
            r=Imagedatadif[p][q][0];
            g=Imagedatadif[p][q][1];
            b=Imagedatadif[p][q][2];

            int mbvq=pyramid(r,g,b);
            int* vp;
            vp=getNearestVertex(mbvq, r,g,b);

            double errorred=r-vp[0];
            double errorgreen=g-vp[1];
            double errorblue=b-vp[2];

            Imagedataoutput[p-1][q-1][0]=vp[0];
            Imagedataoutput[p-1][q-1][1]=vp[1];
            Imagedataoutput[p-1][q-1][2]=vp[2];



        Imagedatadif[p][q-1][0]=(Imagedatadif[p][q-1][0]+((errorred*7)/16));
        Imagedatadif[p+1][q-1][0]=(Imagedatadif[p+1][q-1][0]+((errorred*1)/16));
        Imagedatadif[p+1][q][0]=(Imagedatadif[p+1][q][0]+((errorred*5)/16));
        Imagedatadif[p+1][q+1][0]=(Imagedatadif[p+1][q+1][0]+((errorred*3)/16));

        Imagedatadif[p][q-1][1]=(Imagedatadif[p][q-1][1]+((errorgreen*7)/16));
        Imagedatadif[p+1][q-1][1]=(Imagedatadif[p+1][q-1][1]+((errorgreen*1)/16));
        Imagedatadif[p+1][q][1]=(Imagedatadif[p+1][q][1]+((errorgreen*5)/16));
        Imagedatadif[p+1][q+1][1]=(Imagedatadif[p+1][q+1][1]+((errorgreen*3)/16));

        Imagedatadif[p][q-1][2]=(Imagedatadif[p][q-1][2]+((errorblue*7)/16));
        Imagedatadif[p+1][q-1][2]=(Imagedatadif[p+1][q-1][2]+((errorblue*1)/16));
        Imagedatadif[p+1][q][2]=(Imagedatadif[p+1][q][2]+((errorblue*5)/16));
        Imagedatadif[p+1][q+1][2]=(Imagedatadif[p+1][q+1][2]+((errorblue*3)/16));


        }

}
for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){
        for(int k=0;k<3;k++){
            Imagedataoutput[i][j][k]=((unsigned char)Imagedataoutput[i][j][k]);
        }
    }
}

	// Write image data (filename specified by second argument) from image data matrix

	if (!(file=fopen(argv[2],"wb"))) {
		cout << "Cannot open file: " << argv[2] << endl;
		exit(1);
	}
	fwrite(Imagedataoutput, sizeof(unsigned char), (Size1)*(Size2)*3, file);
	fclose(file);
cout<<"end";
	return 0;

}

