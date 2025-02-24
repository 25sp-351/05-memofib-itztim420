#include <stdio.h>

#define MAX_MEMOIZED 91
#define ARRAY_SIZE (MAX_MEMOIZED + 1)
#define NO_VALUE_YET -1

// Memoization array and cache function
long long _memoization_data[ARRAY_SIZE];
long (*_original_provider)(int);

long cache_func(int n) {
    printf(__FILE__ ":%2d   cache_func(%d) called\n", __LINE__, n);

    if (n > MAX_MEMOIZED)
        return (*_original_provider)(n);

    if (_memoization_data[n] == NO_VALUE_YET) {
        _memoization_data[n] = (*_original_provider)(n);
    }

    return _memoization_data[n];
}

long (*init_cache(long (*real_provider)(int)))(int) {
    for (int ix = 0; ix < ARRAY_SIZE; ix++) {
        _memoization_data[ix] = NO_VALUE_YET;
    }

    _original_provider = real_provider;
    return cache_func;
}