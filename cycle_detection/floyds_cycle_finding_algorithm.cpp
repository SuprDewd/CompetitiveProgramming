#ifndef CYCLE_DETECTION_FLOYD
#define CYCLE_DETECTION_FLOYD
#include "../header.cpp"

template <class T>
ii detect_cycle(T x0, T (*f)(T)) {
	int mu = 0, lam = 1;
	T tortoise = f(x0),
	  hare = f(f(x0));
	
	while (tortoise != hare) {
		tortoise = f(tortoise);
		hare = f(f(hare));
	}
	
	tortoise = x0;
	while (tortoise != hare) {
		tortoise = f(tortoise);
		hare = f(hare);
		mu++;
	}
	
	hare = f(tortoise);
	while (tortoise != hare) {
		hare = f(hare);
		lam++;
	}
	
	return ii(lam, mu);
}

#endif
