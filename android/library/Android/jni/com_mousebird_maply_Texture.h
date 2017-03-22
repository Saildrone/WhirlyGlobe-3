/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_mousebird_maply_Texture */

#ifndef _Included_com_mousebird_maply_Texture
#define _Included_com_mousebird_maply_Texture
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mousebird_maply_Texture
 * Method:    setSettings
 * Signature: (ZZ)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Texture_setSettings
  (JNIEnv *, jobject, jboolean, jboolean);

/*
 * Class:     com_mousebird_maply_Texture
 * Method:    setBitmap
 * Signature: (Landroid/graphics/Bitmap;I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_Texture_setBitmap
  (JNIEnv *, jobject, jobject, jint);

/*
 * Class:     com_mousebird_maply_Texture
 * Method:    getID
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_mousebird_maply_Texture_getID
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_Texture
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Texture_nativeInit
  (JNIEnv *, jclass);

/*
 * Class:     com_mousebird_maply_Texture
 * Method:    initialise
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Texture_initialise
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_Texture
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Texture_dispose
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
