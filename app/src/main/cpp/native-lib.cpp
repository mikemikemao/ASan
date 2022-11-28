//
// Created by Lee on 2020/6/10.
//

#include <jni.h>
#include <android/log.h>

//定义日志宏定义，方便使用
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"xiaojun",__VA_ARGS__)
//
//void JNI_invokeJNI(JNIEnv* env,jobject clazz);
//
//JNINativeMethod RegisterMethods[] = {
//        {"invokeJNI","()V",(void*)JNI_invokeJNI}
//};
//
//jint RegisterNatives(JNIEnv *env){
//    jclass clazz = env->FindClass("com/pqy/asan/JNI");
//    return env->RegisterNatives(clazz,RegisterMethods, sizeof(RegisterMethods)/ sizeof(RegisterMethods[0]));
//}
//
//jint JNI_OnLoad(JavaVM *vm, void *reserved){
//    JNIEnv* env = NULL;
//    if (vm->GetEnv((void **)&env,JNI_VERSION_1_6)!=JNI_OK){
//        return JNI_ERR;
//    }
//    RegisterNatives(env);
//    return JNI_VERSION_1_6;
//}

static void UseAfterFree(){
    int *arr = new int [1024];
    arr[0] = 11;
    delete [] arr;
    LOGE("UseAfterFree arr[0] = %d",arr[0]);
}

static void stackBufferOverflow(){
    int arr[1024];
    arr[0] = 11;
    arr[1024] = 12;
    LOGE("UseAfterFree arr[0] = %d arr[1024] = %d",arr[0],arr[1024]);
}

//----------------------------实现------------------------------------
extern "C" JNIEXPORT void JNICALL
Java_com_pqy_asan_JNI_invokeJNI(JNIEnv* env,jobject clazz){
    UseAfterFree();
    LOGE("调用了native方法");
}
//void JNI_invokeJNI(JNIEnv* env,jobject clazz){
////    char *chars = new char[9];
////    delete[] chars;
////    delete[] chars;
//  //  UseAfterFree();
//    //stackBufferOverflow();
//    LOGE("调用了native方法");
//}