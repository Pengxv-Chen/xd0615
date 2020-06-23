
#define NOTE_C4  262 //NOTE_C4 对应的常量为262//
#define NOTE_G3  196 //NOTE_G3 对应的常量为196//
#define NOTE_A3  220 //NOTE_A3 对应的常量为220//
#define NOTE_B3  247 //NOTE_B3 对应的常量为247//
#define NOTE_C4  262 //NOTE_C4 对应的常量为262//

int melody[] = {   //说明音调旋律有上述几个音调组成//
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {    //定义八分音符和四分音符//
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() { //重复旋律里的音调//

  for (int thisNote = 0; thisNote < 8; thisNote++) { //定义 thisNote 整形变量，并且从0到7每次自增1//

    int noteDuration = 1000 / noteDurations[thisNote];//计算每个音符的时长//
    tone(8, melody[thisNote], noteDuration);//tone 函数第二种使用方法 tone(引脚数(图中为第8引脚)，频率，时长)//

    int pauseBetweenNotes = noteDuration * 1.30; //定义变量pauseBetweenNotes(音调之间的间隔时间)为音调时长的1.3 倍//
    delay(pauseBetweenNotes);//延迟的微秒数为变量pauseBetweenNotes的值
    noTone(8);//在某个引脚截停tone引发的方波，接在第8引脚所以括号里为8，在发出下一个音调之前必须先在前一个引脚上进行notone(前一个引脚数)//
  }
}

void loop() {  //没有需要循环执行的命令//
  
}