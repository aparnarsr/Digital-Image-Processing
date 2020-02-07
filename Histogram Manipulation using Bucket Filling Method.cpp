
// This sample code reads in image data from a RAW image file and// writes it into another file// NOTE:	The code assumes that the image is of size 256 x 256 and is in the//			RAW format. You will need to make corresponding changes to//			accommodate images of different sizes and/or types#include <stdio.h>#include <iostream>#include <stdlib.h>
#include <math.h>
#include <vector>using namespace std;

//Creating a structure named triplet and assigning three values to it

struct triplet{
int x,y,z;
};int main(int argc, char *argv[]){	// Define file pointer and variables	FILE *file;	int BytesPerPixel;	int Size = 400;	// Check for proper syntax	if (argc < 3){		cout << "Syntax Error - Incorrect Parameter Usage:" << endl;		cout << "program_name input_image.raw output_image.raw [BytesPerPixel = 1] [Size = 256]" << endl;		return 0;	}	// Check if image is grayscale or color	if (argc < 4){		BytesPerPixel = 1; // default is grey image	}	else {		BytesPerPixel = atoi(argv[3]);		// Check if size is specified		if (argc >= 5){			Size = atoi(argv[4]);		}	}	// Allocate image data array	unsigned char Imagedata[Size][Size][BytesPerPixel];	// Read image (filename specified by first argument) into image data matrix	if (!(file=fopen(argv[1],"rb"))) {		cout << "Cannot open file: " << argv[1] <<endl;		exit(1);	}	fread(Imagedata, sizeof(unsigned char), Size*Size*BytesPerPixel, file);	fclose(file);	///////////////////////// INSERT YOUR PROCESSING CODE HERE /////////////////////////

//Initializing all arrays

unsigned char Imagedataoutput[Size][Size][BytesPerPixel];

long long int freqarray[256];
long long int bucket[256];
long long int remainingcapacity[256];

//Assigning value 0 to all elements in freqarray
	for(int i=0;i<256;i++)
	{
            freqarray[i]=0;
    }

//Finding bucketsize

int bucketsize=(Size*Size)/256; //Total pixels/Number of bins in grayscale(0-255)

//Initializing Remaining Capacity in the bucket to be equal to bucket size

for(int i=0;i<256;i++){
    remainingcapacity[i]= bucketsize;
}


//Histogram - Number of pixels vs Intensity (Frequency calculation for each intensity value)
	for(int i=0;i<Size;i++){
        for(int j=0;j<Size; j++)
            {
                int l=(int)Imagedata[i][j][0];
                freqarray[l]++;
            }
        }


//Creating a vector which takes in the values of frequency, original bucket number, new bucket number

vector<triplet> v;
int curr_bucket=0;
int remaining=0;
for(int i=0;i<256;i++){
        int remaining=freqarray[i];
        while(remaining>0){
                if(remaining<=remainingcapacity[curr_bucket]){
                    v.push_back({remaining,i,curr_bucket});
                    remainingcapacity[curr_bucket] -= remaining;
                    if(remainingcapacity[curr_bucket]==0){
                        curr_bucket++;
                    }
                    remaining=-1;
                }
                else{
                    v.push_back({remainingcapacity[curr_bucket], i, curr_bucket});
                    remaining -= remainingcapacity[curr_bucket];
                    curr_bucket++;
                }
              }
}
//Updating the vector values

for(int x=0; x<Size;x++){
    for(int y=0; y<Size; y++){
        for(int z=0; z<(v.size());z++){

            triplet t = v[z];
            if(t.y==(int)Imagedata[x][y][0]){
                Imagedataoutput[x][y][0]=t.z;
                t.x--;
                if(t.x==0){
                    v.erase(v.begin()+z);
                }
                break;
            }

        }
    }
}

	// Write image data (filename specified by second argument) from image data matrix	if (!(file=fopen(argv[2],"wb"))) {		cout << "Cannot open file: " << argv[2] << endl;		exit(1);	}	fwrite(Imagedataoutput, sizeof(unsigned char), Size*Size*BytesPerPixel, file);	fclose(file);	return 0;}
