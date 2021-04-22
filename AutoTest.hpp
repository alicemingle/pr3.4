#pragma once
#include <chrono>

int AutoTest() {
	CComplexVector0 a(2);
	a[0] = CComplexNumber(1, 2);
	a[1] = CComplexNumber(1, 1);
	CComplexVector0 b(3);
	b[0] = CComplexNumber(0, 1);
	b[1] = CComplexNumber(1, 0);
	b[2] = CComplexNumber(0, -1);
	CComplexVector0 c = a + b;
	if (c.size() != 3) {
		return 0;
	}
	if (c[0].re != 1 || c[0].im != 3) {
		return 0;
	}
	if (c[1].re != 2 || c[1].im != 1) {
		return 0;
	}
	if (c[2].re != 0 || c[2].im != -1) {
		return 0;
	}
	c = a - b;
	if (c.size() != 3) {
		return 0;
	}
	if (c[0].re != 1 || c[0].im != 1) {
		return 0;
	}
	if (c[1].re != 0 || c[1].im != 1) {
		return 0;
	}
	if (c[2].re != 0 || c[2].im != 1) {
		return 0;
	}
	a[0] = CComplexNumber(1, 0);
	a[1] = CComplexNumber(1, 0);
	b[0] = CComplexNumber(2, 0);
	b[1] = CComplexNumber(1, 0);
	b[2] = CComplexNumber(1, 0);
	if ((a * b).re != 3 || (a * b).im != 0) {
		return 0;
	}
	for (int i = 0; i < 100; i++) {
		CComplexVector0 vect1(1000000);
		CComplexVector0 vect2(1000000);
		std::cout << "Started" << std::endl;
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
		CComplexNumber res = vect1 * vect2;
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
		if (res.re != 0 || res.im != 0) {
			return 0;
		}
	}
	return 1;
}
