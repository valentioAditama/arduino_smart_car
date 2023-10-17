#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// ============== LED Color =====================
int LED_PIN_12 = 12;
int LED_PIN_13 = 13;
// ==============================================

// ========================= OLED LED ==========================
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// ================================ Finished OLED LED =================

// ================ Controller State Via Bluetooth =================
char bt = 'S';
// ======================= End Controller State Via Bluetooth ==========

//==================  Front Wheels
// wheels front of left side
int Front_IN_1 = 8;
int Front_IN_2 = 9;

// wheels front of right side
int Front_IN_3 = 10;
int Front_IN_4 = 11;

// ============== Rear wheels
// wheels front of left back side
int rear_IN_1 = 2;
int rear_IN_2 = 3;

// wheels rear of right right side
int rear_IN_3 = 4;
int rear_IN_4 = 5;

void setup() {
  // put your setup code here, to run once: 
  // ================== LED Lamp  =========
  pinMode(LED_PIN_12, OUTPUT);
  pinMode(LED_PIN_13, OUTPUT);
  // ================== END LED Lamp ==========

  // =================== OLED LED ==========
  // Serial.begin(115200);
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Made By: ");
  display.println();

  display.setTextSize(2);
  // Display static text
  display.println("Valentio");
  display.println("Aditama");

  display.setTextSize(1);
  display.println();
  display.println("##### D 2000 VAL #####");
  display.display(); 
  delay(100);
  // ================ END OLED LED =========


// ================ WHELS =====================
  // ============ Front Wheels 
  // ===== Left side Front Wheels
  pinMode(Front_IN_1, OUTPUT); // forwards
  pinMode(Front_IN_2, OUTPUT); // backwards
  // ================================ 

  // ===== Right side Front Wheels
  pinMode(Front_IN_3, OUTPUT); // forwards
  pinMode(Front_IN_4, OUTPUT); // backwards
  // ================================ 

  // ============ Rear Wheels 
  // ===== Left side Front Wheels
  pinMode(rear_IN_1, OUTPUT); // backwards
  pinMode(rear_IN_2, OUTPUT); // forwards
  // ================================ 

  // ===== Right side Front Wheels
  pinMode(rear_IN_3, OUTPUT); // forwards
  pinMode(rear_IN_4, OUTPUT); // backwards
  // ================================   
}

void loop() {
  // ============ Controller Remote via Bluetooh ============
  // if some date is sent, reads it and saves in t
    bt = Serial.read();

  // if the t is '0' the DC motor will turn left
    if (bt == 'L') {
        // digitalWrite(rear_IN_2, HIGH);
        // digitalWrite(LED_PIN_12, HIGH);

        digitalWrite(LED_PIN_12, HIGH);
        digitalWrite(LED_PIN_13, LOW);
    }

    // if the t is '1' the DC motor will turn right
    if (bt == 'R') {
        // digitalWrite(rear_IN_3, HIGH);
        // digitalWrite(LED_PIN_12, HIGH);

        digitalWrite(LED_PIN_12, HIGH);
        digitalWrite(LED_PIN_13, LOW);
    }

    // if the t is '2' the DC motor will turn forwards
    if (bt == 'F') {
      // digitalWrite(Front_IN_1, HIGH);
      // digitalWrite(Front_IN_3, HIGH);
      // digitalWrite(rear_IN_2, HIGH);
      // digitalWrite(rear_IN_3, HIGH);
      // digitalWrite(LED_PIN_12, HIGH);

      digitalWrite(LED_PIN_12, HIGH);
      digitalWrite(LED_PIN_13, LOW);
    }

    // if the t is '3' the DC motor will turn back
    if (bt == 'B') {
        // digitalWrite(Front_IN_4, HIGH);
        // digitalWrite(Front_IN_2, HIGH);
        // digitalWrite(rear_IN_1, HIGH);
        // digitalWrite(rear_IN_4, HIGH);
        // digitalWrite(LED_PIN_13, HIGH);

        digitalWrite(LED_PIN_12, LOW);
        digitalWrite(LED_PIN_13, HIGH);
    }
    
    
  // ========= LED Lamp 
  // digitalWrite(LED_PIN_12, HIGH);
  // digitalWrite(LED_PIN_13, HIGH);
  // =========== End LED Lamp ======= 
  
  // digitalWrite(Front_IN_1, HIGH);
  // digitalWrite(Front_IN_2, HIGH);
  // digitalWrite(Front_IN_3, HIGH);
  // digitalWrite(Front_IN_4, HIGH);

  // digitalWrite(rear_IN_1, HIGH);
  // digitalWrite(rear_IN_2, HIGH);
  // digitalWrite(rear_IN_3, HIGH);
  // digitalWrite(rear_IN_4, HIGH);
}
