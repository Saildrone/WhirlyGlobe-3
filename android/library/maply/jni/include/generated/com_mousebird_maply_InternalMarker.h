/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_mousebird_maply_InternalMarker */

#ifndef _Included_com_mousebird_maply_InternalMarker
#define _Included_com_mousebird_maply_InternalMarker
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setSelectID
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setSelectID
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setLoc
 * Signature: (Lcom/mousebird/maply/Point2d;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setLoc
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setEndLoc
 * Signature: (Lcom/mousebird/maply/Point2d;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setEndLoc
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setAnimationRange
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setAnimationRange
  (JNIEnv *, jobject, jdouble, jdouble);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setColor
 * Signature: (FFFF)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setColor
  (JNIEnv *, jobject, jfloat, jfloat, jfloat, jfloat);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    addTexID
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_addTexID
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setRotation
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setRotation
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setLockRotation
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setLockRotation
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setSize
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setSize
  (JNIEnv *, jobject, jdouble, jdouble);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setLayoutSize
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setLayoutSize
  (JNIEnv *, jobject, jdouble, jdouble);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setOffset
 * Signature: (DD)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setOffset
  (JNIEnv *, jobject, jdouble, jdouble);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setPeriod
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setPeriod
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    setVertexAttributes
 * Signature: ([Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_setVertexAttributes
  (JNIEnv *, jobject, jobjectArray);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_nativeInit
  (JNIEnv *, jclass);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    initialise
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_initialise
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_InternalMarker
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_InternalMarker_dispose
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif