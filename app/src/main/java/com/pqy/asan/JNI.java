package com.pqy.asan;

/**
 * function:
 * author:xiaojun li
 * data:2020/6/10
 * email:603820467@qq.com
 */
public class JNI {
    static {
        System.loadLibrary("native-lib");
    }

//    private static JNI sJNI = new JNI();
//
//    private JNI(){}
//
//    public static JNI getInstance(){
//        return sJNI;
//    }

    public native void invokeJNI();

}
