#define UNICODE
#include <bits/stdc++.h>
#include <windows.h>
#define BUFFER_SIZE 256
#define MAX_BUFFER_SIZE 256
#define TOKEN_DELIMETERS " \t\r\n\a"
using namespace std;
int sum(int a, int b);
int printPrompt(TCHAR* cur_directory){
    /**
     * In ra màn hình console đường dẫn 
     * (VD: C:\Users\Admin\.....> $ *phần tiếp này là lệnh*)
     **/
    if(GetCurrentDirectory(300,cur_directory) == 0){
        cout << "Reading of current working directory failed.\n";
        return -1;
    }
    printf("your curdirectory:  %S> $",cur_directory);   
    return 1;
}
 wchar_t *GetWC( char *c)
{
    /**
     * Chuyển char* sang wchar_t*
     * 
     * 
     */
    const size_t cSize = strlen(c)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, c, cSize);
    sum(3,5);
    return wc;
}
int sum(int a, int b){return a+b;}


int main(){
    
    return 0;

}