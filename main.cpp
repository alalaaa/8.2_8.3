#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "base64.c"
#include "sha1.c"
using namespace std;

int main()
{
    ifstream plik1;
    string linia;
    plik1.open("a.txt");
        for(int i;i<6;i++){
            getline(plik1,linia);
        }
    plik1.close();
    
    char* char_arr;
    string str_obj(linia);
    char_arr = &str_obj[0];
    cout << char_arr;
    
         char *magicTest = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"; //36 znakow, GUID Magic string
        char shaSource[128] = char_arr; //24
        strcat(shaSource, magicTest); //laczymy te stringi w jeden do zakodowania
        printf("String kodowany: [%s]\n", shaSource);
        char result[32];//21
        SHA1(result, shaSource, strlen(shaSource) ); //Kodowanie SHA1
        char base64string[128];
        Base64encode(base64string, result, strlen(result)); //konwersja Base64
        printf("Po zakodowaniu to [%s] - dlugosc %i bajtow", base64string, strlen(base64string)); //wynikowy string, który wyolemy w odpowiedzi HandShake.
        return 0;
 }
