// This sample code reads in image data from a RAW image file and
// writes it into another file

// NOTE:	The code assumes that the image is of size 256 x 256 and is in the
//			RAW format. You will need to make corresponding changes to
//			accommodate images of different sizes and/or types

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])

{
	// Define file pointer and variables
	FILE *file;
	int BytesPerPixel;
	int Size = 375;

	// Check for proper syntax
	if (argc < 3){
		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
		cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;
		return 0;
	}

	// Check if image is grayscale or color
	if (argc < 4){
		BytesPerPixel = 1; // default is grey image
	}
	else {
		BytesPerPixel = atoi(argv[3]);
		// Check if size is specified
		if (argc >= 5){
			Size = atoi(argv[4]);
		}
	}

	// Allocate image data array
	unsigned char Imagedatainput[Size][Size];

	// Read image (filename specified by first argument) into image data matrix
	if (!(file=fopen(argv[1],"rb"))) {
		cout << "Cannot open file: " << argv[1] <<endl;
		exit(1);
	}
	fread(Imagedatainput, sizeof(unsigned char), Size*Size, file);
	fclose(file);

	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////
unsigned char M[Size+2][Size+2];
unsigned char Imagedatainputext[Size+2][Size+2];
unsigned char Imagedataout[Size][Size];
cout<<"a";

for(int i=0;i<Size;i++){
    for(int j=0;j<Size;j++){
        Imagedatainput[i][j]=(Imagedatainput[i][j])/255;
    }
}

for(int i=0;i<Size;i++){
    Imagedatainputext[0][i]=0;
    Imagedatainputext[i][0]=0;
    Imagedatainputext[Size+1][i]=0;
    Imagedatainputext[i][Size+1]=0;

}

cout<<"b";
for(int i=0;i<Size;i++){
    for(int j=0;j<Size;j++){
        Imagedatainputext[i+1][j+1]=Imagedatainput[i][j];
    }
}

cout<<"c";

//conditional
vector<vector<vector<unsigned char > > > masks_c;

vector<vector<unsigned char> > S4a_1 ={{0,1,0},{0,1,1},{0,0,0}};
 masks_c.push_back(S4a_1);
vector<vector<unsigned char> > S4a_2 ={{0,1,0},{1,1,0},{0,0,0}};
 masks_c.push_back(S4a_2);
vector<vector<unsigned char> > S4a_3 ={{0,0,0},{1,1,0},{0,1,0}};
 masks_c.push_back(S4a_3);
vector<vector<unsigned char> > S4a_4 ={{0,0,0},{0,1,1},{0,1,0}};
 masks_c.push_back(S4a_4);

vector<vector<unsigned char> > S4b_1 ={{0,0,1},{0,1,1},{0,0,1}};
 masks_c.push_back(S4b_1);
vector<vector<unsigned char> > S4b_2 ={{1,1,1},{0,1,0},{0,0,0}};
 masks_c.push_back(S4b_2);
vector<vector<unsigned char> > S4b_3 ={{1,0,0},{1,1,0},{1,0,0}};
 masks_c.push_back(S4b_3);
vector<vector<unsigned char> > S4b_4 ={{0,0,0},{0,1,0},{1,1,1}};
 masks_c.push_back(S4b_4);

vector<vector<unsigned char> > S6b_1 ={{1,1,1},{0,1,1},{0,0,0}};
 masks_c.push_back(S6b_1);
vector<vector<unsigned char> > S6b_2 ={{0,1,1},{0,1,1},{0,0,1}};
 masks_c.push_back(S6b_2);
vector<vector<unsigned char> > S6b_3 ={{1,1,1},{1,1,0},{0,0,0}};
 masks_c.push_back(S6b_3);
vector<vector<unsigned char> > S6b_4 ={{1,1,0},{1,1,0},{1,0,0}};
 masks_c.push_back(S6b_4);
vector<vector<unsigned char> > S6b_5 ={{1,0,0},{1,1,0},{1,1,0}};
 masks_c.push_back(S6b_5);
vector<vector<unsigned char> > S6b_6 ={{0,0,0},{1,1,0},{1,1,1}};
 masks_c.push_back(S6b_6);
vector<vector<unsigned char> > S6b_7 ={{0,0,0},{0,1,1},{1,1,1}};
 masks_c.push_back(S6b_7);
vector<vector<unsigned char> > S6b_8 ={{0,0,1},{0,1,1},{0,1,1}};
 masks_c.push_back(S6b_8);

vector<vector<unsigned char> > S7_1 ={{1,1,1},{0,1,1},{0,0,1}};
 masks_c.push_back(S7_1);
vector<vector<unsigned char> > S7_2 ={{1,1,1},{1,1,0},{1,0,0}};
 masks_c.push_back(S7_2);
vector<vector<unsigned char> > S7_3 ={{1,0,0},{1,1,0},{1,1,1}};
 masks_c.push_back(S7_3);
vector<vector<unsigned char> > S7_4 ={{0,0,1},{0,1,1},{1,1,1}};
 masks_c.push_back(S7_4);

vector<vector<unsigned char> > S8_1 ={{0,1,1},{0,1,1},{0,1,1}};
 masks_c.push_back(S8_1);
vector<vector<unsigned char> > S8_2 ={{1,1,1},{1,1,1},{0,0,0}};
 masks_c.push_back(S8_2);
vector<vector<unsigned char> > S8_3 ={{1,1,0},{1,1,0},{1,1,0}};
 masks_c.push_back(S8_3);
vector<vector<unsigned char> > S8_4 ={{0,0,0},{1,1,1},{1,1,1}};
 masks_c.push_back(S8_4);

vector<vector<unsigned char> > S9_1 ={{1,1,1},{0,1,1},{0,1,1}};
 masks_c.push_back(S9_1);
vector<vector<unsigned char> > S9_2 ={{0,1,1},{0,1,1},{1,1,1}};
 masks_c.push_back(S9_2);
vector<vector<unsigned char> > S9_3 ={{1,1,1},{1,1,1},{1,0,0}};
 masks_c.push_back(S9_3);
vector<vector<unsigned char> > S9_4 ={{1,1,1},{1,1,1},{0,0,1}};
 masks_c.push_back(S9_4);
vector<vector<unsigned char> > S9_5 ={{1,1,1},{1,1,0},{1,1,0}};
 masks_c.push_back(S9_5);
vector<vector<unsigned char> > S9_6 ={{1,1,0},{1,1,0},{1,1,1}};
 masks_c.push_back(S9_6);
vector<vector<unsigned char> > S9_7 ={{1,0,0},{1,1,1},{1,1,1}};
vector<vector<unsigned char> > S9_8 ={{0,0,1},{1,1,1},{1,1,1}};
 masks_c.push_back(S9_8);
 masks_c.push_back(S9_7);

vector<vector<unsigned char> > S10_1 ={{1,1,1},{0,1,1},{1,1,1}};
 masks_c.push_back(S10_1);
vector<vector<unsigned char> > S10_2 ={{1,1,1},{1,1,1},{1,0,1}};
 masks_c.push_back(S10_2);
vector<vector<unsigned char> > S10_3 ={{1,1,1},{1,1,0},{1,1,1}};
 masks_c.push_back(S10_3);
vector<vector<unsigned char> > S10_4 ={{1,0,1},{1,1,1},{1,1,1}};
 masks_c.push_back(S10_4);

vector<vector<unsigned char> > S11_1 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_c.push_back(S11_1);
vector<vector<unsigned char> > S11_2 ={{1,1,1},{1,1,1},{1,1,0}};
 masks_c.push_back(S11_2);
vector<vector<unsigned char> > S11_3 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_c.push_back(S11_3);
vector<vector<unsigned char> > S11_4 ={{0,1,1},{1,1,1},{1,1,1}};
 masks_c.push_back(S11_4);



//unconditional
vector<vector<vector<unsigned char> > > masks_uc;

vector<vector<unsigned char> > S_spur_1 ={{0,0,0},{0,1,0},{0,0,1}};
 masks_uc.push_back(S_spur_1);
vector<vector<unsigned char> > S_spur_2 ={{0,0,0},{0,1,0},{1,0,0}};
 masks_uc.push_back(S_spur_2);
vector<vector<unsigned char> > S_spur_3 ={{0,0,1},{0,1,0},{0,0,0}};
 masks_uc.push_back(S_spur_3);
vector<vector<unsigned char> > S_spur_4 ={{1,0,0},{0,1,0},{0,0,0}};
 masks_uc.push_back(S_spur_4);

vector<vector<unsigned char> > S_s4c_1 ={{0,0,0},{0,1,0},{0,1,0}};
 masks_uc.push_back(S_s4c_1);
vector<vector<unsigned char> > S_s4c_2 ={{0,0,0},{0,1,1},{0,0,0}};
 masks_uc.push_back(S_s4c_2);
vector<vector<unsigned char> > S_s4c_3 ={{0,0,0},{1,1,0},{0,0,0}};
 masks_uc.push_back(S_s4c_3);
vector<vector<unsigned char> > S_s4c_4 ={{0,1,0},{0,1,0},{0,0,0}};
 masks_uc.push_back(S_s4c_4);

vector<vector<unsigned char> > S_lco_1 ={{0,1,0},{0,1,1},{0,0,0}};
 masks_uc.push_back(S_lco_1);
vector<vector<unsigned char> > S_lco_2 ={{0,1,0},{1,1,0},{0,0,0}};
 masks_uc.push_back(S_lco_2);
vector<vector<unsigned char> > S_lco_3 ={{0,0,0},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_lco_3);
vector<vector<unsigned char> > S_lco_4 ={{0,0,0},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_lco_4);

//vector<vector<unsigned char>> S_cc_1 ={{1,1,'D'},{1,1,'D'},{'D','D','D'}};
vector<vector<unsigned char> > S_cc_1_1 ={{1,1,0},{1,1,0},{0,0,0}};
 masks_uc.push_back(S_cc_1_1);
vector<vector<unsigned char> > S_cc_1_2 ={{1,1,0},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_cc_1_2);
vector<vector<unsigned char> > S_cc_1_3 ={{1,1,0},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_cc_1_3);
vector<vector<unsigned char> > S_cc_1_4 ={{1,1,0},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_cc_1_4);
vector<vector<unsigned char> > S_cc_1_5 ={{1,1,0},{1,1,0},{1,0,0}};
 masks_uc.push_back(S_cc_1_5);
vector<vector<unsigned char> > S_cc_1_6 ={{1,1,0},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_cc_1_6);
vector<vector<unsigned char> > S_cc_1_7 ={{1,1,0},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_cc_1_7);
vector<vector<unsigned char> > S_cc_1_8 ={{1,1,0},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_cc_1_8);
vector<vector<unsigned char> > S_cc_1_9 ={{1,1,0},{1,1,1},{0,0,0}};
 masks_uc.push_back(S_cc_1_9);
vector<vector<unsigned char> > S_cc_1_10={{1,1,0},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_cc_1_10);
vector<vector<unsigned char> > S_cc_1_11 ={{1,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_cc_1_11);
vector<vector<unsigned char> > S_cc_1_12 ={{1,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_1_12);
vector<vector<unsigned char> > S_cc_1_13 ={{1,1,0},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_cc_1_13);
vector<vector<unsigned char> > S_cc_1_14 ={{1,1,0},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_cc_1_14);
vector<vector<unsigned char> > S_cc_1_15 ={{1,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_cc_1_15);
vector<vector<unsigned char> > S_cc_1_16 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_1_16);
vector<vector<unsigned char> > S_cc_1_17 ={{1,1,1},{1,1,0},{0,0,0}};
 masks_uc.push_back(S_cc_1_17);
vector<vector<unsigned char> > S_cc_1_18 ={{1,1,1},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_cc_1_18);
vector<vector<unsigned char> > S_cc_1_19 ={{1,1,1},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_cc_1_19);
vector<vector<unsigned char> > S_cc_1_20 ={{1,1,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_cc_1_20);
vector<vector<unsigned char> > S_cc_1_21 ={{1,1,1},{1,1,0},{1,0,0}};
 masks_uc.push_back(S_cc_1_21);
vector<vector<unsigned char> > S_cc_1_22 ={{1,1,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_cc_1_22);
vector<vector<unsigned char> > S_cc_1_23 ={{1,1,1},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_cc_1_23);
vector<vector<unsigned char> > S_cc_1_24 ={{1,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_cc_1_24);
vector<vector<unsigned char> > S_cc_1_25 ={{1,1,1},{1,1,1},{0,0,0}};
 masks_uc.push_back(S_cc_1_25);
vector<vector<unsigned char> > S_cc_1_26 ={{1,1,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_cc_1_26);
vector<vector<unsigned char> > S_cc_1_27 ={{1,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_cc_1_27);
vector<vector<unsigned char> > S_cc_1_28 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_1_28);
vector<vector<unsigned char> > S_cc_1_29 ={{1,1,1},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_cc_1_29);
vector<vector<unsigned char> > S_cc_1_30 ={{1,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_cc_1_30);
vector<vector<unsigned char> > S_cc_1_31 ={{1,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_cc_1_31);
vector<vector<unsigned char> > S_cc_1_32 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_1_32);

//vector<vector<unsigned char>> S_cc_2 ={{'D','D','D'},{'D',1,1},{'D',1,1}};
vector<vector<unsigned char> > S_cc_2_1 ={{0,0,0},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_1);
vector<vector<unsigned char> > S_cc_2_2 ={{0,0,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_2);
vector<vector<unsigned char> > S_cc_2_3 ={{0,0,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_3);
vector<vector<unsigned char> > S_cc_2_4 ={{0,0,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_4);
vector<vector<unsigned char> > S_cc_2_5 ={{0,0,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_5);
vector<vector<unsigned char> > S_cc_2_6 ={{0,0,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_6);
vector<vector<unsigned char> > S_cc_2_7 ={{0,0,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_7);
vector<vector<unsigned char> > S_cc_2_8 ={{0,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_8);
vector<vector<unsigned char> > S_cc_2_9 ={{0,1,0},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_9);
vector<vector<unsigned char> > S_cc_2_10 ={{0,1,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_10);
vector<vector<unsigned char> > S_cc_2_11 ={{0,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_11);
vector<vector<unsigned char> > S_cc_2_12 ={{0,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_12);
vector<vector<unsigned char> > S_cc_2_13 ={{0,1,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_13);
vector<vector<unsigned char> > S_cc_2_14 ={{0,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_14);
vector<vector<unsigned char> > S_cc_2_15 ={{0,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_15);
vector<vector<unsigned char> > S_cc_2_16 ={{0,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_16);
vector<vector<unsigned char> > S_cc_2_17 ={{1,0,0},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_17);
vector<vector<unsigned char> > S_cc_2_18 ={{1,0,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_18);
vector<vector<unsigned char> > S_cc_2_19 ={{1,0,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_19);
vector<vector<unsigned char> > S_cc_2_20 ={{1,0,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_20);
vector<vector<unsigned char> > S_cc_2_21 ={{1,0,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_21);
vector<vector<unsigned char> > S_cc_2_22 ={{1,0,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_22);
vector<vector<unsigned char> > S_cc_2_23 ={{1,0,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_23);
vector<vector<unsigned char> > S_cc_2_24 ={{1,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_24);
vector<vector<unsigned char> > S_cc_2_25 ={{1,1,0},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_25);
vector<vector<unsigned char> > S_cc_2_26 ={{1,1,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_26);
vector<vector<unsigned char> > S_cc_2_27 ={{1,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_27);
vector<vector<unsigned char> > S_cc_2_28 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_28);
vector<vector<unsigned char> > S_cc_2_29 ={{1,1,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_29);
vector<vector<unsigned char> > S_cc_2_30 ={{1,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_30);
vector<vector<unsigned char> > S_cc_2_31 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_cc_2_31);
vector<vector<unsigned char> > S_cc_2_32 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_cc_2_32);

//vector<vector<unsigned char> > S_tb_1 ={{'D',1,'D'},{1,1,1},{'D','D','D'}};
vector<vector<unsigned char> > S_tb_1_1 ={{0,1,0},{1,1,1},{0,0,0}};
 masks_uc.push_back(S_tb_1_1);
vector<vector<unsigned char> > S_tb_1_2 ={{0,1,0},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_tb_1_2);
vector<vector<unsigned char> > S_tb_1_3 ={{0,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_1_3);
vector<vector<unsigned char> > S_tb_1_4 ={{0,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_1_4);
vector<vector<unsigned char> > S_tb_1_5 ={{0,1,0},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_tb_1_5);
vector<vector<unsigned char> > S_tb_1_6 ={{0,1,0},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_tb_1_6);
vector<vector<unsigned char> > S_tb_1_7 ={{0,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_1_7);
vector<vector<unsigned char> > S_tb_1_8 ={{0,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_1_8);
vector<vector<unsigned char> > S_tb_1_9 ={{0,1,1},{1,1,1},{0,0,0}};
 masks_uc.push_back(S_tb_1_9);
vector<vector<unsigned char> > S_tb_1_10 ={{0,1,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_tb_1_10);
vector<vector<unsigned char> > S_tb_1_11 ={{0,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_1_11);
vector<vector<unsigned char> > S_tb_1_12 ={{0,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_1_12);
vector<vector<unsigned char> > S_tb_1_13 ={{0,1,1},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_tb_1_13);
vector<vector<unsigned char> > S_tb_1_14 ={{0,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_tb_1_14);
vector<vector<unsigned char> > S_tb_1_15 ={{0,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_1_15);
vector<vector<unsigned char> > S_tb_1_16 ={{0,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_1_16);
vector<vector<unsigned char> > S_tb_1_17 ={{1,1,0},{1,1,1},{0,0,0}};
 masks_uc.push_back(S_tb_1_17);
vector<vector<unsigned char> > S_tb_1_18 ={{1,1,0},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_tb_1_18);
vector<vector<unsigned char> > S_tb_1_19 ={{1,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_1_19);
vector<vector<unsigned char> > S_tb_1_20 ={{1,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_1_20);
vector<vector<unsigned char> > S_tb_1_21 ={{1,1,0},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_tb_1_21);
vector<vector<unsigned char> > S_tb_1_22 ={{1,1,0},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_tb_1_22);
vector<vector<unsigned char> > S_tb_1_23 ={{1,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_1_23);
vector<vector<unsigned char> > S_tb_1_24 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_1_24);
vector<vector<unsigned char> > S_tb_1_25 ={{1,1,1},{1,1,1},{0,0,0}};
 masks_uc.push_back(S_tb_1_25);
vector<vector<unsigned char> > S_tb_1_26 ={{1,1,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_tb_1_26);
vector<vector<unsigned char> > S_tb_1_27 ={{1,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_1_27);
vector<vector<unsigned char> > S_tb_1_28 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_1_28);
vector<vector<unsigned char> > S_tb_1_29 ={{1,1,1},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_tb_1_29);
vector<vector<unsigned char> > S_tb_1_30 ={{1,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_tb_1_30);
vector<vector<unsigned char> > S_tb_1_31 ={{1,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_1_31);
vector<vector<unsigned char> > S_tb_1_32 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_1_32);

 //vector<vector<unsigned char> > S_tb_2 ={{'D',1,'D'},{1,1,'D'},{'D',1,'D'}};
vector<vector<unsigned char> > S_tb_2_1 ={{0,1,0},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_tb_2_1);
vector<vector<unsigned char> > S_tb_2_2 ={{0,1,0},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_tb_2_2);
vector<vector<unsigned char> > S_tb_2_3 ={{0,1,0},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_tb_2_3);
vector<vector<unsigned char> > S_tb_2_4 ={{0,1,0},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_tb_2_4);
vector<vector<unsigned char> > S_tb_2_5 ={{0,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_2_5);
vector<vector<unsigned char> > S_tb_2_6 ={{0,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_2_6);
vector<vector<unsigned char> > S_tb_2_7 ={{0,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_2_7);
vector<vector<unsigned char> > S_tb_2_8 ={{0,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_2_8);
vector<vector<unsigned char> > S_tb_2_9 ={{0,1,1},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_tb_2_9);
vector<vector<unsigned char> > S_tb_2_10 ={{0,1,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_tb_2_10);
vector<vector<unsigned char> > S_tb_2_11 ={{0,1,1},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_tb_2_11);
vector<vector<unsigned char> > S_tb_2_12 ={{0,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_tb_2_12);
vector<vector<unsigned char> > S_tb_2_13 ={{0,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_2_13);
vector<vector<unsigned char> > S_tb_2_14 ={{0,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_2_14);
vector<vector<unsigned char> > S_tb_2_15 ={{0,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_2_15);
vector<vector<unsigned char> > S_tb_2_16 ={{0,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_2_16);
vector<vector<unsigned char> > S_tb_2_17 ={{1,1,0},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_tb_2_17);
vector<vector<unsigned char> > S_tb_2_18 ={{1,1,0},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_tb_2_18);
vector<vector<unsigned char> > S_tb_2_19 ={{1,1,0},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_tb_2_19);
vector<vector<unsigned char> > S_tb_2_20 ={{1,1,0},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_tb_2_20);
vector<vector<unsigned char> > S_tb_2_21 ={{1,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_2_21);
vector<vector<unsigned char> > S_tb_2_22 ={{1,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_2_22);
vector<vector<unsigned char> > S_tb_2_23 ={{1,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_2_23);
vector<vector<unsigned char> > S_tb_2_24 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_2_24);
vector<vector<unsigned char> > S_tb_2_25 ={{1,1,1},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_tb_2_25);
vector<vector<unsigned char> > S_tb_2_26 ={{1,1,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_tb_2_26);
vector<vector<unsigned char> > S_tb_2_27 ={{1,1,1},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_tb_2_27);
vector<vector<unsigned char> > S_tb_2_28 ={{1,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_tb_2_28);
vector<vector<unsigned char> > S_tb_2_29 ={{1,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_2_29);
vector<vector<unsigned char> > S_tb_2_30 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_2_30);
vector<vector<unsigned char> > S_tb_2_31 ={{1,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_2_31);
vector<vector<unsigned char> > S_tb_2_32 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_2_32);

//vector<vector<unsigned char> > S_tb_3 ={{'D','D','D'},{1,1,1},{'D',1,'D'}};
vector<vector<unsigned char> > S_tb_3_1 ={{0,0,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_3_1);
vector<vector<unsigned char> > S_tb_3_2 ={{0,0,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_3_2);
vector<vector<unsigned char> > S_tb_3_3 ={{0,0,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_3_3);
vector<vector<unsigned char> > S_tb_3_4 ={{0,0,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_3_4);
vector<vector<unsigned char> > S_tb_3_5 ={{0,0,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_3_5);
vector<vector<unsigned char> > S_tb_3_6 ={{0,0,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_3_6);
vector<vector<unsigned char> > S_tb_3_7 ={{0,0,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_3_7);
vector<vector<unsigned char> > S_tb_3_8 ={{0,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_3_8);
vector<vector<unsigned char> > S_tb_3_9 ={{0,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_3_9);
vector<vector<unsigned char> > S_tb_3_10 ={{0,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_3_10);
vector<vector<unsigned char> > S_tb_3_11 ={{0,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_3_11);
vector<vector<unsigned char> > S_tb_3_12 ={{0,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_3_12);
vector<vector<unsigned char> > S_tb_3_13 ={{0,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_3_13);
vector<vector<unsigned char> > S_tb_3_14 ={{0,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_3_14);
vector<vector<unsigned char> > S_tb_3_15 ={{0,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_3_15);
vector<vector<unsigned char> > S_tb_3_16 ={{0,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_3_16);
vector<vector<unsigned char> > S_tb_3_17 ={{1,0,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_3_17);
vector<vector<unsigned char> > S_tb_3_18 ={{1,0,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_3_18);
vector<vector<unsigned char> > S_tb_3_19 ={{1,0,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_3_19);
vector<vector<unsigned char> > S_tb_3_20 ={{1,0,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_3_20);
vector<vector<unsigned char> > S_tb_3_21 ={{1,0,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_3_21);
vector<vector<unsigned char> > S_tb_3_22 ={{1,0,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_3_22);
vector<vector<unsigned char> > S_tb_3_23 ={{1,0,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_3_23);
vector<vector<unsigned char> > S_tb_3_24 ={{1,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_3_24);
vector<vector<unsigned char> > S_tb_3_25 ={{1,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_3_25);
vector<vector<unsigned char> > S_tb_3_26 ={{1,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_3_26);
vector<vector<unsigned char> > S_tb_3_27 ={{1,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_3_27);
vector<vector<unsigned char> > S_tb_3_28 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_3_28);
vector<vector<unsigned char> > S_tb_3_29 ={{1,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_3_29);
vector<vector<unsigned char> > S_tb_3_30 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_3_30);
vector<vector<unsigned char> > S_tb_3_31 ={{1,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_3_31);
vector<vector<unsigned char> > S_tb_3_32 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_3_32);

//vector<vector<unsigned char> > S_tb_4 ={{'D',1,'D'},{'D',1,1},{'D',1,'D'}};
vector<vector<unsigned char> > S_tb_4_1 ={{0,1,0},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_4_1);
vector<vector<unsigned char> > S_tb_4_2 ={{0,1,0},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_4_2);
vector<vector<unsigned char> > S_tb_4_3 ={{0,1,0},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_4_3);
vector<vector<unsigned char> > S_tb_4_4 ={{0,1,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_4_4);
vector<vector<unsigned char> > S_tb_4_5 ={{0,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_4_5);
vector<vector<unsigned char> > S_tb_4_6 ={{0,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_4_6);
vector<vector<unsigned char> > S_tb_4_7 ={{0,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_4_7);
vector<vector<unsigned char> > S_tb_4_8 ={{0,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_4_8);
vector<vector<unsigned char> > S_tb_4_9 ={{0,1,1},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_4_9);
vector<vector<unsigned char> > S_tb_4_10 ={{0,1,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_4_10);
vector<vector<unsigned char> > S_tb_4_11 ={{0,1,1},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_4_11);
vector<vector<unsigned char> > S_tb_4_12 ={{0,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_4_12);
vector<vector<unsigned char> > S_tb_4_13 ={{0,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_4_13);
vector<vector<unsigned char> > S_tb_4_14 ={{0,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_4_14);
vector<vector<unsigned char> > S_tb_4_15 ={{0,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_4_15);
vector<vector<unsigned char> > S_tb_4_16 ={{0,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_4_16);
vector<vector<unsigned char> > S_tb_4_17 ={{1,1,0},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_4_17);
vector<vector<unsigned char> > S_tb_4_18 ={{1,1,0},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_4_18);
vector<vector<unsigned char> > S_tb_4_19 ={{1,1,0},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_4_19);
vector<vector<unsigned char> > S_tb_4_20 ={{1,1,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_4_20);
vector<vector<unsigned char> > S_tb_4_21 ={{1,1,0},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_4_21);
vector<vector<unsigned char> > S_tb_4_22 ={{1,1,0},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_4_22);
vector<vector<unsigned char> > S_tb_4_23 ={{1,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_4_23);
vector<vector<unsigned char> > S_tb_4_24 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_4_24);
vector<vector<unsigned char> > S_tb_4_25 ={{1,1,1},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_4_25);
vector<vector<unsigned char> > S_tb_4_26 ={{1,1,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_4_26);
vector<vector<unsigned char> > S_tb_4_27 ={{1,1,1},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_4_27);
vector<vector<unsigned char> > S_tb_4_28 ={{1,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_4_28);
vector<vector<unsigned char> > S_tb_4_29 ={{1,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_tb_4_29);
vector<vector<unsigned char> > S_tb_4_30 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_tb_4_30);
vector<vector<unsigned char> > S_tb_4_31 ={{1,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_tb_4_31);
vector<vector<unsigned char> > S_tb_4_32 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_tb_4_32);

//vector<vector<unsigned char> > S_vb_1 ={{1,'D',1},{'D',1,'D'},{'A','B','C'}};

//vector<vector<unsigned char> > S_vb_1_1 ={{1,'D',1},{'D',1,'D'},{0,0,1}};
vector<vector<unsigned char> > S_vb_1_1_1 ={{1,0,1},{0,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_1_1_1);
vector<vector<unsigned char> > S_vb_1_1_2 ={{1,0,1},{0,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_1_1_2);
vector<vector<unsigned char> > S_vb_1_1_3 ={{1,0,1},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_1_1_3);
vector<vector<unsigned char> > S_vb_1_1_4 ={{1,1,1},{0,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_1_1_4);
vector<vector<unsigned char> > S_vb_1_1_5 ={{1,1,1},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_1_1_5);
vector<vector<unsigned char> > S_vb_1_1_6 ={{1,0,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_1_1_6);
vector<vector<unsigned char> > S_vb_1_1_7 ={{1,1,1},{0,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_1_1_7);
vector<vector<unsigned char> > S_vb_1_1_8 ={{1,1,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_1_1_8);


//vector<vector<unsigned char>> S_vb_1_2 ={{1,'D',1},{'D',1,'D'},{0,1,0}};
vector<vector<unsigned char> > S_vb_1_2_1 ={{1,0,1},{0,1,0},{0,1,0}};
 masks_uc.push_back(S_vb_1_2_1);
vector<vector<unsigned char> > S_vb_1_2_2 ={{1,0,1},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_vb_1_2_2);
vector<vector<unsigned char> > S_vb_1_2_3 ={{1,0,1},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_vb_1_2_3);
vector<vector<unsigned char> > S_vb_1_2_4 ={{1,1,1},{0,1,0},{0,1,0}};
 masks_uc.push_back(S_vb_1_2_4);
vector<vector<unsigned char> > S_vb_1_2_5 ={{1,0,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_vb_1_2_5);
vector<vector<unsigned char> > S_vb_1_2_6 ={{1,1,1},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_vb_1_2_6);
vector<vector<unsigned char> > S_vb_1_2_7 ={{1,1,1},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_vb_1_2_7);
vector<vector<unsigned char> > S_vb_1_2_8 ={{1,1,1},{1,1,1},{0,1,0}};
 masks_uc.push_back(S_vb_1_2_8);

//vector<vector<unsigned char>> S_vb_1_3 ={{1,'D',1},{'D',1,'D'},{1,0,0}};
vector<vector<unsigned char> > S_vb_1_3_1 ={{1,0,1},{0,1,0},{1,0,0}};
 masks_uc.push_back(S_vb_1_3_1);
vector<vector<unsigned char> > S_vb_1_3_2 ={{1,0,1},{0,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_1_3_2);
vector<vector<unsigned char> > S_vb_1_3_3 ={{1,0,1},{1,1,0},{1,0,0}};
 masks_uc.push_back(S_vb_1_3_3);
vector<vector<unsigned char> > S_vb_1_3_4 ={{1,1,1},{0,1,0},{1,0,0}};
 masks_uc.push_back(S_vb_1_3_4);
vector<vector<unsigned char> > S_vb_1_3_5 ={{1,1,1},{1,1,0},{1,0,0}};
 masks_uc.push_back(S_vb_1_3_5);
vector<vector<unsigned char> > S_vb_1_3_6 ={{1,1,1},{0,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_1_3_6);
vector<vector<unsigned char> > S_vb_1_3_7 ={{1,0,1},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_1_3_7);
vector<vector<unsigned char> > S_vb_1_3_8 ={{1,1,1},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_1_3_8);


//vector<vector<unsigned char>> S_vb_1_4 ={{1,'D',1},{'D',1,'D'},{0,1,1}};
vector<vector<unsigned char> > S_vb_1_4_1 ={{1,0,1},{0,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_1_4_1);
vector<vector<unsigned char> > S_vb_1_4_2 ={{1,0,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_1_4_2);
vector<vector<unsigned char> > S_vb_1_4_3 ={{1,1,1},{0,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_1_4_3);
vector<vector<unsigned char> > S_vb_1_4_4 ={{1,0,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_1_4_4);
vector<vector<unsigned char> > S_vb_1_4_5 ={{1,1,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_1_4_5);
vector<vector<unsigned char> > S_vb_1_4_6 ={{1,0,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_1_4_6);
vector<vector<unsigned char> > S_vb_1_4_7 ={{1,1,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_1_4_7);
vector<vector<unsigned char> > S_vb_1_4_8 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_1_4_8);


//vector<vector<unsigned char>> S_vb_1_5 ={{1,'D',1},{'D',1,'D'},{1,1,0}};
vector<vector<unsigned char> > S_vb_1_5_1 ={{1,0,1},{0,1,0},{1,1,0}};
 masks_uc.push_back(S_vb_1_5_1);
vector<vector<unsigned char> > S_vb_1_5_2 ={{1,0,1},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_1_5_2);
vector<vector<unsigned char> > S_vb_1_5_3 ={{1,0,1},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_vb_1_5_3);
vector<vector<unsigned char> > S_vb_1_5_4 ={{1,1,1},{0,1,0},{1,1,0}};
 masks_uc.push_back(S_vb_1_5_4);
vector<vector<unsigned char> > S_vb_1_5_5 ={{1,1,1},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_vb_1_5_5);
vector<vector<unsigned char> > S_vb_1_5_6 ={{1,0,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_1_5_6);
vector<vector<unsigned char> > S_vb_1_5_7 ={{1,1,1},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_1_5_7);
vector<vector<unsigned char> > S_vb_1_5_8 ={{1,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_1_5_8);

//vector<vector<unsigned char>> S_vb_1_6 ={{1,'D',1},{'D',1,'D'},{1,0,1}};
vector<vector<unsigned char> > S_vb_1_6_1 ={{1,0,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_1_6_1);
vector<vector<unsigned char> > S_vb_1_6_2 ={{1,0,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_1_6_2);
vector<vector<unsigned char> > S_vb_1_6_3 ={{1,1,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_1_6_3);
vector<vector<unsigned char> > S_vb_1_6_4 ={{1,0,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_1_6_4);
vector<vector<unsigned char> > S_vb_1_6_5 ={{1,1,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_1_6_5);
vector<vector<unsigned char> > S_vb_1_6_6 ={{1,0,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_1_6_6);
vector<vector<unsigned char> > S_vb_1_6_7 ={{1,1,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_1_6_7);
vector<vector<unsigned char> > S_vb_1_6_8 ={{1,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_1_6_8);

//vector<vector<unsigned char>> S_vb_1_7 ={{1,'D',1},{'D',1,'D'},{1,1,1}};
vector<vector<unsigned char> > S_vb_1_7_1 ={{1,0,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_1_7_1);
vector<vector<unsigned char> > S_vb_1_7_2 ={{1,0,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_1_7_2);
vector<vector<unsigned char> > S_vb_1_7_3 ={{1,0,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_1_7_3);
vector<vector<unsigned char> > S_vb_1_7_4 ={{1,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_1_7_4);
vector<vector<unsigned char> > S_vb_1_7_5 ={{1,1,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_1_7_5);
vector<vector<unsigned char> > S_vb_1_7_6 ={{1,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_1_7_6);
vector<vector<unsigned char> > S_vb_1_7_7 ={{1,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_1_7_7);
vector<vector<unsigned char> > S_vb_1_7_8 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_1_7_8);


//vector<vector<unsigned char>> S_vb_2 ={{1,'D','C'},{'D',1,'B'},{1,'D','A'}};

//vector<vector<unsigned char>> S_vb_2_1 ={{1,'D',0},{'D',1,0},{1,'D',1}};
vector<vector<unsigned char> > S_vb_2_1_1 ={{1,0,0},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_2_1_1);
vector<vector<unsigned char> > S_vb_2_1_2 ={{1,0,0},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_2_1_2);
vector<vector<unsigned char> > S_vb_2_1_3 ={{1,0,0},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_2_1_3);
vector<vector<unsigned char> > S_vb_2_1_4 ={{1,0,0},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_2_1_4);
vector<vector<unsigned char> > S_vb_2_1_5 ={{1,1,0},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_2_1_5);
vector<vector<unsigned char> > S_vb_2_1_6 ={{1,1,0},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_2_1_6);
vector<vector<unsigned char> > S_vb_2_1_7 ={{1,1,0},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_2_1_7);
vector<vector<unsigned char> > S_vb_2_1_8 ={{1,1,0},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_2_1_8);


//vector<vector<unsigned char>> S_vb_2_2 ={{1,'D',0},{'D',1,1},{1,'D',0}};
vector<vector<unsigned char> > S_vb_2_2_1 ={{1,0,0},{0,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_2_2_1);
vector<vector<unsigned char> > S_vb_2_2_2 ={{1,0,0},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_2_2_2);
vector<vector<unsigned char> > S_vb_2_2_3 ={{1,0,0},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_2_2_3);
vector<vector<unsigned char> > S_vb_2_2_4 ={{1,1,0},{0,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_2_2_4);
vector<vector<unsigned char> > S_vb_2_2_5 ={{1,0,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_2_2_5);
vector<vector<unsigned char> > S_vb_2_2_6 ={{1,1,0},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_2_2_6);
vector<vector<unsigned char> > S_vb_2_2_7 ={{1,1,0},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_2_2_7);
vector<vector<unsigned char> > S_vb_2_2_8 ={{1,1,0},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_2_2_8);


//vector<vector<unsigned char>> S_vb_2_3 ={{1,'D',0},{'D',1,1},{1,'D',1}};
vector<vector<unsigned char> > S_vb_2_3_1 ={{1,0,0},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_2_3_1);
vector<vector<unsigned char> > S_vb_2_3_2 ={{1,0,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_2_3_2);
vector<vector<unsigned char> > S_vb_2_3_3 ={{1,0,0},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_2_3_3);
vector<vector<unsigned char> > S_vb_2_3_4 ={{1,0,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_2_3_4);
vector<vector<unsigned char> > S_vb_2_3_5 ={{1,1,0},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_2_3_5);
vector<vector<unsigned char> > S_vb_2_3_6 ={{1,1,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_2_3_6);
vector<vector<unsigned char> > S_vb_2_3_7 ={{1,1,0},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_2_3_7);
vector<vector<unsigned char> > S_vb_2_3_8 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_2_3_7);


//vector<vector<unsigned char>> S_vb_2_4 ={{1,'D',1},{'D',1,0},{1,'D',0}};
vector<vector<unsigned char> > S_vb_2_4_1 ={{1,0,1},{0,1,0},{1,0,0}};
 masks_uc.push_back(S_vb_2_4_1);
vector<vector<unsigned char> > S_vb_2_4_2 ={{1,0,1},{0,1,0},{1,1,0}};
 masks_uc.push_back(S_vb_2_4_2);
vector<vector<unsigned char> > S_vb_2_4_3 ={{1,0,1},{1,1,0},{1,0,0}};
 masks_uc.push_back(S_vb_2_4_3);
vector<vector<unsigned char> > S_vb_2_4_4 ={{1,0,1},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_vb_2_4_4);
vector<vector<unsigned char> > S_vb_2_4_5 ={{1,1,1},{0,1,0},{1,0,0}};
 masks_uc.push_back(S_vb_2_4_5);
vector<vector<unsigned char> > S_vb_2_4_6 ={{1,1,1},{0,1,0},{1,1,0}};
 masks_uc.push_back(S_vb_2_4_6);
vector<vector<unsigned char> > S_vb_2_4_7 ={{1,1,1},{1,1,0},{1,0,0}};
 masks_uc.push_back(S_vb_2_4_7);
vector<vector<unsigned char> > S_vb_2_4_8 ={{1,1,1},{1,1,0},{1,1,0}};
 masks_uc.push_back(S_vb_2_4_8);

//vector<vector<unsigned char>> S_vb_2_5 ={{1,'D',1},{'D',1,0},{1,'D',1}};
vector<vector<unsigned char> > S_vb_2_5_1 ={{1,0,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_2_5_1);
vector<vector<unsigned char> > S_vb_2_5_2 ={{1,0,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_2_5_2);
vector<vector<unsigned char> > S_vb_2_5_3 ={{1,0,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_2_5_3);
vector<vector<unsigned char> > S_vb_2_5_4 ={{1,0,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_2_5_4);
vector<vector<unsigned char> > S_vb_2_5_5 ={{1,1,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_2_5_5);
vector<vector<unsigned char> > S_vb_2_5_6 ={{1,1,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_2_5_6);
vector<vector<unsigned char> > S_vb_2_5_7 ={{1,1,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_2_5_7);
vector<vector<unsigned char> > S_vb_2_5_8 ={{1,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_2_5_8);


//vector<vector<unsigned char>> S_vb_2_6 ={{1,'D',1},{'D',1,1},{1,'D',0}};
vector<vector<unsigned char> > S_vb_2_6_1 ={{1,0,1},{0,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_2_6_1);
vector<vector<unsigned char> > S_vb_2_6_2 ={{1,0,1},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_2_6_2);
vector<vector<unsigned char> > S_vb_2_6_3 ={{1,0,1},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_2_6_3);
vector<vector<unsigned char> > S_vb_2_6_4 ={{1,0,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_2_6_4);
vector<vector<unsigned char> > S_vb_2_6_5 ={{1,1,1},{0,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_2_6_5);
vector<vector<unsigned char> > S_vb_2_6_6 ={{1,1,1},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_2_6_6);
vector<vector<unsigned char> > S_vb_2_6_7 ={{1,1,1},{1,1,1},{1,0,0}};
 masks_uc.push_back(S_vb_2_6_7);
vector<vector<unsigned char> > S_vb_2_6_8 ={{1,1,1},{1,1,1},{1,1,0}};
 masks_uc.push_back(S_vb_2_6_8);

//vector<vector<unsigned char>> S_vb_2_7 ={{1,'D',1},{'D',1,1},{1,'D',1}};
vector<vector<unsigned char> > S_vb_2_7_1 ={{1,0,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_2_7_1);
vector<vector<unsigned char> > S_vb_2_7_2 ={{1,0,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_2_7_2);
vector<vector<unsigned char> > S_vb_2_7_3 ={{1,0,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_2_7_3);
vector<vector<unsigned char> > S_vb_2_7_4 ={{1,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_2_7_4);
vector<vector<unsigned char> > S_vb_2_7_5 ={{1,1,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_2_7_5);
vector<vector<unsigned char> > S_vb_2_7_6 ={{1,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_2_7_6);
vector<vector<unsigned char> > S_vb_2_7_7 ={{1,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_2_7_7);
vector<vector<unsigned char> > S_vb_2_7_8 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_2_7_8);



//vector<vector<unsigned char>> S_vb_3 ={{'C','B','A'},{'D',1,'D'},{1,'D',1}};

//vector<vector<unsigned char>> S_vb_3_1 ={{0,0,1},{'D',1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_3_1_1 ={{0,0,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_1_1);
vector<vector<unsigned char> > S_vb_3_1_2 ={{0,0,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_1_2);
vector<vector<unsigned char> > S_vb_3_1_3 ={{0,0,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_1_3);
vector<vector<unsigned char> > S_vb_3_1_4 ={{0,0,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_1_4);
vector<vector<unsigned char> > S_vb_3_1_5 ={{0,0,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_1_5);
vector<vector<unsigned char> > S_vb_3_1_6 ={{0,0,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_1_6);
vector<vector<unsigned char> > S_vb_3_1_7 ={{0,0,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_1_7);
vector<vector<unsigned char> > S_vb_3_1_8 ={{0,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_1_8);

//vector<vector<unsigned char>> S_vb_3_2 ={{0,1,0},{'D',1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_3_2_1 ={{0,1,0},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_2_1);
vector<vector<unsigned char> > S_vb_3_2_2 ={{0,1,0},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_2_2);
vector<vector<unsigned char> > S_vb_3_2_3 ={{0,1,0},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_2_3);
vector<vector<unsigned char> > S_vb_3_2_4 ={{0,1,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_2_4);
vector<vector<unsigned char> > S_vb_3_2_5 ={{0,1,0},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_2_5);
vector<vector<unsigned char> > S_vb_3_2_6 ={{0,1,0},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_2_6);
vector<vector<unsigned char> > S_vb_3_2_7 ={{0,1,0},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_2_7);
vector<vector<unsigned char> > S_vb_3_2_8 ={{0,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_2_8);

//vector<vector<unsigned char>> S_vb_3_3 ={{0,1,1},{'D',1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_3_3_1 ={{0,1,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_3_1);
vector<vector<unsigned char> > S_vb_3_3_2 ={{0,1,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_3_2);
vector<vector<unsigned char> > S_vb_3_3_3 ={{0,1,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_3_3);
vector<vector<unsigned char> > S_vb_3_3_4 ={{0,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_3_4);
vector<vector<unsigned char> > S_vb_3_3_5 ={{0,1,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_3_5);
vector<vector<unsigned char> > S_vb_3_3_6 ={{0,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_3_6);
vector<vector<unsigned char> > S_vb_3_3_7 ={{0,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_3_7);
vector<vector<unsigned char> > S_vb_3_3_8 ={{0,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_3_8);

//vector<vector<unsigned char>> S_vb_3_4 ={{1,0,0},{'D',1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_3_4_1 ={{1,0,0},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_4_1);
vector<vector<unsigned char> > S_vb_3_4_2 ={{1,0,0},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_4_2);
vector<vector<unsigned char> > S_vb_3_4_3 ={{1,0,0},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_4_3);
vector<vector<unsigned char> > S_vb_3_4_4 ={{1,0,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_4_4);
vector<vector<unsigned char> > S_vb_3_4_5 ={{1,0,0},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_4_5);
vector<vector<unsigned char> > S_vb_3_4_6 ={{1,0,0},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_4_6);
vector<vector<unsigned char> > S_vb_3_4_7 ={{1,0,0},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_4_7);
vector<vector<unsigned char> > S_vb_3_4_8 ={{1,0,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_4_8);

//vector<vector<unsigned char>> S_vb_3_5 ={{1,0,1},{'D',1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_3_5_1 ={{1,0,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_5_1);
vector<vector<unsigned char> > S_vb_3_5_2 ={{1,0,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_5_2);
vector<vector<unsigned char> > S_vb_3_5_3 ={{1,0,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_5_3);
vector<vector<unsigned char> > S_vb_3_5_4 ={{1,0,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_5_4);
vector<vector<unsigned char> > S_vb_3_5_5 ={{1,0,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_5_5);
vector<vector<unsigned char> > S_vb_3_5_6 ={{1,0,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_5_6);
vector<vector<unsigned char> > S_vb_3_5_7 ={{1,0,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_5_7);
vector<vector<unsigned char> > S_vb_3_5_8 ={{1,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_5_8);

//vector<vector<unsigned char>> S_vb_3_6 ={{1,1,0},{'D',1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_3_6_1 ={{1,1,0},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_6_1);
vector<vector<unsigned char> > S_vb_3_6_2 ={{1,1,0},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_6_2);
vector<vector<unsigned char> > S_vb_3_6_3 ={{1,1,0},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_6_3);
vector<vector<unsigned char> > S_vb_3_6_4 ={{1,1,0},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_6_4);
vector<vector<unsigned char> > S_vb_3_6_5 ={{1,1,0},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_6_5);
vector<vector<unsigned char> > S_vb_3_6_6 ={{1,1,0},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_6_6);
vector<vector<unsigned char> > S_vb_3_6_7 ={{1,1,0},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_6_7);
vector<vector<unsigned char> > S_vb_3_6_8 ={{1,1,0},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_6_8);

//vector<vector<unsigned char>> S_vb_3_7 ={{1,1,1},{'D',1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_3_7_1 ={{1,1,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_7_1);
vector<vector<unsigned char> > S_vb_3_7_2 ={{1,1,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_7_2);
vector<vector<unsigned char> > S_vb_3_7_3 ={{1,1,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_7_3);
vector<vector<unsigned char> > S_vb_3_7_4 ={{1,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_7_4);
vector<vector<unsigned char> > S_vb_3_7_5 ={{1,1,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_3_7_5);
vector<vector<unsigned char> > S_vb_3_7_6 ={{1,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_3_7_6);
vector<vector<unsigned char> > S_vb_3_7_7 ={{1,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_3_7_7);
vector<vector<unsigned char> > S_vb_3_7_8 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_3_7_8);

//vector<vector<unsigned char>> S_vb_4 ={{'A','D',1},{'B',1,'D'},{'C','D',1}};

//vector<vector<unsigned char>> S_vb_4_1 ={{0,'D',1},{0,1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_4_1_1 ={{0,0,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_4_1_1);
vector<vector<unsigned char> > S_vb_4_1_2 ={{0,0,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_4_1_2);
vector<vector<unsigned char> > S_vb_4_1_3 ={{0,0,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_4_1_3);
vector<vector<unsigned char> > S_vb_4_1_4 ={{0,0,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_4_1_4);
vector<vector<unsigned char> > S_vb_4_1_5 ={{0,1,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_4_1_5);
vector<vector<unsigned char> > S_vb_4_1_6 ={{0,1,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_4_1_6);
vector<vector<unsigned char> > S_vb_4_1_7 ={{0,1,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_4_1_7);
vector<vector<unsigned char> > S_vb_4_1_8 ={{0,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_4_1_8);


//vector<vector<unsigned char>> S_vb_4_2 ={{0,'D',1},{1,1,'D'},{0,'D',1}};
vector<vector<unsigned char> > S_vb_4_2_1 ={{0,0,1},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_4_2_1);
vector<vector<unsigned char> > S_vb_4_2_2 ={{0,0,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_4_2_2);
vector<vector<unsigned char> > S_vb_4_2_3 ={{0,0,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_4_2_3);
vector<vector<unsigned char> > S_vb_4_2_4 ={{0,0,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_4_2_4);
vector<vector<unsigned char> > S_vb_4_2_5 ={{0,1,1},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_4_2_5);
vector<vector<unsigned char> > S_vb_4_2_6 ={{0,1,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_4_2_6);
vector<vector<unsigned char> > S_vb_4_2_7 ={{0,1,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_4_2_7);
vector<vector<unsigned char> > S_vb_4_2_8 ={{0,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_4_2_8);


//vector<vector<unsigned char>> S_vb_4_3 ={{0,'D',1},{1,1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_4_3_1 ={{0,0,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_4_3_1);
vector<vector<unsigned char> > S_vb_4_3_2 ={{0,0,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_4_3_2);
vector<vector<unsigned char> > S_vb_4_3_3 ={{0,0,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_4_3_3);
vector<vector<unsigned char> > S_vb_4_3_4 ={{0,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_4_3_4);
vector<vector<unsigned char> > S_vb_4_3_5 ={{0,1,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_4_3_5);
vector<vector<unsigned char> > S_vb_4_3_6 ={{0,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_4_3_6);
vector<vector<unsigned char> > S_vb_4_3_7 ={{0,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_4_3_7);
vector<vector<unsigned char> > S_vb_4_3_8 ={{0,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_4_3_8);


//vector<vector<unsigned char>> S_vb_4_4 ={{1,'D',1},{0,1,'D'},{0,'D',1}};
vector<vector<unsigned char> > S_vb_4_4_1 ={{1,0,1},{0,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_4_4_1);
vector<vector<unsigned char> > S_vb_4_4_2 ={{1,0,1},{0,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_4_4_2);
vector<vector<unsigned char> > S_vb_4_4_3 ={{1,0,1},{0,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_4_4_3);
vector<vector<unsigned char> > S_vb_4_4_4 ={{1,0,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_4_4_4);
vector<vector<unsigned char> > S_vb_4_4_5 ={{1,1,1},{0,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_4_4_5);
vector<vector<unsigned char> > S_vb_4_4_6 ={{1,1,1},{0,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_4_4_6);
vector<vector<unsigned char> > S_vb_4_4_7 ={{1,1,1},{0,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_4_4_7);
vector<vector<unsigned char> > S_vb_4_4_8 ={{1,1,1},{0,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_4_4_8);


//vector<vector<unsigned char>> S_vb_4_5 ={{1,'D',1},{0,1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_4_5_1 ={{1,0,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_4_5_1);
vector<vector<unsigned char> > S_vb_4_5_2 ={{1,0,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_4_5_2);
vector<vector<unsigned char> > S_vb_4_5_3 ={{1,0,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_4_5_3);
vector<vector<unsigned char> > S_vb_4_5_4 ={{1,0,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_4_5_4);
vector<vector<unsigned char> > S_vb_4_5_5 ={{1,1,1},{0,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_4_5_5);
vector<vector<unsigned char> > S_vb_4_5_6 ={{1,1,1},{0,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_4_5_6);
vector<vector<unsigned char> > S_vb_4_5_7 ={{1,1,1},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_4_5_7);
vector<vector<unsigned char> > S_vb_4_5_8 ={{1,1,1},{0,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_4_5_8);


//vector<vector<unsigned char>> S_vb_4_6 ={{1,'D',1},{1,1,'D'},{0,'D',1}};
vector<vector<unsigned char> > S_vb_4_6_1 ={{1,0,1},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_4_6_1);
vector<vector<unsigned char> > S_vb_4_6_2 ={{1,0,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_4_6_2);
vector<vector<unsigned char> > S_vb_4_6_3 ={{1,0,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_4_6_3);
vector<vector<unsigned char> > S_vb_4_6_4 ={{1,0,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_4_6_4);
vector<vector<unsigned char> > S_vb_4_6_5 ={{1,1,1},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_vb_4_6_5);
vector<vector<unsigned char> > S_vb_4_6_6 ={{1,1,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_vb_4_6_6);
vector<vector<unsigned char> > S_vb_4_6_7 ={{1,1,1},{1,1,1},{0,0,1}};
 masks_uc.push_back(S_vb_4_6_7);
vector<vector<unsigned char> > S_vb_4_6_8 ={{1,1,1},{1,1,1},{0,1,1}};
 masks_uc.push_back(S_vb_4_6_8);

//vector<vector<unsigned char>> S_vb_4_7 ={{1,'D',1},{1,1,'D'},{1,'D',1}};
vector<vector<unsigned char> > S_vb_4_7_1 ={{1,0,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_4_7_1);
vector<vector<unsigned char> > S_vb_4_7_2 ={{1,0,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_4_7_2);
vector<vector<unsigned char> > S_vb_4_7_3 ={{1,0,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_4_7_3);
vector<vector<unsigned char> > S_vb_4_7_4 ={{1,0,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_4_7_4);
vector<vector<unsigned char> > S_vb_4_7_5 ={{1,1,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_vb_4_7_5);
vector<vector<unsigned char> > S_vb_4_7_6 ={{1,1,1},{1,1,0},{1,1,1}};
 masks_uc.push_back(S_vb_4_7_6);
vector<vector<unsigned char> > S_vb_4_7_7 ={{1,1,1},{1,1,1},{1,0,1}};
 masks_uc.push_back(S_vb_4_7_7);
vector<vector<unsigned char> > S_vb_4_7_8 ={{1,1,1},{1,1,1},{1,1,1}};
 masks_uc.push_back(S_vb_4_7_8);

//vector<vector<unsigned char>> S_db_1 ={{'D',1,0},{0,1,1},{1,0,'D'}};
vector<vector<unsigned char> > S_db_1_1 ={{0,1,0},{0,1,1},{1,0,0}};
 masks_uc.push_back(S_db_1_1);
vector<vector<unsigned char> > S_db_1_2 ={{0,1,0},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_db_1_2);
vector<vector<unsigned char> > S_db_1_3 ={{1,1,0},{0,1,1},{1,0,0}};
 masks_uc.push_back(S_db_1_3);
vector<vector<unsigned char> > S_db_1_4 ={{1,1,0},{0,1,1},{1,0,1}};
 masks_uc.push_back(S_db_1_4);


//vector<vector<unsigned char>> S_db_2 ={{0,1,'D'},{1,1,0},{'D',0,1}};
vector<vector<unsigned char> > S_db_2_1 ={{0,1,0},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_db_2_1);
vector<vector<unsigned char> > S_db_2_2 ={{0,1,0},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_db_2_2);
vector<vector<unsigned char> > S_db_2_3 ={{0,1,1},{1,1,0},{0,0,1}};
 masks_uc.push_back(S_db_2_3);
vector<vector<unsigned char> > S_db_2_4 ={{0,1,1},{1,1,0},{1,0,1}};
 masks_uc.push_back(S_db_2_4);

//vector<vector<unsigned char>> S_db_3 ={{'D',0,1},{1,1,0},{0,1,'D'}};
vector<vector<unsigned char> > S_db_3_1 ={{0,0,1},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_db_3_1);
vector<vector<unsigned char> > S_db_3_2 ={{0,0,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_db_3_2);
vector<vector<unsigned char> > S_db_3_3 ={{1,0,1},{1,1,0},{0,1,0}};
 masks_uc.push_back(S_db_3_3);
vector<vector<unsigned char> > S_db_3_4 ={{1,0,1},{1,1,0},{0,1,1}};
 masks_uc.push_back(S_db_3_4);

//vector<vector<unsigned char>> S_db_4 ={{1,0,'D'},{0,1,1},{'D',1,0}};
vector<vector<unsigned char> > S_db_4_1 ={{1,0,0},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_db_4_1);
vector<vector<unsigned char> > S_db_4_2 ={{1,0,0},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_db_4_2);
vector<vector<unsigned char> > S_db_4_3 ={{1,0,1},{0,1,1},{0,1,0}};
 masks_uc.push_back(S_db_4_3);
vector<vector<unsigned char> > S_db_4_4 ={{1,0,1},{0,1,1},{1,1,0}};
 masks_uc.push_back(S_db_4_4);

//cout<<(int)masks_uc[1][0][0];
cout<<"d";

int flag=0; int hit=0;
int m; int p; int sc; int otter=0;

//while(flag==0){
    sc=0;
for(int o=0;o<300;o++){
    for(int i=0; i<Size+2; i++){
        for(int j=0; j<Size+2; j++){
            M[i][j] = 0;
        }
    }
    otter++;
    //Conditional
    for(int i=1;i<Size+1;i++){
        for(int j=1;j<Size+1;j++){
            if(Imagedatainputext[i][j]==1){
                for(int k=0;k<masks_c.size();k++){
                    if((Imagedatainputext[i-1][j-1]==masks_c[k][0][0])&&(Imagedatainputext[i-1][j]==masks_c[k][0][1])&&(Imagedatainputext[i-1][j+1]==masks_c[k][0][2])&&(Imagedatainputext[i][j-1]==masks_c[k][1][0])&&(Imagedatainputext[i][j+1]==masks_c[k][1][2])&&(Imagedatainputext[i+1][j-1]==masks_c[k][2][0])&&(Imagedatainputext[i+1][j]==masks_c[k][2][1])&&(Imagedatainputext[i+1][j+1]==masks_c[k][2][2])){
                        hit++;
                        m=1;
                        M[i][j]=1;
                        sc++;
                    }
                }
            }
        }

}
    //Unconditional
    for(int i=1;i<Size+1;i++){
        for(int j=1;j<Size+1;j++){
            if(M[i][j]==1){
                for(int l=0;l<masks_uc.size();l++){
                    if((M[i-1][j-1]==masks_uc[l][0][0])&&(M[i-1][j]==masks_uc[l][0][1])&&(M[i-1][j+1]==masks_uc[l][0][2])&&(M[i][j-1]==masks_uc[l][1][0])&&(M[i][j+1]==masks_uc[l][1][2])&&(M[i+1][j-1]==masks_uc[l][2][0])&&(M[i+1][j]==masks_uc[l][2][1])&&(M[i+1][j+1]==masks_uc[l][2][2])){
                        hit++;
                        p=1;
                        sc++;
                        Imagedatainputext[i][j]=1;
                        break;
                    }
                    else{
                        p=0;
                        Imagedatainputext[i][j]=0;
                    }
                }
            }
        }
    }
//if(sc==0){flag=1;}
}

for(int i=0;i<Size;i++){
    for(int j=0;j<Size;j++){
        if(Imagedatainputext[i+1][j+1]==1){
            Imagedataout[i][j]=255;
        }
        else{
            Imagedataout[i][j]=0;
        }
    }
}
cout<<"end" ;
cout<<"otter "<<otter<<" "<<"hit "<<hit<<"sc "<<sc<<"\n";

int x0,x1,x2,x3,x4,x5,x6,x7,x, l1,l2,l3,l4,pq,p1,p2,p3,p4,p5,p6;
    x0 = x1 = x2 = x3 = x4 = x5 = x6 = x7 = 0;
    for(int i = 1; i<Size-1; i++)
    {
        for(int j = 1; j < Size-1; j++)
        {
            x = ((int)Imagedataout[i][j])/255;
            x0 = ((int)Imagedataout[i][j+1])/255;
            x1 = ((int)Imagedataout[i-1][j+1])/255;
            x2 = ((int)Imagedataout[i-1][j])/255;
            x3 = ((int)Imagedataout[i-1][j-1])/255;
            x4 = ((int)Imagedataout[i][j-1])/255;
            x5 = ((int)Imagedataout[i+1][j-1])/255;
            x6 = ((int)Imagedataout[i+1][j])/255;
            x7 = ((int)Imagedataout[i+1][j+1])/255;
            l1 = !x&& !x0 && x1 && !x2 && x3 && !x4 && !x5 && !x6 && !x7;
            l2 = !x&& !x0 && !x1 && !x2 && x3 && !x4 && x5 && !x6 && !x7;
            l3 = !x&& !x0 && !x1 && !x2 && !x3 && !x4 && x5 && !x6 && x7;
            l4 = !x&& !x0 && x1 && !x2 && !x3 && !x4 && !x5 && !x6 && x7;
            pq = l1||l2||l3||l4;
            p1 = (!x2&&!x6)&&(x3||x4||x5)&&(x0||x1||x7)&&!pq;
            p2 = (!x0&&!x4)&&(x1||x2||x3)&&(x5||x6||x7)&&!pq;
            p3 = (!x0&&!x6&&x7)&&(x2||x3||x4);
            p4 = (!x0&&!x2&&x1)&&(x4||x5||x6);
            p5 = (!x2&&!x4&&x3)&&(x0||x6||x7);
            p6 = (!x4&&!x6&&x5)&&(x0||x1||x2);
            Imagedataout[i][j] = 255*(x || (p1||p2||p3||p4||p5||p6)); 
        }
    }


	// Write image data (filename specified by second argument) from image data matrix

	if (!(file=fopen(argv[2],"wb"))) {
		cout << "Cannot open file: " << argv[2] << endl;
		exit(1);
	}
	fwrite(Imagedataout, sizeof(unsigned char), (Size)*(Size)*BytesPerPixel, file);
	fclose(file);

	return 0;
}








