#include <stdio.h>
#include <stdint.h>

// Comandos
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE_SET 0x04
#define LCD_DISPLAY_CONTROL 0x08
#define LCD_CURSOR_SHIFT 0x10
#define LCD_FUNCTION_SET 0x20
#define LCD_SET_CGRAM_ADDR 0x40
#define LCD_SET_DDRAM_ADDR 0x80

// Flags para o modo de entrada
#define LCD_ENTRY_RIGHT 0x00
#define LCD_ENTRY_LEFT 0x02
#define LCD_ENTRY_SHIFT_INCREMENT 0x01
#define LCD_ENTRY_SHIFT_DECREMENT 0x00

// Flags para o display on/off control
#define LCD_DISPLAY_ON 0x04
#define LCD_DISPLAY_OFF 0x00
#define LCD_CURSOR_ON 0x02
#define LCD_CURSOR_OFF 0x00
#define LCD_BLINK_ON 0x01
#define LCD_BLINK_OFF 0x00

// Flags para o deslocamento do display/cursor 
#define LCD_DISPLAY_MOVE 0x08
#define LCD_CURSOR_MOVE 0x00
#define LCD_MOVE_RIGHT 0x04
#define LCD_MOVE_LEFT 0x00

// Flags para o function set
#define LCD_4BIT_MODE 0x00
#define LCD_2_LINE 0x08
#define LCD_1_LINE 0x00
#define LCD_5x10_DOTS 0x04
#define LCD_5x8_DOTS 0x00

struct gpio_pin{
        int func_reg_ofst;
        int func_pin_ofst;
        int pin_number;    
}pin_rs={8,15,25},pin_e={0,3,1},pin_d4={4,6,12},pin_d5={4,18,16},pin_d6 ={8,0,20},pin_d7={8,3,21};

enum state{OFF,ON};
enum direction{LEFT,WRITE}
extern void nanoSleep(void);
extern void memory_map(void);
extern void GPIODirectionOut(int reg_offset, int pin_offset);
extern void GPIOTurn(int pin_offset,int state);

void delay(int millis){
	for(int i=0;i<millis;i++){
		nanoSleep();
	}
}

void set_gpio_to_out(struct gpio_pin pin){
	GPIODirectionOut(pin.func_reg_ofst,pin.func_pin_ofst);
}

void set_gpio_value(struct gpio_pin pin, uint8_t pin_state){
	int state = pin_state;
	GPIOTurn(pin.pin_number,state);
}

void lcd_pin_to_out(struct gpio_pin e, struct gpio_pin rs, struct gpio_pin d7, struct gpio_pin d6, struct gpio_pin d5, struct gpio_pin d4){
	set_gpio_to_out(e);
	set_gpio_to_out(rs);
	set_gpio_to_out(d7);
	set_gpio_to_out(d6);
	set_gpio_to_out(d5);
	set_gpio_to_out(d4);
}

void pulse_enable(){
	set_gpio_value(pin_e,0);
	set_gpio_value(pin_e,1);
	delay(1);
	set_gpio_value(pin_e,0);
};

void function_set(){
	
};

void display(enum state display_state){
	
}

void cursor(enum state cursor_state){
	
}

void cursor_blink(enum state blink_state){
	
}

void lcd_begin(){
	command(LCD_CLEAR_DISPLAY, 0);
	command(LCD_FUNCTION_SET | LCD_4BIT_MODE | LCD_1_LINE, 0);
	command(LCD_FUNCTION_SET | LCD_4BIT_MODE | LCD_1_LINE, 0);
	command(LCD_FUNCTION_SET | LCD_4BIT_MODE | LCD_1_LINE, 0);
	command(LCD_FUNCTION_SET | LCD_4BIT_MODE | LCD_1_LINE, 0);
	command(LCD_ENTRY_RIGHT | LCD_ENTRY_SHIFT_DECREMENT, 0);
	command(LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_BLINK_ON, 0);
	
}

void clear_lcd(){
	command(LCD_CLEAR_DISPLAY,0);
}

void set_cursor_pos(){
	
}

void write(){
	
}

void write_char(){
	
}

void write_str(){
}

void inc_or_dec_cursor(){
	
}

void command(uint8_t value,uint8_t rs_level){
	uint8_t bits[8];
    
	for(int i=0;i < 8;i++){
		bits[i] = (value >> i) & 0x01;
	}
	
	set_gpio_value(pin_rs,rs_level);
	set_gpio_value(pin_d7,bit[7]);
	set_gpio_value(pin_d6,bit[6]);
	set_gpio_value(pin_d5,bit[5]);
	set_gpio_value(pin_d4,bit[4]);
	
	pulse_enable();
	
	set_gpio_value(pin_rs,rs_level);
	set_gpio_value(pin_d7,bit[3]);
	set_gpio_value(pin_d6,bit[2]);
	set_gpio_value(pin_d5,bit[1]);
	set_gpio_value(pin_d4,bit[0]);
	
	pulse_enable();
}

int  main(){
}