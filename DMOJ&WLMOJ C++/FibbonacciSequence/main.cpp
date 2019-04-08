/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joshua
 *
 * Created on March 31, 2019, 12:20 p.m.
 */

#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int fast_pow_mod(double b, int x, int mod) {
		if (x == 0)
			return 1;
		if (x == 1)
			return b;
		if (x % 2 == 0)
			return fast_pow_mod(b * b % mod, x / 2, mod) % mod;

		return b * fast_pow_mod(b * b % mod, x / 2, mod) % mod;
	}

int main() {


}

