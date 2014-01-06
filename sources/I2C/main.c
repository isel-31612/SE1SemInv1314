

int main(){

	int data[] = {1,2,3,4,5,6,7};

	I2C_Init();
	SYSCLK_Init(1000);
	
	I2C_Transfer(0x0,0,&data,1,0);

	return 0;
}
