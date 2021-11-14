#include "Application.hpp"

int main(int argc,char* filename[])
{
    loadData(filename[1]);
    prompt();
    return argc;
}