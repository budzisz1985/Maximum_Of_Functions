class Data
{
public:

	double data[6];
	int mutation;
	int crossing;
	int reapeting;
	int character = 97;
	int a;

	void enter_data();
};

class Gene
	:public Data

{
public:

	int chromosom[6][5];
	int sum[6];

	void chromo();

};

class Function

	: public Gene
{

public:

	double function[6];
	double first;
	double part[6];

	void firstFunction();

};

class Roulette

	:public Function
{
public:

	int end = 0;
	int wheel;
	int lokus;
	int cp;
	int mp;
	int temp[3][5];
	int max;
	int maximum;
	int counter = 0;

	void count();

};


