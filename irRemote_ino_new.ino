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
        myKey = 0x52;	// key up
        keyboardPress(myKey);
        break;
      case 0xC1CCC23D:
        myKey = 0x51;	// key down
        keyboardPress(myKey);
        break;
      case 0xC1CC22DD:
        myKey = 0x50;	// key left
        keyboardPress(myKey);
        break;
      case 0xC1CCA25D:
        myKey = 0x4F;	// key right
        keyboardPress(myKey);
        break;
      case 0xC1CC827D:
        myKey = 0x28;	// enter
        keyboardPress(myKey);
        break;
      case 0xC1CCA956:
        myKey = 0x29;	// escape
        keyboardPress(myKey);
        break;
      case 0xC1CC0EF1:
        myKey = 0x2A;	// backspace
        keyboardPress(myKey);
        break;
      case 0xC1CCE21D:
        myKey = 0x3F;	// F6
        keyboardPress(myKey);
        break;
      case 0xC1CC12ED:
        myKey = 0x40;	// F7
        keyboardPress(myKey);
        break;
      case 0xC1CC629D:
        myKey = 0x45;	// F12
        keyboardPress(myKey);
        break;
      case 0xC1CC6A95:
        myKey = 0x57;	// +
        keyboardPress(myKey);
        break;
      case 0xC1CCEA15:
        myKey = 0x56;	// -
        keyboardPress(myKey);
        break;
      case 0xC1CC59A6:
        myKey = 0x2C;	// space bar
        keyboardPress(myKey);
        break; 
      case 0xC1CCE916:
        myKey = 0x15;	// r
        keyboardPress(myKey);
        break; 
      case 0xC1CC9966:
        myKey = 0x09;	// f
        keyboardPress(myKey);
        break; 
      case 0xC1CC6996:
        myKey = 0x0C;	// i
        keyboardPress(myKey);
        break; 
      case 0xC1CC29D6:
        myKey = 0x06;	// c
        keyboardPress(myKey);
        break; 
      case 0xC1CC39C6:
        myKey = 0x1B;	// x
        keyboardPress(myKey);
        break; 
      case 0xC1CCCE31:
        myKey = 0x16;	// s
        keyboardPress(myKey);
        break; 


      case 0x80BF53AC:
        myKey = 0x52;	// key up
        keyboardPress(myKey);
        break;
      case 0x80BF4BB4:
        myKey = 0x51;	// key down
        keyboardPress(myKey);
        break;
      case 0x80BF9966:
        myKey = 0x50;	// key left
        keyboardPress(myKey);
        break;
      case 0x80BF837C:
        myKey = 0x4F;	// key right
        keyboardPress(myKey);
        break;
      case 0x80BF738C:
        myKey = 0x28;	// enter
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
	0x00	Reserved (no event indicated)
	0x01	Keyboard ErrorRollOver
	0x02	Keyboard POSTFail
	0x03	Keyboard ErrorUndefined
	0x04	Keyboard a and A
	0x05	Keyboard b and B
	0x06	Keyboard c and C
	0x07	Keyboard d and D
	0x08	Keyboard e and E
	0x09	Keyboard f and F
	0x0A	Keyboard g and G
	0x0B	Keyboard h and H
	0x0C	Keyboard i and I
	0x0D	Keyboard j and J
	0x0E	Keyboard k and K
	0x0F	Keyboard l and L
	0x10	Keyboard m and M
	0x11	Keyboard n and N
	0x12	Keyboard o and O
	0x13	Keyboard p and P
	0x14	Keyboard q and Q
	0x15	Keyboard r and R
	0x16	Keyboard s and S
	0x17	Keyboard t and T
	0x18	Keyboard u and U
	0x19	Keyboard v and V
	0x1A	Keyboard w and W
	0x1B	Keyboard x and X
	0x1C	Keyboard y and Y
	0x1D	Keyboard z and Z
	0x1E	Keyboard 1 and !
	0x1F	Keyboard 2 and @
	0x20	Keyboard 3 and #
	0x21	Keyboard 4 and $
	0x22	Keyboard 5 and %
	0x23	Keyboard 6 and ^
	0x24	Keyboard 7 and &
	0x25	Keyboard 8 and *
	0x26	Keyboard 9 and (
	0x27	Keyboard 0 and )
	0x28	Keyboard Return (ENTER)
	0x29	Keyboard ESCAPE
	0x2A	Keyboard DELETE (Backspace)
	0x2B	Keyboard Tab
	0x2C	Keyboard Spacebar
	0x2D	Keyboard - and (underscore)
	0x2E	Keyboard = and +
	0x2F	Keyboard [ and {
	0x30	Keyboard ] and }
	0x31	Keyboard \ and |
	0x32	Keyboard Non-US # and ~
	0x33	Keyboard ; and :
	0x34	Keyboard ' and "
	0x35	Keyboard Grave Accent and Tilde
	0x36	Keyboard, and <
	0x37	Keyboard . and >
	0x38	Keyboard / and ?
	0x39	Keyboard Caps Lock
	0x3A	Keyboard F1
	0x3B	Keyboard F2
	0x3C	Keyboard F3
	0x3D	Keyboard F4
	0x3E	Keyboard F5
	0x3F	Keyboard F6
	0x40	Keyboard F7
	0x41	Keyboard F8
	0x42	Keyboard F9
	0x43	Keyboard F10
	0x44	Keyboard F11
	0x45	Keyboard F12
	0x46	Keyboard PrintScreen
	0x47	Keyboard Scroll Lock
	0x48	Keyboard Pause
	0x49	Keyboard Insert
	0x4A	Keyboard Home
	0x4B	Keyboard PageUp
	0x4C	Keyboard Delete Forward
	0x4D	Keyboard End
	0x4E	Keyboard PageDown
	0x4F	Keyboard RightArrow
	0x50	Keyboard LeftArrow
	0x51	Keyboard DownArrow
	0x52	Keyboard UpArrow
	0x53	Keypad Num Lock and Clear
	0x54	Keypad /
	0x55	Keypad *
	0x56	Keypad -
	0x57	Keypad +
	0x58	Keypad ENTER
	0x59	Keypad 1 and End
	0x5A	Keypad 2 and Down Arrow
	0x5B	Keypad 3 and PageDn
	0x5C	Keypad 4 and Left Arrow
	0x5D	Keypad 5
	0x5E	Keypad 6 and Right Arrow
	0x5F	Keypad 7 and Home
	0x60	Keypad 8 and Up Arrow
	0x61	Keypad 9 and PageUp
	0x62	Keypad 0 and Insert
	0x63	Keypad . and Delete
	0x64	Keyboard Non-US \ and |
	0x65	Keyboard Application
	0x66	Keyboard Power
	0x67	Keypad =
	0x68	Keyboard F13
	0x69	Keyboard F14
	0x6A	Keyboard F15
	0x6B	Keyboard F16
	0x6C	Keyboard F17
	0x6D	Keyboard F18
	0x6E	Keyboard F19
	0x6F	Keyboard F20
	0x70	Keyboard F21
	0x71	Keyboard F22
	0x72	Keyboard F23
	0x73	Keyboard F24
	0x74	Keyboard Execute
	0x75	Keyboard Help
	0x76	Keyboard Menu
	0x77	Keyboard Select
	0x78	Keyboard Stop
	0x79	Keyboard Again
	0x7A	Keyboard Undo
	0x7B	Keyboard Cut
	0x7C	Keyboard Copy
	0x7D	Keyboard Paste
	0x7E	Keyboard Find
	0x7F	Keyboard Mute
	0x80	Keyboard Volume Up
	0x81	Keyboard Volume Down
	0x82	Keyboard Locking Caps Lock
	0x83	Keyboard Locking Num Lock
	0x84	Keyboard Locking Scroll Lock
	0x85	Keypad Comma
	0x86	Keypad Equal Sign
	0x87	Keyboard International1
	0x88	Keyboard International2
	0x89	Keyboard International3
	0x8A	Keyboard International4
	0x8B	Keyboard International5
	0x8C	Keyboard International6
	0x8D	Keyboard International7
	0x8E	Keyboard International8
	0x8F	Keyboard International9
	0x90	Keyboard LANG1
	0x91	Keyboard LANG2
	0x92	Keyboard LANG3
	0x93	Keyboard LANG4
	0x94	Keyboard LANG5
	0x95	Keyboard LANG6
	0x96	Keyboard LANG7
	0x97	Keyboard LANG8
	0x98	Keyboard LANG9
	0x99	Keyboard Alternate Erase
	0x9A	Keyboard SysReq/Attention
	0x9B	Keyboard Cancel
	0x9C	Keyboard Clear
	0x9D	Keyboard Prior
	0x9E	Keyboard Return
	0x9F	Keyboard Separator
	0xA0	Keyboard Out
	0xA1	Keyboard Oper
	0xA2	Keyboard Clear/Again
	0xA3	Keyboard CrSel/Props
	0xA4	Keyboard ExSel
	0xE0	Keyboard LeftControl
	0xE1	Keyboard LeftShift
	0xE2	Keyboard LeftAlt
	0xE3	Keyboard Left GUI
	0xE4	Keyboard RightControl
	0xE5	Keyboard RightShift
	0xE6	Keyboard RightAlt
	0xE7	Keyboard Right GUI
