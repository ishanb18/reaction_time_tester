#include <reg51.h>
#include <stdlib.h>
#include <stdio.h>

sbit button = P3^2;  
sbit rs = P3^5;      
sbit rw = P3^6;      
sbit en = P3^7;      

char time_str[16];   
unsigned int timer_count = 0;  
unsigned int time_in_seconds;  
unsigned int time_in_ms;       

void delay_ms(unsigned int ms);
void lcd_init();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data1);
void lcd_display(char *text);

void timer0_ISR() interrupt 1 { 
    TH0 = 0xFC;   
    TL0 = 0x66;
    timer_count++;  
}

void main() {
    lcd_init();                
    lcd_display("Reaction Test");
    delay_ms(2000);             
    lcd_cmd(0x01);              

    TMOD = 0x01;   
    TH0 = 0xFC;     
    TL0 = 0x66;
    ET0 = 1;        
    EA = 1;        

    while (1) {
        lcd_display(" Wait...");
        delay_ms(2000 + (rand() % 3000));  
        lcd_cmd(0x01);  
        lcd_display(" GO!");

        timer_count = 0;  
        TR0 = 1;        

        while (button == 1);  
        TR0 = 0;          

        lcd_cmd(0x01);    
        lcd_display(" Time: ");

        time_in_seconds = timer_count / 1000;  
        time_in_ms = timer_count % 1000;       

        sprintf(time_str, "%u.%03u s", time_in_seconds, time_in_ms);  
        lcd_display(time_str);  

        delay_ms(5000);  
        lcd_cmd(0x01);   
    }
}

void delay_ms(unsigned int ms) {
    unsigned int i;
    for (i = 0; i < ms; i++) {
        TMOD = 0x01;    
        TH0 = 0xFC;     
        TL0 = 0x66;     
        TF0 = 0;       
        TR0 = 1;      
        while (TF0 == 0);  
        TR0 = 0;       
    }
}

void lcd_init() {
    lcd_cmd(0x38);  
    lcd_cmd(0x0C);  
    lcd_cmd(0x06);  
    lcd_cmd(0x01);  
    delay_ms(10);   
}

void lcd_cmd(unsigned char cmd) {
    P2 = cmd;
    rs = 0;
    rw = 0;
    en = 1;
    delay_ms(1);
    en = 0;
}

void lcd_data(unsigned char data1) {
    P2 = data1;
    rs = 1;
    rw = 0;
    en = 1;
    delay_ms(1);
    en = 0;
}

void lcd_display(char *text) {
    while (*text) {
        lcd_data(*text++);
    }
}
