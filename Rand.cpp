#include <random>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define array_size 1e1
#define uint32 unsigned long int
#define uint64 unsigned long long


int out[16];

#define R(a,b) (((a) << (b)) | ((a) >> (32 - (b))))
void salsa20_word_specification(int *in)
{
	int i;
    int x[16];
    for (i = 0;i < 16;++i) x[i] = in[i];
    for (i = 20;i > 0;i -= 2) {
		x[ 4] ^= R(x[ 0]+x[12], 7);  x[ 8] ^= R(x[ 4]+x[ 0], 9);
        x[12] ^= R(x[ 8]+x[ 4],13);  x[ 0] ^= R(x[12]+x[ 8],18);
        x[ 9] ^= R(x[ 5]+x[ 1], 7);  x[13] ^= R(x[ 9]+x[ 5], 9);
        x[ 1] ^= R(x[13]+x[ 9],13);  x[ 5] ^= R(x[ 1]+x[13],18);
        x[14] ^= R(x[10]+x[ 6], 7);  x[ 2] ^= R(x[14]+x[10], 9);
        x[ 6] ^= R(x[ 2]+x[14],13);  x[10] ^= R(x[ 6]+x[ 2],18);
        x[ 3] ^= R(x[15]+x[11], 7);  x[ 7] ^= R(x[ 3]+x[15], 9);
        x[11] ^= R(x[ 7]+x[ 3],13);  x[15] ^= R(x[11]+x[ 7],18);
        x[ 1] ^= R(x[ 0]+x[ 3], 7);  x[ 2] ^= R(x[ 1]+x[ 0], 9);
        x[ 3] ^= R(x[ 2]+x[ 1],13);  x[ 0] ^= R(x[ 3]+x[ 2],18);
        x[ 6] ^= R(x[ 5]+x[ 4], 7);  x[ 7] ^= R(x[ 6]+x[ 5], 9);
        x[ 4] ^= R(x[ 7]+x[ 6],13);  x[ 5] ^= R(x[ 4]+x[ 7],18);
        x[11] ^= R(x[10]+x[ 9], 7);  x[ 8] ^= R(x[11]+x[10], 9);
        x[ 9] ^= R(x[ 8]+x[11],13);  x[10] ^= R(x[ 9]+x[ 8],18);
        x[12] ^= R(x[15]+x[14], 7);  x[13] ^= R(x[12]+x[15], 9);
        x[14] ^= R(x[13]+x[12],13);  x[15] ^= R(x[14]+x[13],18);
	}
	for (i = 0;i < 16;++i) out[i] = x[i] + in[i];
}


/*
1 16
7 112
63 1008
625 1e4
6250 1e5
62500 1e6
625000 1e7
*/

int main(){
	
	ofstream fout("input1e6.txt");
	
	int in[16] = {1,0,6,1,1,1,0,7,1,1,0,0,1,0,1,0};

	for(int i = 0; i < 62500; i++){
		salsa20_word_specification(in);
		for(int j = 0; j < 16; j++){
			fout << abs(out[j]) % 1000 << ' ';
			in[j] = out[j];
		}
	}
	
	return 0;
}