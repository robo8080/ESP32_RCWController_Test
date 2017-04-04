typedef union
{

  struct  {
/*
1-2バイト目：ボタン
　UP: 0x0001
　DOWN: 0x0002
　RIGHT: 0x0004
　LEFT: 0x0008
　Y button: 0x0010
　A button: 0x0020
　B button: 0x0040
　X button: 0x0100
　L1: 0x0200
　L2: 0x0400
　R1: 0x0800
　R2: 0x1000
　START: 0x0003
　SELECT: 0x000C
*/
    unsigned X    : 1;
    unsigned L1   : 1;
    unsigned L2   : 1;
    unsigned R1   : 1;
    unsigned R2   : 1;
    unsigned space1 : 3;
    unsigned UP   : 1;
    unsigned DOWN : 1;
    unsigned RIGHT  : 1;
    unsigned LEFT : 1;
    unsigned Y    : 1;
    unsigned A    : 1;
    unsigned B    : 1;
    unsigned space2 : 1;
/*
3-4バイト目：左アナログ
　左右: 1-255 (Neutral=128) 
　上下: 1-255 (Neutral=128)
*/
    unsigned LeftAnalogLR:8;
    unsigned LeftAnalogUD:8;
/*
5-6バイト目：右アナログ
　左右: 1-255 (Neutral=128) 
　上下: 1-255 (Neutral=128)
*/
    unsigned RightAnalogLR:8;
    unsigned RightAnalogUD:8;
/*
7-9バイト目：アクセラレータ
　X軸: 1-255 (Neutral=128) 
　Y軸: 1-255 (Neutral=128)
　Z軸: 1-255 (Neutral=128)
*/
    unsigned AcceleX:8;
    unsigned AcceleY:8;
    unsigned AcceleZ:8;
/*
10バイト目：設定（向き、設定）
　7-6bit目: アクセラレータ設定（0-3）
　5bit目: 左アナログ（0-1）
　4bit目: 右アナログ（0-1）
　3-1bit目: iOSデバイス向き（1-4）
*/
    unsigned DEV_DIR:4;
    unsigned RIGHT_ANALOG:1;
    unsigned LEFT_ANALOG:1;
    unsigned ACCELE_SETTING:2;
  }status;
  unsigned char data[10];
}RCWController;
RCWController controller;            

