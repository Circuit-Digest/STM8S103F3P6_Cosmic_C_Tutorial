/*
Header Name: stm8s_max72xx.h
*/


#define decode_mode_reg 	0x09
#define intensity_reg 		0x0A
#define scan_limit_reg 		0x0B
#define shutdown_reg 			0x0C
#define display_test_reg	0x0F
 
#define shutdown_cmd 0x00
#define run_cmd      0x01
 
#define no_test_cmd 0x00
#define test_cmd    0x01

// 8 hex addresses of the 26 Alphabets

const char char_A[8] = {0x0, 0xfc, 0xfe, 0x27, 0x27, 0xfe, 0xfc, 0x0};   //A
const char char_B[8] = {0x0, 0xfe, 0xfe, 0x92, 0x92, 0xfe, 0x6c, 0x0};   //B
const char char_C[8] = {0x0, 0x7e, 0xff, 0xc3, 0xc3, 0xe7, 0x66, 0x0};   //C
const char char_D[8] = {0x0, 0xff, 0xff, 0xc3, 0xc3, 0xff, 0x7e, 0x0};   //D
const char char_E[8] = {0x0, 0xfe, 0xfe, 0x92, 0xba, 0x82, 0xc6, 0x0};   //E
const char char_F[8] = {0x82, 0xfe, 0xfe, 0x92, 0x3a, 0x2, 0x6, 0x0};   //F
const char char_G[8] = {0x0, 0x7e, 0xff, 0xc3, 0xd3, 0xf7, 0x76, 0x0};   //G
const char char_H[8] = {0x0, 0xfe, 0xfe, 0x30, 0x30, 0xfe, 0xfe, 0x0};   //H
const char char_I[8] = {0x0, 0xc6, 0xc6, 0xfe, 0xfe, 0xc6, 0xc6, 0x0};   //I
const char char_J[8] = {0x0, 0x30, 0x70, 0x63, 0x63, 0x7f, 0x3f, 0x3};     //J
const char char_K[8] = {0x0, 0xff, 0xff, 0x18, 0x3c, 0x6e, 0xc7, 0x0};     //K
const char char_L[8] = {0x0, 0x81, 0xff, 0xff, 0x81, 0x80, 0xe0, 0x0};     //L
const char char_M[8] = {0x0, 0xfe, 0xfe, 0x1c, 0x38, 0x1c, 0xfe, 0xfe};    //M
const char char_N[8] = {0x4e, 0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6, 0xc6};   //N
const char char_O[8] = {0x4f, 0x38, 0x6c, 0xc6, 0xc6, 0xc6, 0x6c, 0x38};   //O
const char char_P[8] = {0x50, 0xfc, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0};   //P
const char char_Q[8] = {0x51, 0x78, 0xcc, 0xcc, 0xcc, 0xdc, 0x78, 0x1c};   //Q
const char char_R[8] = {0x0, 0xff, 0xff, 0x33, 0x33, 0xff, 0xee, 0xc0};    //R
const char char_S[8] = {0x0, 0xce, 0xdf, 0xdb, 0xdb, 0xfb, 0x73, 0x0};     //S
const char char_T[8] = {0x0, 0x7, 0x83, 0xff, 0xff, 0x83, 0x7, 0x0};       //T
const char char_U[8] = {0x0, 0x7f, 0xff, 0xc0, 0xc0, 0xff, 0x7f, 0x0};     //U
const char char_V[8] = {0x56, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x30};   //V
const char char_W[8] = {0x57, 0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6};   //W
const char char_X[8] = {0x58, 0xc6, 0xc6, 0x6c, 0x38, 0x38, 0x6c, 0xc6};   //X
const char char_Y[8] = {0x59, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x30, 0x78};   //Y
const char char_Z[8] = {0x7f, 0x7f, 0x61, 0x31, 0x98, 0x8c, 0xfe, 0xfe};   //Z};

/*
Function Name: string_len
Description: It can be used to get the length of a String.
Return type: int.
*/

int string_len(char *s)
{
    int len = 0;
    while(*s != 0) {
        s++;
        len++;
    }
    return len;
}



/*
Function Name: MAX7219_init
Description: It can be used to initiate MAX7219 device.
type: void.
*/

void MAX7219_init(void)
{
    GPIO_Init(CS_port, CS_pin, GPIO_MODE_OUT_PP_HIGH_FAST);
 
    SPI_write(shutdown_reg, run_cmd);                 
    SPI_write(decode_mode_reg, 0x00);
    SPI_write(scan_limit_reg, 0x07);
    SPI_write(intensity_reg, 0x04);
    SPI_write(display_test_reg, test_cmd);
    delay_ms(10);     
    SPI_write(display_test_reg, no_test_cmd);  
}


/*
Function Name: diplay_clear
Description: It can be used to clear the matrix for once with 100 ms delay.
Return type: void.
*/

void display_clear(void) {
	    unsigned char temp[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
 unsigned char j = 0x00;
	
	for(j = 0; j < sizeof(temp); j++)
	{
			
			SPI_write((1 + j),temp[j]);
			delay_ms(100);
	}

}


		
			
/*
Function Name: display_char
Description: It can be used to print a Character on the 8x8 matrix for once with 100 ms delay.
Return type: void.
*/

void display_char(const char input_char[])
{
	  unsigned int i;

		for(i=0; i<8; i++){
		SPI_write((i+1), input_char[i]);
		delay_ms(100);
		
		}

}

/*
Function Name: display_string
Description: It can be used to display a string on the 8x8 matrix for once with 1000 ms delay.
type: void.
*/

void display_string(const char string[]){
		
    unsigned char j;
		int length;
     length  = string_len(string);
		
	for(j=0; j<=length; j++){
		
	if(string[j] == 'A')
		display_char(char_A);
	else if(string[j] == 'B')
		display_char(char_B);
	else if(string[j] == 'C')
		display_char(char_C);
	else if(string[j] == 'D')
		display_char(char_D);
	else if(string[j] == 'E')
		display_char(char_E);
	else if(string[j] == 'F')
		display_char(char_F);
	else if(string[j] == 'G')
		display_char(char_G);
	else if(string[j] == 'H')
		display_char(char_H);
	else if(string[j] == 'I')
		display_char(char_I);
	else if(string[j] == 'J')
		display_char(char_J);
	else if(string[j] == 'K')
		display_char(char_K);
	else if(string[j] == 'L')
		display_char(char_L);
	else if(string[j] == 'M')
		display_char(char_M);
	else if(string[j] == 'N')
		display_char(char_N);
	else if(string[j] == 'O')
		display_char(char_O);
	else if(string[j] == 'P')
		display_char(char_P);
	else if(string[j] == 'Q')
		display_char(char_Q);
	else if(string[j] == 'R')
		display_char(char_R);
	else if(string[j] == 'S')
		display_char(char_S);
	else if(string[j] == 'T')
		display_char(char_T);
	else if(string[j] == 'U')
		display_char(char_U);
	else if(string[j] == 'V')
		display_char(char_V);
	else if(string[j] == 'W')
		display_char(char_W);
	else if(string[j] == 'X')
		display_char(char_X);
	else if(string[j] == 'Y')
		display_char(char_Y);
	else if(string[j] == 'Z')
		display_char(char_Z);
	else
		display_clear();
		
		delay_ms(1000);
	}

}



