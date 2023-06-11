#pragma once

#include <cmath>

namespace {
	bool boxCollision(float a_x, int a_w, float a_y, int a_h, float b_x, int b_w, float b_y, int b_h) {

		if (a_x - a_w / 2. < b_x - b_w / 2. + b_w &&
			a_x - a_w / 2. + a_w > b_x - b_w / 2. &&
			a_y - a_h / 2. < b_y - b_h / 2. + b_h &&
			a_y - a_h / 2. + a_h > b_y - b_h / 2.) {

			return true;
		}
		return false;
	}
	float distanceBetweenPoints(float x1, float y1, float x2, float y2) {
		return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	}
}