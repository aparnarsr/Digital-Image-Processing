// This sample code reads in image data from a RAW image file and
	int Size2 = 600;
			Size2 = atoi(argv[5]);

//Assigning a boundary extended matrix
unsigned char Imagedata[Size1+2][Size2+2];

//Boundary extension for the columns

for(int i= 0; i<(Size1+1); i++){
    Imagedata[i][0]=(unsigned char)0;
    Imagedata[i][Size2+1]=(unsigned char)0;

}

//Boundary extension for the rows
        for(int i= 1; i<(Size2+1); i++){
            Imagedata[0][i]=(unsigned char)0;
            Imagedata[Size1+1][i]=(unsigned char)0;

        }

//Values taken for Imagedata from Imagedatainput
    for(int i=1; i<(Size1+1);i++){
        for(int j=1; j<(Size2+1); j++){
            Imagedata[i][j]=Imagedatainput[i-1][j-1];
        }
    }
//Corner matrices formed for Imagedata

Imagedata[0][0]=(unsigned char)0;
Imagedata[0][Size2+1]=(unsigned char)0;
Imagedata[Size1+1][0]=(unsigned char)0;
Imagedata[Size1+1][Size2+1]=(unsigned char)0;


unsigned char Imagedatadif[Size1+2][Size2+2];
unsigned char Imagedataoutput[Size1][Size2];


for(int i=0;i<Size1+2;i++){
    for(int j=0;j<Size2+2;j++){
        Imagedatadif[i][j]=Imagedata[i][j];
    }
}

for(int i=1; i<Size1+1; i+=2){
    for(int j=1; j<Size2+1; j++){
        int pixel=Imagedatadif[i][j];
        int temp;
        if(pixel>=127){
            temp=255;
        }
        else{
            temp=0;
        }
        int e=Imagedatadif[i][j]-temp;

        Imagedatadif[i][j+1]=Imagedatadif[i][j+1]+((e*7)/16);
        Imagedatadif[i+1][j+1]=Imagedatadif[i+1][j+1]+((e*1)/16);
        Imagedatadif[i+1][j]=Imagedatadif[i+1][j]+((e*5)/16);
        Imagedatadif[i+1][j-1]=Imagedatadif[i+1][j-1]+((e*3)/16);
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
            Imagedatadif[p][q-1]=Imagedatadif[p][q-1]+((e*7)/16);
            Imagedatadif[p+1][q-1]=Imagedatadif[p+1][q-1]+((e*1)/16);
            Imagedatadif[p+1][q]=Imagedatadif[p+1][q]+((e*5)/16);
            Imagedatadif[p+1][q+1]=Imagedatadif[p+1][q+1]+((e*3)/16);

        }

}


for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){

        Imagedataoutput[i][j]=Imagedatadif[i+1][j+1];

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
}