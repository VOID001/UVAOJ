#include<windows.h>
#include<wchar.h>
#include<stdio.h>

int main(void)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    printf("%d\n",st.wMinute-st.wDay);
    return 0;
}
