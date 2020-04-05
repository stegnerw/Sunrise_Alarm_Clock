#define MUX_PIN         2
#define LIGHT_SRCLK_PIN 7
#define LIGHT_SER_PIN   8

void writeLight(uint8_t, uint8_t, uint8_t, uint8_t);
void writeByte(uint8_t);
void strobeLightSRCLK();
void muxOn();
void muxOff();

#define RED   255
#define GREEN 255
#define BLUE  255
#define WHITE 255

void setup() {
  pinMode(MUX_PIN, OUTPUT);
  pinMode(LIGHT_SER_PIN, OUTPUT);
  pinMode(LIGHT_SRCLK_PIN, OUTPUT);
}

void loop() {
  for (int j = 0; j < 8; j++) {
    writeLight(RED, 0, 0, 0);
  }
  delay(1000);
  for (int j = 0; j < 8; j++) {
    writeLight(0, GREEN, 0, 0);
  }
  delay(1000);
  for (int j = 0; j < 8; j++) {
    writeLight(0, 0, BLUE, 0);
  }
  delay(1000);
  for (int j = 0; j < 8; j++) {
    writeLight(0, 0, 0, WHITE);
  }
  delay(1000);
}

void writeLight(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  writeByte(r);
  writeByte(g);
  writeByte(b);
  writeByte(w);
}

void writeByte(uint8_t b) {
  for (int i = 7; i >= 0; i--) {
    if ((b >> i) & B1) {
      digitalWrite(LIGHT_SER_PIN, HIGH);
    } else {
      digitalWrite(LIGHT_SER_PIN, LOW);
    }
    strobeLightSRCLK();
  }
}

void strobeLightSRCLK() {
  digitalWrite(LIGHT_SRCLK_PIN, HIGH);
  digitalWrite(LIGHT_SRCLK_PIN, LOW);
}

void muxOn() {
  digitalWrite(MUX_PIN, HIGH);
}

void muxOff() {
  digitalWrite(MUX_PIN, LOW);
}
