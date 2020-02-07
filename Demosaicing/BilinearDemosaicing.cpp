// This sample code reads in image data from a RAW image file and
	int Size2 = 390;
			Size2 = atoi(argv[5]);
//Allocate Bytes Per pixel for the output
int BytesPerPixelop=3;
//Number of row/column extensions on each edge of the image=(N-1)/2
int N=3;
//Assigning a Boundary extended matrix
    unsigned char Imagedata[Size1+N-1][Size2+N-1][BytesPerPixel];
    unsigned char Imagedataoutput[Size1][Size2][BytesPerPixelop];

//Boundary extension for the columns
    int l=(N-1)/2;
    for(int j=0;j<((N-1)/2);j++){
        for(int i= ((N-1)/2); i<(Size1+(N-(((N-1)/2)+1))); i++){
            Imagedata[i][j][0]=Imagedatainput[i-((N-1)/2)][l][0];
            Imagedata[i][Size2+(N-2)-j][0]=Imagedatainput[i-((N-1)/2)][Size2-(l+1)][0];

        }
        l--;
    }

//Boundary extension for the rows
     l=(N-1)/2;
    for(int j=0;j<(((N-1)/2)+1);j++){
        for(int i= ((N-1)/2); i<(Size2+(N-(((N-1)/2)+1))); i++){
            Imagedata[j][i][0]=Imagedatainput[l][i-((N-1)/2)][0];
            Imagedata[Size1+(N-2)-j][i][0]=Imagedatainput[Size1-(l+1)][i-((N-1)/2)][0];

        }
        l--;
    }
//Values taken for Imagedata from Imagedatainput
    for(int i=((N-1)/2); i<(Size1+(N-(((N-1)/2)+1)));i++){
        for(int j=((N-1)/2); j<(Size2+(N-(((N-1)/2)+1))); j++){
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
     int q=(Size2+(N-(((N-1)/2)+1)))-2;
    for(int i=0;i<((N-1)/2);i++){
        for(int j=(Size2+(N-(((N-1)/2)+1)));j<(Size2-1+N);j++){
            Imagedata[i][j][0]=Imagedata[i][q][0];
            q=q-2;
        } q=(Size2+(N-(((N-1)/2)+1)))-2;
    }

//Bottom left
       int r=N-1;
    for(int i=(Size1+(N-(((N-1)/2)+1)));i<((N-1)/2);i++){
        for(int j=0;j<((N-1)/2);j++){
            Imagedata[i][j][0]=Imagedata[i][r][0];
            r--;
        } r=(N-1);
    }

//Bottom right
       int s=(Size2+(N-(((N-1)/2)+1)))-2;
    for(int i=(Size1+(N-(((N-1)/2)+1)));i<(Size1-1+N);i++){
        for(int j=(Size2+(N-(((N-1)/2)+1)));j<(Size2-1+N);j++){
            Imagedata[i][j][0]=Imagedata[i][s][0];
            s=s-2;
        } s=(Size2+(N-(((N-1)/2)+1)))-2;
    }

//Finding the pixel values for imagedataoutput by bilinear interpolation
for(int y = 1;  y< Size2+1; y++){

        for (int x = 1; x < Size1+1; x++){


        if((y-1)%2==0){ // even columns

            if((x-1)%2==0){ //green is present in even columns and even rows

                    Imagedataoutput[x-1][y-1][2]= ((int)Imagedata[(x+1)][(y)][0]+(int)Imagedata[(x-1)][(y)][0])/2;//blueingreen

                    Imagedataoutput[x-1][y-1][1]=(int)Imagedata[x][y][0];

                    Imagedataoutput[x-1][y-1][0]= ((int)Imagedata[(x)][(y-1)][0]+(int)Imagedata[(x)][(y+1)][0])/2;  //redingreen


            }

            if((x-1)%2!=0){ //blue is present only in even columns and odd rows


                    Imagedataoutput[x-1][y-1][0]= ((int)Imagedata[(x+1)][(y+1)][0]+(int)Imagedata[(x+1)][(y-1)][0]+(int)Imagedata[(x-1)][(y-1)][0]+(int)Imagedata[(x-1)][(y+1)][0])/4; //redinblue

                    Imagedataoutput[x-1][y-1][1]= ((int)Imagedata[x][(y+1)][0]+(int)Imagedata[x][(y-1)][0]+(int)Imagedata[(x-1)][y][0]+(int)Imagedata[(x+1)][y][0])/4;  //greeninblue

                    Imagedataoutput[x-1][y-1][2]=(int)Imagedata[x][y][0];
                }
        }


        if((y-1)%2!=0){ //odd columns

          if((x-1)%2!=0){ //green is present in odd columns and odd rows

            Imagedataoutput[x-1][y-1][0]= ((int)Imagedata[(x+1)][(y)][0]+(int)Imagedata[(x-1)][(y)][0])/2;  //redingreen

            Imagedataoutput[x-1][y-1][2]= ((int)Imagedata[(x)][(y-1)][0]+(int)Imagedata[(x)][(y+1)][0])/2; //blueingreen

            Imagedataoutput[x-1][y-1][1]=(int)Imagedata[x][y][0];
          }
          if((x-1)%2==0){ //red is present only in odd columns and even rows

                    Imagedataoutput[x-1][y-1][1]= ((int)Imagedata[(x+1)][(y)][0]+(int)Imagedata[(x-1)][(y)][0]+(int)Imagedata[(x)][(y+1)][0]+(int)Imagedata[(x)][(y-1)][0])/4; //greeninred

                    Imagedataoutput[x-1][y-1][2]= ((int)Imagedata[(x+1)][(y-1)][0]+(int)Imagedata[(x-1)][(y-1)][0]+(int)Imagedata[(x+1)][(y+1)][0]+(int)Imagedata[(x-1)][(y+1)][0])/4; //blueinred

                    Imagedataoutput[x-1][y-1][0]=(int)Imagedata[x][y][0];


          }
        }

    }

}