/*
--------------------------------------------------
Project: a2q2
File:    polynomial.h
Author:  Mehdi Al-heloo
Version: 2025-01-24
--------------------------------------------------
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

float horner(float *p, int n, float x);
void derivative(float *p, float *d, int n);
float newton(float *p, int n, float x0);

#endif