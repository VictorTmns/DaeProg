#include "pch.h"
#include "MyUtils.h"

Color4f RgbToColor4f(float r, float g, float b, float a) {
	return Color4f(r / 255, g / 255, b / 255, a / 255);
}