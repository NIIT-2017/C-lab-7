struct sym
{
	unsigned char symb;
	float num;
};
int buildbuf(unsigned char *, float *, const char * fileName);
void buildStruct (int , struct sym [], unsigned char *, float *);