/* 1. Header Guard (The "Anti-Confusion" Layer) */
#ifndef TANGENT_ENGINE_H
#define TANGENT_ENGINE_H

/* 2. Includes (Dependencies) */
// Only include what the header itself needs (like bool or size_t)
#include <stdbool.h>

/* 3. Constants and Macros */
#define TANGENT_VERSION "1.0.0"

/* 4. Function Prototypes (The "Menu") */
// This tells other files what functions exist in tangent_engine.c
double tangent_solve(char *input);
void tangent_clear_memory(void);

#endif /* 5. End of Header Guard */