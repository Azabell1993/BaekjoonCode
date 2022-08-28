#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

#define class struct
#define public static __attribute__((visibility("default")))
#define private static __attribute__((visibility("hidden")))

#ifdef __cheaderfile
extern "C" {
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
#define NORETERN _attribute_ ((_noreturn_))
    /* 함수 전방 선언 */
    public void SUM##_set_Sum(SUM *this, type *input);
    public int SUM##_get_Sum(const SUM *this);
    public size_t SUM##_size(const SUM *this);
    public void SUM##_for_each_ptr(SUM *this, void (*f)(type *));
    public void SUM##_for_each(const SUM *this, void (*f)(const type));
    public inline void init(type *e);
    public inline void print(type *e);

    /* 비멤버 생성자 전방 선언 */
    SUM new_##SUM(void);
#endif

#define SumFunc(SUM, type, length)                                                  \
                                                                                    \
    class SUM;                                                                      \
    typedef class SUM SUM;                                                          \
                                                                                    \
    class SUM                                                                       \
    {                                                                               \
        type input[length];                                                         \
                                                                                    \
        size_t  (*size)(const SUM *);                                               \
        void (*setSum)(SUM *this, type *);                                          \
        int (*getSum)(const SUM *);                                                 \
        void (*for_each_ptr)(SUM *, void(*)(SUM *, type *));                        \
        void (*for_each)(const SUM *, void(*)(const type *));                       \
    };                                                                              \
                                                                                    \
    public void SUM##_set_Sum(SUM *this, type *input) {                             \
        for(int i=0; i<length; i+=1)                                                \
            this -> input[i] = input[i];                                            \
    }                                                                               \
                                                                                    \
    public int SUM##_get_Sum(const SUM *this) {                                     \
        int sum = 0;                                                                \
        for(int i=0; i<length; i+=1) {                                              \
            sum += this->input[i];                                                  \
        }                                                                           \
        return printf("%d", sum);                                                   \
    }                                                                               \
                                                                                    \
    public size_t SUM##_size(const SUM *this)                                       \
    {                                                                               \
        return length;                                                              \
    }                                                                               \
                                                                                    \
    public void SUM##_for_each_ptr(SUM *this, void (*f)(type *))                    \
    {                                                                               \
        for (int i = 0; i < length; i+=1)                                           \
            f(&this->input[i]);                                                     \
    }                                                                               \
                                                                                    \
    public void SUM##_for_each(const SUM *this, void (*f)(const type))              \
    {                                                                               \
        for (int i = 0; i < length; i+=1)                                           \
            f(this->input[i]);                                                      \
    }                                                                               \
                                                                                    \
    public inline void init(type *e) {                                              \
        static int i = 3;                                                           \
        for(; i<length; i+=1)                                                       \
            *e = i;                                                                 \
    }                                                                               \
                                                                                    \
    public inline void print(type *e) {                                             \
        printf("%d ", e);                                                           \
    }                                                                               \
                                                                                    \
    SUM new_##SUM(void)                                                             \
    {                                                                               \
        static SUM temp = {                                                         \
                .input = 0,                                                         \
                .size = SUM##_size,                                                 \
                .setSum = SUM##_set_Sum,                                            \
                .getSum = SUM##_get_Sum,                                            \
                .for_each_ptr = SUM##_for_each_ptr,                                 \
                .for_each = SUM##_for_each,                                         \
        };                                                                          \
        return temp;                                                                \
    }
#ifdef __cplusplus
}
#endif //__cplusplus
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

SumFunc(SumLogic, int, 2)

int main(int argc, char* argv[]) {

    //int data[2] = {8,10};
    int data[2];

    /* 일반적인 입력 */
    for(int i=0; i<2; i+=1)
        scanf("%d", &data[i]);

    SumLogic sum1 = new_SumLogic();
    sum1.setSum(&sum1, data);
    sum1.for_each_ptr(&sum1,init);

    // 출력 확인 용 함수
    //sum1.for_each(&sum1, print);

    sum1.getSum(&sum1);

    return 0;
}