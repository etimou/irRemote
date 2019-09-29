
/*
My codes
C1CC09F6 mute
C1CCCE31 power
C1CC8679 1
C1CC46B9 2
C1CCC639 3
C1CC26D9 4
C1CCA659 5
C1CC6699 6
C1CCE619 7
C1CC16E9 8
C1CC9669 9
C1CC06F9 0
C1CC0EF1 c
C1CC8976 soucoupe
C1CC49B6 book
C1CCC936 neuf
C1CC29D6 list
C1CC629D A
C1CCE21D B
C1CC12ED C
C1CC926D D
C1CC6A95 vol+
C1CCEA15 vol-
C1CC1AE5 prog+
C1CC9A65 prog-
C1CC42BD up
C1CCC23D down
C1CC22DD left
C1CCA25D right
C1CC827D ok
C1CCA956 back
C1CC6996 i
C1CCE916 rewind
C1CC9966 forward
C1CC19E6 nav
C1CC59A6 play/pause
C1CCD926 rec
C1CC39C6 stop
C1CCB946 ....
80BF3BC4 power
80BF39C6 mute
80BF49B6 1
80BFC936 2
80BF33CC 3
80BF718E 4
80BFF10E 5
80BF13EC 6
80BF51AE 7
80BFD12E 8
80BF23DC 9
80BFE11E 0
80BF9B64 tv/radio
80BF41BE <-PR
80BF6B94 EPG
80BFA956 MENU
80BF53AC up
80BF4BB4 down
80BF9966 left
80BF837C right
80BF738C OK
80BF0BF4 INFO
80BFA35C EXIT
80BF6996 AUDIO/RED
80BF43BC TXT/GREEN
80BFC33C SUBTITLE/YELLOW
80BF21DE SPEAKERLR/BLUE
80BFBB44 fast up
80BF31CE fast down
80BFE31C PAUSE
80BFC13E MOZAIC
80BF11EE FAV
80BFB34C UHF
80BF03FC PAL/NTSC
80BF5BA4 TV/AV
 
*/

#include <IRremote.h>
#include <Keyboard.h>
int RECV_PIN = A2;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long old_value;
int RXLED = 17;  // The RX LED has a defined Arduino pin
unsigned long last_time_key_pressed = 0;



byte myKey = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Keyboard.begin();
  pinMode(RXLED, OUTPUT);  // Set RX LED as an output
  delay(200);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned long new_value = results.value;
    if (new_value == 0xFFFFFFFF)
    {
      new_value = old_value;
    }
    else
    {
      old_value = new_value;
    }
    Serial.println(new_value, HEX);
    
    
    
    
    
    if ( (micros() - last_time_key_pressed) > 20000 )

    {
    
    
    switch (new_value)
    {

      case 0xC1CC42BD:
        myKey = KEY_UP_ARROW;  // key up
        keyboardPress(myKey);
        break;
      case 0xC1CCC23D:
        myKey = KEY_DOWN_ARROW; // key down
        keyboardPress(myKey);
        break;
      case 0xC1CC22DD:
        myKey = KEY_LEFT_ARROW; // key left
        keyboardPress(myKey);
        break;
      case 0xC1CCA25D:
        myKey = KEY_RIGHT_ARROW; // key right
        keyboardPress(myKey);
        break;
      case 0xC1CC827D:
        myKey = KEY_RETURN; // enter
        keyboardPress(myKey);
        break;
      case 0xC1CCA956:
        myKey = KEY_ESC; // escape
        keyboardPress(myKey);
        break;
      case 0xC1CC0EF1:
        myKey = KEY_BACKSPACE; // backspace
        keyboardPress(myKey);
        break;
      case 0xC1CCE21D:
        myKey = KEY_F6; // F6
        keyboardPress(myKey);
        break;
      case 0xC1CC12ED:
        myKey = KEY_F7; // F7
        keyboardPress(myKey);
        break;
      case 0xC1CC629D:
        myKey = KEY_F12; // F12
        keyboardPress(myKey);
        break;
      case 0xC1CC6A95:
        myKey = '+'; // +
        keyboardPress(myKey);
        break;
      case 0xC1CCEA15:
        myKey = '-'; // -
        keyboardPress(myKey);
        break;
      case 0xC1CC59A6:
        myKey = ' '; // space bar
        keyboardPress(myKey);
        break; 
      case 0xC1CCE916:
        myKey = 'r'; // r
        keyboardPress(myKey);
        break; 
      case 0xC1CC9966:
        myKey = 'f'; // f
        keyboardPress(myKey);
        break; 
      case 0xC1CC6996:
        myKey = 'i'; // i
        keyboardPress(myKey);
        break; 
      case 0xC1CC29D6:
        myKey = 'c'; // c
        keyboardPress(myKey);
        break; 
      case 0xC1CC39C6:
        myKey = 'x'; // x
        keyboardPress(myKey);
        break; 
      case 0xC1CCCE31:
        myKey = 's'; // s
        keyboardPress(myKey);
        break; 
      case 0xC1CCC936:
        myKey = KEY_TAB; // tab
        keyboardPress(myKey);
        break; 
      case 0xC1CC09F6:
        myKey = KEY_F8; // mute
        keyboardPress(myKey);
        break;
      
      default:
        myKey = 0;
    }
    
    last_time_key_pressed = micros();

    }

    irrecv.resume(); // Receive the next value
  }
  
 digitalWrite(RXLED, HIGH);   // set the LED off
 TXLED0; 
}


void keyboardPress(byte b)
{
    Keyboard.press(b);
    delay(100);
    Keyboard.releaseAll();
}




/*
Key   Hexadecimal value   Decimal value 
KEY_LEFT_CTRL   0x80  128
KEY_LEFT_SHIFT  0x81  129
KEY_LEFT_ALT  0x82  130
KEY_LEFT_GUI  0x83  131
KEY_RIGHT_CTRL  0x84  132
KEY_RIGHT_SHIFT   0x85  133
KEY_RIGHT_ALT   0x86  134
KEY_RIGHT_GUI   0x87  135
KEY_UP_ARROW  0xDA  218
KEY_DOWN_ARROW  0xD9  217
KEY_LEFT_ARROW  0xD8  216
KEY_RIGHT_ARROW   0xD7  215
KEY_BACKSPACE   0xB2  178
KEY_TAB   0xB3  179
KEY_RETURN  0xB0  176
KEY_ESC   0xB1  177
KEY_INSERT  0xD1  209
KEY_DELETE  0xD4  212
KEY_PAGE_UP   0xD3  211
KEY_PAGE_DOWN   0xD6  214
KEY_HOME  0xD2  210
KEY_END   0xD5  213
KEY_CAPS_LOCK   0xC1  193
KEY_F1  0xC2  194
KEY_F2  0xC3  195
KEY_F3  0xC4  196
KEY_F4  0xC5  197
KEY_F5  0xC6  198
KEY_F6  0xC7  199
KEY_F7  0xC8  200
KEY_F8  0xC9  201
KEY_F9  0xCA  202
KEY_F10   0xCB  203
KEY_F11   0xCC  204
KEY_F12   0xCD  205 
*/
