package com.units;

import com.units.geometry.Geometry;
import com.units.geometry.Rectangle;

public class JNIBattleWay {

	public static void main(String[] args) {
		System.out.println("Hello World");
		// System.load("[PATH_TO_PROJECT]/jni/libgeometry.1.0.dylib");
		System.loadLibrary("geometry.1.0");
		
		System.out.println("geometry lib online");
		
		Rectangle rec = new Rectangle();

		Geometry geometry = new Geometry();

		rec.width = 10;
		rec.height = 4;

		int area = geometry.getRectangleArea(rec);

		System.out.println("Area: " + String.valueOf(area));
	}

}
