#ifndef VEC_H
#define VEC_H

#include "include/Agent.h"

struct AVec {
  struct Agent *agents;
  size_t size;
  size_t allocated;
};

void avec_init(struct AVec* vec, size_t size);
void avec_free(struct AVec* vec);
void avec_delete(struct AVec* vec, size_t idx);
void avec_push_back(struct AVec* vec, struct Agent a);
struct Agent* avec_get(struct AVec* vec, size_t idx);

#endif // VEC_H
