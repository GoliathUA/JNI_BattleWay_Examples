#include "com_units_geometry_Geometry.h"
#include "geometry.h"

JNIEXPORT jint JNICALL Java_com_units_geometry_Geometry_getRectangleArea(
		JNIEnv *env, jobject obj, jobject jrectangle) {
	setbuf(stdout, NULL);
	jclass cls = (*env)->GetObjectClass(env, jrectangle);

	jfieldID fidInt = (*env)->GetFieldID(env, cls, "width", "I");
	jint jwidth = (*env)->GetIntField(env, jrectangle, fidInt);
	printf("Width: %d\n", jwidth);
	//fflush(stdout);

	fidInt = (*env)->GetFieldID(env, cls, "height", "I");
	jint jheight = (*env)->GetIntField(env, jrectangle, fidInt);
	printf("Height: %d\n", jheight);
	//fflush(stdout);

	t_rectangle rec;

	rec.width = jwidth;
	rec.heigh = jheight;

	return get_rectangle_area(&rec);
}
