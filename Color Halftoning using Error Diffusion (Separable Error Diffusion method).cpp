// This sample code reads in image data from a RAW image file and
	int Size2 = 500;
			Size2 = atoi(argv[5]);

//Assigning a boundary extended matrix
unsigned char Imagedatadif[Size1+2][Size2+2][3];


cout<<"a";

//Boundary extension for the columns

for(int i= 1; i<(Size1+1); i++){
    for(int k=0;k<3;k++){
        Imagedatadif[i][0][k]=(unsigned char)0;
        Imagedatadif[i][Size2+1][k]=(unsigned char)0;
    }
}

//Boundary extension for the rows
        for(int j= 1; j<(Size2+1); j++){
            for(int k=0;k<3;k++){
                Imagedatadif[0][j][k]=(unsigned char)0;
                Imagedatadif[Size1+1][j][k]=(unsigned char)0;
            }

        }


//Corner matrices formed for Imagedata
for(int k=0;k<3;k++){
    Imagedatadif[0][0][k]=(unsigned char)0;
    Imagedatadif[0][Size2+1][k]=(unsigned char)0;
    Imagedatadif[Size1+1][0][k]=(unsigned char)0;
    Imagedatadif[Size1+1][Size2+1][k]=(unsigned char)0;
}

//Values taken for Imagedata from Imagedatainput
for(int i=1; i<(Size1+1);i++){
    for(int j=1; j<(Size2+1); j++){
        for(int k=0;k<3;k++){
            Imagedatadif[i][j][k]=(unsigned char)255-(Imagedatainput[i-1][j-1][k]);
        }
    }
}


for(int i=1; i<Size1+1; i+=2){
    for(int j=1; j<Size2+1; j++){
        for(int k=0;k<3;k++){
            int pixel=Imagedatadif[i][j][k];
            int temp;
            if(pixel>=127){
                temp=255;
            }
            else{
                temp=0;
            }
            int e=Imagedatadif[i][j][k]-(unsigned char)temp;

            Imagedatadif[i][j+1][k]=Imagedatadif[i][j+1][k]+((e*7)/16);
            Imagedatadif[i+1][j+1][k]=Imagedatadif[i+1][j+1][k]+((e*1)/16);
            Imagedatadif[i+1][j][k]=Imagedatadif[i+1][j][k]+((e*5)/16);
            Imagedatadif[i+1][j-1][k]=Imagedatadif[i+1][j-1][k]+((e*3)/16);
        }
    }
        int p=i+1;
        for(int q=Size2;q>0;q--){
            for(int k=0;k<3;k++){
                int pixel=Imagedatadif[p][q][k];
                int temp;
                if(pixel>=127){
                    temp=255;

                }
                else{
                    temp=0;
                }
                int e=Imagedatadif[p][q][k]-(unsigned char)temp;
                Imagedatadif[p][q-1][k]=Imagedatadif[p][q-1][k]+((e*7)/16);
                Imagedatadif[p+1][q-1][k]=Imagedatadif[p+1][q-1][k]+((e*1)/16);
                Imagedatadif[p+1][q][k]=Imagedatadif[p+1][q][k]+((e*5)/16);
                Imagedatadif[p+1][q+1][k]=Imagedatadif[p+1][q+1][k]+((e*3)/16);

        }
    }
}

cout<<"d";

unsigned char Imagedataoutput[Size1][Size2][3];

for(int i=0;i<Size1;i++){
    for(int j=0;j<Size2;j++){
        for(int k=0;k<3;k++){
            Imagedataoutput[i][j][k]=((unsigned char)255-(Imagedatadif[i+1][j+1][k]));
        }
    }
}
for(int i=0; i<Size1;i++){
    for(int j=0; j<Size2; j++){
        for(int k=0;k<3;k++){
        if(Imagedataoutput[i][j][k]>=127){
            Imagedataoutput[i][j][k]=255;
        }
        else
            Imagedataoutput[i][j][k]=0;
        }

    }
}

cout<<"e";

cout<<"f";

