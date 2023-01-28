#include "helper.h"

float radians(int angle)
{
	return angle / 180.0 * M_PI;
}

int degrees(float angle)
{
	return angle / M_PI * 180.0;
}

void fix_angle(int *angle)
{
	while (*angle < 0) *angle += 360;
	while (*angle > 360) *angle -= 360;
}
