#pragma once
#include "kmath.h"
#include "shapes.h"
#include "transform.h"
#include "Rigidbody.h"
#include "collider.h"

void drawMatrix(const Matrix3 &);
void drawVector(const Matrix3 &, const Vector2 &, unsigned TINT = 0x00ffffff);
void drawPlane(const Plane   &, unsigned TINT);
void drawAABB(const AABB    &, unsigned TINT);
void drawCircle(const Circle  &, unsigned TINT);
void drawRay(const Ray     &, unsigned TINT);


void drawTransform(const Transform &);
void drawRigidbody(const Transform &, const Rigidbody &);
void drawCollider(const Transform &, const Collider  &);