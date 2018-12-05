/*Author- Suraj Singh*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define di0 26
#define di1 27
#define di2 23
#define di3 61

#define do_En 65
#define do0 44
#define do1 45
#define do2 46
#define do3 47
#define btn0 68//push button 1 on IGT-20
#define btn1 67//push button2 on IGT-20
#define led0 0//built in LED in IGT-20
#define led1 1
#define led2 2
#define led3 3
#define led4 4
#define led5 5


void led_wr(int pin, char read_value)//read write to the built in LED in IGT-20
{
	int fp,n;
	char buf[100];
	sprintf(buf,"/sys/class/leds/igt20::usr%d/brightness",pin);
	fp = open(buf,O_WRONLY);
	if(read_value==1){
		n=write(fp,"1",1);
		}
	else if(read_value==0){
		n=write(fp,"0",1);
		}
	else
		printf("Error writing to GPIO\n");
	close(fp);
}

void gpio_write(int gpio,char write_value){//write to output pin of IGT-20
	char buf[100];
	int n;
	sprintf(buf,"/sys/class/gpio/gpio%d/value",gpio);
	int fp=open(buf,O_WRONLY);
	if(write_value==1){
		n=write(fp,"1",1);//
		}
	else if(write_value==0){
		n=write(fp,"0",1);//write to glow the LED
		}
	else
		printf("Error writing to GPIO\n");
	close(fp);
}

/*to read if there is input from digital pin*/
int gpio_read(int gpio)
{
	char read_value;
	char buf_read[100];
	sprintf(buf_read,"/sys/class/gpio/gpio%d/value",gpio);
	int fp=open(buf_read,O_RDONLY);
	read(fp,&read_value,sizeof(read_value));
	if(read_value=='0'){//if input is there
	    printf("Input is here");
		return 1;
		}
	else if(read_value=='1'){
		return 0;
		}
}

int main()
{
	gpio_write(do_En,0);//enable the read/write in GPIO by writing 0 to pin 65
	gpio_write(do0,1);//write 0 to digital output 1 (Do0)
	led_wr(led5,1);
	printf("WelCome To Neousys Technology\n");
	while(1){
	
	}

}
