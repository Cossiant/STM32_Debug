#ifndef INCLUDE_TO_C_H
#define INCLUDE_TO_C_H

#ifdef __cplusplus
extern "C"
{
#endif
//这里添加CPP函数，因为CPP无法正确被C调用，因此要进行转换
    void Debug_Main();
    void Debug_Main_While();
#ifdef __cplusplus
}
#endif

#endif