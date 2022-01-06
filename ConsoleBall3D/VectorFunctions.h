#pragma once
#include <math.h>
#include "Vector2.h"
#include "Vector3.h"

float clamp(float value, float min, float max) { return fmax(fmin(value, max), min); }
float length(vector2 const& v) { return sqrt(v.x * v.x + v.y * v.y); }
float length(vector3 const& v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
vector3 norm(vector3 v) { return v / length(v); }
float dot(vector3 const& a, vector3 const& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

vector2 sphere(vector3 ro, vector3 rd, float r) {
    float b = dot(ro, rd);
    float c = dot(ro, ro) - r * r;
    float h = b * b - c;
    if (h < 0.0) return vector2(-1.0);
    h = sqrt(h);
    return vector2(-b - h, -b + h);
}