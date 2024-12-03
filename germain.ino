
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char name[20] = "Germain Vergara";
char section[20] = "BET - ECET 3A";
char address[40] = "194 B Mata St Tondo Manila";
char address1[20] = "194 B Mata St";
char address2[20] = "Tondo Manila";
int noteIndex = -1;           
int noteDuration = 0;    
unsigned long currentT;
unsigned long previousT = 0;

#define led 23
#define buzzerpin 19

#define C6 1047
#define C_6 1109
#define D6 1175
#define D_6 1245
#define E6 1319
#define F6 1397
#define F_6 1480
#define G6 1568
#define G_6 1661
#define A6 1760
#define A_6 1865
#define B6 1976
#define C7 2093
#define C_7 2217
#define D7 2349
#define D_7 2489
#define E7 2637
#define F7 2794
#define F_7 2960
#define G7 3136
#define G_7 3322
#define A7 3520
#define A_7 3729
#define B7 3951
#define C8 4186
#define C_8 4435
#define D8 4699
#define D_8 4978
#define E8 5274
#define F8 5588
#define F_8 5920
#define G8 6272
#define G_8 6645
#define A8 7040
#define A_8 7458
#define B8 7902
#define C9 8372
#define C_9 8869
#define D9 9397
#define D_9 9956
#define E9 10548
#define F9 11175
#define F_9 11840
#define G9 12544
#define G_9 13290
#define A9 14080
#define A_9 14917
#define B9 15804
#define C10 16744
// 'germain_resize', 128x64px
const unsigned char epd_bitmap_germain_resize [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdf, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x07, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x00, 0x07, 0xc0, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x77, 0xe0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xdd, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1040)
const int epd_bitmap_allArray_LEN = 1;
const unsigned char* epd_bitmap_allArray[1] = {
	epd_bitmap_germain_resize
};
int melody[] = {
    G7, G7, G7, E8, E8, G8, E8, D8,  // Triple notes
    D8, E8, D8, C8, A7,              // Rest and whole notes
    G7, A7, G7, E8, E8,              // Notes
    E8, G8, E8, D8,                  // 2 notes
    D8, E8, C8, A7, A7,              // 3 notes
    0, G7, G7, G7, G7, G7, G8,       // G7 repeated with G8
    E8, E8, E8, G8, E8, G8, E8,      // Notes
    E8, G8, E8, A8,                  // Notes
    G8, G8, E8, E8, D8,              // Notes
    0, G7, G7, G7, G7, G7, G8,       // G7 repeated with G8
    E8, E8, E8, D8,                  // 3 notes
    C8, A7                           // Notes
};
int noteDurations[] = {
     8, 8, 8, 2,             // Section 1
    4, 4, 4, 2,             // Section 2
    8, 8, 8, 8, 1,          // Section 3
    8, 8, 8, 8, 2,          // Section 4

    4, 4, 4, 2,             // Section 5
    8, 8, 8, 8, 1,          // Section 6
    8, 8, 8, 8, 8, 8, 8, 8, // Section 7
    2, 8, 4, 8, 4, 4,       // Section 8

    8, 8, 8, 2,             // Section 9
    8, 8, 8, 8, 1,          // Section 10
    8, 8, 8, 8, 8, 4, 8, 2, // Section 11
    4, 2, 4, 1,             // Section 12
};

void setup() {
  pinMode(buzzerpin,OUTPUT);
  pinMode(led,OUTPUT);

    Wire.begin(21, 22); // SDA, SCL
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.clearDisplay();
    //display.drawBitmap(0,0,epd_bitmap_germain_resize,128,64,SSD1306_WHITE);
    display.display();
}

void loop() {
  display.clearDisplay();
  centerText(name,18,1);
  centerText(section,28,1);
  centerText(address1,38,1);
  centerText(address2,48,1);
  display.display();
  delay(5000);
  print_name();
  print_section();
  print_address();
  print_picture();
  display.display();

}

void centerText(const char *text ,int y,int TEXT_SIZE ) {
  display.setTextSize(TEXT_SIZE);
  display.setTextColor(SSD1306_WHITE);
  int textWidth = strlen(text) * 6 * TEXT_SIZE; 
  int textHeight = 8 * TEXT_SIZE;            
  int x = (SCREEN_WIDTH - textWidth) / 2;
  y -= textHeight;
  display.setCursor(x, y);
  display.println(text);
}


void print_name(){
  while(true){
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  static int run = 128;
  display.setTextSize(1);
  display.setCursor(50, 8);
  display.print("Name");
  
  int TEXT_SIZE = 5;
  display.setTextSize(TEXT_SIZE);
  int textWidth = strlen(name) * 6 * TEXT_SIZE; 
  display.setCursor(run, 28);
  display.print(name);
  if(run == -textWidth){
    run = 128;
    break;
  }
  display.display();
  buzzer_sound();
  run--;
  }
}
void print_section(){
  while(true){
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  static int run = 128;
  display.setTextSize(1);
  display.setCursor(41, 8);
  display.print("Section");
  
  int TEXT_SIZE = 5;
  display.setTextSize(TEXT_SIZE);
  int textWidth = strlen(section) * 6 * TEXT_SIZE; 
  display.setCursor(run, 28);
  display.print(section);
  if(run == -textWidth){
    run = 128;
    break;
  }
  buzzer_sound();
  display.display();
  run--;
  }
}

void print_address(){
  while(true){
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  static int run = 128;
  display.setTextSize(1);
  display.setCursor(41, 8);
  display.print("Address");
  
  int TEXT_SIZE = 5;
  display.setTextSize(TEXT_SIZE);
  int textWidth = strlen(address) * 6 * TEXT_SIZE; 
  display.setCursor(run, 28);
  display.print(address);
  if(run == -textWidth){
    run = 128;
    break;
  }
    display.display();
    buzzer_sound();
  run--;
  }
}

void print_picture(){
  while(true){
    display.setTextColor(SSD1306_WHITE);
    display.clearDisplay();
    static int run = 128;
    display.drawBitmap(run,0,epd_bitmap_germain_resize,128,64,SSD1306_WHITE);
    if(run == -128){
    run = 128;
    break;
    }
    display.display();
    run--;
  }
}


void buzzer_sound(){
  currentT = millis();
  digitalWrite(led,LOW);
    if (currentT - previousT >= noteDuration * .5) {
    digitalWrite(led,HIGH);
    noTone(buzzerpin);
    noteIndex++;
    if (noteIndex >= sizeof(melody) / sizeof(melody[0])) {
      noteIndex = 0;
    }
    noteDuration = 4000 / noteDurations[noteIndex];
    tone(buzzerpin, melody[noteIndex], noteDuration);
    previousT = currentT;
  }
}





 
