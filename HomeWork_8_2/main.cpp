#include "mbed.h"
#include "UnbufferedSerial.h"

UnbufferedSerial pc(USBTX, USBRX);

void onSerialRx(){
    static char serialInBuffer[64];
    static int serialCount = 0;
    while (pc.readable()){
        char byteln;
        pc.read(&byteln, 1);
        if (byteln=='\n'){
            serialInBuffer[serialCount]=0;
            char *p = serialInBuffer;
            float data[4];
            int count = 0;
            while(*p){
                if(*p==','){
                    *p++=0;
                    if(count<4){
                        data[count++]=atof(serialInBuffer);
                        // atof 함수는 문자열을 읽다가 처음으로 숫자나 소수점ㅇ르 만나면 그 위치부터 부동소수점 값을 읽어서
                        // double 형으로 변환한다
                        // 문자열이나 숫자나 소수점을 만나지 못하면 0을 반환한다
                        serialInBuffer[0]=0;
                    }
                    else{
                        break;
                    }
                }
                else{
                        ++p;
                    }
                }
                if(count==4){
                    printf("%.3f,%.3f,%.3f,%.3f\r\n",data[0],data[1],data[2],data[3]);
            }
            serialCount=0;
            }
            else{
                serialInBuffer[serialCount]=byteln;
                if(serialCount<64){
                    ++serialCount;
                }
        }
    }
}

// main() runs in its own thread in the OS
int main()
{
    pc.attach(&onSerialRx);
    while (true) {
        
    }
    // get 함수로 한 바이트를 수신하여 serialBuffer에 저장하고 ','를 만나면 버퍼의 데이터를 atof 함수로 
}