*/
/*
Key		Hexadecimal value		Decimal value	
KEY_LEFT_CTRL 	0x80 	128
KEY_LEFT_SHIFT 	0x81 	129
KEY_LEFT_ALT 	0x82 	130
KEY_LEFT_GUI 	0x83 	131
KEY_RIGHT_CTRL 	0x84 	132
KEY_RIGHT_SHIFT 	0x85 	133
KEY_RIGHT_ALT 	0x86 	134
KEY_RIGHT_GUI 	0x87 	135
KEY_UP_ARROW 	0xDA 	218
KEY_DOWN_ARROW 	0xD9 	217
KEY_LEFT_ARROW 	0xD8 	216
KEY_RIGHT_ARROW 	0xD7 	215
KEY_BACKSPACE 	0xB2 	178
KEY_TAB 	0xB3 	179
KEY_RETURN 	0xB0 	176
KEY_ESC 	0xB1 	177
KEY_INSERT 	0xD1 	209
KEY_DELETE 	0xD4 	212
KEY_PAGE_UP 	0xD3 	211
KEY_PAGE_DOWN 	0xD6 	214
KEY_HOME 	0xD2 	210
KEY_END 	0xD5 	213
KEY_CAPS_LOCK 	0xC1 	193
KEY_F1 	0xC2 	194
KEY_F2 	0xC3 	195
KEY_F3 	0xC4 	196
KEY_F4 	0xC5 	197
KEY_F5 	0xC6 	198
KEY_F6 	0xC7 	199
KEY_F7 	0xC8 	200
KEY_F8 	0xC9 	201
KEY_F9 	0xCA 	202
KEY_F10 	0xCB 	203
KEY_F11 	0xCC 	204
KEY_F12 	0xCD 	205 

*/





