
// This sample code reads in image data from a RAW image file and
#include <math.h>
#include <vector>

//Creating a structure named triplet and assigning three values to it

struct triplet{
int x,y,z;
};

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

